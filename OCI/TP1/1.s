# Implementação para calcular a grandeza ausente na fórmula da Capacitância c = q/v
.data
c: .word 0  # Capacitância
q: .word 4  # Carga
v: .word 2  # Diferença de potencial

.text
main:
	lw x10, c           # x10 = c
    lw x11, q           # x11 = q
    lw x12, v           # x12 = v
    bne x10, x0, Else   # Se c != 0 vai para Else
    beq x11, x0, Zero   # Se c == 0 e q == 0 vai para Zero
    beq x12, x0, Zero   # Se c == 0 e v == 0 vai para Zero
    div x5, x11, x12    # Somente c == 0: x5 = q / v
    beq x0, x0, print   # Escreve o resultado no console
Else:
	bne x11, x0, V      # Se q != 0 vai para V
    beq x12, x0, Zero   # Se q == 0 e v == 0 vai para Zero
    mul x5, x10, x12    # Somente q == 0: x5 = c * v
    beq x0, x0, print   # Escreve o resultado no console
V:
	div x5, x11, x10    # Somente v == 0: x5 = q / c
    beq x0, x0, print   # Escreve o resultado no console
    
# --- print ---
# x5: Registrador que armazena o resultado
print:
    addi x10, x0, 1
    mv x11, x5
    ecall
    beq x0, x0, Exit
Zero:
	addi x10, x0, 1
    addi x11, x0, 0
    ecall
Exit: