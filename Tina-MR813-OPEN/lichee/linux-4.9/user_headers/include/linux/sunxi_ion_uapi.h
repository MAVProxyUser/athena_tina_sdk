/*
 * drivers/staging/android/ion/sunxi/sunxi_ion.h
 *
 * Copyright(c) 2015-2020 Allwinnertech Co., Ltd.
 *      http://www.allwinnertech.com
 *
 * Author: Wim Hwang <huangwei@allwinnertech.com>
 *
 * sunxi ion header file
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef _LINUX_ION_SUNXI_H
#define _LINUX_ION_SUNXI_H

struct sunxi_cache_range {
	long start;
	long end;
};

//typedef int ion_user_handle_t;

typedef struct sunxi_phys_data {
	ion_user_handle_t handle;
	unsigned int phys_addr;
	unsigned int size;
} sunxi_phys_data;

#define ION_IOC_SUNXI_FLUSH_RANGE           5
#define ION_IOC_SUNXI_PHYS_ADDR             7
#define ION_IOC_SUNXI_TEE_ADDR              17

#ifdef CONFIG_SUNXI_ION_DEBUG
extern unsigned long bitmap_size;
extern unsigned long *sys_user_bitmap;
#endif

#endif
