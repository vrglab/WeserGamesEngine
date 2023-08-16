#include "pch.h"


void DirectXRenderer::GLFWInit()
{
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void DirectXRenderer::RenderFrameworkInit(GLFWwindow* window)
{
    Console::Log("DirectX11 Starting");
    D3D_FEATURE_LEVEL featureLevel;
    HRESULT result = D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        0,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &device,
        &featureLevel,
        &deviceContext
    );

    if (FAILED(result))
    {
        throw std::runtime_error("DirectX device could not start: " + result);
    }

    Resolution* res = (Resolution*)AppSettings::GetInstance().GetSetting("Initial_resolution");

    DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
    swapChainDesc.BufferCount = 1;
    swapChainDesc.Width = res->GetWidth();
    swapChainDesc.Height = res->GetHeight();
    swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    swapChainDesc.SampleDesc.Count = 1;
    swapChainDesc.SampleDesc.Quality = 0;
    
    result = CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory));
    if (FAILED(result))
    {
        // Handle DXGI factory creation failure
        throw std::runtime_error("DirectX DXGIFactory failed initializition: " + result);
    }

    result = dxgiFactory->CreateSwapChainForHwnd(device, glfwGetWin32Window(window), &swapChainDesc, nullptr, nullptr, &swapChain);
    if (FAILED(result))
    {
        // Handle swap chain creation failure
        throw std::runtime_error("DirectX swapchain could not be made: " + result);
    }

    dxgiFactory->Release();

    swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
    device->CreateRenderTargetView(backBuffer, nullptr, &renderTargetView);
    backBuffer->Release();

    deviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);

    D3D11_VIEWPORT viewport;
    viewport.Width = static_cast<float>(res->GetWidth());
    viewport.Height = static_cast<float>(res->GetHeight());
    viewport.MinDepth = 0.0f;
    viewport.MaxDepth = 1.0f;
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;

    deviceContext->RSSetViewports(1, &viewport);
    
}

ID3D11Buffer* ppBuffer;

void DirectXRenderer::RenderInit()
{
    float clearColor[] = { 1.0f, 0.0f, 1.0f, 1.0f };
    deviceContext->ClearRenderTargetView(renderTargetView, clearColor);
}

void DirectXRenderer::Render()
{
    auto BATCH = MeshBatch::GetInstance().GetBatch();
}

void DirectXRenderer::RenderEnd()
{
    swapChain->Present(0, 0);
}

void DirectXRenderer::RenderFrameworkCleanup()
{
}
