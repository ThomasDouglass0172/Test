@1
D=A
@SP
A=M
M=D
@SP
M=M+1

@1
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
AM=M-1
D=M
@SP
AM=M-1
D=M-D
@labelTrue
D;JEQ
D=0
@labelFalse
0;JMP
(labelTrue)
D=-1
(labelFalse)
@SP
A=M
M=D
@SP
M=M+1

