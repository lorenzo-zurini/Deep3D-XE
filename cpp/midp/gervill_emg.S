/* Gervill's emergency soundbank (~/.gervill/soundbank-emg.sf2, which the
   Java build's synthesizer generates when it finds no other bank), built
   into the executable for media.cpp. */
    .section .rodata
    .global deep3d_gervill_emg
    .global deep3d_gervill_emg_end
    .balign 16
deep3d_gervill_emg:
    .incbin "gervill_emg.sf2"
deep3d_gervill_emg_end:
    .section .note.GNU-stack,"",@progbits
