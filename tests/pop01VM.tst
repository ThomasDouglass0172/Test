
// Run using VMEmulator

load pop01.vm,
output-file pop01.cmp,
output-list RAM[0]%D1.6.1 RAM[1]%D1.6.1 RAM[2]%D1.6.1 RAM[3]%D1.6.1 RAM[4]%D1.6.1
            RAM[256]%D1.6.1 RAM[257]%D1.6.1 RAM[258]%D1.6.1 RAM[259]%D1.6.1 RAM[260]%D1.6.1 RAM[261]%D1.6.1
            RAM[303]%D1.6.1
            RAM[303]%D1.6.1
            RAM[17]%D1.6.1
            RAM[3002]%D1.6.1 RAM[3011]%D1.6.1;

set sp 256,        // stack pointer
set local 300,     // base address of the local segment
set argument 400,  // base address of the argument segment
set this 3000,     // base address of the this segment
set that 3010,     // base address of the that segment

repeat 10 {        // Change this number to cover the number of instructions in the VM test file
  vmstep;
}

output;
