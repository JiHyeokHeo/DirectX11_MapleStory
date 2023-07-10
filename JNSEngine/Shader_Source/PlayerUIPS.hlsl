#include "globals.hlsli"

struct VSIn
{
    float3 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

float4 main(VSOut In) : SV_TARGET
{
    float4 color = (float4) 0.0f;
    
    float uvPos = ((float)hp) / 100.0f;
    
    if(In.UV.x >= 0.5f && hp <= 50)
    {
        discard;
    }
    else
    {
        color = albedoTexture.Sample(anisotropicSampler, In.UV);
    }
    
    
    
    return color;
}