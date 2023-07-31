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
    float3 WorldPos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};


float4 main(VSOut In) : SV_TARGET
{
    float4 color = float4(0.0f, 0.0f, 0.0f, 0.0f);
    
    float uvPos = ((float) hp) / 100.0f;
    
    if (barType == 0) // hp bar
    {
        if (In.UV.x >= 0.5f && hp <= 50)
        {
            discard;
        }
        else
        {
            color = albedoTexture.Sample(anisotropicSampler, In.UV);
        }
    }
    else if (barType == 1) // mp bar
    {
        color = albedoTexture.Sample(anisotropicSampler, In.UV);
    }
    
    float4 lightColor = float4(0.2f, 0.2f, 0.2f, 1.0f);
    for (int i = 0; i < 2; i++)
    {
        CalculateLight2D(lightColor, In.WorldPos, i);
    }
    
    color *= lightColor;
    
    return color;
}