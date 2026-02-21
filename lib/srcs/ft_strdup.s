extern malloc

extern ft_strlen
extern ft_strcpy

section .text

global ft_strdup

; extern char *ft_strdup(const char* str);
; parameter:
;   di = const char* str

ft_strdup:
    ; load malloc()'s position from 'Global Object Table'
    ; and resolve it to RIP-relative position for PIE object to use
    mov r8, [rel malloc wrt ..got]

    push rdi                ; 1: push str's ptr on stack (+8 bytes -> 8+8 bytes on stack)

    call ft_strlen          ; call ft_strlen() -> rdi = str's ptr -> return N

    mov rdi, rax            ; copy N on rdi
    add rdi, 1              ; N = N + 1
    call r8                 ; call malloc() -> rdi = N -> return heap ptr

    test rax, rax           ; if ptr = NULL, ZF flag is set
    jz .return              ; jump if ZF flag is set

    mov rdi, rax            ; copy heap ptr to rdi
    call ft_strcpy          ; call ft_strcpy -> rdi = 1st, rsi = 2nd -> return rdi value

    .return:
        pop rsi             ; 1: pop str's ptr to rsi (-8 bytes -> 8+0 bytes on stack)
        ret
