#include "pch.h"
#include "Engine.h"

#include "CommandQueue.h"
#include "DescriptorHeap.h"
#include "Device.h"
#include "SwapChain.h"

void Engine::init(const WindowInfo& window)
{
    window_ = window;

    ResizeWindow(window.width, window.height);

    //그려질 크기를 설정
    viewport_ = { 0,0, static_cast<FLOAT>(window.width), static_cast<FLOAT>(window.height),0.f, 1.f };
    scissorRect_ = CD3DX12_RECT(0, 0, window.width, window.height);

    //디바이스 초기화
    device_ = make_shared<Device>();
    cmdQueue_ = make_shared<CommandQueue>();
    swapChain_ = make_shared<SwapChain>();
    descHeap_ = make_shared<DescriptorHeap>();
}

void Engine::Rendering()
{
}

void Engine::ResizeWindow(int32 width, int32 height)
{
    window_.width = width;
    window_.height = height;

    RECT rect = { 0,0,height, width };
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
    SetWindowPos(window_.hwnd, 0, 100, 100, width, height, 0);
}
