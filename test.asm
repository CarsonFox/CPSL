.text

li $s0, 0 #Load literal 0
sw $s0, 0($gp) #x := 0;

while_begin_0:
lw $s0, 0($gp) #Load x
li $s1, 10 #Load literal 10
slt $s0, $s0, $s1 #x < 10
beqz $s0, while_end_0 #test x < 10

lw $s1, 0($gp) #Load x
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE(x, \n);
syscall

li $s1, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s1 #WRITE(x, \n);
syscall

lw $s1, 0($gp) #Load x
li $s2, 1 #Load literal 1
add $s1, $s1, $s2 #x + 1
sw $s1, 0($gp) #x := x + 1;

j while_begin_0 #Next while iteration
while_end_0:

li $v0, 10
syscall

.data