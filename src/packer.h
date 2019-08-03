#ifndef _PACKER_H_
#define _PACKER_H_

#include <stdint.h>



#if UINTPTR_MAX == 0xffffffff
/* 32-bit */
#define ELF_HEADER_SIZE 52
typedef uint32_t ElfN_Addr;
typedef uint32_t ElfN_Off;

#elif UINTPTR_MAX == 0xffffffffffffffff
/* 64-bit */
#define ELF_HDR_SIZE 64
typedef uint64_t ElfN_Addr;
typedef uint64_t ElfN_Off;

#endif

#define EI_NIDENT 16
typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t      e_type;
    uint16_t      e_machine;
    uint32_t      e_version;
    ElfN_Addr     e_entry;
    ElfN_Off      e_phoff;
    ElfN_Off      e_shoff;
    uint32_t      e_flags;
    uint16_t      e_ehsize;
    uint16_t      e_phentsize;
    uint16_t      e_phnum;
    uint16_t      e_shentsize;
    uint16_t      e_shnum;
    uint16_t      e_shstrndx;
} elf_header;

#define ELF_MAG_HEADER "ELF"

#endif