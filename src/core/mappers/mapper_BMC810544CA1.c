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

#include "mappers.h"
#include "info.h"
#include "mem_map.h"

void map_init_BMC810544CA1(void) {
	EXTCL_CPU_WR_MEM(BMC810544CA1);

	extcl_cpu_wr_mem_BMC810544CA1(0x8000, 0);
}
void extcl_cpu_wr_mem_BMC810544CA1(WORD address, BYTE value) {
	WORD base = address >> 7;
	DBWORD bank;

	if (address & 0x0040) {
		_control_bank(base, info.prg.rom.max.banks_32k)
		map_prg_rom_8k(4, 0, base);
	} else {
		base = (base << 1) | ((address & 0x0020) >> 5);
		_control_bank(base, info.prg.rom.max.banks_16k)
		map_prg_rom_8k(2, 0, base);
		map_prg_rom_8k(2, 2, base);
	}
	map_prg_rom_8k_update();

	value = address & 0x0F;
	control_bank(info.chr.rom.max.banks_8k)
	bank = value << 13;
	chr.bank_1k[0] = chr_pnt(bank);
	chr.bank_1k[1] = chr_pnt(bank | 0x0400);
	chr.bank_1k[2] = chr_pnt(bank | 0x0800);
	chr.bank_1k[3] = chr_pnt(bank | 0x0C00);
	chr.bank_1k[4] = chr_pnt(bank | 0x1000);
	chr.bank_1k[5] = chr_pnt(bank | 0x1400);
	chr.bank_1k[6] = chr_pnt(bank | 0x1800);
	chr.bank_1k[7] = chr_pnt(bank | 0x1C00);

	if (address & 0x0010) {
		mirroring_H();
	} else  {
		mirroring_V();
	}
}
