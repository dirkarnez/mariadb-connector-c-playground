@REM run as Administrator
@echo off
cd /d %~dp0
set DOWNLOADS_DIR=%USERPROFILE%\Downloads
set DOWNLOADS_DIR_LINUX=%DOWNLOADS_DIR:\=/%

set PREFIX=D:\Softwares
@REM set PREFIX=%USERPROFILE%\Downloads

SET PATH=^
%PREFIX%\PortableGit\bin;^
%PREFIX%\winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1\mingw64;^
%PREFIX%\winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1\mingw64\bin;^
%PREFIX%\cmake-3.29.3-windows-x86_64\bin;

cmake.exe -G"MinGW Makefiles" ^
-DCMAKE_BUILD_TYPE=Debug ^
-DMARIADB_CLIENT_ROOT="%DOWNLOADS_DIR_LINUX%/mariadb-connector-c-v3.4.3-winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64-9.0.0-r1" ^
-B./cmake-build &&^
cd cmake-build &&^
cmake --build . &&^
echo Successful build &&^
pause