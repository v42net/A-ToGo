@echo off
DOSKEY make=A:\Tools\MinGW-w64\i686\mingw32\bin\mingw32-make.exe $*
cd /d %~dp0
cmd /k