#include "globals.hlsli"
RWStructuredBuffer<Particle> ParticleBuffer : register(u0);
RWStructuredBuffer<ParticleShared> ParticleSharedBuffer : register(u1);

[numthreads(128, 1, 1)]
void main(uint3 DTid : SV_DispatchThreadID)
{
    if (elementCount <= DTid.x)
        return;
    
    
    if (ParticleBuffer[DTid.x].active == 0)
    {
        while (0 < ParticleSharedBuffer[0].ActiveSharedCount)
        {
            int origin = ParticleSharedBuffer[0].ActiveSharedCount;
            int exchange = origin - 1;
            
            // 쓰레드 동기화 Interlock 관련 함수
            InterlockedExchange(ParticleSharedBuffer[0].ActiveSharedCount
                , exchange, exchange);
            
            if (origin == exchange)
            {
                ParticleBuffer[DTid.x].active = 1;
                break;
            }
        }
    }
    else
    {
        ParticleBuffer[DTid.x].position 
        += ParticleBuffer[DTid.x].direction * ParticleBuffer[DTid.x].speed * elapsedTime;
    }
}