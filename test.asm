.text

li $s0, 1 #Load literal 1
sw $s0, 0($gp) #x := 1;

while_begin_0:
lw $s0, 0($gp) #Load x
li $s1, 20 #Load literal 20
slt $s0, $s0, $s1 #x < 20
beqz $s0, while_end_0 #test (x < 20)

lw $s0, 0($gp) #Load x
li $s1, 3 #Load literal 3
div $s0, $s1 #x % 3
mfhi $s0 #x % 3
li $s1, 0 #Load literal 0
seq $s0, $s0, $s1 #(x % 3) = 0
lw $s1, 0($gp) #Load x
li $s2, 5 #Load literal 5
div $s1, $s2 #x % 5
mfhi $s1 #x % 5
li $s2, 0 #Load literal 0
seq $s1, $s1, $s2 #(x % 5) = 0
and $s0, $s0, $s1 #(x % 3) = 0 & (x % 5) = 0
beqz $s0, if_2 #Test condition (x % 3) = 0 & (x % 5) = 0
la $s0, string_3 #Load string "FizzBuzz\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("FizzBuzz\n");
syscall

j if_1 #Jump to end of if statement

if_2:

lw $s0, 0($gp) #Load x
li $s1, 5 #Load literal 5
div $s0, $s1 #x % 5
mfhi $s0 #x % 5
li $s1, 0 #Load literal 0
seq $s0, $s0, $s1 #(x % 5) = 0
beqz $s0, if_4 #Test condition (x % 5) = 0
la $s0, string_5 #Load string "Buzz\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Buzz\n");
syscall

j if_1 #Jump to end of if statement

if_4:

lw $s0, 0($gp) #Load x
li $s1, 3 #Load literal 3
div $s0, $s1 #x % 3
mfhi $s0 #x % 3
li $s1, 0 #Load literal 0
seq $s0, $s0, $s1 #(x % 3) = 0
beqz $s0, if_6 #Test condition (x % 3) = 0
la $s0, string_7 #Load string "Fizz\n"
li $v0, 4 #Print string syscall
move $a0, $s0 #WRITE("Fizz\n");
syscall

j if_1 #Jump to end of if statement

if_6:

#Else:
lw $s0, 0($gp) #Load x
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE(x, \n);
syscall

li $s0, 10 #Load literal \n
li $v0, 11 #Print character syscall
move $a0, $s0 #WRITE(x, \n);
syscall

if_1:

lw $s0, 0($gp) #Load x
li $s1, 1 #Load literal 1
add $s0, $s0, $s1 #x + 1
sw $s0, 0($gp) #x := x + 1;

j while_begin_0 #Next while iteration
while_end_0:

li $v0, 10
syscall

.data
string_3: .asciiz "FizzBuzz\n"
string_5: .asciiz "Buzz\n"
string_7: .asciiz "Fizz\n"