#include "jnsBloodyMeso.h"
#include "CommonSceneInclude.h"
#include "jnsAttackColScript.h"

namespace jns
{
	bool ComparePosition(GameObject* a, GameObject* b)
	{
		Vector3 playerPos = SceneManager::GetPlayer()->GetComponent<Transform>()->GetPosition();

		if (abs(a->GetComponent<Transform>()->GetPosition().x - playerPos.x)
			>= abs(b->GetComponent<Transform>()->GetPosition().x - playerPos.x))
			return false;

		return true;
	}

	BloodyMeso::BloodyMeso()
		: SkillBase(eSkillType::BloodyMeso)
	{
		
	}
	BloodyMeso::~BloodyMeso()
	{
		//settarget.clear();
	}
	void BloodyMeso::Initialize()
	{
		if (isInitialize)
			return;

		isInitialize = true;


		cd = AddComponent<Collider2D>();
		//cd->SetColliderOn(false);
		
		
		AddComponent<RigidBody>()->SetGround(false);
		SetName(L"BloodyMeso");
		SetMesh(L"RectMesh");
		SetMaterial(L"SpriteAnimaionMaterial");
		at->CreateAnimations(L"..\\Resources\\Rogue_Skill\\BloodyParket", 500, 0.1f, Vector2(0.0f,0.05f));
		at->PlayAnimation(L"Rogue_SkillBloodyParket", true);
		tr->SetScale(Vector3(500.0f, 500.0f, 1.0f));
		cd->SetSize(Vector2(0.1f, 0.1f));

		AddComponent<AttackColScript>();
		tr->SetPosition(Vector3(-300.0f, -400.0f, 2.0f));

		// 데이터는 맨 마지막 초기화
		SetInitData();
	}
	void BloodyMeso::Update()
	{
		std::random_device rd;

		// random_device 를 통해 난수 생성 엔진을 초기화 한다.
		std::mt19937 gen(rd());

		// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
		std::uniform_int_distribution<int> dis(0, 99);
		// 플레이어 위치정보 가져오기
		//int direction = (int)mPlayerScript->GetPlayerDirection();
		//mPos.x += direction * 130.0f;
		//mPos.z = 0.0f;
		//SetPosition(mPos);
		auto now = std::chrono::high_resolution_clock::now();
		int seed = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
		srand(seed);

		RigidBody* rb = GetComponent<RigidBody>();

		if (rb->GetGround() == false)
		{
			Vector3 mesoPos = tr->GetPosition();
			mAirTime += Time::DeltaTime();

			if (mAirTime <= airMaxTime)
			{
				Vector3 mVelocity = rb->GetVelocity();
				mVelocity.y -= 600.0f *Time::DeltaTime();
				rb->SetVelocity(mVelocity);
				mesoPos.y += 150.0f * Time::DeltaTime();
				tr->SetPosition(mesoPos);
			}
			else
			{
				rb->SetIsRigidBodyOn(true);
			}
		}
		else
		{
			cd->SetColliderOn(false);
			mAirTime = 999.0f;
		}

		// 가까운 8명 랜덤으로 잡기
		if (targetNum < 0 && active)
		{
			int t = dis(gen);
			
			if (settarget.size() >= 1)	
			{
				if (settarget.size() >= 8)
				{
					targetNum = t % 8;
				}
				else
				{
					targetNum = t % settarget.size();
				}
			}
		}
		else if(targetNum >=0 && active)
		{
			std::sort(settarget.begin(), settarget.end(), ComparePosition);
			rb->SetGround(false);
			rb->SetIsRigidBodyOn(false);
			Vector3 monsterPos = settarget[targetNum]->GetComponent<Transform>()->GetPosition();
			Vector3 mesoPos = tr->GetPosition();
		
			if (abs(monsterPos.x - mesoPos.x) <= 600.0f)
			{
				if (settarget[targetNum]->GetState() == GameObject::eState::Active)
				{
					mTime += Time::DeltaTime();
					Vector3 newPos = {};

					if (mTime <= 1.0f)
					{
						Vector3 pos = tr->GetPosition();

						int randangle = 10.0f;
						if (monsterPos.x >= tr->GetPosition().x)
						{
							randangle %= 180;
						}
						else
						{
							randangle %= 180;
							randangle += 180;
						}

						angle = randangle;
						angle++;

					

						float g = -9.8f;
						if (updown == 0)
						{
							g = -9.8f;

						}
						else
						{
							g = 9.8f;
						}
						float t = Time::DeltaTime();
						float y = velocity * cos(DegreeToRadian(45)) * t;
						float x = velocity * sin(DegreeToRadian(45)) * t - 0.5f * t * g * t;
						newPos = tr->GetPosition() + Vector3(x, y, 0.0f);

					}
					else
					{
						newPos = tr->GetPosition();
					}


					Vector3 interpolatedPos = Vector3::Lerp(newPos, monsterPos, 5.0f * Time::DeltaTime());

					Vector3 pos = tr->GetPosition();

					if (pos.x <= monsterPos.x + 100.0f && pos.x >= monsterPos.x - 100.0f)
					{
						cd->SetColliderOn(true);
					}

					tr->SetPosition(interpolatedPos);
				}
				else
				{
					isDamageDisplayed = true;
				}

			}
		}
		

		SkillBase::Update();
	}
	void BloodyMeso::LateUpdate()
	{
		SkillBase::LateUpdate();
	}
	void BloodyMeso::Render()
	{
		SkillBase::Render();

		if (isDamageDisplayed == true)
		{
			MesoPooling::MesoObjectPooling::GetInstance().RecycleMesoObject(this);
		}
	}
	void BloodyMeso::CompleteSkillAnimation()
	{
	}
	void BloodyMeso::StartSkillAnimation()
	{
	}
	void BloodyMeso::Activate()
	{
		if (this->GetState() == eState::Paused)
			return;
		cd->SetColliderOn(true);
		active = true;
		std::vector<GameObject*> monsters = {};
		AttackColScript* attackColScript = GetComponent<AttackColScript>();
		
		attackColScript->UpdateMonsters();
		monsters = attackColScript->GetMonsterObjects();


		for (GameObject* obj : monsters)
		{
			MonsterBase* base = dynamic_cast<MonsterBase*>(obj);

			if (obj->GetState() == eState::Paused)
				continue;

			if (base == nullptr)
			{
				return;
			}
			else
			{
				settarget.push_back(base);
			}
		}

		std::sort(settarget.begin(), settarget.end(), ComparePosition);
	}
	void BloodyMeso::DeActivate()
	{
		SetInitData();
	}
	void BloodyMeso::SetPosition(Vector3 pos)
	{
		tr->SetPosition(pos);
	}

	// 데이터 초기화
	void BloodyMeso::SetInitData()
	{
		RigidBody* rb = GetComponent<RigidBody>();
		rb->SetGround(false);
		rb->SetIsRigidBodyOn(true);
		settarget.clear();
		isRenderOn = true;
		targetNum = -99;
		velocity = 150.0f;
		
		angle = 0.0f;

		mAirTime = 0.0f;
		airMaxTime = 0.5f;

		active = false;
		mTime = 0.0f;
		isDamageDisplayed = false;
	}
}