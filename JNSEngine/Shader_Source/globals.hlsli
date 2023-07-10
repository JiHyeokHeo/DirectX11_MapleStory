cbuffer Transform : register(b0)
{
    //float4 Position;
    row_major matrix WorldMatrix;
    row_major matrix ViewMatrix;
    row_major matrix ProjectionMatrix;
}

cbuffer Grid : register(b2)
{
    float4 CameraPosition;
    float2 CameraScale;
    float2 Resolution;
}


cbuffer Time: register(b3)
{
    int type;
    float3 mTime;
}


cbuffer PlayerUI : register(b4)
{
    int hp;
    int mp;
    float2 mPlayerTime;
}

Texture2D albedoTexture : register(t0);
SamplerState pointSampler : register(s0);
SamplerState anisotropicSampler : register(s1);