#include <iostream>
#include "cpu.h"

int main()
{
	cpu CPU;
	CPU.loadBinaryImage("program.bin");
	CPU.clockTick();
	CPU.clockTick();
	CPU.clockTick();
	CPU.clockTick();
	CPU.clockTick();
	CPU.clockTick();
	CPU.clockTick();
	return 0;
}