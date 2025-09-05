section .text

global ft_strcpy

; function: extern char *ft_strcpy(char* s1, const char* s2);
; parameter:
;   di = char* s1
;   si = const char* s2

ft_strcpy:
    mov rax, rdi    ; copy s1's ptr to return register

    .loop_start:
        mov byte r9b, [rsi]     ; copy *s2 to s2-tmp
        mov byte [rdi], r9b     ; copy s2-tmp to *s1

        test byte r9b, r9b      ; if s2-tmp == 0, ZF flag is set
        jz .loop_end            ; jump to .loop_end if ZF flag is set

        inc rdi                 ; s1++
        inc rsi                 ; s2++
        jmp .loop_start

    .loop_end:
        ret
