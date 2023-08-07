cbuffer Transform : register(b0)
{
    //float4 Position;
    row_major matrix WorldMatrix;
    row_major matrix ViewMatrix;
    row_major matrix ProjectionMatrix;
}

// 1
//
///


cbuffer Grid : register(b2)
{
    float4 CameraPosition;
    float2 CameraScale;
    float2 Resolution;
}


cbuffer Time: register(b3)
{
    int type;
    float3 mTime;
}


cbuffer PlayerUI : register(b4)
{
    int hp;
    int mp;
    int exp;
    int barType;
}

cbuffer Animator : register(b5)
{
    float2 SpriteLeftTop;
    float2 SpriteSize;
    float2 SpriteOffset;
    float2 AtlasSize;
    uint animationType;
    float3 pad;
}

cbuffer ParticleSystem : register(b6)
{
    uint elementCount;
    float elapsedTime;
    int padd;
    int padd2;
}

struct ParticleShared
{
    uint ActiveSharedCount;
};

Texture2D albedoTexture : register(t0);
Texture2D atlasTexture : register(t12);

struct LightAttribute
{
    float4 color;
    float4 position;
    float4 direction;
    
    uint type;
    float radius;
    float angle;
    int pad;
};

struct Particle
{
    float4 position;
    float4 direction;
    
    float endTime;
    float time;
    float speed;
    uint active;
};

StructuredBuffer<LightAttribute> lightsAttribute : register(t13);
StructuredBuffer<Particle> particles : register(t14);

SamplerState pointSampler : register(s0);
SamplerState anisotropicSampler : register(s1);

void CalculateLight2D(in out float4 lightColor, float3 position, int idx)
{
    if (0 == lightsAttribute[idx].type)
    {
        lightColor += lightsAttribute[idx].color;
    }
    else if (1 == lightsAttribute[idx].type)
    {
        float length = distance(position.xy, lightsAttribute[idx].position.xy);
        
        if (length < lightsAttribute[idx].radius)
        {
            float ratio = 1.0f - (length / lightsAttribute[idx].radius);
            lightColor += lightsAttribute[idx].color * ratio;
        }
    }
    else
    {
        
    }
}