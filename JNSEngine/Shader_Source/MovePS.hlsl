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
    float4 color = (float4) 0.0f;
    float2 uv = In.UV;
    
    if (type == 1)
        uv.x += mTime.x * 0.3f;
    if (type == 2)
        uv.x -= mTime.x * 0.3f;

    //if(In.UV.x >= 0.5f)
    //{
    //    discard;
    //}
    //else
    //{
    //    color = albedoTexture.Sample(anisotropicSampler, uv);
    //}
    float4 lightColor = float4(0.0f, 0.0f, 0.0f, 1.0f);
    
    for (int i = 0; i < 2; i++)
    {
        CalculateLight2D(lightColor, In.WorldPos, i);
    }
    
    
    color = albedoTexture.Sample(anisotropicSampler, uv);
    
    color.rgb = 1.0f;
    color.rgb *= 0.4f;
    color.a *= 0.2f;
    color *= lightColor;
    
    return color;
}