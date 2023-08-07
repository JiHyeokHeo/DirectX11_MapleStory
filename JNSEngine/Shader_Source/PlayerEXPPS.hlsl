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
    
    
    if (barType == 2) // exp bar
    {
        float uvPos = ((float) exp) / 100.0f;
        if (In.UV.x >= uvPos)
        {
            //discard;
        }
        else
        {
            color = albedoTexture.Sample(anisotropicSampler, In.UV);
        }
    }
    
    //color = albedoTexture.Sample(anisotropicSampler, In.UV);
    
    float4 lightColor = float4(0.0f, 0.0f, 0.0f, 1.0f);
    for (int i = 0; i < 2; i++)
    {
        CalculateLight2D(lightColor, In.WorldPos, i);
    }
    
    color *= lightColor;
    
    return color;
}