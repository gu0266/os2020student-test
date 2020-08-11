// XMega65 Kernal Development Template
// Each function of the kernal is a no-args function
// The functions are placed in the SYSCALLS table surrounded by JMP and NOP
import "string"

// Use a linker definition file (put the previous listing into that file)
#pragma link("mega65hyper.ld")

// Some definitions of addresses and special values that this program uses
const char * RASTER = 0xd012;
const char *VIC_MEMORY = 0xd018;
const char *SCREEN = 0x0400;
const char *BGCOL = 0xd021;
const char *COLS = 0xd800;
const char BLACK = 0;
const char WHITE = 1;

// Some text to display
char[] MESSAGE = "checkpoint 2.3 by gu0266";

// Here are a couple sample SYSCALL handlers that just display a character on the screen
void syscall1() {
    exit_hypervisor();
}

void syscall2() {
    exit_hypervisor();
}

void syscall3() {
    exit_hypervisor();
}

void syscall4() {
    exit_hypervisor();
}

void syscall5() {
    exit_hypervisor();
}

void syscall6() {
    exit_hypervisor();
}

void syscall7() {
    exit_hypervisor();
}

void syscall8() {
    exit_hypervisor();
}

void syscall9() {
    exit_hypervisor();
}

void syscall10() {
    exit_hypervisor();
}

void syscall11() {
    exit_hypervisor();
}

void syscall12() {
    exit_hypervisor();
}

void syscall13() {
    exit_hypervisor();
}

void syscall14() {
    exit_hypervisor();
}

void syscall15() {
    exit_hypervisor();
}

void syscall16() {
    exit_hypervisor();
}

void SECURENTR() {
    exit_hypervisor();
}

void SECUREXIT() {
    exit_hypervisor();
}

void syscall19() {
    exit_hypervisor();
}

void syscall20() {
    exit_hypervisor();
}

void syscall21() {
    exit_hypervisor();
}

void syscall22() {
    exit_hypervisor();
}

void syscall23() {
    exit_hypervisor();
}

void syscall24() {
    exit_hypervisor();
}

void syscall25() {
    exit_hypervisor();
}

void syscall26() {
    exit_hypervisor();
}

void syscall27() {
    exit_hypervisor();

}

void syscall28() {
    exit_hypervisor();
}

void syscall29() {
    exit_hypervisor();
}

void syscall30() {
    exit_hypervisor();
}

void syscall31() {
    exit_hypervisor();
}

void syscall32() {
    exit_hypervisor();
}

void syscall33() {
    exit_hypervisor();
}

void syscall34() {
    exit_hypervisor();
}

void syscall35() {
    exit_hypervisor();
}

void syscall36() {
    exit_hypervisor();
}

void syscall37() {
    exit_hypervisor();
}

void syscall38() {
    exit_hypervisor();
}

void syscall39() {
    exit_hypervisor();
}

void syscall40() {
    exit_hypervisor();
}

void syscall41() {
    exit_hypervisor();
}

void syscall42() {
    exit_hypervisor();
}

void syscall43() {
    exit_hypervisor();
}

void syscall44() {
    exit_hypervisor();
}

void syscall45() {
    exit_hypervisor();
}

void syscall46() {
    exit_hypervisor();
}

void syscall47() {
    exit_hypervisor();
}

void syscall48() {
    exit_hypervisor();
}

void syscall49() {
    exit_hypervisor();
}

void syscall50() {
    exit_hypervisor();
}

void syscall51() {
    exit_hypervisor();
}

void syscall52() {
    exit_hypervisor();
}

void syscall53() {
    exit_hypervisor();
}

void syscall54() {
    exit_hypervisor();
}

void syscall55() {
    exit_hypervisor();
}

void syscall56() {
    exit_hypervisor();
}

void syscall57() {
    exit_hypervisor();
}

void syscall58() {
    exit_hypervisor();
}

void syscall59() {
    exit_hypervisor();
}

void syscall60() {
    exit_hypervisor();
}

void syscall61() {
    exit_hypervisor();
}

void syscall62() {
    exit_hypervisor();
}

void syscall63() {
    exit_hypervisor();
}

void syscall64() {
    exit_hypervisor();
}

void undefined_trap() {

}

void RESET() {
    // Initialize screen memory, and select correct font
    *VIC_MEMORY = 0x14;
    // Fill the screen with spaces
    memset(SCREEN, ' ', 40 * 25);
    // Set the colour of every character on the screen to white
    memset(COLS, WHITE, 40 * 25);
    // Print the "FAN" message
    char *sc = SCREEN + 40; // Display it one line down on the screen
    char *msg = MESSAGE;    // The messag to display
    // A simple copy routine to copy the string
    while (*msg)
    {
        *sc++ = *msg++;
    }
    // Loop forever showing two white lines as raster bars
    while (true)
    {
        if (*RASTER == 54 || *RASTER == 66)
        {
            *BGCOL = WHITE;
        }
        else
        {
            *BGCOL = BLACK;
        }
    }
}

