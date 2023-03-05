# GUSTAVO TEIXEIRA DOS SANTOS | TIA: 32197020

.data
	Array: .space 80 # 20 Locações de inteiros
	texto1: .asciiz "Digite o "
	texto2: .asciiz "º Número: "
	texto3: .asciiz "° Valor: "
	quebra_linha: .asciiz "\n"
	texto_imprime: .asciiz "\n\n********** IMPRIMINDO ***********\n\n"

.text

	li $t0,20 #Contador do loop
	li $t1,4 #Aponta para o primeiro índice
	li $t2, 1 #Serve para o print
	
	loop1: # LOOP PARA LER OS VALORES
		beq $t0,$zero,imprime
		
		li $v0, 4 #Imprime String
		la $a0, texto1
		syscall
		
		li $v0, 1 # Imprime o número de referência
		move $a0, $t2
		syscall
		
		
		li $v0, 4 # Imprime a segunda string
		la $a0, texto2
		syscall
		
		li $v0, 5 #Ler o valor
		syscall
		
		sw $v0, Array($t1) # Carrega no array o valor digitado pelo usuário
		
		subi $t0, $t0, 1 #subtrai 1 do contador do loop
		addi $t1, $t1, 4 #Soma uma posição de inteiro para servir de referência para o índice do array
		addi, $t2, $t2, 1 # Soma 1 do número que é exibido para o usuário ter uma referência da ordem	
		
		j loop1
		
	imprime:
	li $t0,20 #Contador do loop
	li $t1,4 #Aponta para o primeiro índice
	li $t2, 1 #Serve para o print
	
	li $v0, 4 # Imprime mensagem avisando que vai começar a exibir os valores
	la $a0, texto_imprime
	syscall
		
	loop2:
		beq $t0, $zero, sair
		
		li $v0, 1 # Imprime o número usado como referência para a exibição
		move $a0, $t2
		syscall
		
		li $v0, 4 #Imprime o texto
		la $a0, texto3
		syscall
		
		li $v0, 1 # Imprime o valor em si
		lw $a0, Array($t1)
		syscall
		
		li $v0, 4 # Aplica uma quebra de linha
		la $a0, quebra_linha
		syscall
		
		subi $t0, $t0, 1
		addi $t1, $t1, 4
		addi, $t2, $t2, 1
		
		j loop2
		
	sair:
		
