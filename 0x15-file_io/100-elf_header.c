#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments vector
 *
 * Return: 0 on success, exit with code on failure
 */
int main(int argc, char *argv[])
{
    int fd;
    ssize_t n_read;
    Elf64_Ehdr ehdr;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    n_read = read(fd, &ehdr, sizeof(ehdr));
    if (n_read == -1 || n_read != sizeof(ehdr))
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
        ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
        ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
        ehdr.e_ident[EI_MAG3] != ELFMAG3)
    {
        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", ehdr.e_ident[i]);
    printf("\n");

    printf("  Class:                             ");
    switch (ehdr.e_ident[EI_CLASS])
    {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("<unknown: %x>\n", ehdr.e_ident[EI_CLASS]);
            break;
    }

    printf("  Data:                              ");
    switch (ehdr.e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: %x>\n", ehdr.e_ident[EI_DATA]);
            break;
    }

    printf("  Version:                           ");
    switch (ehdr.e_ident[EI_VERSION])
    {
        case EV_NONE:
            printf("0\n");
            break;
        case EV_CURRENT:
            printf("%d (current)\n", EV_CURRENT);
            break;
        default:
            printf("%d\n", ehdr.e_ident[EI_VERSION]);
            break;
    }

    printf("  OS/ABI:                            ");
    switch (ehdr.e_ident[EI_OSABI])
    {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
        case ELFOSABI_ARM:
            printf("ARM architecture\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("<standalone>\n");
            break;
        default:
            printf("<unknown: %x>\n", ehdr.e_ident[EI_OSABI]);
            break;
    }

    printf("  ABI Version:                       %d\n", ehdr.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (ehdr.e_type)
    {
        case ET_NONE:
            printf("NONE (None)\n");
            break;
        case ET_REL:
            printf("REL (Relocatable file)\n");
            break;
        case ET_EXEC:
            printf("EXEC (Executable file)\n");
            break;
        case ET_DYN:
            printf("DYN (Shared object file)\n");
            break;
        case ET_CORE:
            printf("CORE (Core file)\n");
            break;
        default:
            printf("<unknown: %x>\n", ehdr.e_type);
            break;
    }

    printf("  Entry point address:               %#lx\n", ehdr.e_entry);

    close(fd);
    return (0);
}

