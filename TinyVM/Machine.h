#include <iostream>

namespace VM
{
	class Machine
	{
	public:
		int registers[4];
		int program_cnt = 0;
		int instrNum = 0;
		int register1 = 0;
		int register2 = 0;
		int register3 = 0;
		int imm_instruct = 0;
		bool is_running;

		void i_decode(int instruction);

		void prettyPrint();

		void setRunning();

		void stopVm();

		void parseInstruction();

		int fetchProgram(int bytecodeProgram[]);
	};
}