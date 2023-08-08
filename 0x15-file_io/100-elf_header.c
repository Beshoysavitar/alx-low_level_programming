#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void c_e(unsigned char *i);
void p_m(unsigned char *i);
void p_c(unsigned char *i);
void p_d(unsigned char *i);
void p_v(unsigned char *i);
void print_abi(unsigned char *i);
void p_o(unsigned char *i);
void p_t(unsigned int e_type, unsigned char *i);
void p_ent(unsigned long int e_entry, unsigned char *i);
void c_elf(int elf);

/**
 * c_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void c_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * p_m - Prints the magic numbers of an ELF header.
 * @i: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void p_m(unsigned char *i)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", i[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * p_c - Prints the class of an ELF header.
 * @i: A pointer to an array containing the ELF class.
 */
void p_c(unsigned char *i)
{
	printf("  Class:                             ");

	switch (i[EI_CLASS])
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
		printf("<unknown: %x>\n", i[EI_CLASS]);
	}
}

/**
 * p_d - Prints the data of an ELF header.
 * @i: A pointer to an array containing the ELF class.
 */
void p_d(unsigned char *i)
{
	printf("  Data:                              ");

	switch (i[EI_DATA])
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
		printf("<unknown: %x>\n", i[EI_CLASS]);
	}
}
/**
 * c_e - Checks if a file is an ELF file.
 * @i: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void c_e(unsigned char *i)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (i[index] != 127 &&
		    i[index] != 'E' &&
		    i[index] != 'L' &&
		    i[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
 * p_v - Prints the version of an ELF header.
 * @i: A pointer to an array containing the ELF version.
 */
void p_v(unsigned char *i)
{
	printf("  Version:                           %d",
	       i[EI_VERSION]);

	switch (i[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * p_o - Prints the OS/ABI of an ELF header.
 * @i: A pointer to an array containing the ELF version.
 */
void p_o(unsigned char *i)
{
	printf("  OS/ABI:                            ");

	switch (i[EI_OSABI])
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
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", i[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @i: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *i)
{
	printf("  ABI Version:                       %d\n",
	       i[EI_ABIVERSION]);
}

/**
 * p_t - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @i: A pointer to an array containing the ELF class.
 */
void p_t(unsigned int e_type, unsigned char *i)
{
	if (i[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * p_ent - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @i: A pointer to an array containing the ELF class.
 */
void p_ent(unsigned long int e_entry, unsigned char *i)
{
	printf("  Entry point address:               ");

	if (i[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (i[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}



/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		c_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		c_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	c_e(header->i);
	printf("ELF Header:\n");
	p_m(header->i);
	p_c(header->i);
	p_d(header->i);
	p_v(header->i);
	p_o(header->i);
	print_abi(header->i);
	p_t(header->e_type, header->i);
	p_ent(header->e_entry, header->i);

	free(header);
	c_elf(o);
	return (0);
}
