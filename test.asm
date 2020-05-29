.text

li $s0, 2 #Load literal 2
sw $s0, 8($gp) #a := 2;

for_begin_0: #Begin for loop
lw $s0, 8($gp) #Load a
li $s1, 4 #Load literal 4
sgt $s0, $s0, $s1 #a > 4
bnez $s0, for_end_0 #Test condition a > 4

la $s1, string_1 #Load string "a is "
li $v0, 4 #Print string syscall
move $a0, $s1 #WRITE("a is ", a, \n);
syscall

lw $s1, 8($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE("a is ", a, \n);
syscall

li $s1, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s1 #WRITE("a is ", a, \n);
syscall

li $s1, 4 #Load literal 4
sw $s1, 12($gp) #b := 4;

for_begin_2: #Begin for loop
lw $s1, 12($gp) #Load b
li $s2, 2 #Load literal 2
slt $s1, $s1, $s2 #b < 2
bnez $s1, for_end_2 #Test condition b < 2

la $s2, string_3 #Load string "b is "
li $v0, 4 #Print string syscall
move $a0, $s2 #WRITE("b is ", b, \n);
syscall

lw $s2, 12($gp) #Load b
li $v0, 1 #Print integer syscall
move $a0, $s2 #WRITE("b is ", b, \n);
syscall

li $s2, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s2 #WRITE("b is ", b, \n);
syscall

lw $s2, 12($gp) #Load b
li $s3, -1 #Load literal -1
add $s2, $s2, $s3 #b + -1
sw $s2, 12($gp) #b := b + -1;

j for_begin_2 #Jump to next iteration of the for loop
for_end_2: #End for loop

lw $s2, 8($gp) #Load a
li $s3, 1 #Load literal 1
add $s2, $s2, $s3 #a + 1
sw $s2, 8($gp) #a := a + 1;

j for_begin_0 #Jump to next iteration of the for loop
for_end_0: #End for loop

li $s2, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s2 #WRITE(\n);
syscall

li $s2, 4 #Load literal 4
sw $s2, 8($gp) #a := 4;

for_begin_4: #Begin for loop
lw $s2, 8($gp) #Load a
li $s3, 2 #Load literal 2
slt $s2, $s2, $s3 #a < 2
bnez $s2, for_end_4 #Test condition a < 2

la $s3, string_5 #Load string "a is "
li $v0, 4 #Print string syscall
move $a0, $s3 #WRITE("a is ", a, \n);
syscall

lw $s3, 8($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s3 #WRITE("a is ", a, \n);
syscall

li $s3, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s3 #WRITE("a is ", a, \n);
syscall

li $s3, 2 #Load literal 2
sw $s3, 12($gp) #b := 2;

for_begin_6: #Begin for loop
lw $s3, 12($gp) #Load b
li $s4, 4 #Load literal 4
sgt $s3, $s3, $s4 #b > 4
bnez $s3, for_end_6 #Test condition b > 4

la $s4, string_7 #Load string "b is "
li $v0, 4 #Print string syscall
move $a0, $s4 #WRITE("b is ", b, \n);
syscall

lw $s4, 12($gp) #Load b
li $v0, 1 #Print integer syscall
move $a0, $s4 #WRITE("b is ", b, \n);
syscall

li $s4, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s4 #WRITE("b is ", b, \n);
syscall

lw $s4, 12($gp) #Load b
li $s5, 1 #Load literal 1
add $s4, $s4, $s5 #b + 1
sw $s4, 12($gp) #b := b + 1;

j for_begin_6 #Jump to next iteration of the for loop
for_end_6: #End for loop

lw $s4, 8($gp) #Load a
li $s5, -1 #Load literal -1
add $s4, $s4, $s5 #a + -1
sw $s4, 8($gp) #a := a + -1;

j for_begin_4 #Jump to next iteration of the for loop
for_end_4: #End for loop

li $v0, 10
syscall

.data
string_1: .asciiz "a is "
string_3: .asciiz "b is "
string_5: .asciiz "a is "
string_7: .asciiz "b is "