// Now we select the SYSCALL segment to hold the SYSCALL/trap entry point table.
#pragma data_seg(Syscall)

// The structure of each entry point is JMP <handler address> + NOP.Syscall
// We have a char (xjmp) to hold the opcode for the JMP instruction,
// and then put the address of the SYSCALL/trap handler in the next
// two points as a pointer, and end with the NOP instruction opcode.
struct SysCall {
    char xjmp; // Holds $4C, the JMP $nnnn opcode
    void()* syscall; // Holds handler address, will be the target of the JMP
    char xnop; // Holds $EA, the NOP opcode
};

// To save writing 0x4C and 0xEA all the time, we define them as constants
const char JMP = 0x4c;
const char NOP = 0xea;


// Now we can have a nice table of up to 64 SYSCALL handlers expressed
// in a fairly readable and easy format.
// Each line is an instance of the struct SysCall from above, with the JMP
// opcode value, the address of the handler routine and the NOP opcode value.
export struct SysCall[] SYSCALLS ={
    { JMP, &syscall1, NOP },
    { JMP, &syscall2, NOP },
    { JMP, &syscall3, NOP },
    { JMP, &syscall4, NOP },
    { JMP, &syscall5, NOP },
    { JMP, &syscall6, NOP },
    { JMP, &syscall7, NOP },
    { JMP, &syscall8, NOP },
    { JMP, &syscall9, NOP },
    { JMP, &syscall10, NOP },
    { JMP, &syscall11, NOP },
    { JMP, &syscall12, NOP },
    { JMP, &syscall13, NOP },
    { JMP, &syscall14, NOP },
    { JMP, &syscall15, NOP },
    { JMP, &syscall16, NOP },
    { JMP, &SECURENTR, NOP },
    { JMP, &SECUREXIT, NOP },
    { JMP, &syscall19, NOP },
    { JMP, &syscall20, NOP },
    { JMP, &syscall21, NOP },
    { JMP, &syscall22, NOP },
    { JMP, &syscall23, NOP },
    { JMP, &syscall24, NOP },
    { JMP, &syscall25, NOP },
    { JMP, &syscall26, NOP },
    { JMP, &syscall27, NOP },
    { JMP, &syscall28, NOP },
    { JMP, &syscall29, NOP },
    { JMP, &syscall30, NOP },
    { JMP, &syscall31, NOP },
    { JMP, &syscall32, NOP },
    { JMP, &syscall33, NOP },
    { JMP, &syscall34, NOP },
    { JMP, &syscall35, NOP },
    { JMP, &syscall36, NOP },
    { JMP, &syscall37, NOP },
    { JMP, &syscall38, NOP },
    { JMP, &syscall39, NOP },
    { JMP, &syscall40, NOP },
    { JMP, &syscall41, NOP },
    { JMP, &syscall42, NOP },
    { JMP, &syscall43, NOP },
    { JMP, &syscall44, NOP },
    { JMP, &syscall45, NOP },
    { JMP, &syscall46, NOP },
    { JMP, &syscall47, NOP },
    { JMP, &syscall48, NOP },
    { JMP, &syscall49, NOP },
    { JMP, &syscall50, NOP },
    { JMP, &syscall51, NOP },
    { JMP, &syscall52, NOP },
    { JMP, &syscall53, NOP },
    { JMP, &syscall54, NOP },
    { JMP, &syscall55, NOP },
    { JMP, &syscall56, NOP },
    { JMP, &syscall57, NOP },
    { JMP, &syscall58, NOP },
    { JMP, &syscall59, NOP },
    { JMP, &syscall60, NOP },
    { JMP, &syscall61, NOP },
    { JMP, &syscall62, NOP },
    { JMP, &syscall63, NOP },
    { JMP, &syscall64, NOP }
};
// In this example we had only two SYSCALLs defined, so rather than having
// another 62 lines, we can just ask KickC to make the TRAP table begin
// at the next multiple of $100, i.e., at $8100.
export align(0x100) struct SysCall[] SYSCALL_RESET ={
    { JMP, &RESET, NOP },
    { JMP, &PAGFAULT, NOP },
    { JMP, &RESTORKEY, NOP },
    { JMP, &ALTTABKEY, NOP },
    { JMP, &VF011RD, NOP },
    { JMP, &VF011WR, NOP },

    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },

    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },

    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },

    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },

    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },

    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &undefined_trap, NOP },
    { JMP, &CPUKIL, NOP }
};

void exit_hypervisor() {
    // Trigger exit from Hypervisor mode
    *(unsigned char *)$D67F = $01;
}