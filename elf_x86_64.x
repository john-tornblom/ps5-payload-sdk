OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

PHDRS {
	ph_text   PT_LOAD FLAGS (0x1 | 0x4);
	ph_rodata PT_LOAD FLAGS (0x4);
	ph_data   PT_LOAD FLAGS (0x2 | 0x4);
}

SECTIONS {
	.text : { *(.text .text.*) } : ph_text
	. = ALIGN(0x4000);
	.rodata : { *(.rodata .rodata.*) } : ph_rodata
	. = ALIGN(0x4000);
	.data : { *(.data .data.*) } : ph_data
	.bss : {
	    PROVIDE_HIDDEN(__bss_start = .);
	    *(.bss .bss.*) *(COMMON)
	    PROVIDE_HIDDEN(__bss_end = .);
	}
	.init_array : {
	    PROVIDE_HIDDEN(__init_array_start = .);
	    KEEP(*(SORT(.init_array.*)))
	    KEEP(*(.init_array*))
	    PROVIDE_HIDDEN(__init_array_end = .);
	}
	.fini_array : {
	    PROVIDE_HIDDEN(__fini_array_start = .);
	    KEEP(*(SORT(.fini_array.*)))
	    KEEP(*(.fini_array*))
	    PROVIDE_HIDDEN(__fini_array_end = .);
	}
}
