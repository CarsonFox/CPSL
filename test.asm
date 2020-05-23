.text

li $s0, 5 #Load literal 5
addi $s1, $s0, 1 #SUCC(5)
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE(SUCC(5));
syscall

li $v0, 10
syscall