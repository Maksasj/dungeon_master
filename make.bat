
@ECHO OFF

del dist\tmp\*.o
del dist\main.gba
del dist\main.sav

for %%f in (src\entity\*.c) do (
    gcc -c -w -O3 src\entity\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\utils\*.c) do (
    gcc -c -w -O3 src\utils\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\sound\*.c) do (
    gcc -c -w -O3 src\sound\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\entity\prototypes\*.c) do (
    gcc -c -w -O3 src\entity\prototypes\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\world\*.c) do (
    gcc -c -w -O3 src\world\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\text\*.c) do (
    gcc -c -w -O3 src\text\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

for %%f in (src\*.c) do (
    gcc -c -w -O3 src\%%~nf.c -o dist\tmp\%%~nf.o
    echo Successfully compiled: %%~nf.c
)

gcc -o dist\main.elf dist\tmp\*.o -Wall -lm

if "%errorlevel%"=="1" pause
if "%errorlevel%"=="0" objcopy -O binary dist\main.elf dist\main.gba

dist\main.gba