extern __errno_location

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

    mov rax, 1          ; 1 for using write
    movsx rbx, edi      ; copy fd to 1st syscall arg with respect of sign bit
    mov rcx, rsi        ; copy buf's ptr fto 2nd sycall arg

    syscall             ; in syscall -> b = 1st, c = 2nd, d = 3rd (3rd one already in d register)

    pop rdx             ; restore caller's register
    pop rcx             ; restore caller's register
    pop rbx             ; restore non-volitile register

    test rax, rax       ; if rax is negative, SF flag is set
    js .error           ; jump to .error if SF falg is set

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
