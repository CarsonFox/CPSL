.text

j main #Begin with main entry point

functionOne:
addiu $sp, $sp, -8 #Set up stack frame
sw $s0, 0($sp) #Store argument a
sw $ra, 4($sp) #Save return address

la $s0, string_0 #Load string "Function One Recieved:"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Function One Recieved:", a, ". \nCalling Function Two From Function One With ", a + 5, "\n");
syscall

lw $s0, 0($sp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Function One Recieved:", a, ". \nCalling Function Two From Function One With ", a + 5, "\n");
syscall

la $s0, string_1 #Load string ". \nCalling Function Two From Function One With "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Function One Recieved:", a, ". \nCalling Function Two From Function One With ", a + 5, "\n");
syscall

lw $s0, 0($sp) #Load a
li $s1, 5 #Load literal 5
add $s0, $s0, $s1 #a + 5
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Function One Recieved:", a, ". \nCalling Function Two From Function One With ", a + 5, "\n");
syscall

la $s0, string_2 #Load string "\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Function One Recieved:", a, ". \nCalling Function Two From Function One With ", a + 5, "\n");
syscall

lw $s0, 0($sp) #Load a
li $s1, 5 #Load literal 5
add $s0, $s0, $s1 #a + 5
jal functionTwo #Call function
move $s0, $v0 #Load return value
move $v0, $s0 #RETURN functionTwo(a + 5);
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return to caller
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return from procedure functionOne

functionTwo:
addiu $sp, $sp, -8 #Set up stack frame
sw $s0, 0($sp) #Store argument a
sw $ra, 4($sp) #Save return address

la $s0, string_3 #Load string "Function Two Recieved:"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Function Two Recieved:", a, "\n");
syscall

lw $s0, 0($sp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Function Two Recieved:", a, "\n");
syscall

la $s0, string_4 #Load string "\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Function Two Recieved:", a, "\n");
syscall

la $s0, string_5 #Load string "Returning "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Returning ", a + 5, "\n");
syscall

lw $s0, 0($sp) #Load a
li $s1, 5 #Load literal 5
add $s0, $s0, $s1 #a + 5
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Returning ", a + 5, "\n");
syscall

la $s0, string_6 #Load string "\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Returning ", a + 5, "\n");
syscall

lw $s0, 0($sp) #Load a
li $s1, 5 #Load literal 5
add $s0, $s0, $s1 #a + 5
move $v0, $s0 #RETURN a + 5;
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return to caller
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 8 #Delete stack frame
jr $ra #Return from procedure functionTwo

main:
la $s0, string_7 #Load string "Calling Function One With 5\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Calling Function One With 5\n");
syscall

li $s0, 5 #Load literal 5
jal functionOne #Call function
move $s0, $v0 #Load return value
sw $s0, 0($gp) #a := functionOne(5);

la $s0, string_8 #Load string "Function One Returned:"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Function One Returned:", a);
syscall

lw $s0, 0($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Function One Returned:", a);
syscall

li $v0, 10
syscall

.data
string_0: .asciiz "Function One Recieved:"
string_1: .asciiz ". \nCalling Function Two From Function One With "
string_2: .asciiz "\n"
string_3: .asciiz "Function Two Recieved:"
string_4: .asciiz "\n"
string_5: .asciiz "Returning "
string_6: .asciiz "\n"
string_7: .asciiz "Calling Function One With 5\n"
string_8: .asciiz "Function One Returned:"
