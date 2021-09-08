/*
 * nand_ids.c
 *
 * Copyright (C) 2019 Allwinner.
 *
 * cuizhikui <cuizhikui@allwinnertech.com>
 *
 * SPDX-License-Identifier: GPL-2.0
 */

#include "rawnand_ids.h"
#include "rawnand_chip.h"
#include "rawnand_boot.h"
#include "rawnand_debug.h"
#include <linux/string.h>
#include <malloc.h>

/*cmd stay to handle*/
struct nand_phy_op_par phy_op_para[] = {
	{
		// CMD_SET_0 index
		.instr = {
			.read_instr = {0x00, 0x30},
			.multi_plane_read_instr = {0x00, 0x30, 0x00, 0x30}, //simulate
			.write_instr = {0x80, 0x10},
			.multi_plane_write_instr = {0x80, 0x10, 0x80, 0x10}, //simulate
		},
	},
	{
		// CMD_SET_1 index
		.instr = {
			.read_instr = {0x00, 0x30},
			.multi_plane_read_instr = {0x00, 0x30, 0x00, 0x30}, //simulate
			.write_instr = {0x80, 0x10},
			.multi_plane_write_instr = {0x80, 0x11, 0x80, 0x10},
		},
	},
	{
		// CMD_SET_2 index
		.instr = {
			.read_instr = {0x00, 0x30},
			.multi_plane_read_instr = {0x00, 0x32, 0x00, 0x30},
			.write_instr = {0x80, 0x10},
			.multi_plane_write_instr = {0x80, 0x11, 0x81, 0x10},
		},
	},
	{
		// CMD_SET_3 index
		.instr = {
			.read_instr = {0x00, 0x30},
			.multi_plane_read_instr = {0x00, 0x32, 0x00, 0x30},
			.write_instr = {0x80, 0x10},
			.multi_plane_write_instr = {0x80, 0x11, 0x80, 0x10},
		},
	},

};


