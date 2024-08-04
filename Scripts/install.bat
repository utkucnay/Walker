@echo off
mkdir .out
cmake -S . -O .out -G Ninja -DCMAKE_BUILD_TYPE=Debug
ninja -C %cd%\.out

mkdir .\.out\Sandbox\D3D12
copy .\Walker\vendor\DirectX12\bin\x64\D3D12Core.dll .\.out\Sandbox\D3D12
copy .\Walker\vendor\DirectX12\bin\x64\d3d12SDKLayers.dll .\.out\Sandbox\D3D12
