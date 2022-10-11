#include <stdint.h>
#include <stddef.h>

#include <jit-nasm.h>

int main() {
  const char* msg = "Hello World!\n";
  char* code = 
    "mov rdx, rsi\n"
    "mov rsi, rdi\n"
    "mov rax, 1\n"
    "mov rdi, 1\n"
    "syscall\n"
    "xor rax, rax\n"
    "ret\n";

  jit_nasm_t jnasm = jit_nasm_create_instance(NULL, 0);
  jit_nasm_assemble(jnasm, code, 0, NULL);

  void (*hello_world)(char*, int) = jit_nasm_get_code(jnasm);
  
  hello_world(msg, 13);

  jit_nasm_destroy_instance(jnasm);
}