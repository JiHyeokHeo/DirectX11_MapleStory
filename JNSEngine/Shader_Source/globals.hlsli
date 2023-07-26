cbuffer Transform : register(b0)
{
    //float4 Position;
    row_major matrix WorldMatrix;
    row_major matrix ViewMatrix;
    row_major matrix ProjectionMatrix;
}

// 1
//
///


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
    int exp;
    int barType;
}

cbuffer Animator : register(b5)
{
    float2 SpriteLeftTop;
    float2 SpriteSize;
    float2 SpriteOffset;
    float2 AtlasSize;
    uint animationType;
    float3 pad;
}

Texture2D albedoTexture : register(t0);
Texture2D atlasTexture : register(t12);

struct LightAttribute
{
    float4 color;
    float4 position;
    float4 direction;
    
    uint type;
    float radius;
    float angle;
    int pad;
};

StructuredBuffer<LightAttribute> lightsAttribute : register(t13);

SamplerState pointSampler : register(s0);
SamplerState anisotropicSampler : register(s1);