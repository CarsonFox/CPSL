.text

li $s0, 1 #Load literal 1
addi $s1, $s0, 1 #SUCC(1)
sub $s1, $zero, $s1 #-SUCC(1)
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE(-SUCC(1));
syscall

li $v0, 10
syscall