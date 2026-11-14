/* Gervill's emergency soundbank (~/.gervill/soundbank-emg.sf2, which the
   Java build's synthesizer generates when it finds no other bank), built
   into the executable for media.cpp. */
#ifdef __APPLE__
    /* Mach-O: read-only data, C symbols with a leading underscore */
    .const
    .globl _deep3d_gervill_emg
    .globl _deep3d_gervill_emg_end
    .p2align 4
_deep3d_gervill_emg:
    .incbin "gervill_emg.sf2"
_deep3d_gervill_emg_end:
#else
    .section .rodata
    .global deep3d_gervill_emg
    .global deep3d_gervill_emg_end
    .balign 16
deep3d_gervill_emg:
    .incbin "gervill_emg.sf2"
deep3d_gervill_emg_end:
#endif
#ifdef __ELF__
    .section .note.GNU-stack,"",@progbits
#endif
