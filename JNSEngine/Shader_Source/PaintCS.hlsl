RWTexture2D<float4> tex : register(u0);

//https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl/sv-dispatchthreadid
// SV_GroupID           : 스레드가 속한 그룹의 좌표
// SV_GoupThreadID      : 그룹 내에서, 스레드의 좌표
// SV_GoupIndex         : 그룹 내에서, 스레드의 인덱스 (1차원)
// SV_DispatchThreadID  : 전체 스레드(모든 그룹 통합) 기준으로, 호출된 스레드의 좌표

[numthreads(32, 32, 1)] // 그룹 당 스레드 개수 (최대 1024 까지 지정 가능)
void main(uint3 DTid : SV_DispatchThreadID)
{
    if (DTid.x >= 1024 || DTid.y >= 1024)
    {
        return;
    }

    tex[DTid.xy] = float4(0.f, 0.f, 1.f, 1.f);
}