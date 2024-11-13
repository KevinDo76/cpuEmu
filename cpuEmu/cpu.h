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
		NOP, // no oprand
		PCALL, // no oprand, use ra register
		PRET, // no oprand
		//RDMSR, //
		//WRMSR, //
		READIMM4, // address / reg
		READIMM2, // address / reg
		READIMM1, // address / reg
		READPTR4, // ptr reg / result reg
		READPTR2, // ptr reg / result reg
		READPTR1,// ptr reg / result reg
		WRITEIMM4,
		WRITEIMM2,
		WRITEIMM1,
		WRITEPTR4,
		WRITEPTR2,
		WRITEPTR1,
		ADD,
		ADDI,
		MUL,
		MOV,
		CMP,
		JMP,
		JMPIMM,
		JMPCMP,
		JMPREL,
		JMPRELCMP,
		OUT,
		IN,
		HALT,
	};

private:
	uint32_t ra;
	uint32_t rb;
	uint32_t rc;
	uint32_t rd;
	uint32_t instructionCounter;
	char rf; //flag register
	char* memoryArray;
};

