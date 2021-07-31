-include tools.mk

z_sdcc=${SDCC_PATH}/bin/sdcc
z_sdld=${SDCC_PATH}/bin/sdld
z_packihx=${SDCC_PATH}/bin/packihx
z_hex2bin=${HEX2BIN_PATH}/hex2bin
z_stm8flash=${STM8FLASH_PATH}/stm8flash

files_temp=*.asm *.lst *.rst *.rel *.sym *.ihx *.hex *.map *.lk *.bin *.cdb


build:
	$(z_sdcc) -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $(APP_PATH)/$(PROJECT)/*.c
	${z_packihx} *.ihx > $(PROJECT).hex
	${z_hex2bin} $(PROJECT).hex

	mv -f $(files_temp) $(BIN_PATH)


clean:
	rm -f $(BIN_PATH)/*

flash:
	echo "00 00 ff 00 ff 00 ff 00 ff 00 ff" | xxd -r -p > factory_defaults.bin
	$(z_stm8flash) -c stlinkv2 -p stm8s103?3 -s opt -w factory_defaults.bin
	$(z_stm8flash) -c stlinkv2 -p stm8s103?3 -w $(BIN_PATH)/*.ihx
	rm factory_defaults.bin


