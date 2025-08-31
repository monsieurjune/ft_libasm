section .text

global ft_strcpy

; function: extern char *ft_strcpy(char* s1, const char* s2);
; parameter:
;   rdi = char* s1
;   rsi = const char* s2

ft_strcpy:
    mov r8, rdi     ; copy s1 to s1-tmp

    .loop_start:
        mov byte r9b, [rsi]     ; copy *s2 to tmp
        mov byte [r8], r9b      ; copy tmp to *s1-tmp
        cmp byte [rsi], 0       ; compare *s2 to 0
        je .loop_end            ; jump to .loop_end if *s2 == 0
        inc r8                  ; s1-tmp++
        inc rsi                 ; s2++
        jmp .loop_start

    .loop_end:
        mov rax, rdi            ; return s1's ptr
        ret
