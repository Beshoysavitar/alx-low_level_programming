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

  // Seek to the start of the ELF header
  if (lseek(fd, 0, SEEK_SET) != 0) {
    perror("lseek");
    exit(1);
  }

  // Read the ELF header
  if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
    perror("read");
    exit(1);
  }

  // Print the ELF header information
  printf("Magic: %#x\n", elf_header.e_ident[EI_MAG0]);
  printf("Class: %d\n", elf_header.e_class);
  printf("Data: %d\n", elf_header.e_data);
  printf("Version: %d\n", elf_header.e_version);
  printf("OS/ABI: %#x\n", elf_header.e_osabi);
  printf("ABI Version: %d\n", elf_header.e_abiversion);
  printf("Type: %d\n", elf_header.e_type);
  printf("Entry point address: %#x\n", elf_header.e_entry);

  close(fd);
  return 0;
}
