
@ECHO OFF

if not exist dist mkdir dist
if not exist dist\tmp mkdir dist\tmp
if not exist dist\tmp\test mkdir dist\tmp\test

del dist\tmp\*.o
del dist\test.gba
del dist\test.sav

for %%f in (src\entity\*.c) do (
    gcc -c -w -O3 src\entity\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\utils\*.c) do (
    gcc -c -w -O3 src\utils\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\sound\*.c) do (
    gcc -c -w -O3 src\sound\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\entity\prototypes\*.c) do (
    gcc -c -w -O3 src\entity\prototypes\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\world\*.c) do (
    gcc -c -w -O3 src\world\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\text\*.c) do (
    gcc -c -w -O3 src\text\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\*.c) do (
    gcc -c -w -O3 src\%%~nf.c -o dist\tmp\test\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

del dist\tmp\test\main.o

gcc -c -w -O3 test\test.c -o dist\tmp\test\test.o

gcc -o dist\test.elf dist\tmp\test\*.o -Wall -lm

if "%errorlevel%"=="1" pause
if "%errorlevel%"=="0" objcopy -O binary dist\test.elf dist\test.gba

dist\test.gba