; hello_world.asm
;
; Author: Jared Pangallozzi

section .text:


section .data:
    message: db "Hello world!", 0xA ; This line allocates exactly one byte for the text "Hello world!", with a newline character after
    message_length equ $-message