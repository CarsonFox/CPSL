.text

j main #Begin with main entry point

init_board:
addiu $sp, $sp, -92 #Set up stack frame
sw $ra, 0($sp) #Save return address

li $t0, 0 #Load literal 0
sw $t0, 8($sp) #i := 0;

for_begin_0: #Begin for loop
lw $t0, 8($sp) #Load i
li $t1, 23 #Load literal 23
sgt $t0, $t0, $t1 #i > 23
bnez $t0, for_end_0 #Test condition i > 23

lw $t0, 8($sp) #Load i
li $t1, 8 #Load literal 8
div $t0, $t1 #i % 8
mfhi $t0 #i % 8
lw $t1, 8($sp) #Load i
li $t2, 2 #Load literal 2
div $t1, $t2 #i % 2
mfhi $t1 #i % 2
add $t0, $t0, $t1 #(i % 8) + (i % 2)
li $t1, 0 #Load literal 0
seq $t0, $t0, $t1 #((i % 8) + (i % 2)) = 0
beqz $t0, if_2 #Test condition ((i % 8) + (i % 2)) = 0
li $t0, 120 #Load literal x
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 8($sp) #Load i
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[i]
sw $t0, ($t1) # game_board[i] := x;

j if_1 #Jump to end of if statement

if_2:

#Else:
li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 8($sp) #Load i
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[i]
sw $t0, ($t1) # game_board[i] :=  ;

if_1:

lw $t0, 8($sp) #Load i
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #i + 1
sw $t0, 8($sp) #i := i + 1;

j for_begin_0 #Jump to next iteration of the for loop
for_end_0: #End for loop

li $t0, 24 #Load literal 24
sw $t0, 20($sp) #i := 24;

for_begin_3: #Begin for loop
lw $t0, 20($sp) #Load i
li $t1, 39 #Load literal 39
sgt $t0, $t0, $t1 #i > 39
bnez $t0, for_end_3 #Test condition i > 39

li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 20($sp) #Load i
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[i]
sw $t0, ($t1) # game_board[i] :=  ;

lw $t0, 20($sp) #Load i
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #i + 1
sw $t0, 20($sp) #i := i + 1;

j for_begin_3 #Jump to next iteration of the for loop
for_end_3: #End for loop

li $t0, 40 #Load literal 40
sw $t0, 44($sp) #i := 40;

for_begin_4: #Begin for loop
lw $t0, 44($sp) #Load i
li $t1, 63 #Load literal 63
sgt $t0, $t0, $t1 #i > 63
bnez $t0, for_end_4 #Test condition i > 63

lw $t0, 44($sp) #Load i
li $t1, 8 #Load literal 8
div $t0, $t1 #i % 8
mfhi $t0 #i % 8
lw $t1, 44($sp) #Load i
li $t2, 2 #Load literal 2
div $t1, $t2 #i % 2
mfhi $t1 #i % 2
add $t0, $t0, $t1 #(i % 8) + (i % 2)
li $t1, 0 #Load literal 0
seq $t0, $t0, $t1 #((i % 8) + (i % 2)) = 0
beqz $t0, if_6 #Test condition ((i % 8) + (i % 2)) = 0
li $t0, 120 #Load literal x
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 44($sp) #Load i
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[i]
sw $t0, ($t1) # game_board[i] := x;

j if_5 #Jump to end of if statement

if_6:

#Else:
li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 44($sp) #Load i
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[i]
sw $t0, ($t1) # game_board[i] :=  ;

if_5:

lw $t0, 44($sp) #Load i
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #i + 1
sw $t0, 44($sp) #i := i + 1;

j for_begin_4 #Jump to next iteration of the for loop
for_end_4: #End for loop

li $t0, 0 #Load literal 0
sw $t0, 256($gp) #turn := 0;

lw $ra, 0($sp) #Restore return address
addiu $sp, $sp, 92 #Delete stack frame
jr $ra #Return from procedure init_board

pieces_remaining:
addiu $sp, $sp, -28 #Set up stack frame
sw $a0, 0($sp) #Store argument label
sw $ra, 4($sp) #Save return address

