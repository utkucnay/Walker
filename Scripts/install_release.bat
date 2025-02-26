@echo off
mkdir .out
cmake -S . -O .out\Release -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C %cd%\.out\Release

mkdir .\.out\Release\Sandbox\D3D12
copy .\Walker\vendor\DirectX12\bin\x64\D3D12Core.dll .\.out\Release\Sandbox\D3D12
copy .\Walker\vendor\DirectX12\bin\x64\d3d12SDKLayers.dll .\.out\Release\Sandbox\D3D12
