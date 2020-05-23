.text

li $s0, 2 #Load literal 1
li $s1, 1 #Load literal 1
sle $s0, $s0, $s1 #1 <= 1
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(1 <= 1);
syscall

li $v0, 10
syscall