li $t0, 0 #Load literal 0
sw $t0, 8($sp) #remain := 0;

li $t0, 0 #Load literal 0
sw $t0, 12($sp) #i := 0;

for_begin_7: #Begin for loop
lw $t0, 12($sp) #Load i
li $t1, 63 #Load literal 63
sgt $t0, $t0, $t1 #i > 63
bnez $t0, for_end_7 #Test condition i > 63

addi $t0, $gp, 0 #Load location of game_board
lw $t1, 12($sp) #Load i
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[i]
lw $t0, ($t0) #game_board[i]
lw $t1, 0($sp) #Load label
seq $t0, $t0, $t1 #game_board[i] = label
beqz $t0, if_9 #Test condition (game_board[i] = label)
lw $t0, 8($sp) #Load remain
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #remain + 1
sw $t0, 8($sp) #remain := remain + 1;

j if_8 #Jump to end of if statement

if_9:

if_8:

lw $t0, 12($sp) #Load i
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #i + 1
sw $t0, 12($sp) #i := i + 1;

j for_begin_7 #Jump to next iteration of the for loop
for_end_7: #End for loop

lw $t0, 8($sp) #Load remain
move $v0, $t0 #RETURN remain;
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 28 #Delete stack frame
jr $ra #Return to caller
lw $ra, 4($sp) #Restore return address
addiu $sp, $sp, 28 #Delete stack frame
jr $ra #Return from procedure pieces_remaining

print_board:
addiu $sp, $sp, -20 #Set up stack frame
sw $ra, 0($sp) #Save return address

li $t0, 0 #Load literal 0
sw $t0, 4($sp) #i := 0;

li $t0, 7 #Load literal 7
sw $t0, 8($sp) #i := 7;

for_begin_10: #Begin for loop
lw $t0, 8($sp) #Load i
li $t1, 0 #Load literal 0
slt $t0, $t0, $t1 #i < 0
bnez $t0, for_end_10 #Test condition i < 0

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i]
lw $t0, ($t0) #game_board[8 * i]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 1 #Load literal 1
add $t1, $t1, $t2 #8 * i + 1
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 1]
lw $t0, ($t0) #game_board[8 * i + 1]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 2 #Load literal 2
add $t1, $t1, $t2 #8 * i + 2
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 2]
lw $t0, ($t0) #game_board[8 * i + 2]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 3 #Load literal 3
add $t1, $t1, $t2 #8 * i + 3
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 3]
lw $t0, ($t0) #game_board[8 * i + 3]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 4 #Load literal 4
add $t1, $t1, $t2 #8 * i + 4
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 4]
lw $t0, ($t0) #game_board[8 * i + 4]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 5 #Load literal 5
add $t1, $t1, $t2 #8 * i + 5
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 5]
lw $t0, ($t0) #game_board[8 * i + 5]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 6 #Load literal 6
add $t1, $t1, $t2 #8 * i + 6
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 6]
lw $t0, ($t0) #game_board[8 * i + 6]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

addi $t0, $gp, 0 #Load location of game_board
li $t1, 8 #Load literal 8
lw $t2, 8($sp) #Load i
mul $t1, $t1, $t2 #8 * i
li $t2, 7 #Load literal 7
add $t1, $t1, $t2 #8 * i + 7
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[8 * i + 7]
lw $t0, ($t0) #game_board[8 * i + 7]
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

li $t0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(game_board[8 * i], game_board[8 * i + 1], game_board[8 * i + 2], game_board[8 * i + 3], game_board[8 * i + 4], game_board[8 * i + 5], game_board[8 * i + 6], game_board[8 * i + 7], \n);
syscall

lw $t0, 8($sp) #Load i
li $t1, -1 #Load literal -1
add $t0, $t0, $t1 #i + -1
sw $t0, 8($sp) #i := i + -1;

j for_begin_10 #Jump to next iteration of the for loop
for_end_10: #End for loop

