#define QUAD_VERTICES (4)

cbuffer cbPerFrame : register (b0) {
	float4x4 gView;
	float4x4 gProj;
};

struct GSInput {
	nointerpolation float3 mLightCenterPosW : POSITION;
	nointerpolation float4 mLightColorAndRadius : LIGHT_COLOR_AND_RADIUS;
};

struct GSOutput {
	float4 mVertexPosH : SV_POSITION;
	nointerpolation float3 mLightPosW : POSITION;
	nointerpolation float4 mLightColorAndRadius : LIGHT_COLOR_AND_RADIUS;
};

[maxvertexcount(QUAD_VERTICES)]
void
main(const in point GSInput input[1], inout TriangleStream<GSOutput> triangleStream) {
	// Compute quad center position in view space.
	// Then we can easily build a quad (two triangles) that face the camera.
	const float4 lightCenterPosV = mul(float4(input[0].mLightCenterPosW, 1.0f), gView);

	const float quadHalfSize = input[0].mLightColorAndRadius.w;

	// Compute vertices positions and texture coordinates based on
	// a quad whose center position is lightCenterPosV
	GSOutput output;

	output.mVertexPosH = mul(lightCenterPosV + float4(-quadHalfSize, quadHalfSize, 0.0f, 0.0f), gProj);
	output.mLightPosW = input[0].mLightCenterPosW;
	output.mLightColorAndRadius = input[0].mLightColorAndRadius;
	triangleStream.Append(output);

	output.mVertexPosH = mul(lightCenterPosV + float4(quadHalfSize, quadHalfSize, 0.0f, 0.0f), gProj);
	output.mLightPosW = input[0].mLightCenterPosW;
	output.mLightColorAndRadius = input[0].mLightColorAndRadius;
	triangleStream.Append(output);

	output.mVertexPosH = mul(lightCenterPosV + float4(-quadHalfSize, -quadHalfSize, 0.0f, 0.0f), gProj);
	output.mLightPosW = input[0].mLightCenterPosW;
	output.mLightColorAndRadius = input[0].mLightColorAndRadius;
	triangleStream.Append(output);

	output.mVertexPosH = mul(lightCenterPosV + float4(quadHalfSize, -quadHalfSize, 0.0f, 0.0f), gProj);
	output.mLightPosW = input[0].mLightCenterPosW;
	output.mLightColorAndRadius = input[0].mLightColorAndRadius;
	triangleStream.Append(output);

	triangleStream.RestartStrip();
}