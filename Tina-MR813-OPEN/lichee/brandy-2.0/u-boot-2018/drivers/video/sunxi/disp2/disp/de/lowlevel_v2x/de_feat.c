/*
 * drivers/video/sunxi/disp2/disp/de/lowlevel_v2x/de_feat.c
 *
 * Copyright (c) 2007-2019 Allwinnertech Co., Ltd.
 * Author: zhengxiaobin <zhengxiaobin@allwinnertech.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#include "de_feat.h"

static const struct de_feat *de_cur_features;

#if defined(CONFIG_MACH_SUN8IW15)
static const int sun8iw15_de_num_chns[] = {
	/* DISP0 */
	4,
};

static const int sun8iw15_de_num_vi_chns[] = {
	/* DISP0 */
	1,
};

static const int sun8iw15_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
};

static const int sun8iw15_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
};

static const int sun8iw15_de_is_support_smbl[] = {
	/* CH0 */
	1,
	/* CH1 */
	0,
};

static const int sun8iw15_de_supported_output_types[] = {
	/* tcon0 */
	DE_OUTPUT_TYPE_LCD,
};

static const int sun8iw15_de_is_support_wb[] = {
	/* DISP0 */
	1,
};

static const int sun8iw15_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
};

static const int sun8iw15_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	2560,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
};

static const int sun8iw15_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2560,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
};

static const int sun8iw15_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2560,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
};

static const struct de_feat sun8iw15_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun8iw15_de_num_chns,
	.num_vi_chns = sun8iw15_de_num_vi_chns,
	.num_layers = sun8iw15_de_num_layers,
	.is_support_vep = sun8iw15_de_is_support_vep,
	.is_support_smbl = sun8iw15_de_is_support_smbl,
	.is_support_wb = sun8iw15_de_is_support_wb,
	.supported_output_types = sun8iw15_de_supported_output_types,
	.is_support_scale = sun8iw15_de_is_support_scale,
	.scale_line_buffer_yuv = sun8iw15_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun8iw15_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun8iw15_de_scale_line_buffer_ed,
};
#endif /*endif CONFIG_MACH_SUN8IW15*/

#if defined(CONFIG_MACH_SUN8IW7)
static const int sun8iw7_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	2,
};

static const int sun8iw7_de_num_vi_chns[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	1,
};

static const int sun8iw7_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
};

static const int sun8iw7_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
};

static const int sun8iw7_de_is_support_smbl[] = {
	/* CH0 */
	0,
	/* CH1 */
	0,
};

static const int sun8iw7_de_supported_output_types[] = {
	/* DISP0 */
	DE_OUTPUT_TYPE_HDMI,
	/* DISP1 */
	DE_OUTPUT_TYPE_TV,
};

static const int sun8iw7_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	0,
};

static const int sun8iw7_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
};

static const int sun8iw7_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw7_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw7_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const struct de_feat sun8iw7_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun8iw7_de_num_chns,
	.num_vi_chns = sun8iw7_de_num_vi_chns,
	.num_layers = sun8iw7_de_num_layers,
	.is_support_vep = sun8iw7_de_is_support_vep,
	.is_support_smbl = sun8iw7_de_is_support_smbl,
	.is_support_wb = sun8iw7_de_is_support_wb,
	.supported_output_types = sun8iw7_de_supported_output_types,
	.is_support_scale = sun8iw7_de_is_support_scale,
	.scale_line_buffer_yuv = sun8iw7_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun8iw7_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun8iw7_de_scale_line_buffer_ed,
};

#endif /*endif CONFIG_MACH_SUN8IW7 */


#if defined(CONFIG_MACH_SUN8IW6)
static const int sun8iw6_de_num_chns[] = {
	4,
	2,
};
static const int sun8iw6_de_num_vi_chns[] = {
	1,
	1,
};
static const int sun8iw6_de_num_layers[] = {
	4,
	4,
	4,
	4,
	4,
	4,
};
static const int sun8iw6_de_is_support_vep[] = {
	1,
	0,
	0,
	0,
	0,
	0,
};
static const int sun8iw6_de_is_support_smbl[] = {
	1,
	0,
};
static const int sun8iw6_de_supported_output_types[] = {
	DE_OUTPUT_TYPE_LCD,
	DE_OUTPUT_TYPE_HDMI ,
};
static const int sun8iw6_de_is_support_wb[] = {
	1,
	0,
};
static const int sun8iw6_de_is_support_scale[] = {
	1,
	1,
	1,
	1,
	1,
	1,
};

