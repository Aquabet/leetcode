@echo off
:loop
MakeData.exe
BigInterger.exe
baoli.exe
fc testdata.out baoli.out
if not  errorlevel 1 goto loop
pause
:end