#pragma once
#include "pch.h"

#ifndef __DIRECTXRENDERER__
#define __DIRECTXRENDERER__
class DirectXRenderer : public RendereringFramework
{
	public:
		ID3D11Device* device = nullptr;
		ID3D11DeviceContext* deviceContext = nullptr;
		IDXGIFactory2* dxgiFactory = nullptr;
		IDXGISwapChain1* swapChain = nullptr;
		ID3D11RenderTargetView* renderTargetView = nullptr;
		ID3D11Texture2D* backBuffer;
		DirectXRenderer() = default;

		void GLFWInit() override;
		void RenderFrameworkInit(GLFWwindow*) override;
		void RenderInit() override;
		void Render() override;
		void RenderEnd() override;
		void RenderFrameworkCleanup() override;
};
#endif

