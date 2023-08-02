#include "globals.hlsli"


struct VSIn
{
    float3 pos : POSITION;
    uint Instance : SV_InstanceID;
};

struct VSOut
{
    float4 pos : SV_POSITION;
};


VSOut main(VSIn In)
{
    VSOut Out = (VSOut) 0.0f;
    //float3 worldPos = (In.pos.xyz) + WorldMatrix._41_42_43 + particles[In.Instance].position.xyz;
    
    float4 worldPos = mul(float4(In.pos, 1.0f), WorldMatrix);
    worldPos.xyz += particles[In.Instance].position.xyz;
    
    float4 viewPos = mul(worldPos, ViewMatrix);
    Out.pos = mul(viewPos, ProjectionMatrix);
    
    return Out;
}