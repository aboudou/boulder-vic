/* VIC-20 PRG file linker script.
 *
 * Three distinct types of memory configurations are supported:
 *
 * - no memory expansion (memory area 0x1001 - 0x1DFF),
 * - +3K memory expansion (memory area 0x0401 - 0x1DFF),
 * - +8/16/24K memory expansion (memory area 0x1201 - ...).
 *
 * BASIC memory regions are freely overwritten, but any KERNAL regions are left alone.
 *
 * Produces a PRG file with a SYS command to start the program.
 */

PROVIDE(__memory_expansion = 3);
ASSERT(__memory_expansion == 0 || __memory_expansion == 3 || __memory_expansion == 8 || __memory_expansion == 16 || __memory_expansion == 24,
        "The memory expansion symbol must be set to 0, 3, 8, 16 or 24 (extra KB).")

__basic_zp_start = 0x0000;
__basic_zp_end = 0x0090;

MEMORY {
    /* ram (rw) : ORIGIN = 0x0401, LENGTH = 0x19FF */ /* 3kB - With default charset */
    /* ram (rw) : ORIGIN = 0x0401, LENGTH = 0x17FF */ /* 3kB - With full 512 bytes user charset space */
    ram (rw) : ORIGIN = 0x0401, LENGTH = 0x19C7       /* 3kB - With 56 bytes user charset space (7 chars) */ 
}

INCLUDE commodore.ld

__stack = 0x8000;

OUTPUT_FORMAT {
    /* Tells the VIC-20 LOAD command where to place the file's contents. */
    SHORT(ORIGIN(ram))
    TRIM(ram)
}
