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

li $v0, 10
syscall

.data