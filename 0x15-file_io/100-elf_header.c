#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

int main(int argc, char *argv[]) {
if (argc != 2) {
fprintf(stderr, "Usage: elf_header elf_filename\n");
exit(1);
}

char *filename = argv[1];
int fd = open(filename, O_RDONLY);
if (fd < 0) {
perror("open");
exit(1);
}

Elf64_Ehdr elf_header;
if (memcmp(elf_header.e_ident, ELFMAG, 4) != 0) {
fprintf(stderr, "File is not an ELF file\n");
exit(98);
}
printf("ELF Header:\n");
printf("  Magic: ");
for (int i = 0; i < EI_NIDENT; i++) {
printf("%#x ", elf_header.e_ident[i]);
}
printf("\n");
printf("  Class: %d\n", elf_header.e_class);
printf("  Data: %d\n", elf_header.e_data);
printf("  Version: %d\n", elf_header.e_version);
printf("  OS/ABI: %#x\n", elf_header.e_osabi);
printf("  ABI Version: %d\n", elf_header.e_abiversion);
printf("  Type: %d\n", elf_header.e_type);
printf("  Entry point address: %#x\n", elf_header.e_entry);

close(fd);
return 0;
}
