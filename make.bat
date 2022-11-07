
@ECHO OFF

del dist\*.o
del dist\main.gba
del dist\main.sav

gcc -c -O3 src\main.c -o dist\main.o
gcc -c -O3 src\delay.c -o dist\delya.o
gcc -c -O3 src\sprite.c -o dist\sprite.o
gcc -c -O3 src\player.c -o dist\player.o
gcc -c -O3 src\buttons.c -o dist\buttons.o
gcc -c -O3 src\background.c -o dist\background.o
gcc -c -O3 src\vsync.c -o dist\vsync.o
gcc -o dist\main.elf dist\*.o -Wall -lm

if "%errorlevel%"=="1" pause
if "%errorlevel%"=="0" objcopy -O binary dist\main.elf dist\main.gba

dist\main.gba