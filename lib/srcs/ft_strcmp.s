section .text

global ft_strcmp

; extern int  ft_strcmp(const char* s1, const char* s2);
; parameter:
;   rdi = const char* s1
;   rsi = const char* s2

ft_strcmp:
    mov rax, 0      ; clean the rax register

    .loop_start:
        mov byte r10b, [rdi]    ; copy *s1 to s1-tmp-0

        cmp byte r10b, [rsi]    ; compare s1-tmp-0 with *s2
        jne .loop_end           ; jump if s1-tmp-0 != *s2

        test byte r10b, [rsi]   ; if s1-tmp-0 or *s2 == 0, ZF is set
        jz .loop_both_zero      ; jump if ZF flag is set

        inc rdi                 ; s1++
        inc rsi                 ; s2++
        jmp .loop_start

    .loop_end:
        mov byte r8b, [rdi]     ; copy *s1 to s1-tmp-1
        mov byte r9b, [rsi]     ; copy *s2 to s2-tmp-0
        sub r8d, r9d            ; s1-tmp-0 - s2-tmp-1 as int, avoid OF flag set
        mov al, r8b             ; return 0th byte of result
        ret

    .loop_both_zero:
        ret