static const int sun8iw6_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw6_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw6_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const struct de_feat sun8iw6_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun8iw6_de_num_chns,
	.num_vi_chns = sun8iw6_de_num_vi_chns,
	.num_layers = sun8iw6_de_num_layers,
	.is_support_vep = sun8iw6_de_is_support_vep,
	.is_support_smbl = sun8iw6_de_is_support_smbl,
	.is_support_wb = sun8iw6_de_is_support_wb,
	.supported_output_types = sun8iw6_de_supported_output_types,
	.is_support_scale = sun8iw6_de_is_support_scale,
	.scale_line_buffer_yuv = sun8iw6_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun8iw6_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun8iw6_de_scale_line_buffer_ed,
};
#endif

#if defined(CONFIG_MACH_SUN50IW2)
static const int sun50iw2_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	2,
};

static const int sun50iw2_de_num_vi_chns[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	1,
};

static const int sun50iw2_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
};

static const int sun50iw2_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
};

static const int sun50iw2_de_is_support_smbl[] = {
	/* CH0 */
	0,
	/* CH1 */
	0,
};

static const int sun50iw2_de_supported_output_types[] = {
	/* DISP0 */
#if defined(TCON1_DRIVE_PANEL)
	DE_OUTPUT_TYPE_LCD,
#else
	DE_OUTPUT_TYPE_HDMI,
#endif
	/* DISP1 */
	DE_OUTPUT_TYPE_TV,
};

static const int sun50iw2_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	0,
};

static const int sun50iw2_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
};

static const int sun50iw2_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	4096,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun50iw2_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun50iw2_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const struct de_feat sun50iw2_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun50iw2_de_num_chns,
	.num_vi_chns = sun50iw2_de_num_vi_chns,
	.num_layers = sun50iw2_de_num_layers,
	.is_support_vep = sun50iw2_de_is_support_vep,
	.is_support_smbl = sun50iw2_de_is_support_smbl,
	.is_support_wb = sun50iw2_de_is_support_wb,
	.supported_output_types = sun50iw2_de_supported_output_types,
	.is_support_scale = sun50iw2_de_is_support_scale,
	.scale_line_buffer_yuv = sun50iw2_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun50iw2_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun50iw2_de_scale_line_buffer_ed,
};
#endif

#if defined(CONFIG_MACH_SUN50IW1)
static const int sun50iw1_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	2,
};

static const int sun50iw1_de_num_vi_chns[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	1,
};

static const int sun50iw1_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
};

static const int sun50iw1_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
};

static const int sun50iw1_de_is_support_smbl[] = {
	/* CH0 */
	1,
	/* CH1 */
	0,
};

static const int sun50iw1_de_supported_output_types[] = {
	/* DISP0 */
	DE_OUTPUT_TYPE_LCD,
	/* DISP1 */
	DE_OUTPUT_TYPE_HDMI,
};

static const int sun50iw1_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	0,
};

static const int sun50iw1_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
};

static const int sun50iw1_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	4096,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun50iw1_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun50iw1_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const struct de_feat sun50iw1_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun50iw1_de_num_chns,
	.num_vi_chns = sun50iw1_de_num_vi_chns,
	.num_layers = sun50iw1_de_num_layers,
	.is_support_vep = sun50iw1_de_is_support_vep,
	.is_support_smbl = sun50iw1_de_is_support_smbl,
	.is_support_wb = sun50iw1_de_is_support_wb,
	.supported_output_types = sun50iw1_de_supported_output_types,
	.is_support_scale = sun50iw1_de_is_support_scale,
	.scale_line_buffer_yuv = sun50iw1_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun50iw1_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun50iw1_de_scale_line_buffer_ed,
};
#endif

