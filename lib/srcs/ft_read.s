extern __errno_location

section .text

global ft_read

; extern ssize_t  ft_read(int fd, void* buff, size_t n);
; parameter:
;   di = int fd
;   si = void* buff
;   d = size_t n

ft_read:
    push rbx
    push rcx
    push rdx

    mov rax, 0
    movsx rbx, edi
    mov rcx, rsi

    syscall

    pop rdx
    pop rcx
    pop rbx

    test rax, rax
    js .error

    ret

    .error:
        neg rax         ; error_value = -1 * syscall_error_ret_value 
        mov r8, rax     ; store error_value in err-tmp

        ; load __errno_location()'s position from 'Global Object Table'
        ; and resolve it to RIP-relative position for PIE object to use
        mov r9, [rel __errno_location wrt ..got]        
        call r9

        mov dword [rax], r8d    ; save error_value on *errno

        mov rax, -1     ; return -1
        ret
