#pragma once


class Engine
{
public:
    void init(const WindowInfo& window);
    void Rendering();
    void ResizeWindow(int32 width, int32 height);
private:
    WindowInfo window_;
    D3D12_VIEWPORT viewport_ = {};
    D3D12_RECT scissorRect_ = {};

    shared_ptr<class Device> device_;
    shared_ptr<class CommandQueue> cmdQueue_;
    shared_ptr<class SwapChain> swapChain_;
    shared_ptr<class DescriptorHeap> descHeap_;
};