
//structedBuffer
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

cbuffer Transform : register(b0)
{
    //float4 Position;
    row_major matrix mWorld;
    row_major matrix mView;
    row_major matrix mProjection;
}


VSOut main(VSIn In)
{
    VSOut Out = (VSOut) 0.0f;
    
    float4 world = mul(float4(In.Pos, 1.0f), mWorld);
    float4 view = mul(world, mView);
    float4 proj = mul(view, mProjection);
    
    Out.Pos = proj;
    Out.UV = In.UV;
    Out.Color = In.Color;
    
    // sin();
    
    
    return Out;
}