#if defined(CONFIG_MACH_SUN8IW11)
static const int sun8iw11_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	2,
};

static const int sun8iw11_de_num_vi_chns[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	1,
};

static const int sun8iw11_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
};

static const int sun8iw11_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
};

static const int sun8iw11_de_is_support_smbl[] = {
	/* CH0 */
	1,
	/* CH1 */
	0,
};

static const int sun8iw11_de_supported_output_types[] = {
	/* tcon0 */
	DE_OUTPUT_TYPE_LCD,
	/* tcon0 */
	DE_OUTPUT_TYPE_LCD,
	/* tcon2 */
	DE_OUTPUT_TYPE_TV | DE_OUTPUT_TYPE_HDMI | DE_OUTPUT_TYPE_VGA,
	/* tcon3 */
	DE_OUTPUT_TYPE_TV | DE_OUTPUT_TYPE_HDMI | DE_OUTPUT_TYPE_VGA,
};

static const int sun8iw11_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	0,
};

static const int sun8iw11_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
};

static const int sun8iw11_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw11_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw11_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const struct de_feat sun8iw11_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun8iw11_de_num_chns,
	.num_vi_chns = sun8iw11_de_num_vi_chns,
	.num_layers = sun8iw11_de_num_layers,
	.is_support_vep = sun8iw11_de_is_support_vep,
	.is_support_smbl = sun8iw11_de_is_support_smbl,
	.is_support_wb = sun8iw11_de_is_support_wb,
	.supported_output_types = sun8iw11_de_supported_output_types,
	.is_support_scale = sun8iw11_de_is_support_scale,
	.scale_line_buffer_yuv = sun8iw11_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun8iw11_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun8iw11_de_scale_line_buffer_ed,
};
#endif

#if defined(CONFIG_MACH_SUN50IW10)
static const int sun50iw10_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	3,
};

static const int sun50iw10_de_num_vi_chns[] = {
	/* DISP0 */
	2,
	/* DISP1 */
	1,
};

static const int sun50iw10_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
	/* DISP1 CH2 */
	4,
};

static const int sun50iw10_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
	/* DISP1 CH2 */
	0,
};

static const int sun50iw10_de_is_support_smbl[] = {
	/* CH0 */
	1,
	/* CH1 */
	0,
};

static const int sun50iw10_de_supported_output_types[] = {
	/* tcon0 */
	DE_OUTPUT_TYPE_LCD,
	/* tcon1 */
	DE_OUTPUT_TYPE_LCD,
};

static const int sun50iw10_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	1,
};

static const int sun50iw10_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
	/* DISP1 CH2 */
	1,
};

static const int sun50iw10_de_scale_line_buffer[] = {
	/* DISP0 CH0*/
	2560,
	/* DISP0 CH1*/
	2048,
	/* DISP0 CH2*/
	2048,
	/* DISP0 CH3*/
	2048,
	/* DISP1 CH0*/
	2048,
	/* DISP1 CH1*/
	2048,
	/* DISP1 CH2*/
	2048,
};

static const struct de_feat sun50iw10_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun50iw10_de_num_chns,
	.num_vi_chns = sun50iw10_de_num_vi_chns,
	.num_layers = sun50iw10_de_num_layers,
	.is_support_vep = sun50iw10_de_is_support_vep,
	.is_support_smbl = sun50iw10_de_is_support_smbl,
	.is_support_wb = sun50iw10_de_is_support_wb,
	.supported_output_types = sun50iw10_de_supported_output_types,
	.is_support_scale = sun50iw10_de_is_support_scale,
	.scale_line_buffer_yuv = sun50iw10_de_scale_line_buffer,
	.scale_line_buffer_rgb = sun50iw10_de_scale_line_buffer,
	.scale_line_buffer_ed = sun50iw10_de_scale_line_buffer,
};
#endif /*~ CONFIG_MACH_SUN50IW10*/

#if defined(CONFIG_MACH_SUN8IW12) || defined(CONFIG_MACH_SUN8IW16) \
	|| defined(CONFIG_MACH_SUN8IW19)
