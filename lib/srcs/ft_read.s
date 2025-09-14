extern __errno_location

section .text

global ft_read

; extern ssize_t  ft_read(int fd, void* buff, size_t n);
; parameter:
;   di = int fd
;   si = void* buff
;   d = size_t n

ft_read:
    push rbx            ; preserve non-volatile register on stack (+8 bytes -> 8+8 bytes on stack)

    mov rax, 0          ; 0 for using reading
    movsx rbx, edi      ; copy fd to 1st syscall arg with respect of sign bit
    mov rcx, rsi        ; copy buf's ptr fto 2nd sycall arg

    syscall             ; in syscall -> b = 1st, c = 2nd, d = 3rd (3rd one already in d register)

    pop rbx             ; restore non-volitile register (-8 bytes -> 8+0 bytes on stack)

    test rax, rax       ; if rax is negative, SF flag is set
    js .error           ; jump to .error if SF flag is set
    ret

    .error:
        neg rax         ; error_value = -1 * syscall_error_ret_value
        push rax        ; preserve error_value on stack (+8 bytes -> 8+8 bytes on stack)

        ; load __errno_location()'s position from 'Global Object Table'
        ; and resolve it to RIP-relative position for PIE object to use
        mov r9, [rel __errno_location wrt ..got]
        call r9

        pop r8                  ; restore error_value to r8 (-8 bytes -> 8+0 bytes on stack)
        mov dword [rax], r8d    ; save error_value on *errno_ptr

        mov rax, -1             ; return -1
        ret
