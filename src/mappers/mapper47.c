/*
 * mapper47.c
 *
 *  Created on: 21/apr/2012
 *      Author: fhorse
 */

#include <stdlib.h>
#include <string.h>
#include "mappers.h"
#include "mem_map.h"
#include "irqA12.h"
#include "save_slot.h"

#define m47chr1k(vl) bank = (m47.reg << 7) | (vl & 0x7F)
#define m47prg8k(vl) value = (m47.reg << 4) | (vl & 0x0F)
#define m47chr1kupdate()\
{\
	BYTE i;\
	for (i = 0; i < 8; i++) {\
		WORD bank;\
		m47chr1k(m47.chrmap[i]);\
		_control_bank(bank, chrRom1kMax)\
		chr.bank_1k[i] = &chr.data[bank << 10];\
	}\
}
#define m47prg8kupdate()\
{\
	BYTE i;\
	for (i = 0; i < 4; i++) {\
		m47prg8k(m47.prgmap[i]);\
		control_bank(prgRom8kMax)\
		map_prg_rom_8k(1, i, value);\
	}\
	map_prg_rom_8k_update();\
}
#define m47swapChrBank1k(src, dst)\
{\
	BYTE *chrBank1k = chr.bank_1k[src];\
	chr.bank_1k[src] = chr.bank_1k[dst];\
	chr.bank_1k[dst] = chrBank1k;\
	WORD map = m47.chrmap[src];\
	m47.chrmap[src] = m47.chrmap[dst];\
	m47.chrmap[dst] = map;\
}
#define m47_8000()\
{\
	const BYTE chrRomCfgOld = mmc3.chrRomCfg;\
	const BYTE prgRomCfgOld = mmc3.prgRomCfg;\
	mmc3.bankToUpdate = value & 0x07;\
	mmc3.prgRomCfg = (value & 0x40) >> 5;\
	mmc3.chrRomCfg = (value & 0x80) >> 5;\
	/*\
	 * se il tipo di configurazione della chr cambia,\
	 * devo swappare i primi 4 banchi con i secondi\
	 * quattro.\
	 */\
	if (mmc3.chrRomCfg != chrRomCfgOld) {\
		m47swapChrBank1k(0, 4)\
		m47swapChrBank1k(1, 5)\
		m47swapChrBank1k(2, 6)\
		m47swapChrBank1k(3, 7)\
	}\
	if (mmc3.prgRomCfg != prgRomCfgOld) {\
		WORD p0 = mapper.rom_map_to[0];\
		WORD p2 = mapper.rom_map_to[2];\
		mapper.rom_map_to[0] = p2;\
		mapper.rom_map_to[2] = p0;\
		p0 = m47.prgmap[0];\
		p2 = m47.prgmap[2];\
		m47.prgmap[0] = p2;\
		m47.prgmap[2] = p0;\
		m47.prgmap[mmc3.prgRomCfg ^ 0x02] = prgRom8kBeforeLast;\
		/*\
		 * prgRomCfg 0x00 : $C000 - $DFFF fisso al penultimo banco\
		 * prgRomCfg 0x02 : $8000 - $9FFF fisso al penultimo banco\
		 */\
		m47prg8k(prgRom8kBeforeLast);\
		control_bank(prgRom8kMax)\
		map_prg_rom_8k(1, mmc3.prgRomCfg ^ 0x02, value);\
		map_prg_rom_8k_update();\
	}\
}
#define m47_8001()\
{\
	WORD bank;\
	switch (mmc3.bankToUpdate) {\
		case 0:\
			m47.chrmap[mmc3.chrRomCfg] = value;\
			m47.chrmap[mmc3.chrRomCfg | 0x01] = value + 1;\
			m47chr1k(value);\
			bank &= 0xFFE;\
			_control_bank(bank, chrRom1kMax)\
			chr.bank_1k[mmc3.chrRomCfg] = &chr.data[bank << 10];\
			chr.bank_1k[mmc3.chrRomCfg | 0x01] = &chr.data[(bank + 1) << 10];\
			return;\
		case 1:\
			m47.chrmap[mmc3.chrRomCfg | 0x02] = value;\
			m47.chrmap[mmc3.chrRomCfg | 0x03] = value + 1;\
			m47chr1k(value);\
			bank &= 0xFFE;\
			_control_bank(bank, chrRom1kMax)\
			chr.bank_1k[mmc3.chrRomCfg | 0x02] = &chr.data[bank << 10];\
			chr.bank_1k[mmc3.chrRomCfg | 0x03] = &chr.data[(bank + 1) << 10];\
			return;\
		case 2:\
			m47.chrmap[mmc3.chrRomCfg ^ 0x04] = value;\
			m47chr1k(value);\
			_control_bank(bank, chrRom1kMax)\
			chr.bank_1k[mmc3.chrRomCfg ^ 0x04] = &chr.data[bank << 10];\
			return;\
		case 3:\
			m47.chrmap[(mmc3.chrRomCfg ^ 0x04) | 0x01] = value;\
			m47chr1k(value);\
			_control_bank(bank, chrRom1kMax)\
			chr.bank_1k[(mmc3.chrRomCfg ^ 0x04) | 0x01] = &chr.data[bank << 10];\
			return;\
		case 4:\
			m47.chrmap[(mmc3.chrRomCfg ^ 0x04) | 0x02] = value;\
			m47chr1k(value);\
			_control_bank(bank, chrRom1kMax)\
			chr.bank_1k[(mmc3.chrRomCfg ^ 0x04) | 0x02] = &chr.data[bank << 10];\
			return;\
		case 5:\
			m47.chrmap[(mmc3.chrRomCfg ^ 0x04) | 0x03] = value;\
			m47chr1k(value);\
			_control_bank(bank, chrRom1kMax)\
			chr.bank_1k[(mmc3.chrRomCfg ^ 0x04) | 0x03] = &chr.data[bank << 10];\
			return;\
		case 6:\
			m47.prgmap[mmc3.prgRomCfg] = value;\
			m47prg8k(value);\
			control_bank(prgRom8kMax)\
			map_prg_rom_8k(1, mmc3.prgRomCfg, value);\
			map_prg_rom_8k_update();\
			return;\
		case 7:\
			m47.prgmap[1] = value;\
			m47prg8k(value);\
			control_bank(prgRom8kMax)\
			map_prg_rom_8k(1, 1, value);\
			map_prg_rom_8k_update();\
			return;\
	}\
}