static const int sun8iw12_de_num_chns[] = {
	/* DISP0 */
	4,
};

static const int sun8iw12_de_num_vi_chns[] = {
	/* DISP0 */
	2,
};

static const int sun8iw12_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
};

static const int sun8iw12_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
};

static const int sun8iw12_de_is_support_smbl[] = {
	/* CH0 */
	1,
};

static const int sun8iw12_de_supported_output_types[] = {
	/* tcon0 */
	DE_OUTPUT_TYPE_LCD,
	/* tcon1 */
	DE_OUTPUT_TYPE_TV | DE_OUTPUT_TYPE_HDMI,

};

static const int sun8iw12_de_is_support_wb[] = {
	/* DISP0 */
	1,
};

static const int sun8iw12_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
};

static const int sun8iw12_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
#if defined(CONFIG_MACH_SUN8IW19)
	2048,
#else
	4096,
#endif
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
};

static const int sun8iw12_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	4096,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
};

static const int sun8iw12_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	4096,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
};

static const struct de_feat sun8iw12_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun8iw12_de_num_chns,
	.num_vi_chns = sun8iw12_de_num_vi_chns,
	.num_layers = sun8iw12_de_num_layers,
	.is_support_vep = sun8iw12_de_is_support_vep,
	.is_support_smbl = sun8iw12_de_is_support_smbl,
	.is_support_wb = sun8iw12_de_is_support_wb,
	.supported_output_types = sun8iw12_de_supported_output_types,
	.is_support_scale = sun8iw12_de_is_support_scale,
	.scale_line_buffer_yuv = sun8iw12_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun8iw12_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun8iw12_de_scale_line_buffer_ed,
};
#endif

#if defined(CONFIG_MACH_SUN8IW17)
static const int sun8iw17_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	2,
};

static const int sun8iw17_de_num_vi_chns[] = {
	/* DISP0 */
	2,
	/* DISP1 */
	1,
};

static const int sun8iw17_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
};

static const int sun8iw17_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
};

static const int sun8iw17_de_is_support_smbl[] = {
	/* CH0 */
	1,
	/* CH1 */
	0,
};

static const int sun8iw17_de_supported_output_types[] = {
	/* tcon0 */
	DE_OUTPUT_TYPE_LCD,
	/* tcon1 */
	DE_OUTPUT_TYPE_LCD,
	/* tcon2 */
	DE_OUTPUT_TYPE_TV | DE_OUTPUT_TYPE_HDMI,
};

static const int sun8iw17_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	0,
};

static const int sun8iw17_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
};

static const int sun8iw17_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw17_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int sun8iw17_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const struct de_feat sun8iw17_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = sun8iw17_de_num_chns,
	.num_vi_chns = sun8iw17_de_num_vi_chns,
	.num_layers = sun8iw17_de_num_layers,
	.is_support_vep = sun8iw17_de_is_support_vep,
	.is_support_smbl = sun8iw17_de_is_support_smbl,
	.is_support_wb = sun8iw17_de_is_support_wb,
	.supported_output_types = sun8iw17_de_supported_output_types,
	.is_support_scale = sun8iw17_de_is_support_scale,
	.scale_line_buffer_yuv = sun8iw17_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = sun8iw17_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = sun8iw17_de_scale_line_buffer_ed,
};
#endif

static const int default_de_num_chns[] = {
	/* DISP0 */
	4,
	/* DISP1 */
	2,
};

static const int default_de_num_vi_chns[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	1,
};

static const int default_de_num_layers[] = {
	/* DISP0 CH0 */
	4,
	/* DISP0 CH1 */
	4,
	/* DISP0 CH2 */
	4,
	/* DISP0 CH3 */
	4,
	/* DISP1 CH0 */
	4,
	/* DISP1 CH1 */
	4,
};

static const int default_de_is_support_vep[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	0,
	/* DISP0 CH2 */
	0,
	/* DISP0 CH3 */
	0,
	/* DISP1 CH0 */
	0,
	/* DISP1 CH1 */
	0,
};

