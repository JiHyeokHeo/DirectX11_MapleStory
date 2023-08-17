#include "globals.hlsli"



struct GSOut
{
    float4 Pos : SV_Position;
    float2 UV : TEXCOORD;
    uint Instance : SV_InstanceID;
};

float4 main(GSOut In) : SV_TARGET
{
    float4 Out = (float4) 0.0f;
    
    Out = albedoTexture.Sample(anisotropicSampler, In.UV);
    
    if (Out.a <= 0.0f)
        discard;
    
    float3 startcolor = particles[In.Instance.x].startColor.xyz;
    float3 endcolor = particles[In.Instance.x].endColor.xyz;
    
    float colorchangetime = particles[In.Instance.x].elapsedTime / particles[In.Instance.x].lifeTime;
    Out.rgb = lerp(startcolor, endcolor, colorchangetime);
    
    
    
    return Out;

}