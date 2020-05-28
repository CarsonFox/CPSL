.text

li $s0, 1 #Load literal 1
addi $s1, $gp, 0 #Load location of foo
addi $s1, $s1, 24 #Compute location of member x
sw $s0, ($s1) # foo.x := 1;

li $s0, 2 #Load literal 2
addi $s1, $gp, 0 #Load location of foo
addi $s1, $s1, 28 #Compute location of member y
sw $s0, ($s1) # foo.y := 2;

li $s0, 69 #Load literal 69
addi $s1, $gp, 0 #Load location of foo
addi $s1, $s1, 0 #Compute location of member arr
li $s2, 0 #Load literal 0
li $s3, 4 #Get array element size
mul $s2, $s2, $s3 #Compute offset
add $s1, $s1, $s2 #Compute array access for foo.arr[0]
sw $s0, ($s1) # foo.arr[0] := 69;

la $s0, string_0 #Load string "succ(1) = "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("succ(1) = ", SUCC(1), \n);
syscall

li $s0, 1 #Load literal 1
addi $s1, $s0, 1 #SUCC(1)
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE("succ(1) = ", SUCC(1), \n);
syscall

li $s0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE("succ(1) = ", SUCC(1), \n);
syscall

la $s0, string_1 #Load string "pred(2) = "
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("pred(2) = ", PRED(2), \n);
syscall

li $s0, 2 #Load literal 2
addi $s1, $s0, -1 #PRED(2)
li $v0, 1 #Print integer syscall
move $a0, $s1 #WRITE("pred(2) = ", PRED(2), \n);
syscall

li $s0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE("pred(2) = ", PRED(2), \n);
syscall

li $v0, 10
syscall

.data
string_0: .asciiz "succ(1) = "
string_1: .asciiz "pred(2) = "