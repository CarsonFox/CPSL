.text

li $s0, 2 #Load literal 2
sw $s0, 4($gp) #a_ := 2;

for_begin_0: #Begin for loop
lw $s0, 4($gp) #Load a_
li $s1, 4 #Load literal 4
sgt $s0, $s0, $s1 #a_ > 4
bnez $s0, for_end_0 #Test condition a_ > 4

la $s1, string_1 #Load string "a is "
li $v0, 4 #Print string syscall
move $a0, $s1 #WRITE("a is ", a, \n);
syscall

lw $s1, 0($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE("a is ", a, \n);
syscall

li $s1, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s1 #WRITE("a is ", a, \n);
syscall

lw $s1, 4($gp) #Load a_
li $s2, 1 #Load literal 1
add $s1, $s1, $s2 #a_ + 1
sw $s1, 4($gp) #a_ := a_ + 1;

j for_begin_0 #Jump to next iteration of the for loop
for_end_0: #End for loop

li $s1, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s1 #WRITE(\n);
syscall

li $s1, 4 #Load literal 4
sw $s1, 8($gp) #a__ := 4;

for_begin_2: #Begin for loop
lw $s1, 8($gp) #Load a__
li $s2, 2 #Load literal 2
slt $s1, $s1, $s2 #a__ < 2
bnez $s1, for_end_2 #Test condition a__ < 2

la $s2, string_3 #Load string "a is "
li $v0, 4 #Print string syscall
move $a0, $s2 #WRITE("a is ", a, \n);
syscall

lw $s2, 0($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s2 #WRITE("a is ", a, \n);
syscall

li $s2, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s2 #WRITE("a is ", a, \n);
syscall

lw $s2, 8($gp) #Load a__
li $s3, -1 #Load literal -1
add $s2, $s2, $s3 #a__ + -1
sw $s2, 8($gp) #a__ := a__ + -1;

j for_begin_2 #Jump to next iteration of the for loop
for_end_2: #End for loop

li $v0, 10
syscall

.data
string_1: .asciiz "a is "
string_3: .asciiz "a is "
