.text

li $s0, 3 #Load literal 3
sw $s0, 16($gp) #x := 3;

li $s0, 4 #Load literal 4
sw $s0, 20($gp) #y := 4;

la $s0, string_0 #Load string "x + y = "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("x + y = ", x + y, \n);
syscall

lw $s0, 16($gp) #Load x
lw $s1, 20($gp) #Load y
add $s0, $s0, $s1 #x + y
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("x + y = ", x + y, \n);
syscall

li $s0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE("x + y = ", x + y, \n);
syscall

li $v0, 10
syscall

.data
string_0: .asciiz "x + y = "