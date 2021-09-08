/*
 * (C) Copyright 2018
 * wangwei <wangwei@allwinnertech.com>
 */

#ifndef  __boot0_v2_h
#define  __boot0_v2_h

#include <linux/types.h>
#include <spare_head.h>

#define BOOT0_MAGIC                     "eGON.BT0"
#define DRAM_EXT_MAGIC                 "DRAM.ext"
#define SYS_PARA_LOG                    0x4d415244

/******************************************************************************/
/*                              file head of Boot                             */
/******************************************************************************/
typedef struct _Boot_file_head
{
	__u32  jump_instruction;   /* one intruction jumping to real code */
	__u8   magic[MAGIC_SIZE];  /* ="eGON.BT0" */
	__u32  check_sum;          /* generated by PC */
	__u32  length;             /* generated by PC */
	__u32  pub_head_size;      /* the size of boot_file_head_t */
	__u8   pub_head_vsn[4];    /* the version of boot_file_head_t */
	__u32 ret_addr;           /* the return value */
	__u32  run_addr;           /* run addr */
	__u32  boot_cpu;           /* eGON version */
	__u8   platform[8];        /* platform information */
}boot_file_head_t;


/******************************************************************************/
/*                              file head of Boot0                            */
/******************************************************************************/
typedef struct _boot0_private_head_t
{
	__u32                       prvt_head_size;
	/*debug_mode = 0 : do not print any message,debug_mode = 1 ,print debug message*/
	__u8                        debug_mode;
	/*0:axp, 1: no axp  */
	__u8                        power_mode;
	__u8                        reserve[2];
	/*DRAM patameters for initialising dram. Original values is arbitrary*/
	unsigned int                dram_para[32];
	/*uart: num & uart pin*/
	__s32						uart_port;
	normal_gpio_cfg             uart_ctrl[2];
	/* jtag: 1 : enable,  0 : disable */
	__s32                       enable_jtag;
    normal_gpio_cfg	            jtag_gpio[5];
	/* nand/mmc pin*/
    normal_gpio_cfg             storage_gpio[32];
	/*reserve data*/
    char                        storage_data[512 - sizeof(normal_gpio_cfg) * 32];
}boot0_private_head_t;

typedef struct __fes_aide_info {
    __u32 dram_init_flag;       /* flag for Dram init */
    __u32 dram_update_flag;     /* flag for dram para */
    __u32 dram_paras[SUNXI_DRAM_PARA_MAX];
} fes_aide_info_t;

typedef struct _boot0_file_head_t
{
	boot_file_head_t      boot_head;
	boot0_private_head_t  prvt_head;
	char hash[64];
	__u8		      reserved[8];
	union {
#ifdef CFG_SUNXI_SELECT_DRAM_PARA
	boot_extend_head_t    extd_head;
#endif
	fes_aide_info_t fes1_res_addr;

	} fes_union_addr;
}boot0_file_head_t;

typedef struct _sboot_file_head_t
{
	boot_file_head_t      boot_head;
	char hash[32];
	char data[8];
	char res[24];
#ifdef CFG_SUNXI_SELECT_DRAM_PARA
	boot_extend_head_t	extd_head;
#endif
}sboot_file_head_t;

extern const sboot_file_head_t  sboot_head ;
extern const boot0_file_head_t BT0_head;
extern const boot0_file_head_t fes1_head;

#endif
