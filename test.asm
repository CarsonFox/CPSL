.text

li $s0, 0 #Load literal 0
sw $s0, 0($gp) #x := 0;

repeat_0:
lw $s0, 0($gp) #Load x
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(x, \n);
syscall

li $s0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE(x, \n);
syscall

lw $s0, 0($gp) #Load x
li $s1, 1 #Load literal 1
add $s0, $s0, $s1 #x + 1
sw $s0, 0($gp) #x := x + 1;

lw $s0, 0($gp) #Load x
li $s1, 10 #Load literal 10
slt $s0, $s0, $s1 #x < 10
bnez $s0, repeat_0 #test x < 10

li $v0, 10
syscall

.data