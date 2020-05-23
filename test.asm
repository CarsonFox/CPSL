.text

li $s0, 9 #Load literal 9
li $s1, 3 #Load literal 3
seq $s0, $s0, $s1 #9 = 3
not $s0, $s0 #~(9 = 3)
not $s0, $s0 #~~(9 = 3)
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(~~(9 = 3));
syscall

li $v0, 10
syscall