@echo off
setlocal

@REM echo =============================
@REM echo Building SFML Project
@REM echo =============================

if not exist build (
    mkdir build
)

cd build

cmake -G "MinGW Makefiles" ..
if errorlevel 1 goto error

mingw32-make
if errorlevel 1 goto error

@REM echo =============================
@REM echo Copying SFML DLLs
@REM echo =============================
copy ..\external\bin\*.dll . >nul

@REM echo =============================
@REM echo Running Program
@REM echo =============================
kampung_rejo.exe

pause
exit /b 0

:error
echo.
echo BUILD FAILED
pause
exit /b 1
