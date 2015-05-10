#pragma once

/////////////////////////////////////////////////////////////////////
//
// Manage shader resources.
//
////////////////////////////////////////////////////////////////////

#include <unordered_map>

struct D3D11_BLEND_DESC;
struct D3D11_BUFFER_DESC;
struct D3D11_DEPTH_STENCIL_DESC;
struct D3D11_DEPTH_STENCIL_VIEW_DESC;
struct D3D11_RASTERIZER_DESC;
struct D3D11_RENDER_TARGET_VIEW_DESC;
struct D3D11_SAMPLER_DESC;
struct D3D11_SHADER_RESOURCE_VIEW_DESC;
struct D3D11_SUBRESOURCE_DATA;
struct D3D11_TEXTURE2D_DESC;
struct D3D11_UNORDERED_ACCESS_VIEW_DESC;
struct ID3D11BlendState;
struct ID3D11Buffer;
struct ID3D11DepthStencilState;
struct ID3D11DepthStencilView;
struct ID3D11Device1;
struct ID3D11RasterizerState;
struct ID3D11RenderTargetView;
struct ID3D11Resource;
struct ID3D11SamplerState;
struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;
struct ID3D11UnorderedAccessView;

namespace BRE {
	class ShaderResourcesManager {
	public:
		static ShaderResourcesManager* gInstance;

		ShaderResourcesManager(ID3D11Device1& device)
			: mDevice(device)
		{
		}

		~ShaderResourcesManager();

		const ShaderResourcesManager& operator=(const ShaderResourcesManager& rhs) = delete;

		ID3D11ShaderResourceView* AddTextureFromFileSRV(const char* filepath);

		ID3D11ShaderResourceView* AddResourceSRV(const char* id, ID3D11Resource& resource, const D3D11_SHADER_RESOURCE_VIEW_DESC* desc);
		ID3D11ShaderResourceView* AddResourceSRV(const size_t id, ID3D11Resource& resource, const D3D11_SHADER_RESOURCE_VIEW_DESC* desc);

		ID3D11UnorderedAccessView* AddResourceUAV(const char* id, ID3D11Resource& resource, const D3D11_UNORDERED_ACCESS_VIEW_DESC& desc);
		ID3D11UnorderedAccessView* AddResourceUAV(const size_t id, ID3D11Resource& resource, const D3D11_UNORDERED_ACCESS_VIEW_DESC& desc);

		ID3D11Buffer* AddBuffer(const char* id, D3D11_BUFFER_DESC& desc, const D3D11_SUBRESOURCE_DATA* const initData);
		ID3D11Buffer* AddBuffer(const size_t id, D3D11_BUFFER_DESC& desc, const D3D11_SUBRESOURCE_DATA* const initData);

		ID3D11Texture2D* AddTexture2D(const char* id, const D3D11_TEXTURE2D_DESC& texDesc, const D3D11_SUBRESOURCE_DATA* initialData);
		ID3D11Texture2D* AddTexture2D(const size_t id, const D3D11_TEXTURE2D_DESC& texDesc, const D3D11_SUBRESOURCE_DATA* initialData);

		ID3D11RasterizerState* AddRasterizerState(const char* id, const D3D11_RASTERIZER_DESC& desc);
		ID3D11RasterizerState* AddRasterizerState(const size_t id, const D3D11_RASTERIZER_DESC& desc);

		ID3D11RenderTargetView* AddRenderTargetView(const char* id, ID3D11Resource& resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc);
		ID3D11RenderTargetView* AddRenderTargetView(const size_t id, ID3D11Resource& resource, const D3D11_RENDER_TARGET_VIEW_DESC* desc);

		ID3D11DepthStencilView* AddDepthStencilView(const char* id, ID3D11Resource& resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc);
		ID3D11DepthStencilView* AddDepthStencilView(const size_t id, ID3D11Resource& resource, const D3D11_DEPTH_STENCIL_VIEW_DESC* desc);

		ID3D11BlendState* AddBlendState(const char* id, const D3D11_BLEND_DESC& desc);
		ID3D11BlendState* AddBlendState(const size_t id, const D3D11_BLEND_DESC& desc);

		ID3D11DepthStencilState* AddDepthStencilState(const char* id, const D3D11_DEPTH_STENCIL_DESC& desc);
		ID3D11DepthStencilState* AddDepthStencilState(const size_t id, const D3D11_DEPTH_STENCIL_DESC& desc);

		ID3D11SamplerState* AddSamplerState(const char* id, const D3D11_SAMPLER_DESC& desc);
		ID3D11SamplerState* AddSamplerState(const size_t id, const D3D11_SAMPLER_DESC& desc);

		ID3D11ShaderResourceView* ShaderResourceView(const char* id) const;
		ID3D11ShaderResourceView* ShaderResourceView(const size_t id) const;

		ID3D11UnorderedAccessView* UnorderedAccessView(const char* id) const;
		ID3D11UnorderedAccessView* UnorderedAccessView(const size_t id) const;

		ID3D11Buffer* Buffer(const char* id) const;
		ID3D11Buffer* Buffer(const size_t id) const;

		ID3D11Texture2D* Texture2D(const char* id) const;
		ID3D11Texture2D* Texture2D(const size_t id) const;

		ID3D11RasterizerState* RasterizerState(const char* id) const;
		ID3D11RasterizerState* RasterizerState(const size_t id) const;

		ID3D11RenderTargetView* RenderTargetView(const char* id) const;
		ID3D11RenderTargetView* RenderTargetView(const size_t id) const;

		ID3D11DepthStencilView* DepthStencilView(const char* id) const;
		ID3D11DepthStencilView* DepthStencilView(const size_t id) const;

		ID3D11BlendState* BlendState(const char* id) const;
		ID3D11BlendState* BlendState(const size_t id) const;

		ID3D11DepthStencilState* DepthStencilState(const char* id) const;
		ID3D11DepthStencilState* DepthStencilState(const size_t id) const;

		ID3D11SamplerState* SamplerState(const char* id) const;
		ID3D11SamplerState* SamplerState(const size_t id) const;

	private:
		ID3D11Device1& mDevice;

		typedef std::unordered_map<size_t, ID3D11ShaderResourceView*> ShaderResourceViews;
		ShaderResourceViews mShaderResourceViews;

		typedef std::unordered_map<size_t, ID3D11UnorderedAccessView*> UnorderedAccessViews;
		UnorderedAccessViews mUnorderedAccessViews;

		typedef std::unordered_map<size_t, ID3D11Buffer*> Buffers;
		Buffers mBuffers;

		typedef std::unordered_map<size_t, ID3D11Texture2D*> Textures2D;
		Textures2D mTextures2D;

		typedef std::unordered_map<size_t, ID3D11RasterizerState*> RasterizerStates;
		RasterizerStates mRasterizerStates;

		typedef std::unordered_map<size_t, ID3D11RenderTargetView*> RenderTargetViews;
		RenderTargetViews mRenderTargetViews;

		typedef std::unordered_map<size_t, ID3D11DepthStencilView*> DepthStencilViews;
		DepthStencilViews mDepthStencilViews;

		typedef std::unordered_map<size_t, ID3D11BlendState*> BlendStates;
		BlendStates mBlendStates;

		typedef std::unordered_map<size_t, ID3D11DepthStencilState*> DepthStencilStates;
		DepthStencilStates mDepthStencilStates;

		typedef std::unordered_map<size_t, ID3D11SamplerState*> SamplerStates;
		SamplerStates mSamplerStates;
	};
}