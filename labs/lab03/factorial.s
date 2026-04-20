.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    #BEGIN PROLOGUE
    addi sp, sp, -4
    sw s0, 0(sp)
    #END PROLOGUE
    addi s0, a0, 0
    addi t0, a0, 0
    addi t1, x0, 1
    #BEGIN PROLOGUE
    lw s0, 0(sp)
    addi sp, sp, 4
    #END PROLOGUE
loop:   
    beq t0, t1, exit
    addi t0, t0, -1
    mul s0, s0, t0
    jal x0 loop
exit:
    addi a0, s0, 0
    jr ra