static const int default_de_is_support_smbl[] = {
	/* CH0 */
	1,
	/* CH1 */
	0,
};

static const int default_de_supported_output_types[] = {
	/* DISP0 */
	DE_OUTPUT_TYPE_LCD,
	/* DISP1 */
	DE_OUTPUT_TYPE_HDMI,
};

static const int default_de_is_support_wb[] = {
	/* DISP0 */
	1,
	/* DISP1 */
	0,
};

static const int default_de_is_support_scale[] = {
	/* DISP0 CH0 */
	1,
	/* DISP0 CH1 */
	1,
	/* DISP0 CH2 */
	1,
	/* DISP0 CH3 */
	1,
	/* DISP1 CH0 */
	1,
	/* DISP1 CH1 */
	1,
};

static const int default_de_scale_line_buffer_yuv[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int default_de_scale_line_buffer_rgb[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

static const int default_de_scale_line_buffer_ed[] = {
	/* DISP0 CH0 */
	2048,
	/* DISP0 CH1 */
	2048,
	/* DISP0 CH2 */
	2048,
	/* DISP0 CH3 */
	2048,
	/* DISP1 CH0 */
	2048,
	/* DISP1 CH1 */
	2048,
};

__attribute__((unused)) static const struct de_feat default_de_features = {
	.num_screens = DE_NUM,
	.num_devices = DEVICE_NUM,
	.num_chns = default_de_num_chns,
	.num_vi_chns = default_de_num_vi_chns,
	.num_layers = default_de_num_layers,
	.is_support_vep = default_de_is_support_vep,
	.is_support_smbl = default_de_is_support_smbl,
	.is_support_wb = default_de_is_support_wb,
	.supported_output_types = default_de_supported_output_types,
	.is_support_scale = default_de_is_support_scale,
	.scale_line_buffer_yuv = default_de_scale_line_buffer_yuv,
	.scale_line_buffer_rgb = default_de_scale_line_buffer_rgb,
	.scale_line_buffer_ed = default_de_scale_line_buffer_ed,
};

int de_feat_get_num_screens(void)
{
	return de_cur_features->num_screens;
}

int de_feat_get_num_devices(void)
{
	return de_cur_features->num_devices;
}

int de_feat_get_num_chns(unsigned int disp)
{
	return de_cur_features->num_chns[disp];
}

int de_feat_get_num_vi_chns(unsigned int disp)
{
	return de_cur_features->num_vi_chns[disp];
}

int de_feat_get_num_ui_chns(unsigned int disp)
{
	return de_cur_features->num_chns[disp] -
	    de_cur_features->num_vi_chns[disp];
}

int de_feat_get_num_layers(unsigned int disp)
{
	unsigned int i, index = 0, num_channels = 0;
	int num_layers = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);

	num_channels = de_feat_get_num_chns(disp);
	for (i = 0; i < num_channels; i++, index++)
		num_layers += de_cur_features->num_layers[index];

	return num_layers;
}

int de_feat_get_num_layers_by_chn(unsigned int disp, unsigned int chn)
{
	unsigned int i, index = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;
	if (chn >= de_feat_get_num_chns(disp))
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);
	index += chn;

	return de_cur_features->num_layers[index];
}

int de_feat_is_support_vep(unsigned int disp)
{
	unsigned int i, index = 0, num_channels = 0;
	int is_support_vep = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);

	num_channels = de_feat_get_num_chns(disp);
	for (i = 0; i < num_channels; i++, index++)
		is_support_vep += de_cur_features->is_support_vep[index];

	return is_support_vep;
}

int de_feat_is_support_vep_by_chn(unsigned int disp, unsigned int chn)
{
	unsigned int i, index = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;
	if (chn >= de_feat_get_num_chns(disp))
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);
	index += chn;

	return de_cur_features->is_support_vep[index];
}

int de_feat_is_support_smbl(unsigned int disp)
{
	return de_cur_features->is_support_smbl[disp];
}

int de_feat_is_supported_output_types(unsigned int disp,
				      unsigned int output_type)
{
	return de_cur_features->supported_output_types[disp] & output_type;
}

