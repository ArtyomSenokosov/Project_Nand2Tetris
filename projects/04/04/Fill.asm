// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(OutLoop)
@R0
M=-1            // set @R0=-1
    
@KBD
D=M             // load keyboard value

@Pressed
D;JNE
@R0
M=0             // no pressed

(Pressed)
@SCREEN
D=A             // load SCREEN address

@ADDRESS
M=D             // save SCREEN address and reset

(InnerLoop)
@ADDRESS
D=M

@KBD
D=A-D

@OutLoop
D;JLE           // if KBD - ADDRESS <= 0, out innerloop
@R0
D=M

@ADDRESS 
A=M
M=D             // set M[ADDRESS] = R0

@ADDRESS
M=M+1           // ADDRESS ++

@InnerLoop
0;JMP
    
@OutLoop
0;JMP