lw $ra, 0($sp) #Restore return address
addiu $sp, $sp, 20 #Delete stack frame
jr $ra #Return from procedure print_board

move_cell:
addiu $sp, $sp, -20 #Set up stack frame
sw $a0, 0($sp) #Store argument cell
sw $a0, 4($sp) #Store argument dir
sw $ra, 8($sp) #Save return address

lw $t0, 0($sp) #Load cell
sw $t0, 12($sp) #new := cell;

li $t0, 0 #Load literal 0
sw $t0, 16($sp) #adj := 0;

lw $t0, 4($sp) #Load dir
li $t1, 0 #Load literal 0
seq $t0, $t0, $t1 #dir = 0
beqz $t0, if_12 #Test condition dir = 0
li $t0, 7 #Load literal 7
neg $t0, $t0 #-7
sw $t0, 16($sp) #adj := -7;

j if_11 #Jump to end of if statement

if_12:

lw $t0, 4($sp) #Load dir
li $t1, 1 #Load literal 1
seq $t0, $t0, $t1 #dir = 1
beqz $t0, if_13 #Test condition dir = 1
li $t0, 9 #Load literal 9
sw $t0, 16($sp) #adj := 9;

j if_11 #Jump to end of if statement

if_13:

lw $t0, 4($sp) #Load dir
li $t1, 2 #Load literal 2
seq $t0, $t0, $t1 #dir = 2
beqz $t0, if_14 #Test condition dir = 2
li $t0, 7 #Load literal 7
sw $t0, 16($sp) #adj := 7;

j if_11 #Jump to end of if statement

if_14:

lw $t0, 4($sp) #Load dir
li $t1, 3 #Load literal 3
seq $t0, $t0, $t1 #dir = 3
beqz $t0, if_15 #Test condition dir = 3
li $t0, 9 #Load literal 9
neg $t0, $t0 #-9
sw $t0, 16($sp) #adj := -9;

j if_11 #Jump to end of if statement

if_15:

if_11:

lw $t0, 12($sp) #Load new
lw $t1, 16($sp) #Load adj
add $t0, $t0, $t1 #new + adj
sw $t0, 12($sp) #new := new + adj;

addi $t0, $gp, 0 #Load location of game_board
lw $t1, 12($sp) #Load new
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[new]
lw $t0, ($t0) #game_board[new]
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 0($sp) #Load cell
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[cell]
lw $t1, ($t1) #game_board[cell]
seq $t0, $t0, $t1 #game_board[new] = game_board[cell]
beqz $t0, if_17 #Test condition game_board[new] = game_board[cell]
li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 12($sp) #new := -1;

j if_16 #Jump to end of if statement

if_17:

addi $t0, $gp, 0 #Load location of game_board
lw $t1, 12($sp) #Load new
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[new]
lw $t0, ($t0) #game_board[new]
li $t1, 32 #Load literal  
sne $t0, $t0, $t1 #game_board[new] <>  
beqz $t0, if_18 #Test condition game_board[new] <>  
lw $t0, 12($sp) #Load new
lw $t1, 16($sp) #Load adj
add $t0, $t0, $t1 #new + adj
sw $t0, 12($sp) #new := new + adj;

addi $t0, $gp, 0 #Load location of game_board
lw $t1, 12($sp) #Load new
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[new]
lw $t0, ($t0) #game_board[new]
li $t1, 32 #Load literal  
sne $t0, $t0, $t1 #game_board[new] <>  
beqz $t0, if_20 #Test condition game_board[new] <>  
li $t0, 2 #Load literal 2
neg $t0, $t0 #-2
sw $t0, 12($sp) #new := -2;

j if_19 #Jump to end of if statement

if_20:

if_19:

j if_16 #Jump to end of if statement

if_18:

if_16:

lw $t0, 12($sp) #Load new
move $v0, $t0 #RETURN new;
lw $ra, 8($sp) #Restore return address
addiu $sp, $sp, 20 #Delete stack frame
jr $ra #Return to caller
lw $ra, 8($sp) #Restore return address
addiu $sp, $sp, 20 #Delete stack frame
jr $ra #Return from procedure move_cell

