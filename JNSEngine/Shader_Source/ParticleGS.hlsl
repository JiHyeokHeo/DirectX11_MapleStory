#include "globals.hlsli"

struct VSOut
{
    float4 LocalPos : SV_Position;
    uint Instance : SV_InstanceID;
};

struct GSOut
{
    float4 Pos : SV_Position;
    float2 UV : TEXCOORD;
    //uint Instance : SV_InstanceID;
};

[maxvertexcount(6)]
void main(point VSOut In[1], inout TriangleStream<GSOut> output)
{
    GSOut Out[4] = { (GSOut) 0.0f, (GSOut) 0.0f, (GSOut) 0.0f, (GSOut) 0.0f };
    
    if (particles[In[0].Instance].active == 0)
        return;
    
    float3 worldPos = (In[0].LocalPos.xyz)
                    //+ WorldMatrix._41_42_43 
                    + particles[In[0].Instance].position.xyz;
    
    float3 viewPos = mul(float4(worldPos, 1.0f), ViewMatrix).xyz;
    
    float3 NewPos[4] =
    {
        viewPos - float3(-0.5f, 0.5f, 0.f) * float3(10.2f, 10.2f, 1.f),
        viewPos - float3(0.5f, 0.5f, 0.f) * float3(10.2f, 10.2f, 1.f),
        viewPos - float3(0.5f, -0.5f, 0.f) * float3(10.2f, 10.2f, 1.f),
        viewPos - float3(-0.5f, -0.5f, 0.f) * float3(10.2f, 10.2f, 1.f),
    };
    
    for (int i = 0; i < 4; ++i)
    {
        Out[i].Pos = mul(float4(NewPos[i], 1.0f), ProjectionMatrix);
        //Out[i].Pos = float4(NewPos[i], 1.0f);
    }
    
    Out[0].UV = float2(0.0f, 0.0f);
    Out[1].UV = float2(1.0f, 0.0f);
    Out[2].UV = float2(1.0f, 1.0f);
    Out[3].UV = float2(0.0f, 1.0f);
    

    //Out[0].Instance = In[0].Instance;
    //Out[1].Instance = In[0].Instance;
    //Out[2].Instance = In[0].Instance;
    //Out[3].Instance = In[0].Instance;
    
    // 0 -- 1
    // | \  |
    // 3 -- 2
    output.Append(Out[0]);
    output.Append(Out[1]);
    output.Append(Out[2]);
    output.RestartStrip();

    output.Append(Out[0]);
    output.Append(Out[2]);
    output.Append(Out[3]);
    output.RestartStrip();
}