%nasm.exe -f win64 code.asm
%gcc -m64 -nostartfiles -nodefaultlibs -o code.exe code.obj

section .text
global _start	
_start:
	db 0xCA, 0xFE, 0xBA, 0xBE