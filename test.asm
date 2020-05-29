.text

li $s0, 1 #Load literal 1
sw $s0, 0($gp) #a := 1;

li $s0, 98 #Load literal b
sw $s0, 4($gp) #b := b;

li $s0, 1 #Load literal 1
sw $s0, 8($gp) #c := true;

li $s0, 0 #Load literal 0
sw $s0, 12($gp) #d := false;

lw $s0, 0($gp) #Load a
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(a, b, c, d);
syscall

lw $s0, 4($gp) #Load b
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(a, b, c, d);
syscall

lw $s0, 8($gp) #Load c
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(a, b, c, d);
syscall

lw $s0, 12($gp) #Load d
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(a, b, c, d);
syscall

li $v0, 10
syscall

.data
