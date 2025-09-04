section .text

global ft_strlen

; function: extern size_t   ft_strlen(const char* str);
; parameter:
;   di = const char* str

ft_strlen:
    mov rax, rdi    ; copy str to str-tmp

    .loop_start:
        cmp byte [rax], 0   ; compare *str-tmp to 0
        je .loop_end        ; jump to .loop_end if *str == 0
        inc rax             ; str-tmp++
        jmp .loop_start

    .loop_end:
        sub rax, rdi        ; len = current ptr - origninal ptr
        ret
