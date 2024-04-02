section .data
section .text
bits 64
default rel		; to handle address relocation

global stencil_kernel_asm
extern printf

stencil_kernel_asm:

    ; rcx contains vectorX
    ; rdx contains vectorY
    ; r8 contains n

    ; Set r10 as n and subtract it by 6 -- number of loops to be done
    MOV r10, r8
    SUB r10, 6

    ; Set r11 as counter
    MOV r11, 0

    get_sum:
        CMP r11, r10
        JE end
        MOVSD XMM0, [rcx + r11 * 8] 		; Represents X[i - 3]
        MOVSD XMM1, [rcx + r11 * 8 + 8]		; Represents X[i - 2]
        MOVSD XMM2, [rcx + r11 * 8 + 16]	; Represents X[i - 1]
        MOVSD XMM3, [rcx + r11 * 8 + 24]	; Represents X[i]
        MOVSD XMM4, [rcx + r11 * 8 + 32]	; Represents X[i + 1]
        MOVSD XMM5, [rcx + r11 * 8 + 40]	; Represents X[i + 2]
        MOVSD XMM6, [rcx + r11 * 8 + 48]	; Represents X[i + 3]
        
        
        ADDSD XMM0, XMM1
        ADDSD XMM0, XMM2
        ADDSD XMM0, XMM3
        ADDSD XMM0, XMM4
        ADDSD XMM0, XMM5
        ADDSD XMM0, XMM6
        
        MOVSD [rdx + r11 * 8], XMM0 ; Store the sum into the Y array
        INC r11
        
        JMP get_sum

    end:
        NOP
    ret
