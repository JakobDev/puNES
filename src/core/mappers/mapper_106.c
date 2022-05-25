/*
 *  Copyright (C) 2010-2022 Fabio Cavallo (aka FHorse)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <string.h>
#include "mappers.h"
#include "info.h"
#include "mem_map.h"
#include "cpu.h"
#include "save_slot.h"

INLINE static void prg_fix_106(void);
INLINE static void chr_fix_106(void);
INLINE static void mirroring_fix_106(void);

struct _m106 {
	BYTE prg[4];
	BYTE chr[8];
	BYTE mirroring;
	struct _m106_irq {
		BYTE enabled;
		WORD counter;
	} irq;
} m106;

void map_init_106(void) {
	EXTCL_AFTER_MAPPER_INIT(106);
	EXTCL_CPU_WR_MEM(106);
	EXTCL_SAVE_MAPPER(106);
	EXTCL_CPU_EVERY_CYCLE(106);
	mapper.internal_struct[0] = (BYTE *)&m106;
	mapper.internal_struct_size[0] = sizeof(m106);

	if (info.reset >= HARD) {
		memset(&m106, 0x00, sizeof(m106));
	}
}
void extcl_after_mapper_init_106(void) {
	prg_fix_106();
	chr_fix_106();
	mirroring_fix_106();
}
void extcl_cpu_wr_mem_106(WORD address, BYTE value) {
	switch (address & 0x000F) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			m106.chr[address & 0x0007] = (value & (address & 0x0004 ? 0xFF : 0xFE)) |
				(address & 0x0004 ? 0x00 : address & 0x0001 ? 0x01 : 0x00);
			chr_fix_106();
			break;
		case 8:
		case 9:
		case 10:
		case 11:
			m106.prg[address & 0x0003] = value;
			prg_fix_106();
			break;
		case 12:
			m106.mirroring = value;
			mirroring_fix_106();
			break;
		case 13:
			m106.irq.enabled = FALSE;
			m106.irq.counter = 0;
			irq.high &= ~EXT_IRQ;
			break;
		case 14:
			m106.irq.counter = (m106.irq.counter & 0xFF00) | value;
			break;
		case 15:
			m106.irq.counter = (m106.irq.counter & 0x00FF) | (value << 8);
			m106.irq.enabled = TRUE;
			break;
	}
}
BYTE extcl_save_mapper_106(BYTE mode, BYTE slot, FILE *fp) {
	save_slot_ele(mode, slot, m106.prg);
	save_slot_ele(mode, slot, m106.chr);
	save_slot_ele(mode, slot, m106.mirroring);
	save_slot_ele(mode, slot, m106.irq.enabled);
	save_slot_ele(mode, slot, m106.irq.counter);

	return (EXIT_OK);
}
void extcl_cpu_every_cycle_106(void) {
    if (m106.irq.counter != 0xFFFF) {
    	m106.irq.counter++;
       if ((m106.irq.counter == 0xFFFF) && m106.irq.enabled) {
    	   irq.high |= EXT_IRQ;
       }
    }
}

INLINE static void prg_fix_106(void) {
	BYTE value;

	value = m106.prg[0] | 0x010;
	control_bank(info.prg.rom.max.banks_8k)
	map_prg_rom_8k(1, 0, value);

	value = m106.prg[1];
	control_bank(info.prg.rom.max.banks_8k)
	map_prg_rom_8k(1, 1, value);

	value = m106.prg[2];
	control_bank(info.prg.rom.max.banks_8k)
	map_prg_rom_8k(1, 2, value);

	value = m106.prg[3] | 0x010;
	control_bank(info.prg.rom.max.banks_8k)
	map_prg_rom_8k(1, 3, value);

	map_prg_rom_8k_update();
}
INLINE static void chr_fix_106(void) {
	DBWORD bank;

	bank = m106.chr[0];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[0] = chr_pnt(bank << 10);

	bank = m106.chr[1];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[1] = chr_pnt(bank << 10);

	bank = m106.chr[2];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[2] = chr_pnt(bank << 10);

	bank = m106.chr[3];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[3] = chr_pnt(bank << 10);

	bank = m106.chr[4];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[4] = chr_pnt(bank << 10);

	bank = m106.chr[5];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[5] = chr_pnt(bank << 10);

	bank = m106.chr[6];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[6] = chr_pnt(bank << 10);

	bank = m106.chr[7];
	_control_bank(bank, info.chr.rom.max.banks_1k)
	chr.bank_1k[7] = chr_pnt(bank << 10);
}
INLINE static void mirroring_fix_106(void) {
	if (m106.mirroring & 0x01) {
		mirroring_H();
	} else {
		mirroring_V();
	}
}
