/* ----------------------------------------------------------------------- *
 *
 *   Copyright 1996-2020 The NASM Authors - All Rights Reserved
 *   See the file AUTHORS included with the NASM distribution for
 *   the specific copyright holders.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------------------------------------------------------------- */

/*
 * nasm.h   main header file for the Netwide Assembler: inter-module interface
 */

#ifndef JIT_NASM_NASM_H
#define JIT_NASM_NASM_H

#ifdef __cplusplus
extern "C" {
#endif

// default length of internal buffer
#define MEM_BUFFER 6000
// actual writable buffer size = MEM_BUFFER - BUFFER_TOLERANCE
#define BUFFER_TOLERANCE 20

struct jit_nasm_s {
  uint8_t *buffer;
  int buffer_len;
  int external;
};

typedef struct jit_nasm_s* jit_nasm_t;

int jit_nasm_assemble(jit_nasm_t instance, const char* code, int argc, char **argv);

jit_nasm_t jit_nasm_create_instance(uint8_t *buffer, int len);
int jit_nasm_destroy_instance(jit_nasm_t instance);


void *jit_nasm_get_code(jit_nasm_t al);

#ifdef __cplusplus
}
#endif

#endif  /* NASM_NASM_H */
