
// Run using CPUEmulator

load pop02.asm,
output-file pop02.out,
compare-to pop02.cmp,
output-list RAM[0]%D1.6.1 RAM[1]%D1.6.1 RAM[2]%D1.6.1 RAM[3]%D1.6.1 RAM[4]%D1.6.1
            RAM[256]%D1.6.1 RAM[257]%D1.6.1 RAM[258]%D1.6.1
            RAM[306]%D1.6.1
            RAM[416]%D1.6.1
            RAM[417]%D1.6.1
            RAM[418]%D1.6.1
            RAM[3000]%D1.6.1 RAM[3010]%D1.6.1;


set RAM[0] 256,     // stack pointer
set RAM[1] 300,     // base address of the local segment
set RAM[2] 400,     // base address of the argument segment
set RAM[3] 3000,    // base address of the this segment
set RAM[4] 3010,    // base address of the that segment

repeat 150 {        // Change this number to cover the number of instructions in the asm test file
  ticktock;
}

output;