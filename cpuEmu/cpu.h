#pragma once
#include <stdint.h>
#include <security.h>

#define CPU_MEMORY_SIZE 0x20000

class cpu
{
public:
	cpu();
	bool clockTick();

	enum instructions {
		NOP,      // no oprand
		PCALL,    // no oprand, use ra register for code
		PRET,     // no oprand
		//RDMSR,  //
		//WRMSR,  //
		READIMM4, // arg1: Reg Index Result / arg2: Address<32>
		READIMM2, // arg1: Reg Index Result / arg2: Address<32>
		READIMM1, // arg1: Reg Index Result / arg2: Address<32>
		READPTR4, // arg1: Reg Index PTR / arg2: Reg Index Ouput
		READPTR2, // arg1: Reg Index PTR / arg2: Reg Index Ouput
		READPTR1, // arg1: Reg Index PTR / arg2: Reg Index Ouput
		WRITEIMM4,// arg1: Reg Index Value / arg2: Address<32>
		WRITEIMM2,// arg1: Reg Index Value / arg2: Address<32>
		WRITEIMM1,// arg1: Reg Index Value / arg2: Address<32>
		WRITEPTR4,// arg1: Reg Index PTR / arg2: Reg Index Value
		WRITEPTR2,// arg1: Reg Index PTR / arg2: Reg Index Value
		WRITEPTR1,// arg1: Reg Index PTR / arg2: Reg Index Value
		ADD,	  // arg1: Reg Index Result / Reg Index Oprand A / Reg Index Oprand B
		ADDI,	  // arg1: Reg Index Result / Reg Index Oprand A / Reg Index Oprand B
		MUL,	  // arg1: Reg Index Result / Reg Index Oprand A / Reg Index Oprand B
		MOV,	  // arg1: Reg Index Result / arg2: Value<32>
		CMP,	
		JMP,	  // arg1: Reg Index Value
		JMPIMM,	  // arg1: Value<32>
		JMPCMP,   // 
		JMPREL,   // arg1: Reg Index Value<signed>
		JMPRELCMP,// 
		OUT,      // 
		IN,       // 
		HALT,     // no oprand
	};

private:
	uint32_t RA; // General Purpose Register
	uint32_t RB; // General Purpose Register
	uint32_t RC; // General Purpose Register
	uint32_t RD; // General Purpose Register
	uint32_t PC; // Program Counter
	uint32_t SP; // Stack pointer
	uint32_t BP; // Stack Base

	char rf; //flag register
	char* memoryArray;
};