player_move:
addiu $sp, $sp, -16 #Set up stack frame
sw $ra, 0($sp) #Save return address

li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 4($sp) #cell := -1;

li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 8($sp) #dir := -1;

li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 12($sp) #new := -1;

while_begin_21:
lw $t0, 4($sp) #Load cell
li $t1, 1 #Load literal 1
neg $t1, $t1 #-1
sgt $t0, $t0, $t1 #cell > -1
lw $t1, 4($sp) #Load cell
li $t2, 64 #Load literal 64
slt $t1, $t1, $t2 #cell < 64
and $t0, $t0, $t1 #(cell > -1) & (cell < 64)
lw $t1, 12($sp) #Load new
li $t2, 0 #Load literal 0
slt $t1, $t1, $t2 #new < 0
and $t0, $t0, $t1 #(cell > -1) & (cell < 64) & (new < 0)
seq $t0, $t0, $zero #~((cell > -1) & (cell < 64) & (new < 0))
beqz $t0, while_end_21 #test ~((cell > -1) & (cell < 64) & (new < 0))

la $t0, string_22 #Load string "\nEnter the number of a square with an x: "
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nEnter the number of a square with an x: ");
syscall

li $v0, 5 #Read integer syscall
syscall
sw $v0, 4($sp) #Store value read

li $t0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(\n);
syscall

la $t0, string_23 #Load string "\n3 0\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\n3 0\n");
syscall

la $t0, string_24 #Load string " x \n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE(" x \n");
syscall

la $t0, string_25 #Load string "2 1\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("2 1\n");
syscall

la $t0, string_26 #Load string "\nPick a direction: \n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nPick a direction: \n");
syscall

li $v0, 5 #Read integer syscall
syscall
sw $v0, 8($sp) #Store value read

li $t0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(\n);
syscall

lw $t0, 4($sp) #Load cell
move $a0, $t0 #Hack: move to arg register
lw $t0, 8($sp) #Load dir
move $a0, $t0 #Hack: move to arg register
jal move_cell #Call function
move $t0, $v0 #Load return value
sw $t0, 12($sp) #new := move_cell(cell, dir);

j while_begin_21 #Next while iteration
while_end_21:

li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 4($sp) #Load cell
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[cell]
sw $t0, ($t1) # game_board[cell] :=  ;

li $t0, 120 #Load literal x
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 12($sp) #Load new
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[new]
sw $t0, ($t1) # game_board[new] := x;

lw $t0, 12($sp) #Load new
lw $t1, 4($sp) #Load cell
sub $t0, $t0, $t1 #new - cell
li $t1, 9 #Load literal 9
sgt $t0, $t0, $t1 #(new - cell) > 9
beqz $t0, if_28 #Test condition (new - cell) > 9
li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 4($sp) #Load cell
lw $t3, 12($sp) #Load new
lw $t4, 4($sp) #Load cell
sub $t3, $t3, $t4 #new - cell
li $t4, 2 #Load literal 2
div $t3, $t4 #(new - cell) / 2
mflo $t3 #(new - cell) / 2
add $t2, $t2, $t3 #cell + ((new - cell) / 2)
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[cell + ((new - cell) / 2)]
sw $t0, ($t1) # game_board[cell + ((new - cell) / 2)] :=  ;

j if_27 #Jump to end of if statement

if_28:

if_27:

lw $ra, 0($sp) #Restore return address
addiu $sp, $sp, 16 #Delete stack frame
jr $ra #Return from procedure player_move

player_o_move:
addiu $sp, $sp, -16 #Set up stack frame
sw $ra, 0($sp) #Save return address

li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 4($sp) #cell := -1;

li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 8($sp) #dir := -1;

li $t0, 1 #Load literal 1
neg $t0, $t0 #-1
sw $t0, 12($sp) #new := -1;

