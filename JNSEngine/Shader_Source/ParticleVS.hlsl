#include "globals.hlsli"


struct VSIn
{
    float3 LocalPos : POSITION;
    uint Instance : SV_InstanceID;
};

struct VSOut
{
    float4 LocalPos : SV_Position;
    uint Instance : SV_InstanceID;
};


VSOut main(VSIn In)
{
    VSOut Out = (VSOut) 0.0f;
    Out.LocalPos = float4(In.LocalPos, 1.0f);
    Out.Instance = In.Instance;
    
    //float3 worldPos = (In.pos.xyz) + WorldMatrix._41_42_43 + particles[In.Instance].position.xyz;
    
    //float4 worldPos = mul(float4(In.pos, 1.0f), WorldMatrix);
    //worldPos.xyz += particles[In.Instance].position.xyz;
    
    //float4 viewPos = mul(worldPos, ViewMatrix);
    //Out.pos = mul(viewPos, ProjectionMatrix);
    
    return Out;
}