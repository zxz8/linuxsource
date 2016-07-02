@echo off
rem +++++++++++++++++++++++++++++++++++++++++++++
rem              mtadp8ke
rem +++++++++++++++++++++++++++++++++++++++++++++

set Export_LintFile=export.lnt
set PclintFullName=%PCLINT_ROOT%\lint-nt.exe
set Output=mtadp8kelib_pclint.log

for %%c in (*.dsp ) do %PclintFullName% +linebuf %%c >%Export_LintFile% 

%PclintFullName% +ffn -i%PCLINT_ROOT%\ -i.\ std.lnt env-vc6.lnt %Export_LintFile% > %Output% 

FOR /F "tokens=1,2,7" %%i in  (';findstr /C:"error 900"  %Output%';) do if "%%k" == "0" (goto end)

copy /Y %Output% ..\..\..\10-common\version\pclintinfo\%Output%

:end
echo on
