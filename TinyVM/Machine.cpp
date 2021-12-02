#include "Machine.h"

void VM::Machine::i_decode(int instruction) 
{
	instrNum = (instruction & 0xf000) >> 12;
	register1 = (instruction & 0xf00) >> 8;
	register2 = (instruction & 0xf0) >> 4;
	register3 = (instruction & 0xff);
	imm_instruct = (instruction & 0xff);
}

void VM::Machine::stopVm()
{
	std::cout << "stopping TinyVM...\n";
	this->is_running = false;
	delete[] registers;
}

int VM::Machine::fetchProgram(int bytecodeProgram[])
{
	return bytecodeProgram[program_cnt++];
}

void VM::Machine::prettyPrint() 
{
	int counter = 0;

	for (counter = 0; counter < 5; counter++)
	{
		std::cout << registers[counter] << "\n";
	}
}

void VM::Machine::setRunning()
{
	this->is_running = true;
}

void VM::Machine::parseInstruction()
{
	switch (instrNum)
	{
	case 0:
		stopVm();

	case 1:
		registers[register1] = imm_instruct;

	case 2:
		registers[register1] = registers[register2] + registers[register3];
	}
}