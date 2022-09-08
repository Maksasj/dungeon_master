
@ECHO OFF

gcc -c -O3 src\main.c -o dist\main.o
gcc -o dist\main.elf dist\main.o -lm

if "%errorlevel%"=="1" pause
if "%errorlevel%"=="0" objcopy -O binary dist\main.elf dist\main.gba