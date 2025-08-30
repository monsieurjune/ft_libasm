section .text

global ft_strlen

; function: extern size_t   ft_strlen(const char* str);
; parameter:
;   rdi = const char* str

ft_strlen:
    mov rax, rdi    ; move str's ptr to rax

    .loop_start:
        cmp byte [rax], 0   ; compare *str to 0
        je .loop_end        ; jump to .loop_end if *str == 0
        inc rax             ; increment ptr
        jmp .loop_start     ; jump back to .loop_start

    .loop_end:
        sub rax, rdi        ; len = current ptr - origninal ptr
        ret
