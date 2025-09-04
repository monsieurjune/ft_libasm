section .text

global ft_strcmp

; extern int  ft_strcmp(const char* s1, const char* s2);
; parameter:
;   di = const char* s1
;   si = const char* s2

ft_strcmp:
    .loop_start:
        movzx eax, byte [rdi]   ; copy *s1 to s1-tmp
        movzx r8d, byte [rsi]   ; copy *s2 to s2-tmp

        test eax, r8d           ; if s1-tmp or s2-tmp == 0, ZF is set
        jz .loop_end            ; jump to .loop_end if ZF is set

        cmp eax, r8d            ; compare s1-tmp to s2-tmp
        jne .loop_end           ; jume to .loop_end if they aren't equal

        inc rdi                 ; s1++
        inc rsi                 ; s2++
        jmp .loop_start

    .loop_end:
        sub eax, r8d            ; ret = s1-tmp - s2-tmp
        ret
