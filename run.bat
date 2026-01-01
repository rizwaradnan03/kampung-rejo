@echo off
setlocal

echo =============================
echo Building SFML Project
echo =============================

if not exist build (
    mkdir build
)

cd build

cmake -G "MinGW Makefiles" ..
if errorlevel 1 goto error

mingw32-make
if errorlevel 1 goto error

echo =============================
echo Copying SFML DLLs
echo =============================
copy ..\external\bin\*.dll . >nul

echo =============================
echo Running Program
echo =============================
kampung_rejo.exe

pause
exit /b 0

:error
echo.
echo BUILD FAILED
pause
exit /b 1