struct sunxi_nand_flash_device raw_sandisk[] = {
	{
		.name = "SDTNSGAMA-016G",
		.id = {0x45, 0x3A, 0x94, 0x93, 0x76, 0x51, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 4212,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			SANDISK_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x342009,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_SANDISK,
		.ddr_info_no = 1,
		.id_number = 0x0,
		.max_blk_erase_times = 3000,
		.access_high_freq = 40,
	},
};

struct sunxi_nand_flash_device raw_toshiba[] = {
	{
		.name = "TC58TEG6DDLTA00",
		.id = {0x98, 0xde, 0x94, 0x93, 0x76, 0x51, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 2148,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			TOSHIBA_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 60,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x120a05,
		.ddr_type = TOG_DDR,
		.ddr_opt = NAND_VCCQ_1P8V | NAND_TOGGLE_IO_DRIVER_STRENGTH
			| NAND_TOGGLE_VENDOR_SPECIFIC_CFG,
		.bad_block_flag_position = LAST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_TOSHIBA,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 3000,
		.access_high_freq = 60,
	},
	{
		/*TC58NVG2S0HTAI0&TC58NVG2S0HTA00 the same id (industry/consumption)*/
		.name = "TC58NVG2S0HTAI0",
		.id = {0x98, 0xdc, 0x90, 0x26, 0x76, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 8,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_32,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_TOSHIBA,
		.ddr_info_no = 0,
		.id_number = 0x1,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
	{
		.name = "TC58NVG1S3HTA00",
		.id = {0x98, 0xda, 0x90, 0x15, 0x76, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_32,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x2,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
	{
		.name = "TC58TFG7DDLTA0D",
		.id = {0x98, 0x3a, 0x94, 0x93, 0x76, 0x51, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 4212,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			TOSHIBA_LSB_PAGE | NAND_READ_RETRY,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x120a05,
		.ddr_type = TOG_DDR,
		.ddr_opt = NAND_VCCQ_1P8V | NAND_TOGGLE_IO_DRIVER_STRENGTH
			| NAND_TOGGLE_VENDOR_SPECIFIC_CFG,
		.bad_block_flag_position = LAST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_TOSHIBA,
		.ddr_info_no = 0,
		.id_number = 0x3,
		.max_blk_erase_times = 3000,
		.access_high_freq = 40,
	},
	{
		.name = "TC58BVG0S3HTAI0",
		.id = {0x98, 0xf1, 0x80, 0x15, 0xf2, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 1024,
		.operation_opt = NAND_RANDOM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_16,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_0,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x4,
		.max_blk_erase_times = 30000,
		.access_high_freq = 30,
	},
};
struct sunxi_nand_flash_device raw_micron[] = {
	{
		.name = "MT29F64G08CBABA",
		.id = {0x2c, 0x64, 0x44, 0x4B, 0xA9, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 16,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 4096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			MICRON_0x41_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_48,
		.read_retry_type = 0x400a01,
		.ddr_type = SDR,
		.ddr_opt = NAND_ONFI_TIMING_MODE,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 3000,
		.access_high_freq = 40,
	},
	{
		.name = "MT29F32G08CBADBWP",
		.id = {0x2c, 0x44, 0x44, 0x4B, 0xA9, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 16,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 2128,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			MICRON_0x41_LSB_PAGE | NAND_FIND_ID_TAB_BY_NAME,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 60,
		.ecc_mode = BCH_48,
		.read_retry_type = 0x400a01,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_ONFI_TIMING_MODE | NAND_ONFI_IO_DRIVER_STRENGTH
			| NAND_ONFI_RB_STRENGTH,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = 0,
		.id_number = 0x1,
		.max_blk_erase_times = 3000,
		.access_high_freq = 60,
	},
	{
		.name = "MT29F128G08CFAAA",
		.id = {0x2c, 0x88, 0x04, 0x4B, 0xA9, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 16,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 4096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			GENERIC_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_28,
		.read_retry_type = 0,
		.ddr_type = SDR,
		.ddr_opt = NAND_ONFI_TIMING_MODE,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_3,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x2,
		.max_blk_erase_times = 3000,
		.access_high_freq = 40,
	},
	{
		.name = "FBNL05B128G1KDBABJ4",
		.id = {0x2c, 0x84, 0x44, 0x32, 0xAA, 0x04, 0x00, 0x00},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 2192,
		/*
		 * This nand request that it should write lsb/msb shared pages together,
		 * so use GENERIC_LSB_PAGE to write boot0 data both to lsb and msb pages
		 * and use NAND_PAIRED_PAGE_SYNC for driver to write lsb,msb pages together
		 */
		.operation_opt = NAND_RANDOM | NAND_READ_RETRY | NAND_READ_UNIQUE_ID | NAND_PAGE_ADR_NO_SKIP | NAND_PAIRED_PAGE_SYNC |NAND_ONFI_SYNC_RESET_OP | GENERIC_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_76,
		.read_retry_type = 0x421201,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_VCCQ_1P8V|NAND_ONFI_TIMING_MODE|NAND_ONFI_DDR2_CFG|NAND_ONFI_IO_DRIVER_STRENGTH|NAND_TOGGLE_VENDOR_SPECIFIC_CFG,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_3,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS1_DRV_2,
		.id_number = 0x3,
		.max_blk_erase_times = 1500,
		.access_high_freq = 75,
	},
	{
		.name = "FBNL06B256G1KDBABJ4",
		.id = {0x2c, 0xA4, 0x64, 0x32, 0xAA, 0x04, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 1024,
		.blk_cnt_per_die = 2192,
		.operation_opt =  NAND_RANDOM | MICRON_0x44_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_76,
		.read_retry_type = 0x421000,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_VCCQ_1P8V | NAND_ONFI_IO_DRIVER_STRENGTH |
			NAND_ONFI_TIMING_MODE,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = 0,
		.id_number = 0x4,
		.max_blk_erase_times = 1000,
		.access_high_freq = 75,
	},
	{
		.name = "MT29F4G08ABAF",
		.id = {0x2c, 0xDC, 0x80, 0xA6, 0x62, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 8,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | GENERIC_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_32,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.ddr_opt = NAND_ONFI_TIMING_MODE,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_0,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x5,
		.max_blk_erase_times = 60000,
		.access_high_freq = 40,
	},
	{
		.name = "MT29F32G08CBADAWP",
		.id = {0x2c, 0x44, 0x44, 0x4B, 0xA9, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 16,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 2128,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM |
			MICRON_0x41_LSB_PAGE | NAND_FIND_ID_TAB_BY_NAME,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_48,
		.read_retry_type = 0x400a01,
		.ddr_type = SDR,
		.ddr_opt = NAND_ONFI_TIMING_MODE,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = 0,
		.id_number = 0x6,
		.max_blk_erase_times = 3000,
		.access_high_freq = 40,
	},
	{
		.name = "FxxL85C71KSBAB",
		.id = {0x2C, 0x84, 0x64, 0x3C, 0xa9, 0x04, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 2096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY | NAND_FIND_ID_TAB_BY_NAME |
			NAND_READ_UNIQUE_ID | MICRON_0x41_LSB_PAGE | NAND_ONFI_SYNC_RESET_OP,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x410c01,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_ONFI_RB_STRENGTH | NAND_ONFI_TIMING_MODE | NAND_ONFI_DDR2_CFG |
			NAND_ONFI_IO_DRIVER_STRENGTH | NAND_TOGGLE_VENDOR_SPECIFIC_CFG,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS1_DRV_2,
		.id_number = 0x7,
		.max_blk_erase_times = 1500,
		.access_high_freq = 75,
	},
	{
		.name = "FxxL95B71KDBABH6",
		.id = {0x2C, 0x84, 0x64, 0x54, 0xa9, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 2096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY |
			MICRON_0x42_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_64,
		.read_retry_type = 0x410c01,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_ONFI_RB_STRENGTH | NAND_ONFI_TIMING_MODE | NAND_ONFI_DDR2_CFG | NAND_ONFI_IO_DRIVER_STRENGTH | NAND_VCCQ_1P8V,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_3,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS1_DRV_2,
		.id_number = 0x8,
		.max_blk_erase_times = 1000,
		.access_high_freq = 75,
	},
	{
		.name = "L84D",
		.id = {0x2C, 0x64, 0x64, 0x3C, 0xa5, 0x08, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 1048,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY |
			MICRON_0x41_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x400a01,
		.ddr_type = ONFI_DDR,
		/*.ddr_opt = NAND_ONFI_TIMING_MODE,*/
		.ddr_opt = NAND_ONFI_DDR2_CFG | NAND_ONFI_IO_DRIVER_STRENGTH |
			NAND_ONFI_TIMING_MODE | NAND_VCCQ_1P8V,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_3,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.id_number = 0x9,
		.max_blk_erase_times = 3000,
		.access_high_freq = 40,
	},
	{
		.name = "L04A",
		.id = {0x2C, 0x64, 0x44, 0x32, 0xa5, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 1088,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY |
			GENERIC_LSB_PAGE | NAND_PAIRED_PAGE_SYNC,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_76,
		.read_retry_type = 0x421201,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_ONFI_DDR2_CFG | NAND_ONFI_IO_DRIVER_STRENGTH |
			NAND_ONFI_TIMING_MODE | NAND_VCCQ_1P8V,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_3,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS1_DRV_2,
		.id_number = 0xA,
		.max_blk_erase_times = 1000,
		.access_high_freq = 75,
	},
	{
		.name = "FxxL85C71KSBAR",
		.id = {0x2C, 0x84, 0x64, 0x3C, 0xa9, 0x04, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 2096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY | MICRON_0x41_LSB_PAGE | NAND_FIND_ID_TAB_BY_NAME,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x410c01,
		.ddr_type = SDR,
		.ddr_opt = NAND_ONFI_RB_STRENGTH | NAND_ONFI_TIMING_MODE | NAND_ONFI_IO_DRIVER_STRENGTH,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = 0,
		.id_number = 0xB,
		.max_blk_erase_times = 1500,
		.access_high_freq = 40,
	},
	{
		.name = "MT29F128G08CBEBB3W",
		.id = {0x2C, 0x84, 0x64, 0x3C, 0xa9, 0x04, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 2096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY |
			NAND_FIND_ID_TAB_BY_NAME_CANCEL | NAND_READ_UNIQUE_ID | MICRON_0x41_LSB_PAGE |
			NAND_ONFI_SYNC_RESET_OP,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x410c01,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_ONFI_RB_STRENGTH | NAND_ONFI_TIMING_MODE | NAND_ONFI_DDR2_CFG |
			NAND_ONFI_IO_DRIVER_STRENGTH,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS1_DRV_2,
		.id_number = 0xC,
		.max_blk_erase_times = 1500,
		.access_high_freq = 75,
	},
};

struct sunxi_nand_flash_device raw_spansion[] = {
	{
		.name = "S34ML01G200TFI000",
		.id = {0x01, 0xf1, 0x80, 0x1d, 0xff, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 1024,
		.operation_opt = NAND_RANDOM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_16,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_0,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
	{
		.name = "S34ML02G200TFI000",
		.id = {0x01, 0xda, 0x90, 0x95, 0x46, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_RANDOM | NAND_MULTI_PROGRAM | NAND_PAGE_COPYBACK,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_32,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x1,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
};

struct sunxi_nand_flash_device raw_esmt[] = {
	{
		.name = "IS34ML04G084",
		.id = {0xC8, 0xDC, 0x90, 0x95, 0x54, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 4096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_16,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
	{
		.name = "F59L2G81KA",
		.id = {0xc8, 0x6a, 0x90, 0x04, 0x34, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | GENERIC_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_32,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x1,
		.max_blk_erase_times = 50000,
		.access_high_freq = 30,
	},
	{
		.name = "F59L1G81MB",
		.id = {0xc8, 0xd1, 0x80, 0x95, 0x40, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 1024,
		.operation_opt = NAND_RANDOM | GENERIC_LSB_PAGE,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_16,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_0,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x2,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
};

struct sunxi_nand_flash_device raw_intel[] = {
	{
		.name = "JS29F64G08ACMF3",
		.id = {0x89, 0x88, 0x24, 0x4B, 0xa9, 0x84, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 16,
		.page_cnt_per_blk = 256,
		.blk_cnt_per_die = 4096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY | NAND_READ_UNIQUE_ID | MICRON_0x40_LSB_PAGE | NAND_ONFI_SYNC_RESET_OP,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 50,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x500701,
		.ddr_type = SDR,
		.ddr_opt = NAND_VCCQ_1P8V | NAND_ONFI_TIMING_MODE | NAND_ONFI_DDR2_CFG | NAND_ONFI_IO_DRIVER_STRENGTH | NAND_TOGGLE_VENDOR_SPECIFIC_CFG,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS1_DRV_2,
		.id_number = 0x0,
		.max_blk_erase_times = 3000,
		.access_high_freq = 50,
	},
	{
		.name = "AW56B16A4",
		.id = {0x89, 0x84, 0x64, 0x3C, 0xa5, 0x0c, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 32,
		.page_cnt_per_blk = 512,
		.blk_cnt_per_die = 2096,
		.operation_opt = NAND_MULTI_PROGRAM | NAND_RANDOM | NAND_READ_RETRY |
			MICRON_0x41_LSB_PAGE | NAND_ONFI_SYNC_RESET_OP | NAND_READ_UNIQUE_ID,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 75,
		.ecc_mode = BCH_40,
		.read_retry_type = 0x411201,
		.ddr_type = ONFI_DDR,
		.ddr_opt = NAND_ONFI_RB_STRENGTH | NAND_ONFI_TIMING_MODE | NAND_ONFI_DDR2_CFG |
			NAND_ONFI_IO_DRIVER_STRENGTH | NAND_TOGGLE_VENDOR_SPECIFIC_CFG,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_MICRON,
		.ddr_info_no = DDR_INFO_PARAS0_DEF,
		.id_number = 0x1,
		.max_blk_erase_times = 1500,
		.access_high_freq = 75,
	},
};

struct sunxi_nand_flash_device raw_mxic[] = {
	{
		.name = "MX30LF2G18AC",
		.id = {0xC2, 0xDA, 0x90, 0x95, 0x06, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_RANDOM | NAND_READ_UNIQUE_ID,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 50,
		.ecc_mode = BCH_16,
		.read_retry_type = 0x0,
		.ddr_type = SDR,
		.ddr_opt = 0x0,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = 0,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 10000,
		.access_high_freq = 50,
	},
	{
		.name = "MX30LF1G18AC",
		.id = {0xC2, 0xF1, 0x80, 0x95, 0x02, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 1024,
		.operation_opt = NAND_RANDOM | NAND_READ_UNIQUE_ID,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 50,
		.ecc_mode = BCH_16,
		.read_retry_type = 0x0,
		.ddr_type = SDR,
		.ddr_opt = 0x0,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_0,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = 0,
		.ddr_info_no = 0,
		.id_number = 0x1,
		.max_blk_erase_times = 10000,
		.access_high_freq = 50,
	},
};

struct sunxi_nand_flash_device raw_giga[] = {
	{
		.name = "GD9FU2G8F2A",
		.id = {0xC8, 0xDA, 0x90, 0x95, 0x46, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 2048,
		.operation_opt = NAND_RANDOM | NAND_READ_UNIQUE_ID,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 50,
		.ecc_mode = BCH_32,
		.read_retry_type = 0x0,
		.ddr_type = SDR,
		.ddr_opt = 0x0,
		.bad_block_flag_position = FIRST_PAGE,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_1,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = 0,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 10000,
		.access_high_freq = 50,
	},
};

struct sunxi_nand_flash_device raw_foresee[] = {
	{
		.name = "FS33ND04GS108TF10",
		.id = {0xec, 0xdc, 0x10, 0x95, 0x56, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 4096,
		.operation_opt = NAND_RANDOM | NAND_MULTI_PROGRAM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 40,
		.ecc_mode = BCH_16,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.ddr_opt = 0x0,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_2,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 60000,
		.access_high_freq = 40,
	},
};

struct sunxi_nand_flash_device raw_samsung[] = {
	{
		.name = "FS33ND01GS108TF10",
		.id = {0xec, 0xf1, 0x00, 0x95, 0x42, 0xff, 0xff, 0xff},
		.die_cnt_per_chip = 1,
		.sect_cnt_per_page = 4,
		.page_cnt_per_blk = 64,
		.blk_cnt_per_die = 1024,
		.operation_opt = NAND_RANDOM,
		.valid_blk_ratio = VALID_BLK_RATIO_DEFAULT,
		.access_freq = 30,
		.ecc_mode = BCH_16,
		.read_retry_type = READ_RETRY_TYPE_NULL,
		.ddr_type = SDR,
		.ddr_opt = 0x0,
		.bad_block_flag_position = FIRST_TWO_PAGES,
		.multi_plane_block_offset = 1,
		.cmd_set_no = CMD_SET_0,
		.selected_write_boot0_no = NAND_WRITE_BOOT0_GENERIC,
		.selected_readretry_no = NAND_READRETRY_NO,
		.ddr_info_no = 0,
		.id_number = 0x0,
		.max_blk_erase_times = 60000,
		.access_high_freq = 30,
	},
};

struct nand_manufacture mfr_tbl[] = {
	NAND_MANUFACTURE(NAND_MFR_MICRON, MICRON_NAME, raw_micron),
	NAND_MANUFACTURE(NAND_MFR_SPANSION, SPANSION_NAME, raw_spansion),
	NAND_MANUFACTURE(NAND_MFR_SANDISK, SANDISK_NAME, raw_sandisk),
	NAND_MANUFACTURE(NAND_MFR_TOSHIBA, TOSHIBA_NAME, raw_toshiba),
	NAND_MANUFACTURE(NAND_MFR_ESMT, ESMT_NAME, raw_esmt),
	NAND_MANUFACTURE(NAND_MFR_INTEL, INTEL_NAME, raw_intel),
	NAND_MANUFACTURE(NAND_MFR_GIGA, GIGA_NAME, raw_giga),
	NAND_MANUFACTURE(NAND_MFR_MXIC, MXIC_NAME, raw_mxic),
	NAND_MANUFACTURE(NAND_MFR_FORESEE, FORESEE_NAME, raw_foresee),
	NAND_MANUFACTURE(NAND_MFR_SAMSUNG, SAMSUNG_NAME, raw_samsung),
};

struct sunxi_nand_flash_device *sunxi_search_idtab_by_id(unsigned char *id)
{
	int m = 0;
	int d = 0;
	int i = 0;
	u8 mfr_id = id[0];
	u8 dev_id = id[1];
	int cnt = 0;
	int match_id_cnt = 0;
	struct sunxi_nand_flash_device *match = NULL;

	for (m = 0; m < sizeof(mfr_tbl) / sizeof(struct nand_manufacture); m++) {
		struct nand_manufacture *mfr = &mfr_tbl[m];

		if (mfr_id == mfr->id) {
			for (d = 0; d < mfr->ndev; d++) {
				struct sunxi_nand_flash_device *dev =
					&mfr->dev[d];
				cnt = 0;
				if (dev_id == dev->dev_id) {
					for (i = 0; i < NAND_MAX_ID_LEN; i++) {
						if (dev->id[i] == id[i])
							cnt++;
						else
							break;
					}
					if (cnt > match_id_cnt) {
						if (cnt >= NAND_MIN_ID_LEN) {
							match = dev;
							match_id_cnt = cnt;
						}
					}
				}
			}
		}
	}

	return match;
}

struct sunxi_nand_flash_device *sunxi_search_idtab_by_name(char *mfr_name, char *device_name)
{
	int m = 0;
	int d = 0;
	struct sunxi_nand_flash_device *match = NULL;

	for (m = 0; m < sizeof(mfr_tbl) / sizeof(struct nand_manufacture); m++) {
		struct nand_manufacture *mfr = &mfr_tbl[m];
		if (!memcmp(mfr_name, mfr->name, strlen(mfr->name))) {
			for (d = 0; d < mfr->ndev; d++) {
				struct sunxi_nand_flash_device *dev =
					&mfr->dev[d];
				if (!memcmp(device_name, dev->name, strlen(dev->name))) {
					match = dev;
				} else if (dev->operation_opt & NAND_FIND_ID_TAB_BY_NAME_CANCEL) {
					match = dev;
				}
			}
		}
	}

	return match;
}
/**
 * sunxi_search_id: search id is id table
 * @id : this id is read from device
 * */
struct sunxi_nand_flash_device *sunxi_search_id(struct nand_chip_info *nci,
		unsigned char *id)
{
	/*
	 *int m = 0;
	 *int d = 0;
	 *int i = 0;
	 *u8 mfr_id = id[0];
	 *u8 dev_id = id[1];
	 *int match_id_cnt = 0;
	 */
	struct sunxi_nand_flash_device *match = NULL;
	unsigned char *mem = NULL;
	char *device_name = NULL;
	int ret = 0;
	unsigned int nand_close_model_match = 0;

	mem = malloc_align(REVISION_FEATURES_BLOCK_INFO_PARAMETER_LEN, 64);
	if (!mem) {
		RAWNAND_ERR("malloc buffer fail in %s %d\n", __func__, __LINE__);
		goto err0;
	}

	memset(mem, 0, REVISION_FEATURES_BLOCK_INFO_PARAMETER_LEN);

	device_name = (char *)&mem[MCIRON_DEVICE_MODEL_OFFSET];

	match = sunxi_search_idtab_by_id(id);
	if (!match) {
		goto err0;
	}

	/*micron: different flash have the same id, find the id table by name(device model)*/
	if (match->mfr_id == NAND_MFR_MICRON) {
		if (match->operation_opt & NAND_FIND_ID_TAB_BY_NAME) {
			nand_close_model_match = nand_fdt_get_uint("/soc/nand0",
					"nand0_close_model_match");
			if (nand_close_model_match != 1) {
				ret = rawnand_read_parameter_page(nci, mem);
				if (ret != NAND_OP_TRUE) {
					RAWNAND_ERR("rawnand read parameter fail ret:%d\n", ret);
					goto err0;
				}

				RAWNAND_INFO("device model from flash:%s\n", device_name);
				match = sunxi_search_idtab_by_name(MICRON_NAME, device_name);
			}
		}
	}

	RAWNAND_INFO("match the device from idtab:%s\n", match ? match->name : "null");
err0:
	return match;
}

int generic_is_lsb_page(__u32 page_num) //0x00
{
	return 1;
}

int hynix20nm_is_lsb_page(__u32 page_num) //0x01
{
	struct nand_chip_info *nci = g_nsi->nci;

	//hynix 20nm
	if ((page_num == 0) || (page_num == 1))
		return 1;
	if ((page_num == nci->npi->page_cnt_per_blk - 2) || (page_num == nci->npi->page_cnt_per_blk - 1))
		return 0;
	if ((page_num % 4 == 2) || (page_num % 4 == 3))
		return 1;
	return 0;
}

int hynix26nm_is_lsb_page(__u32 page_num) //0x01
{
	struct nand_chip_info *nci = g_nsi->nci;

	//hynix 26nm
	if ((page_num == 0) || (page_num == 1))
		return 1;
	if ((page_num == nci->npi->page_cnt_per_blk - 2) || (page_num == nci->npi->page_cnt_per_blk - 1))
		return 0;
	if ((page_num % 4 == 2) || (page_num % 4 == 3))
		return 1;
	return 0;
}

int hynix16nm_is_lsb_page(__u32 page_num) //0x02
{
	__u32 pages_per_block;
	//	__u32 read_retry_type;
	struct nand_chip_info *nci = g_nsi->nci;

	pages_per_block = nci->page_cnt_per_blk;

	if (page_num == 0)
		return 1;
	if (page_num == pages_per_block - 1)
		return 0;
	if (page_num % 2 == 1)
		return 1;
	return 0;
}

int toshiba_is_lsb_page(__u32 page_num) //0x10
{
	struct nand_chip_info *nci = g_nsi->nci;

	//toshiba 2xnm 19nm 1ynm
	if (page_num == 0)
		return 1;
	if (page_num == nci->npi->page_cnt_per_blk - 1)
		return 0;
	if (page_num % 2 == 1)
		return 1;
	return 0;
}

int samsung_is_lsb_page(__u32 page_num) //0x20
{
	struct nand_chip_info *nci = g_nsi->nci;

	//(NAND_LSBPAGE_TYPE == 0x20) //samsung 25nm
	if (page_num == 0)
		return 1;
	if (page_num == nci->npi->page_cnt_per_blk - 1)
		return 0;
	if (page_num % 2 == 1)
		return 1;
	return 0;
}
int sandisk_is_lsb_page(__u32 page_num) //0x30
{
	struct nand_chip_info *nci = g_nsi->nci;

	//sandisk 2xnm 19nm 1ynm
	if (page_num == 0)
		return 1;
	if (page_num == nci->npi->page_cnt_per_blk - 1)
		return 0;
	if (page_num % 2 == 1)
		return 1;
	return 0;
}

int micron_0x40_is_lsb_page(__u32 page_num) // 20nm (29f64g08cbaba) 0x40
{
	struct nand_chip_info *nci = g_nsi->nci;

	if ((page_num == 0) || (page_num == 1))
		return 1;
	if ((page_num == nci->npi->page_cnt_per_blk - 2) || (page_num == nci->npi->page_cnt_per_blk - 1))
		return 0;
	if ((page_num % 4 == 2) || (page_num % 4 == 3))
		return 1;
	return 0;
}

int micron_0x41_is_lsb_page(__u32 page_num) //20nm (29f32g08cbada) 0x41
{
	struct nand_chip_info *nci = g_nsi->nci;

	//micron 20nm L83A L84A L84C L84D L85A L85C
	if ((page_num == 2) || (page_num == 3))
		return 1;
	if ((page_num == nci->npi->page_cnt_per_blk - 2) || (page_num == nci->npi->page_cnt_per_blk - 1))
		return 1;
	if ((page_num % 4 == 0) || (page_num % 4 == 1))
		return 1;
	return 0;
}

int micron_0x42_is_lsb_page(__u32 page_num) // 16nm l95b 0x42
{
	//	struct nand_chip_info *nci = g_nsi->nci;

	//micron 16nm l95b
	if ((page_num == 0) || (page_num == 1) || (page_num == 2) || (page_num == 3) || (page_num == 4) || (page_num == 5) || (page_num == 7) || (page_num == 8) || (page_num == 509))
		return 1;
	if ((page_num == 6) || (page_num == 508) || (page_num == 511))
		return 0;
	if ((page_num % 4 == 2) || (page_num % 4 == 3))
		return 1;
	return 0;
}

int micron_0x43_is_lsb_page(__u32 page_num) // L04A
{
	if ((page_num < 16) || ((page_num > 495) && (page_num < 512)))
		return 1;
	if (page_num % 2 == 0)
		return 1;
	if (page_num % 2 == 1)
		return 0;
	return 0;
}

int micron_0x44_is_lsb_page(__u32 page_num) // L06B
{
	if (page_num < 64)
		return 1;
	if (page_num % 2 == 0)
		return 0;
	if (page_num % 2 == 1)
		return 1;
	return 0;
}

lsb_page_t chose_lsb_func(__u32 no)
{
	no = (no << LSB_PAGE_POS);

	switch (no) {
	case GENERIC_LSB_PAGE:
		return generic_is_lsb_page;
	case HYNIX20_26NM_LSB_PAGE:
		return hynix20nm_is_lsb_page;
	case HYNIX16NM_LSB_PAGE:
		return hynix16nm_is_lsb_page;
	case TOSHIBA_LSB_PAGE:
		return toshiba_is_lsb_page;
	case SAMSUNG_LSB_PAGE:
		return samsung_is_lsb_page;
	case SANDISK_LSB_PAGE:
		return sandisk_is_lsb_page;
	case MICRON_0x40_LSB_PAGE:
		return micron_0x40_is_lsb_page;
	case MICRON_0x41_LSB_PAGE:
		return micron_0x41_is_lsb_page;
	case MICRON_0x42_LSB_PAGE:
		return micron_0x42_is_lsb_page;
	case MICRON_0x43_LSB_PAGE:
		return micron_0x43_is_lsb_page;
	case MICRON_0x44_LSB_PAGE:
		return micron_0x44_is_lsb_page;
	default:
		return generic_is_lsb_page;
	}
	return generic_is_lsb_page;
}

struct sunxi_nand_flash_device selected_id_tbl;

struct nfc_init_ddr_info def_ddr_info[] = {
	////////////////////////////
	{
		0, //en_dqs_c;
		0, //en_re_c;
		0, //odt;
		0, //en_ext_verf;
		0, //dout_re_warmup_cycle;
		0, //din_dqs_warmup_cycle;
		0, //output_driver_strength;
		0, //rb_pull_down_strength;
	},
	////////////////////////////
	{
		0, //en_dqs_c;
		0, //en_re_c;
		0, //odt;
		0, //en_ext_verf;
		0, //dout_re_warmup_cycle;
		0, //din_dqs_warmup_cycle;
		2, //output_driver_strength;
		2, //rb_pull_down_strength;
	},
	////////////////////////////
};

