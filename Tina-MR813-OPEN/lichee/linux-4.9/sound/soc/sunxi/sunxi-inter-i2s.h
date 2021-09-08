/*
 * sound\soc\sunxi\sunxi-i2s.h
 * (C) Copyright 2010-2017
 * Reuuimlla Technology Co., Ltd. <www.reuuimllatech.com>
 * huangxin <huangxin@Reuuimllatech.com>
 *
 * some simple description for this code
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 */

#ifndef __SUNXI_I2S_H__
#define __SUNXI_I2S_H__

#include "sunxi-pcm.h"

struct sunxi_i2s {
	struct clk *pllclk;
	struct clk *moduleclk;
	struct clk *ac_rst;
	void __iomem  *membase;
	bool hub_mode;
	struct sunxi_dma_params play_dma_param;
	struct sunxi_dma_params capture_dma_param;
	struct snd_soc_dai_driver dai;
#ifdef CONFIG_SND_SUNXI_MAD
	struct resource res;
	unsigned int mad_bind;
	unsigned int lpsd_chan_sel;
	unsigned int mad_standby_chan_sel;
	unsigned int audio_src_chan_num;
	unsigned int capture_en;
#endif
};
#endif
