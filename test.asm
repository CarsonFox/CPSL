main:
	#read first number
	li $v0, 5
	syscall
	move $t1, $v0
	
	#read second number
	li $v0, 5
	syscall
	move $t2, $v0
	
	#add them
	add $t0, $t1, $t2
	
	#print the sum
	move $a0, $t0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall