OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)

ENTRY(_start)

PHDRS
{
	/*
	 * PF_X = 0x1
	 * PF_W = 0x2
	 * PF_R = 0x4
	 */

	ph_text PT_LOAD FLAGS (0x1 | 0x4);
	ph_data PT_LOAD FLAGS (0x2 | 0x4);
}

SECTIONS
{
	__payload_base = .;

	.text :
	{
		KEEP (*(.init))
		KEEP (*(.fini))

		*(.text .text.*)

		. = ALIGN(4);
	} : ph_text = 0x90909090

	.rodata :
	{
		*(.rodata .rodata.*)

		. = ALIGN(4);
	}

	. = ALIGN(0x4000);

	.data :
	{
		*(.data .data.*)

		. = ALIGN(0x10);

		__imports_start = .;
		KEEP(*(.imports .imports.*))
		__imports_end = .;

		__patches_start = .;
		KEEP(*(.patches .patches.*))
		QUAD(0); BYTE(0); BYTE(0);
		__patches_end = .;

		__bss_start = .;
		*(.bss .bss.*) *(COMMON)
		__bss_end = .;

		. = . + 4;
		. = ALIGN(4);
	} : ph_data

	.init_array :
	{
		__init_array_start = .;
		KEEP (*(SORT(.init_array.*)))
		KEEP (*(.init_array*))
		__init_array_end = .;
	} : ph_data

	.fini_array :
	{
		__fini_array_start = .;
		KEEP (*(SORT(.fini_array.*)))
		KEEP (*(.fini_array*))
		 __fini_array_end = .;
	} : ph_data
}
