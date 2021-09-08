/*
 * rawnand_base.c for sunxi rawnand base
 *
 * Copyright (C) 2019 Allwinner.
 * SPDX-License-Identifier: GPL-2.0
 */
#include "../../aw_nand_type.h"
#include "controller/ndfc_base.h"

extern struct _nand_temp_buf ntf;
extern struct _nand_permanent_data nand_permanent_data;

extern u8 *nand_get_temp_buf(unsigned int size);
extern int nand_free_temp_buf(unsigned char *buf, unsigned int size);
extern s32 nand_get_dma_desc(struct nand_controller_info *nctri);
extern s32 nand_free_dma_desc(struct nand_controller_info *nctri);
extern int nand_init_temp_buf(struct _nand_temp_buf *nand_temp_buf);
extern int (*nand_physic_special_init)(void);
extern int (*nand_physic_special_exit)(void);
struct _nand_info *RawNandHwInit(void);
int RawNandHwExit(void);
int RawNandHwSuperStandby(void);
int RawNandHwSuperResume(void);
int RawNandHwNormalStandby(void);
int RawNandHwNormalResume(void);
int RawNandHwShutDown(void);
int nand_read_scan_data(unsigned int chip, unsigned int block, unsigned int page, unsigned int bitmap, unsigned char *mbuf, unsigned char *sbuf);

int get_nand_structure(struct _nand_super_storage_info *nssi);
int rawnand_physic_erase_block(unsigned int chip, unsigned int block);
int rawnand_physic_write_page(unsigned int chip, unsigned int block, unsigned int page, unsigned int bitmap, unsigned char *mbuf, unsigned char *sbuf);
int rawnand_physic_read_page(unsigned int chip, unsigned int block, unsigned int page, unsigned int bitmap, unsigned char *mbuf, unsigned char *sbuf);
int rawnand_physic_read_boot0_page(unsigned int chip, unsigned int block, unsigned int page, unsigned int bitmap, unsigned char *mbuf, unsigned char *sbuf);
int rawnand_physic_erase_super_block(unsigned int chip, unsigned int block);
int rawnand_physic_write_super_page(unsigned int chip, unsigned int block, unsigned int page, unsigned int bitmap, unsigned char *mbuf, unsigned char *sbuf);
int rawnand_physic_read_super_page(unsigned int chip, unsigned int block, unsigned int page, unsigned int bitmap, unsigned char *mbuf, unsigned char *sbuf);
int rawnand_physic_super_bad_block_check(unsigned int chip, unsigned int block);
int rawnand_physic_super_bad_block_mark(unsigned int chip, unsigned int block);

struct physic_special_ops {
	int (*nand_physic_special_init)(void);
	int (*nand_physic_special_exit)(void);
};
extern struct physic_special_ops special_ops;
