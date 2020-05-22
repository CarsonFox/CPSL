.text

li $s0, 3 #Load literal 3
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(3, \n, 4, \n, 5);
syscall

li $v0, 10
syscall