.text

li $s0, 10 #Load literal 10
sw $s0, 0($gp) #i := 10;

for_begin_0: #Begin for loop
lw $s0, 0($gp) #Load i
li $s1, 1 #Load literal 1
slt $s0, $s0, $s1 #i < 1
bnez $s0, for_end_0 #Test condition i < 1

lw $s1, 0($gp) #Load i
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE(i, \n);
syscall

li $s1, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s1 #WRITE(i, \n);
syscall

lw $s1, 0($gp) #Load i
li $s2, -1 #Load literal -1
add $s1, $s1, $s2 #i + -1
sw $s1, 0($gp) #i := i + -1;

j for_begin_0 #Jump to next iteration of the for loop
for_end_0: #End for loop

li $v0, 10
syscall

.data
