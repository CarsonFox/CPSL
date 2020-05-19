.text
#la $gp, GLOBAL_AREA

# x := 3;
li $25, 3
sw $25, 0($28) # x := 3;

# write(x);
li $v0, 1 # load print integer instruction
lw $25, 0($28)
or $a0, $0, $25 # write(x)
syscall


.data

#.align 2
#GLOBAL_AREA: