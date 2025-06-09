@echo off
setlocal enabledelayedexpansion
set files=

for /r src %%i in (*.cpp) do (
    set files=!files! "%%i"
)

g++ -fdiagnostics-color=always %files% -o app.exe