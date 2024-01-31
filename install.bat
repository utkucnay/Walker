@echo off
mkdir .out
cmake -S . -O .out -G Ninja
ninja -C %cd%\.out
