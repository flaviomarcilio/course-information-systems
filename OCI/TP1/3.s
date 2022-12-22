# Implementação do bubble sort
main:
    addi sp, sp, -36
    li x10, 27
    sw x10, 0(sp)
    li x10, 16
    sw x10, 4(sp)
    li x10, 20
    sw x10, 8(sp)
    li x10, 49
    sw x10, 12(sp)
    li x10, 39
    sw x10, 16(sp)
    li x10, 48
    sw x10, 20(sp)
    li x10, 38
    sw x10, 24(sp)
    li x10, 7
    sw x10, 28(sp)
    li x10, 5
    sw x10, 32(sp)
    li x10, 19
    sw x10, 36(sp)
    li x11, 10
    mv x10, sp
    jal x1, bubble-sort
    beq x0, x0, Exit
bubble-sort:
    li x8, 0           # i = 0
for1:
    bge x8, x11, exit1 # Vai para exit1 se x8 >= x11 (i >= n)
    li x9, 0           # j = 0
    sub x12, x11, x8   # x12 = n - i
    addi x12, x12, -1  # x12 = n - i - 1
for2:
    bge x9, x12, exit2 # vai para exit2 se x9 >= x12 (j >= n - i - 1)
    slli x5, x9, 2     # x5 = j * 4
    add x5, x10, x5    # x5 = arr + (j * 4)
    lw x6, 0(x5)       # x6 = arr[j]
    lw x7, 4(x5)       # x7 = arr[j + 1]
    ble x6, x7, exit3  # vai para exit3 se x6 <= x7 (arr[j] <= arr[j + 1])
    sw x7, 0(x5)       # arr[j] = x7
    sw x6, 4(x5)       # arr[j + 1] = x6
exit3:
    addi x9, x9, 1     # j++
    j for2             # volta para o for2
exit2:
    addi x8, x8, 1     # i++
    j for1             # volta para o for1
exit1:
    ret
Exit: