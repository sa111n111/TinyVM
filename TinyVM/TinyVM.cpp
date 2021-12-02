#include <iostream>
#include "Machine.h"

bool g_isRunning = true;
int  g_bytecodeProgram[] = { 0x1064, 0x11C8, 0x2201, 0x0000 };

int main()
{
	VM::Machine* vm = new VM::Machine;
	while (g_isRunning)
	{
		int instructions = vm->fetchProgram(g_bytecodeProgram);
		vm->i_decode(instructions);
		vm->prettyPrint();
		break;
	}

	vm->prettyPrint();
}
