@0
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
@labelTrue1
D;JLT
D=0
@labelFalse1
0;JMP
(labelTrue1)
D=-1
(labelFalse1)
@SP
A=M
M=D
@SP
M=M+1

@148
D=A
@SP
A=M
M=D
@SP
M=M+1

@SP
A=M
A=A-1
M=-M

@15
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
@labelTrue2
D;JLT
D=0
@labelFalse2
0;JMP
(labelTrue2)
D=-1
(labelFalse2)
@SP
A=M
M=D
@SP
M=M+1

@10000
D=A
@SP
A=M
M=D
@SP
M=M+1

@10001
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
@labelTrue3
D;JLT
D=0
@labelFalse3
0;JMP
(labelTrue3)
D=-1
(labelFalse3)
@SP
A=M
M=D
@SP
M=M+1

@89
D=A
@SP
A=M
M=D
@SP
M=M+1

@14
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
@labelTrue4
D;JLT
D=0
@labelFalse4
0;JMP
(labelTrue4)
D=-1
(labelFalse4)
@SP
A=M
M=D
@SP
M=M+1

@0
D=A
@SP
A=M
M=D
@SP
M=M+1

@0
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
@labelTrue5
D;JLT
D=0
@labelFalse5
0;JMP
(labelTrue5)
D=-1
(labelFalse5)
@SP
A=M
M=D
@SP
M=M+1

