# Implementação do algoritmo de Fibonnaci recursivo 
# para calcular o n-ésimo termo da sequência de Fibonacci

.data
n:	.word   7
str1:   .asciiz "fib("
str2:	.asciiz ") = "

.text
main:
        lw  x10, n              # x10 = n
        jal x1, fib             # Chama fib

        # Escreve no console
        mv  x11, x10
        lw  x10, n
        jal x1, print
fib:
        addi sp, sp, -8		# Ajusta a pilha para 2 itens
        sw   x1, 4(sp)		# Salva o endereço de retorno
        sw   x10, 0(sp)		# Salva o parâmetro n
        addi x5, x10, -2	# x5 = n - 2	
        bge  x5, x0, L1		# Se (n - 2) >= 0 pula para L1
        addi sp, sp, 8		# x10 = 1 retorna 1 e se x10 = 0 retorna 0. Portanto, só retira 2 itens da pilha
        jalr x1			# Retorna para quem chamou
L1:
        addi x10, x10, -1	# n > 1: x10 = n - 1
        jal  x1, fib		# fib(n - 1)
        addi x6, x10, 0		# Retorno de fib(n - 1) movido para x6
        lw   x10, 0(sp)		# Restauro o parâmetro n
        sw   x6, 0(sp)		# Salva fib(n - 1) na mesma posição da pilha
        addi x10, x10, -2	# x10 = n - 2
        jal  x1, fib		# fib(n - 2)
        lw   x6, 0(sp)		# Restauro o valor de fib(n - 1)
        add  x10, x10, x6	# Retorno de fib(n - 2): x10 = fib(n - 2) + fib(n - 1)
        lw   x1, 4(sp)		# Restauro o endereço de retorno
        addi sp, sp, 8		# Ajusto a pilha retirando 2 itens
        jalr x0, 0(x1)		# Retorna para quem chamou
# --- print ---
print:
        mv   x5, x10
        mv   x6, x11
        addi x10, x0, 4
        la   x11, str1
        ecall
        addi x10, x0, 1
        mv   x11, x5
        ecall
        addi x10, x0, 4
        la   x11, str2
        ecall
        addi x10, x0, 1
        mv   x11, x6
        ecall
        beq  x0, x0, Exit
Exit: