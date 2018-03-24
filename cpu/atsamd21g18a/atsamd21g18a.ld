/*------------------------------------------------------------------------------------------------*/
/* Linker script for the ATSAMD21G18A microcontroller.                                            */
/*                                                                                                */
/* Author: Joksan Alvarado.                                                                       */
/*------------------------------------------------------------------------------------------------*/

/* reserved flash size for bootloader (bossac) */
__bootloader_size__ = 8K;

/* Memory configuration for the microcontroller part */
MEMORY {
  FLASH (rx) : ORIGIN = 0x00000000 + __bootloader_size__, LENGTH = 256K - __bootloader_size__
  SRAM  (rw) : ORIGIN = 0x20000000, LENGTH = 32K
}

/* Heap and stack section sizes. Adjust to better fit the application. */
__heap_size__ = 8K;
__stack_size__ = 4K;

/* Entry point function */
ENTRY(startup)

/* Section mapping */
SECTIONS {
  /* Vector table is allocated at address 0 in flash */
  .vectors __bootloader_size__ : {
    KEEP(*(.vectors))
  } > FLASH

  /* Code sections are allocated in flash */
  .text : {
    . = ALIGN(4);
    *(.text*)       /* Text (code) section and subsections */
    . = ALIGN(4);
    *(.init)        /* Init section */
    . = ALIGN(4);
    *(.fini)        /* Fini section */
    . = ALIGN(4);
     *(.eh_frame)   /* Exception unwinding and source language information section */
  } > FLASH

  /* Read only data (constants) are allocated in flash */
  .rodata : {
    . = ALIGN(4);
    *(.rodata*)     /* General read only data section */
    . = ALIGN(4);
    *(.init_array)  /* Initialization functions array */
    . = ALIGN(4);
    *(.fini_array)  /* Finalization functions array */
    . = ALIGN(4);
    *(.jcr)         /* Information used for registering compiled java classes */
  } > FLASH

  /* Stack unwinding information section is allocated in flash */
  .ARM.exidx : {
    *(.ARM.exidx*)
  } > FLASH

  /* Initialized read/write sections are allocated in RAM but loaded in flash */
  .data : {
    . = ALIGN(4);
    __relocate_sram_start__ = .;
    *(.data*)
    . = ALIGN(4);
    __relocate_sram_end__ = .;
  } > SRAM AT > FLASH

  /* Export a symbol to allow relocation of the initialized data sections from flash to RAM */
  __relocate_flash_start__ = LOADADDR(.data);

  /* Uninitialized read/write sections are allocated in RAM but not loaded anywhere */
  .bss (NOLOAD) : {
    . = ALIGN(4);
    __bss_start__ = .;
    *(.bss*)
    . = ALIGN(4);
    __bss_end__ = .;
  } > SRAM

  /* The heap starts after all other data sections but before the stack */
  .heap (NOLOAD) : {
    . = ALIGN(4);
    __heap_start__ = .;
    . += __heap_size__;
    __heap_end__ = .;
  } > SRAM

  /* The stack goes right at the end of RAM */
  .stack __ram_end__ - __stack_size__ (NOLOAD) : {
    __stack_start__ = .;
    . += __stack_size__;
    __stack_end__ = .;
  } > SRAM

  /* Compute the end address of the RAM space */
  __ram_end__ = ORIGIN(SRAM) + LENGTH(SRAM);
}
