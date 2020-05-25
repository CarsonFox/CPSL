.text

la $s0, string_0 #Load string "Hello!\n"
li $v0, 1 #Print integer syscall
move $a0, $s0 #WRITE("Hello!\n");
syscall

li $v0, 10
syscall

.data
string_0: .asciiz "Hello!\n"