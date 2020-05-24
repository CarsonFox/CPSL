.text

li $s0, 0 #Load literal 0
sw $s0, 0($gp) #x := 0;

lw $s0, 0($gp) #Load x
li $s1, 1 #Load literal 1
sle $s0, $s0, $s1 #x <= 1
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(x <= 1);
syscall

li $v0, 10
syscall