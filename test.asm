.text
la $gp, GLOBAL_AREA

# x := 3;
li $25, 3
sw $25, 0($28) # x := 3;

.data

.align 2
GLOBAL_AREA:
