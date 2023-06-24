# My_CPU Class

The `My_CPU` class is a CPU simulator that supports various instructions and operations. It provides functionality for executing a series of instructions stored in a text file.

## Usage

To use the `My_CPU` class, follow these steps:

1. Include the `"My_CPU.h"` header file.
2. Create an instance of the `My_CPU` class.
3. Open a text file containing the instructions to be executed.
4. Call the `read()` function of the `My_CPU` instance, passing the file stream as an argument.
5. The CPU will read the instructions from the file and execute them.
6. After execution, the state of the CPU registers will be displayed.

## Instruction Set

The `My_CPU` class supports the following instructions:

- `mov(reg, operand)`: Move the value of the operand to the specified register.
- `add(reg1, reg2)`: Add the values of two registers and store the result in the first register.
- `div(reg1, reg2)`: Divide the value of the first register by the value of the second register and store the result in the first register.
- `mul(reg1, reg2)`: Multiply the values of two registers and store the result in the first register.
- `sub(reg1, reg2)`: Subtract the value of the second register from the value of the first register and store the result in the first register.
- `cmp(reg1, reg2)`: Compare the values of two registers.
- `inc(reg)`: Increment the value of the specified register by 1.
- `dec(reg)`: Decrement the value of the specified register by 1.
- `jmp(reg)`: Jump to the instruction specified by the value in the register.
- `jle(reg1, reg2)`: Jump to the instruction specified by the value in the second register if the value in the first register is less than or equal to the value in the second register.
- `jge(reg1, reg2)`: Jump to the instruction specified by the value in the second register if the value in the first register is greater than or equal to the value in the second register.

## File Format

The input file should contain one instruction per line, with each instruction consisting of three parts: the operation, the destination register, and the operand. Each part should be separated by whitespace.

Example input file:

mov r1 10
inc r1
add r1 r2
jmp r3


## File I/O

The `read()` function reads the instructions from the input file specified by its parameter, which should be an `std::ifstream` object. If the file cannot be opened, an error message is displayed.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
