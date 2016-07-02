@echo off

del .\bin\RecSetup.exe

rem This file is generated by InstallShield IDE.

rem ===============================================
rem Set up tools.
rem ===============================================

set COMPILER=C:\Program Files\Common Files\InstallShield\IScript\Compile.exe
set BUILDER=C:\Program Files\InstallShield\Professional - Standard Edition\Program\isbuild.exe

rem ===============================================
rem Set the environment for the compiler
rem ===============================================

set INSTALLPROJECT=.\recsetup.ipr
set CURRENTBUILD=New CD-ROM Media

set INCLUDEIFX=C:\Program Files\InstallShield\Professional - Standard Edition\Script\Ifx\Include
set INCLUDEISRT=C:\Program Files\InstallShield\Professional - Standard Edition\Script\Isrt\Include
set INCLUDESCRIPT=E:\ccroot\guzhenhua_kdv40\kdv40_vob\60-service2\recorder\recsetup\Script Files
set LINKPATHS=-LibPath"C:\Program Files\InstallShield\Professional - Standard Edition\Script\Ifx\Lib" -LibPath"C:\Program Files\InstallShield\Professional - Standard Edition\Script\Isrt\Lib" 
set RULFILES=.\Script Files\setup.rul
set LIBRARIES="isrt.obl" "ifx.obl" 
set DEFINITIONS=
set SWITCHES=-w50 -e50 -v3 -g

rem ==================================================
rem Compile
rem ==================================================
"%COMPILER%" "%RULFILES%" -I"%INCLUDEIFX%" -I"%INCLUDEISRT%" -I"%INCLUDESCRIPT%" %LINKPATHS% %LIBRARIES% %DEFINITIONS% %SWITCHES%

if ERRORLEVEL 1 goto InstallShieldCompileError

rem ==================================================
rem build
rem ==================================================
"%BUILDER%" -p"%INSTALLPROJECT%" -m"%CURRENTBUILD%" 


copy /y .\bin\RecSetup.exe ..\..\..\10-common\version\release\win32


:InstallShieldCompileError

cd ..
