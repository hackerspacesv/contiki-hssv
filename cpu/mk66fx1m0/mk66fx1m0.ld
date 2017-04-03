/*------------------------------------------------------------------------------------------------*/
/* Linker script for the Kinetis MK66FX1M0 microcontroller.                                       */
/*                                                                                                */
/* Author: Joksan Alvarado.                                                                       */
/*------------------------------------------------------------------------------------------------*/

/* Memory configuration for the microcontroller part */
MEMORY {
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 1M
  SRAM  (rw) : ORIGIN = 0x1FFF0000, LENGTH = 256K
}

/* Entry point function */
ENTRY(startup)

/* Heap and stack section sizes. Adjust to better fit the application. */
__heap_size__ = 64K;
__stack_size__ = 16K;

/* Section mapping */
SECTIONS {
  /* Vector table is allocated at address 0 in flash */
  .vectors 0x00000000 : {
    KEEP(*(.vectors))
  } > FLASH

  /* Non volatile configuration bits are located at 0x400 */
  .flash_configuration_field 0x00000400: {
    KEEP(*(.flash_configuration_field))
  } > FLASH

  /* Read only sections (code, data, etc) are allocated in flash */
  .text : {
    . = ALIGN(4);
    *(.text*)
    . = ALIGN(4);
    *(.rodata*)
    . = ALIGN(4);
    *(.init)
    . = ALIGN(4);
    *(.fini)
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