WORD prgRom8kMax, prgRom8kBeforeLast, chrRom1kMax;

void map_init_47(void) {
	prgRom8kMax = info.prg_rom_8k_count - 1;
	prgRom8kBeforeLast = info.prg_rom_8k_count - 2;
	chrRom1kMax = info.chr_rom_1k_count - 1;

	EXTCL_CPU_WR_MEM(47);
	EXTCL_SAVE_MAPPER(47);
	EXTCL_CPU_EVERY_CYCLE(MMC3);
	EXTCL_PPU_000_TO_34X(MMC3);
	EXTCL_PPU_000_TO_255(MMC3);
	EXTCL_PPU_256_TO_319(MMC3);
	EXTCL_PPU_320_TO_34X(MMC3);
	EXTCL_UPDATE_R2006(MMC3);
	mapper.internal_struct[0] = (BYTE *) &m47;
	mapper.internal_struct_size[0] = sizeof(m47);
	mapper.internal_struct[1] = (BYTE *) &mmc3;
	mapper.internal_struct_size[1] = sizeof(mmc3);

	memset(&mmc3, 0x00, sizeof(mmc3));
	memset(&irqA12, 0x00, sizeof(irqA12));
	memset(&m47, 0x00, sizeof(m47));

	{
		BYTE value, i;

		map_prg_rom_8k_reset();
		chr_bank_1k_reset()

		for (i = 0; i < 8; i++) {
			if (i < 4) {
				m47.prgmap[i] = mapper.rom_map_to[i];
			}
			m47.chrmap[i] = i;
		}

		m47prg8kupdate()
		m47chr1kupdate()
	}

	info.mapper_extend_wr = TRUE;

	irqA12.present = TRUE;
	irqA12_delay = 1;
}
void extcl_cpu_wr_mem_47(WORD address, BYTE value) {
	if (address > 0x7FFF) {
		switch (address & 0xE001) {
			case 0x8000:
				m47_8000()
				return;
			case 0x8001:
				m47_8001()
				return;
		}
		extcl_cpu_wr_mem_MMC3(address, value);
		return;
	}

	if (address >= 0x6000) {
		value &= 0x01;

		if (m47.reg != value) {
			m47.reg = value;

			m47prg8kupdate()
			m47chr1kupdate()
		}
	}
}
BYTE extcl_save_mapper_47(BYTE mode, BYTE slot, FILE *fp) {
	save_slot_ele(mode, slot, m47.reg);
	save_slot_ele(mode, slot, m47.prgmap);
	save_slot_ele(mode, slot, m47.chrmap);
	extcl_save_mapper_MMC3(mode, slot, fp);

	return (EXIT_OK);
}