while_begin_29:
lw $t0, 4($sp) #Load cell
li $t1, 1 #Load literal 1
neg $t1, $t1 #-1
sgt $t0, $t0, $t1 #cell > -1
lw $t1, 4($sp) #Load cell
li $t2, 64 #Load literal 64
slt $t1, $t1, $t2 #cell < 64
and $t0, $t0, $t1 #(cell > -1) & (cell < 64)
lw $t1, 12($sp) #Load new
li $t2, 0 #Load literal 0
slt $t1, $t1, $t2 #new < 0
and $t0, $t0, $t1 #(cell > -1) & (cell < 64) & (new < 0)
seq $t0, $t0, $zero #~((cell > -1) & (cell < 64) & (new < 0))
beqz $t0, while_end_29 #test ~((cell > -1) & (cell < 64) & (new < 0))

la $t0, string_30 #Load string "\nEnter the number of a square with an o: "
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nEnter the number of a square with an o: ");
syscall

li $v0, 5 #Read integer syscall
syscall
sw $v0, 4($sp) #Store value read

li $t0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(\n);
syscall

la $t0, string_31 #Load string "\n3 0\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\n3 0\n");
syscall

la $t0, string_32 #Load string " x \n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE(" x \n");
syscall

la $t0, string_33 #Load string "2 1\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("2 1\n");
syscall

la $t0, string_34 #Load string "\nPick a direction: \n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nPick a direction: \n");
syscall

li $v0, 5 #Read integer syscall
syscall
sw $v0, 8($sp) #Store value read

li $t0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $t0 #WRITE(\n);
syscall

lw $t0, 4($sp) #Load cell
move $a0, $t0 #Hack: move to arg register
lw $t0, 8($sp) #Load dir
move $a0, $t0 #Hack: move to arg register
jal move_cell #Call function
move $t0, $v0 #Load return value
sw $t0, 12($sp) #new := move_cell(cell, dir);

j while_begin_29 #Next while iteration
while_end_29:

li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 4($sp) #Load cell
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[cell]
sw $t0, ($t1) # game_board[cell] :=  ;

li $t0, 111 #Load literal o
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 12($sp) #Load new
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[new]
sw $t0, ($t1) # game_board[new] := o;

lw $t0, 12($sp) #Load new
lw $t1, 4($sp) #Load cell
sub $t0, $t0, $t1 #new - cell
li $t1, 9 #Load literal 9
sgt $t0, $t0, $t1 #(new - cell) > 9
beqz $t0, if_36 #Test condition (new - cell) > 9
li $t0, 32 #Load literal  
addi $t1, $gp, 0 #Load location of game_board
lw $t2, 4($sp) #Load cell
lw $t3, 12($sp) #Load new
lw $t4, 4($sp) #Load cell
sub $t3, $t3, $t4 #new - cell
li $t4, 2 #Load literal 2
div $t3, $t4 #(new - cell) / 2
mflo $t3 #(new - cell) / 2
add $t2, $t2, $t3 #cell + ((new - cell) / 2)
li $t3, 4 #Get array element size
mul $t2, $t2, $t3 #Compute offset
add $t1, $t1, $t2 #Compute array access for game_board[cell + ((new - cell) / 2)]
sw $t0, ($t1) # game_board[cell + ((new - cell) / 2)] :=  ;

j if_35 #Jump to end of if statement

if_36:

if_35:

lw $ra, 0($sp) #Restore return address
addiu $sp, $sp, 16 #Delete stack frame
jr $ra #Return from procedure player_o_move

ai_move:
addiu $sp, $sp, -36 #Set up stack frame
sw $ra, 0($sp) #Save return address

li $t0, 0 #Load literal 0
sw $t0, 16($sp) #i := 0;

for_begin_37: #Begin for loop
lw $t0, 16($sp) #Load i
li $t1, 63 #Load literal 63
sgt $t0, $t0, $t1 #i > 63
bnez $t0, for_end_37 #Test condition i > 63

