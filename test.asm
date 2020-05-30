.text

la $s0, string_0 #Load string "Enter a number: "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Enter a number: ");
syscall

li $v0, 5 #Read integer syscall
syscall
sw $v0, 0($gp) #Store value read

la $s0, string_1 #Load string "Enter a character: "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Enter a character: ");
syscall

li $v0, 12 #Read character syscall
syscall
sw $v0, 4($gp) #Store value read

la $s0, string_2 #Load string "You entered: "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("You entered: ", a, ", ", b);
syscall

lw $s0, 0($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("You entered: ", a, ", ", b);
syscall

la $s0, string_3 #Load string ", "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("You entered: ", a, ", ", b);
syscall

lw $s0, 4($gp) #Load b
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE("You entered: ", a, ", ", b);
syscall

li $v0, 10
syscall

.data
string_0: .asciiz "Enter a number: "
string_1: .asciiz "Enter a character: "
string_2: .asciiz "You entered: "
string_3: .asciiz ", "
