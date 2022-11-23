
@ECHO OFF

del dist\*.o
del dist\main.gba
del dist\main.sav

for %%f in (src\prototypes\*.c) do (
    gcc -c -O3 src\prototypes\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\*.c) do (
    gcc -c -O3 src\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

gcc -o dist\main.elf dist\tmp\*.o -Wall -lm

if "%errorlevel%"=="1" pause
if "%errorlevel%"=="0" objcopy -O binary dist\main.elf dist\main.gba

dist\main.gba