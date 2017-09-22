@echo off

IF "%~1"=="" (
    echo Plese pass in the name of the wad file you want to run!
    EXIT 1
)

REM Rename wad file to generate the symbol with the right name
ren %~n1%~x1 doom_wad

REM Generate corresponding object file to wad
CMD /c nios2-elf-objcopy --rename-section .data=.rodata,alloc,load,data,contents,readonly -I binary -O elf32-littlenios2 -B nios2 doom_wad doom_wad.o

REM Change name back
ren doom_wad %~n1%~x1

REM Create binary file that contains the wad file name
echo|set /p="%~n1%~x1" > doom_wad_name

REM Generate corresponding object file to doom_wad_name
CMD /c nios2-elf-objcopy --rename-section .data=.rodata,alloc,load,data,contents,readonly -I binary -O elf32-littlenios2 -B nios2 doom_wad_name doom_wad_name.o

REM Remove doom_wad_name
IF EXIST doom_wad_name (
    del doom_wad_name
)