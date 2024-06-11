; hello_world.asm
;
; Author: Jared Pangallozzi

; eax, ebx, ecx, edx: All-purpose registers, 4 out of total 16
; eax has lower 16 bits, upper byte, lower byte

; You need to consider the number of bits of the area that you are writing to:
; e.g., writing a one byte var "value" (value db 5), but setting it to eax (a 4 byter register)
; will cause the program to read 4 bytes starting at the mem location of
; value, and store it in eax. This would potentially store junk values in eax

; _start is a label that tells the code where to start executing (the entry point)
; section .text is a keyword that contains all the executable code, including the entry point

; global _start lets _start be used by the linker and other files in the program
; The linker merges the object files produced by the assembler into one executable,
; resolving references to symbols shared between these files (e.g., global _start)
; _start is a convention for programmers, and you need to let the linker know that
; this is the entrypoint for the entire program when running the linker

; What is difference between db and equ?
; What do labels actually do?
global _start

section .text:

_start:
    mov eax, 0x4; Use write syscall - system understands this value as "write" op
    mov ebx, 1 ; This line and below are args for write syscall: fd, buffer, size
    mov ecx, message
    mov edx, message_length
    int 0x80 ; 0x80 is the identifier for running a syscall

    ; now gracefully exit

    mov eax, 0x1
    mov ebx, 0
    int 0x80

section .data:
    message: db "Hello world!", 0xA ; This line allocates exactly one byte for the text "Hello world!", with a newline character after
    message_length equ $-message