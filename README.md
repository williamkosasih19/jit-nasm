# Just In Time NASM

Assemble your assemble listings and call it instantaneously within your program.

## Build

To build jit-nasm, simply run the command

`$ ./autogen.sh`

`$ ./configure`

`$ make` 

inside the code directory.

## Install Library

To install the jit-nasm library, do the following after building

`$ sudo make install PREFIX=/usr/local`

to install libjitnasm in /usr/local/lib

## Usage

To link your code with jit-nasm, use -ljitnasm
`$ gcc your_code.c -ljitnasm`

### Instantiate Library
To initialize library, first do the following
```
#include <jit-nasm.h>

jit_nasm_t jnasm = jit_nasm_create_instance(NULL, 0);   // interface: jit_nasm_create_instance(pointer to buffer, buffer size). These two parameters are used for external buffer. Default value is NULL, where jit-nasm will allocate the buffer used to assemble instructions internally.
```

### Assemble Instructions
To assemble instructions, do the following after initialization
```
jit_nasm_t jnasm = jit_nasm_create_instance(NULL, 0);
jit_nasm_assemble(jnasm, "mov rax, 0x14fff\n"
                         "mov rax, 4\n"
                         "imul rax, rax\n"
                         "idiv rdx\n", 0, NULL);   // interface: jit_nasm(jit-nasm struct pointer, code to assemble, argc, argv). argc and argv are used by nasm for more advanced control over the program. Defaults to 0 and NULL.
                         
```

### Getting Pointer to Assembled Code
After assembling your code, you can do the following to execute it.
```
jit_nasm_t jnasm = jit_nasm_create_instance(NULL, 0);
jit_nasm_assemble(jnasm, "mov rax, 0x14fff\n"
                         "mov rax, 4\n"
                         "imul rax, rax\n"
                         "idiv rdx\n"
                         "ret\n", 0, NULL);  
void (*func)() = jit_nasm_get_code(jnasm);   // Cast value to a void function pointer
func();   // Call the code.
```


Original NASM Readme Below

==============================================================================================================================

NASM, the Netwide Assembler
===========================

[![master](https://travis-ci.org/netwide-assembler/nasm.svg?branch=master)](https://travis-ci.org/netwide-assembler/nasm)

Many many developers all over the net respect NASM for what it is:
a widespread (thus netwide), portable (thus netwide!), very flexible
and mature assembler tool with support for many output formats (thus netwide!!).

Now we have good news for you: NASM is licensed under the "simplified"
[(2-clause) BSD license](https://opensource.org/licenses/BSD-2-Clause).
This means its development is open to even wider society of programmers
wishing to improve their lovely assembler.

Visit our [nasm.us](https://www.nasm.us/) website for more details.

With best regards, the NASM crew.
