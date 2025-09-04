section .text

global ft_write

; extern ssize_t  ft_write(int fd, const void* buff, size_t n);
; parameter:
;   di = int fd
;   si = const void* buf
;   d = size_t n

ft_write:
    push rbx            ; preserve non-volatile register on stack

    push rcx            ; preserve caller's register before call function
    push rdx            ; preserve caller's register before call function

    mov eax, 0x01       ; 0x01 for using write
    mov ebx, edi        ; copy fd to 1st syscall arg
    mov ecx, esi        ; copy buf fto 2nd sycall arg

    syscall             ; in syscall -> b = 1st, c = 2nd, d = 3rd

    pop rdx             ; restore caller's register
    pop rcx             ; restore caller's register

    pop rbx             ; restore non-volitile register

    ret
