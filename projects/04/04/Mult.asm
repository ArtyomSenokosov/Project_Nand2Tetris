// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

@R2     // Start to final answer
M=0     // R2=0

@R1
D=M
@END
D;JEQ   // If R1=0

@R0
D=M
@END
D;JEQ   // If R0=0

(LOOP)
@R2
D=M     // Get R2

@R1
D=D+M   // Add R1 to R2

@R2
M=D     // Rewrite result in R2

@R0
D=M-1   // Reduce R0 by 1
M=D

@LOOP
D;JGT   // If R0>0

(END)
@END
0;JMP