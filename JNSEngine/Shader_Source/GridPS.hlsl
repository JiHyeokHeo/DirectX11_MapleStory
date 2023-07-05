#include "globals.hlsli"

struct VSIn
{
    float3 Pos : POSITION;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : SV_Position;
    float2 UV : TEXCOORD;
    float2 GridPos : POSITION;
};

float4 main(VSOut In) : SV_TARGET
{
    float4 Out = float4(1.0f, 0.0f, 1.0f, 1.0f);
    
    const int width = 100;
    const int height = 100;
       
    int gridX = (int) In.GridPos.x;
    int gridY = (int) In.GridPos.y;
    
    if (abs((gridX + 1) % width) <= 1.0f)
        return Out;
    
    if (abs((gridY + 1) % height) <= 1.0f)
        return Out;
    
    discard;
    
    return Out;
}