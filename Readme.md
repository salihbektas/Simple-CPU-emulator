This program is an assignment of the object-oriented programming course of the

Computer Engineering Department of the Gebze Technical University.

Using c++ 2011 standard.

Written by Salih Bektaş



This is a simple CPU emulator

This CPU has 5 registers(R1, R2,..., R5) and 50 memory areas(#1, #2, ..., #50)


Works in terminal.

The program needs a file in which the instructions are written to work.

Get file name as main argument.



Arguments:

file_name debug_mode



Debug mod:

0 = Debug mod disabled

1 = Debug mod enabled. Print data in all registers on console.

2 = Debug mod enabled. Print data in all registers and all memory areas on console.



Instructions file:

-There must be one instruction per line.

-Each line must contain a instruction.

-Parameters must be separated by spaces or commas.

-Comments can be written after a semicolon.



Instructions:

MOV [register], [number] ;Move number to register. Example: "MOV R1, 12"

MOV [register], [memory] ;Move data from register to memory. Example: "MOV R1, #5"

MOV [register>, [register] ;Move data from first register to second register. Example: "MOV R1, R2"

MOV [memory], [number] ;Move number to memory. Example: "MOV #1, 8"

MOV [memory], [register] ;Move data from memory to register. Example: "MOV #3, R2"



ADD [register], [number] ;Add number to register. Example: "ADD R2, 45"

ADD [register], [memory] ;Add data from memory to register. Example: "ADD R5, #36"

ADD [register], [register] ;Add second register to first register. Example: "ADD R2, R4"



SUB [register], [number] ;Subtraction number to register. Example: "SUB R3, 21"

SUB [register], [memory] ;Subtraction data from memory to register. Example: "SUB R4, #32"

SUB [register], [register] ;Subtraction second register from first register. Example: "SUB R4, R1"



JMP [number] ;Jump the program on number line. Example: "JMP 11"

JMP [register] [number] ;If the data which it is in the register is zero, jump the numbered line. Example; "JMP R1 6"



JPN [number] ;Jump the program on number line. Example: "JPN 1"

JPN [register] [number] ;If the data which it is in the register is under zero, jump the numbered line. Example; "JPN R2 2"



PRN [memory] ;Prints data in memory on console. Example: "PRN #25"

PRN [register] ;Prints data in register on console. Example: "PRN R3"



HLT ;Prints datas in all registers on console and terminate the program.
