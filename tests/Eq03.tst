

// Run using CPUEmulator

load eq03.asm,
output-file eq03.out,
compare-to eq03.cmp,
output-list RAM[0]%D1.6.1 RAM[1]%D1.6.1 RAM[2]%D1.6.1 RAM[3]%D1.6.1 RAM[4]%D1.6.1
            RAM[256]%D1.6.1 RAM[257]%D1.6.1 RAM[258]%D1.6.1 RAM[258]%D1.6.1 RAM[259]%D1.6.1
            RAM[260]%D1.6.1 RAM[261]%D1.6.1 RAM[262]%D1.6.1 RAM[263]%D1.6.1 RAM[264]%D1.6.1
            RAM[300]%D1.6.1
            RAM[3000]%D1.6.1 RAM[3010]%D1.6.1;


set RAM[0] 256,     // stack pointer
set RAM[1] 300,     // base address of the local segment
set RAM[2] 400,     // base address of the argument segment
set RAM[3] 3000,    // base address of the this segment
set RAM[4] 3010,    // base address of the that segment

repeat 100 {        // Change this number to cover the number of instructions in the asm test file
  ticktock;
}

output;