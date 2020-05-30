.text

j main #Begin with main entry point

fibonacci:
addiu $sp, $sp, -8 #Set up stack frame
sw $a0, 0($sp) #Store argument n
sw $ra, 4($sp) #Save return address

lw $t0, 0($sp) #Load n
li $t1, 0 #Load literal 0
seq $t0, $t0, $t1 #n = 0
beqz $t0, if_1 #Test condition n = 0
li $t0, 0 #Load literal 0
move $v0, $t0 #RETURN 0;
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return to caller
j if_0 #Jump to end of if statement

if_1:

lw $t0, 0($sp) #Load n
li $t1, 1 #Load literal 1
seq $t0, $t0, $t1 #n = 1
beqz $t0, if_2 #Test condition n = 1
li $t0, 1 #Load literal 1
move $v0, $t0 #RETURN 1;
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return to caller
j if_0 #Jump to end of if statement

if_2:

#Else:
lw $t0, 0($sp) #Load n
li $t1, 1 #Load literal 1
sub $t0, $t0, $t1 #n - 1
move $a0, $t0 #Hack: move to arg register
jal fibonacci #Call function
move $t0, $v0 #Load return value
lw $t1, 0($sp) #Load n
li $t2, 2 #Load literal 2
sub $t1, $t1, $t2 #n - 2
move $a0, $t1 #Hack: move to arg register
jal fibonacci #Call function
move $t1, $v0 #Load return value
add $t0, $t0, $t1 #fibonacci(n - 1) + fibonacci(n - 2)
move $v0, $t0 #RETURN fibonacci(n - 1) + fibonacci(n - 2);
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return to caller
if_0:

lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return from procedure fibonacci

main:
la $t0, string_3 #Load string "This should display the fibonacci sequence from 1-10\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("This should display the fibonacci sequence from 1-10\n");
syscall

li $t0, 1 #Load literal 1
sw $t0, 4($gp) #i := 1;

for_begin_4: #Begin for loop
lw $t0, 4($gp) #Load i
li $t1, 10 #Load literal 10
sgt $t0, $t0, $t1 #i > 10
bnez $t0, for_end_4 #Test condition i > 10

lw $t0, 4($gp) #Load i
move $a0, $t0 #Hack: move to arg register
jal fibonacci #Call function
move $t0, $v0 #Load return value
li $v0, 1 #Print integer syscall
move $a0, $t0 #WRITE(fibonacci(i), \n);
syscall

li $t0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(fibonacci(i), \n);
syscall

lw $t0, 4($gp) #Load i
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #i + 1
sw $t0, 4($gp) #i := i + 1;

j for_begin_4 #Jump to next iteration of the for loop
for_end_4: #End for loop

li $v0, 10
syscall

.data
string_3: .asciiz "This should display the fibonacci sequence from 1-10\n"