addi $t0, $gp, 0 #Load location of game_board
lw $t1, 16($sp) #Load i
li $t2, 4 #Get array element size
mul $t1, $t1, $t2 #Compute offset
add $t0, $t0, $t1 #Compute array access for game_board[i]
lw $t0, ($t0) #game_board[i]
li $t1, 111 #Load literal o
seq $t0, $t0, $t1 #game_board[i] = o
beqz $t0, if_39 #Test condition game_board[i] = o
lw $t0, 16($sp) #Load i
sw $t0, 8($sp) #cell := i;

j if_38 #Jump to end of if statement

if_39:

if_38:

lw $t0, 16($sp) #Load i
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #i + 1
sw $t0, 16($sp) #i := i + 1;

j for_begin_37 #Jump to next iteration of the for loop
for_end_37: #End for loop

li $t0, 0 #Load literal 0
sw $t0, 12($sp) #dir := 0;

lw $ra, 0($sp) #Restore return address
addiu $sp, $sp, 36 #Delete stack frame
jr $ra #Return from procedure ai_move

main:
jal init_board #Call procedure
while_begin_40:
li $t0, 120 #Load literal x
move $a0, $t0 #Hack: move to arg register
jal pieces_remaining #Call function
move $t0, $v0 #Load return value
li $t1, 0 #Load literal 0
sgt $t0, $t0, $t1 #pieces_remaining(x) > 0
li $t1, 111 #Load literal o
move $a0, $t1 #Hack: move to arg register
jal pieces_remaining #Call function
move $t1, $v0 #Load return value
li $t2, 0 #Load literal 0
sgt $t1, $t1, $t2 #pieces_remaining(o) > 0
and $t0, $t0, $t1 #(pieces_remaining(x) > 0) & (pieces_remaining(o) > 0)
beqz $t0, while_end_40 #test (pieces_remaining(x) > 0) & (pieces_remaining(o) > 0)

jal print_board #Call procedure
lw $t0, 256($gp) #Load turn
li $t1, 0 #Load literal 0
seq $t0, $t0, $t1 #turn = 0
beqz $t0, if_42 #Test condition (turn = 0)
jal player_move #Call procedure
j if_41 #Jump to end of if statement

if_42:

#Else:
jal player_o_move #Call procedure
if_41:

lw $t0, 256($gp) #Load turn
li $t1, 1 #Load literal 1
add $t0, $t0, $t1 #turn + 1
li $t1, 2 #Load literal 2
div $t0, $t1 #(turn + 1) % 2
mfhi $t0 #(turn + 1) % 2
sw $t0, 256($gp) #turn := (turn + 1) % 2;

j while_begin_40 #Next while iteration
while_end_40:

li $t0, 120 #Load literal x
move $a0, $t0 #Hack: move to arg register
jal pieces_remaining #Call function
move $t0, $v0 #Load return value
li $t1, 0 #Load literal 0
sgt $t0, $t0, $t1 #pieces_remaining(x) > 0
beqz $t0, if_44 #Test condition pieces_remaining(x) > 0
la $t0, string_45 #Load string "\nPlayer x Won!!!\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nPlayer x Won!!!\n");
syscall

j if_43 #Jump to end of if statement

if_44:

#Else:
la $t0, string_46 #Load string "\nPlayer o Won!!!\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nPlayer o Won!!!\n");
syscall

if_43:

la $t0, string_47 #Load string "\nGame Over.\n"
li $v0, 4 #Print string syscall
move $a0, $t0 #WRITE("\nGame Over.\n");
syscall

li $v0, 10
syscall

.data
string_22: .asciiz "\nEnter the number of a square with an x: "
string_23: .asciiz "\n3 0\n"
string_24: .asciiz " x \n"
string_25: .asciiz "2 1\n"
string_26: .asciiz "\nPick a direction: \n"
string_30: .asciiz "\nEnter the number of a square with an o: "
string_31: .asciiz "\n3 0\n"
string_32: .asciiz " x \n"
string_33: .asciiz "2 1\n"
string_34: .asciiz "\nPick a direction: \n"
string_45: .asciiz "\nPlayer x Won!!!\n"
string_46: .asciiz "\nPlayer o Won!!!\n"
string_47: .asciiz "\nGame Over.\n"
