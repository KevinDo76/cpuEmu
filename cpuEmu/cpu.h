#pragma once
#define CPU_AVALIABLE_MEMORY 0x20000

class instructionData;

class cpu
{
public:
	cpu();
	~cpu();
	bool clockTick();
	bool loadBinaryImage(std::string);
	bool getHaltState();

	enum CMPenum {
		EQUAL = 0,
		NOT_EQUAL = 1,
		LESS_THAN = 2,
		GREATER_THAN = 3,
		LESS_THAN_OR_EQUAL = 4,
		GREATER_THAN_OR_EQUAL = 5,
	};

	enum instructions {
/*Done*/NOP        = 0x00,    // no oprand
		CALL       = 0x01,    // arg1: Address<32>, push PC to Stack
		RET        = 0x02,    // no oprand, pull PC from Stack
		POP        = 0x03,	  // arg1: Reg Index Result
		PUSH       = 0x04,	  // arg1: Reg Index Value
		//RDMSR,  //
		//WRMSR,  //
		READIMM4   = 0x05,	  // arg1: Reg Index Result / arg2: Address<32>
		READIMM2   = 0x06,    // arg1: Reg Index Result / arg2: Address<32>
		READIMM1   = 0x07,    // arg1: Reg Index Result / arg2: Address<32>
		READPTR4   = 0x08,    // arg1: Reg Index Result / arg2: Reg Index PTR 
		READPTR2   = 0x09,    // arg1: Reg Index Result / arg2: Reg Index PTR 
/*Done*/READPTR1   = 0x0a,    // arg1: Reg Index Result / arg2: Reg Index PTR 
		WRITEIMM4  = 0x0b,    // arg1: Address<32> / arg2: Reg Index Value
		WRITEIMM2  = 0x0c,	  // arg1: Address<32> / arg2: Reg Index Value
		WRITEIMM1  = 0x0d,	  // arg1: Address<32> / arg2: Reg Index Value
		WRITEPTR4  = 0x0e,	  // arg1: Reg Index PTR / arg2: Reg Index Value
		WRITEPTR2  = 0x0f,	  // arg1: Reg Index PTR / arg2: Reg Index Value
		WRITEPTR1  = 0x10,	  // arg1: Reg Index PTR / arg2: Reg Index Value
/*done*/ADD = 0x11,	  // arg1: Reg Index Result / arg2: Reg Index Oprand A / arg3: Reg Index Oprand B
		ADDI       = 0x12,	  // arg1: Reg Index Result / arg2: Reg Index Oprand A / arg3: Reg Index Oprand B
		MUL        = 0x13,	  // arg1: Reg Index Result / arg2: Reg Index Oprand A / arg3: Reg Index Oprand B
		LSHIFT	   = 0x14,    // arg1: Reg Index Result / arg2: Reg Index Oprand / arg3: Reg Index Amount
		RSHIFT     = 0x15,	  // arg1: Reg Index Result / arg2: Reg Index Oprand / arg3: Reg Index Amount
		XOR        = 0x16,    // arg1: Reg Index Result / arg2: Reg Index Oprand A / arg3: Reg Index Oprand B
		AND        = 0x17,    // arg1: Reg Index Result / arg2: Reg Index Oprand A / arg3: Reg Index Oprand B
		OR         = 0x18,    // arg1: Reg Index Result / arg2: Reg Index Oprand A / arg3: Reg Index Oprand B
/*Done*/MOV        = 0x19,	  // arg1: Reg Index Result / arg2: Value<32> 
/*Done*/CMP        = 0x1a,	  // arg1: Reg Index Result / arg2: Reg Index Value 1 / arg3: Reg Index Value 2
/*Done*/JMP        = 0x1b,	  // arg1: Reg Index Value
/*Done*/JMPIMM     = 0x1c,	  // arg1: Value<32>
/*Done*/JMPIF      = 0x1d,	  // arg1: Reg Index Check(jump if register is not zero) / arg2: Reg Index Jump Value
		JMPREL     = 0x1e,	  // arg1: Reg Index Value<signed>
		JMPRELIF   = 0x1f,	  // arg1: Reg Index Check(jump if register is not zero) / arg2: Reg Index Jump Value<signed>
/*Done*/OUT        = 0x20,    // arg1: Reg Index Value / arg2: Address<32>
		IN         = 0x21,    // arg1: Reg Index Result / arg2: Address<32>
		INT        = 0x22,	  // no oprands, take code from reg RA;
/*Done*/HALT       = 0x23,	  // no oprand
	};

	static std::string instructionEnumToName(instructions instr);

	static uint32_t flipEndian(uint32_t n);
	static uint16_t flipEndian(uint16_t n);

private:

	void cpuDebugCheck(std::string errorMessage);

	bool clockHalted;

	uint32_t readGeneralRegister(int index);
	void writeGeneralRegister(int index, uint32_t value);
	void incrementAndFetch(instructionData& instructionObj);

	void handleCMPInstruction(instructionData& instructionObj);
	void handleOutInstruction(instructionData& instructionObj);

	bool decodeAndExecute(instructionData& instructionObj);
	uint8_t readMemory8(uint32_t address);

	uint32_t RA; // General Purpose Register
	uint32_t RB; // General Purpose Register
	uint32_t RC; // General Purpose Register
	uint32_t RD; // General Purpose Register
	uint32_t PC; // Program Counter
	uint32_t SP; // Stack pointer
	uint32_t BP; // Stack Base

	uint8_t CMPREG; //ALU compare code.
	uint8_t RF; //flag register
	uint8_t* memoryArray;
};


class instructionData
{
public:
	cpu::instructions instr;
	uint32_t oprandA;
	uint32_t oprandB;
	uint32_t oprandC;

	instructionData();
	instructionData(cpu::instructions _instr, uint32_t _oprandA, uint32_t _oprandB, uint32_t _oprandC);
};
