.text

li $s0, 1 #Load literal 1
addi $s1, $gp, 0 #Load location of tuple
li $s2, 0 #Load literal 0
li $s3, 4 #Get array element size
mul $s2, $s2, $s3 #Compute offset
add $s1, $s1, $s2 #Compute array access for tuple[0]
sw $s0, ($s1) # tuple[0] := 1;

li $s0, 2 #Load literal 2
addi $s1, $gp, 0 #Load location of tuple
li $s2, 1 #Load literal 1
li $s3, 4 #Get array element size
mul $s2, $s2, $s3 #Compute offset
add $s1, $s1, $s2 #Compute array access for tuple[1]
sw $s0, ($s1) # tuple[1] := 2;

la $s0, string_0 #Load string "Sum: "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Sum: ", tuple[0] + tuple[1], \n);
syscall

addi $s0, $gp, 0 #Load location of tuple
li $s1, 0 #Load literal 0
li $s2, 4 #Get array element size
mul $s1, $s1, $s2 #Compute offset
add $s0, $s0, $s1 #Compute array access for tuple[0]
lw $s0, ($s0) #tuple[0]
addi $s1, $gp, 0 #Load location of tuple
li $s2, 1 #Load literal 1
li $s3, 4 #Get array element size
mul $s2, $s2, $s3 #Compute offset
add $s1, $s1, $s2 #Compute array access for tuple[1]
lw $s1, ($s1) #tuple[1]
add $s0, $s0, $s1 #tuple[0] + tuple[1]
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Sum: ", tuple[0] + tuple[1], \n);
syscall

li $s0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE("Sum: ", tuple[0] + tuple[1], \n);
syscall

li $v0, 10
syscall

.data
string_0: .asciiz "Sum: "