int de_feat_is_support_wb(unsigned int disp)
{
	return de_cur_features->is_support_wb[disp];
}

int de_feat_is_support_scale(unsigned int disp)
{
	unsigned int i, index = 0, num_channels = 0;
	int is_support_scale = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);

	num_channels = de_feat_get_num_chns(disp);
	for (i = 0; i < num_channels; i++, index++)
		is_support_scale += de_cur_features->is_support_scale[index];

	return is_support_scale;
}

int de_feat_is_support_scale_by_chn(unsigned int disp, unsigned int chn)
{
	unsigned int i, index = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;
	if (chn >= de_feat_get_num_chns(disp))
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);
	index += chn;

	return de_cur_features->is_support_scale[index];
}

int de_feat_get_scale_linebuf_for_yuv(unsigned int disp, unsigned int chn)
{
	unsigned int i, index = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;
	if (chn >= de_feat_get_num_chns(disp))
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);
	index += chn;

	return de_cur_features->scale_line_buffer_yuv[index];
}

int de_feat_get_scale_linebuf_for_rgb(unsigned int disp, unsigned int chn)
{
	unsigned int i, index = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;
	if (chn >= de_feat_get_num_chns(disp))
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);
	index += chn;

	return de_cur_features->scale_line_buffer_rgb[index];
}

int de_feat_get_scale_linebuf_for_ed(unsigned int disp, unsigned int chn)
{
	unsigned int i, index = 0;

	if (disp >= de_feat_get_num_screens())
		return 0;
	if (chn >= de_feat_get_num_chns(disp))
		return 0;

	for (i = 0; i < disp; i++)
		index += de_feat_get_num_chns(i);
	index += chn;

	return de_cur_features->scale_line_buffer_ed[index];
}

/**
 * @name       :de_feat_get_tcon_type
 * @brief      :get tcon type
 * @param[IN]  :tcon_index:index of tcon in software
 * @return     :0->tcon_lcd,1->tcon_tv
 */
unsigned int de_feat_get_tcon_type(unsigned int tcon_index)
{
	return (de_cur_features->supported_output_types[tcon_index] &
		DE_OUTPUT_TYPE_LCD)
		   ? 0
		   : 1;
}

/**
 * @name       :de_feat_get_tcon_index
 * @brief      :get tcon index of spec of display if top
 * @param[IN]  :tcon_index:tcon index of software
 * @return     :return a positive index,-1 if fail to find one
 */
int de_feat_get_tcon_index(unsigned int tcon_index)
{
	unsigned int i = 0, tcon_type = 0;

	tcon_type = de_feat_get_tcon_type(tcon_index);

	for (i = 0; i < DEVICE_NUM; ++i) {
		if (de_feat_get_tcon_type(i) == tcon_type)
			return tcon_index - i;
	}
	return -1;
}

int de_feat_init(void)
{
#if defined(CONFIG_MACH_SUN50IW2)
	de_cur_features = &sun50iw2_de_features;
#elif defined(CONFIG_MACH_SUN50IW1)
	de_cur_features = &sun50iw1_de_features;
#elif defined(CONFIG_MACH_SUN8IW11)
	de_cur_features = &sun8iw11_de_features;
#elif defined(CONFIG_MACH_SUN8IW12) || defined(CONFIG_MACH_SUN8IW16) \
	|| defined(CONFIG_MACH_SUN8IW19)
	de_cur_features = &sun8iw12_de_features;
#elif defined(CONFIG_MACH_SUN50IW10)
	de_cur_features = &sun50iw10_de_features;
#elif defined(CONFIG_MACH_SUN8IW17)
	de_cur_features = &sun8iw17_de_features;
#elif defined(CONFIG_MACH_SUN8IW7)
	de_cur_features = &sun8iw7_de_features;
#elif defined(CONFIG_MACH_SUN8IW6)
	de_cur_features = &sun8iw6_de_features;
#elif defined(CONFIG_MACH_SUN8IW15)
	de_cur_features = &sun8iw15_de_features;
#else
#error "undefined platform!!!"
#endif
	return 0;
}
