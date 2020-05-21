.text

li $s0, 3 #Load literal 3
sw $s0, 0($gp) #x := 3;

li $s0, 4 #Load literal 4
sw $s0, 4($gp) #y := 4;

li $v0, 10
syscall