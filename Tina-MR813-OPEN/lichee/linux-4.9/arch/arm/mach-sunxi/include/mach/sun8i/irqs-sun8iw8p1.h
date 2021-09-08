/*
 * arch/arm/mach-sunxi/include/mach/sun8i/irqs-sun8iw8p1.h
 *
 * Copyright (c) 2013-2015 Allwinnertech Co., Ltd.
 *      http://www.allwinnertech.com
 *
 * Author: Sugar <shuge@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __IRQS_SUN8I_W8P1_H
#define __IRQS_SUN8I_W8P1_H

#if  defined(CONFIG_FPGA_V4_PLATFORM) \
	|| defined(CONFIG_FPGA_V7_PLATFORM) \
	|| defined(CONFIG_EVB_PLATFORM)

#define SUNXI_IRQ_UART0			(SUNXI_GIC_START + 0)   /* 32 Uart0     */
#define SUNXI_IRQ_UART1			(SUNXI_GIC_START + 1)   /* 33 Uart1     */
#define SUNXI_IRQ_UART2			(SUNXI_GIC_START + 2)   /* 34 Uart2     */
#define SUNXI_IRQ_TWI0			(SUNXI_GIC_START + 6)   /* 38 Twi0      */
#define SUNXI_IRQ_TWI1			(SUNXI_GIC_START + 7)   /* 39 Twi1      */
#define SUNXI_IRQ_IIS0			(SUNXI_GIC_START + 13)  /* 45 DAUDIO    */
#define SUNXI_IRQ_EINTB			(SUNXI_GIC_START + 15)  /* 47 PB_EINT   */
#define SUNXI_IRQ_EINTG       	(SUNXI_GIC_START + 17)  /* 49 PG_EINT   */
#define SUNXI_IRQ_TIMER0      	(SUNXI_GIC_START + 18)  /* 50 Timer0    */
#define SUNXI_IRQ_TIMER1      	(SUNXI_GIC_START + 19)  /* 51 Timer1    */
#define SUNXI_IRQ_TIMER2      	(SUNXI_GIC_START + 20)  /* 52 Timer2    */
#define SUNXI_IRQ_WATCHDOG    	(SUNXI_GIC_START + 25)  /* 57 Watchdog     */
#define SUNXI_IRQ_CODEC       	(SUNXI_GIC_START + 29)  /* 61 Audio Codec  */
#define SUNXI_IRQ_LRADC       	(SUNXI_GIC_START + 30)  /* 62 KeyADC       */
#define SUNXI_IRQ_NMI         	(SUNXI_GIC_START + 32)  /* 64 External NMI */
#define SUNXI_IRQ_ALARM0      	(SUNXI_GIC_START + 40)  /* 72 RLARM0       */
#define SUNXI_IRQ_ALARM1      	(SUNXI_GIC_START + 41)  /* 73 RLARM1       */
#define SUNXI_IRQ_HMIC        	(SUNXI_GIC_START + 46)  /* 78 HMIC         */
#define SUNXI_IRQ_DMA         	(SUNXI_GIC_START + 50)  /* 82 DMA          */
#define SUNXI_IRQ_HSTMR0      	(SUNXI_GIC_START + 51)  /* 83 HS Timer0    */
#define SUNXI_IRQ_HSTMR1      	(SUNXI_GIC_START + 52)  /* 84 HS Timer1    */
#define SUNXI_IRQ_VE			(SUNXI_GIC_START + 58)  /* 90 VE           */
#define SUNXI_IRQ_MMC0			(SUNXI_GIC_START + 60)  /* 92 SD/MMC0      */
#define SUNXI_IRQ_MMC1			(SUNXI_GIC_START + 61)  /* 93 SD/MMC1      */
#define SUNXI_IRQ_MMC2        	(SUNXI_GIC_START + 62)  /* 94 SD/MMC2      */
#define SUNXI_IRQ_SPI0        	(SUNXI_GIC_START + 65)  /* 97 SPI          */
#define SUNXI_IRQ_USBOTG      	(SUNXI_GIC_START + 71)  /* 103 USB-OTG     */
#define SUNXI_IRQ_USBEHCI0    	(SUNXI_GIC_START + 72)  /* 104 USB-EHCI    */
#define SUNXI_IRQ_USBOHCI0    	(SUNXI_GIC_START + 73)  /* 105 USB-OHCI    */
#define SUNXI_IRQ_SS          	(SUNXI_GIC_START + 80)  /* 112 SS   */
#define SUNXI_IRQ_GMAC        	(SUNXI_GIC_START + 82)  /* 114      */
#define SUNXI_IRQ_CSI0        	(SUNXI_GIC_START + 83)  /* 115 CSI0 */
#define SUNXI_IRQ_CSI1        	(SUNXI_GIC_START + 84)  /* 116 CSI1 */
#define SUNXI_IRQ_CSI_CCI     	(SUNXI_GIC_START + 85)  /* 117 CSI_CCI */
#define SUNXI_IRQ_LCD0        	(SUNXI_GIC_START + 86)  /* 118 TCON    */
#define SUNXI_IRQ_MIPICSI     	(SUNXI_GIC_START + 90)  /* 122 MIPICSI */
#define SUNXI_IRQ_DEIRQ0      	(SUNXI_GIC_START + 95)  /* 127 DE      */

#define SUNXI_IRQ_CTI0        	(SUNXI_GIC_START + 108) /* CTI0        */
#define SUNXI_IRQ_CTI1        	(SUNXI_GIC_START + 109) /* CTI1        */
#define SUNXI_IRQ_CTI2        	(SUNXI_GIC_START + 110) /* CTI2        */
#define SUNXI_IRQ_CTI3        	(SUNXI_GIC_START + 111) /* CTI3        */
#define SUNXI_IRQ_COMMTX0     	(SUNXI_GIC_START + 112) /* COMMTX0     */
#define SUNXI_IRQ_COMMTX1     	(SUNXI_GIC_START + 113) /* COMMTX1     */
#define SUNXI_IRQ_COMMTX2     	(SUNXI_GIC_START + 114) /* COMMTX2     */
#define SUNXI_IRQ_COMMTX3     	(SUNXI_GIC_START + 115) /* COMMTX3     */
#define SUNXI_IRQ_COMMRX0     	(SUNXI_GIC_START + 116) /* COMMRX0     */
#define SUNXI_IRQ_COMMRX1     	(SUNXI_GIC_START + 117) /* COMMRX1     */
#define SUNXI_IRQ_COMMRX2     	(SUNXI_GIC_START + 118) /* COMMRX2     */
#define SUNXI_IRQ_COMMRX3     	(SUNXI_GIC_START + 119) /* COMMRX3     */
#define SUNXI_IRQ_PMU0        	(SUNXI_GIC_START + 120) /* PMU0        */
#define SUNXI_IRQ_PMU1        	(SUNXI_GIC_START + 121) /* PMU1        */
#define SUNXI_IRQ_PMU2        	(SUNXI_GIC_START + 122) /* PMU2        */
#define SUNXI_IRQ_PMU3        	(SUNXI_GIC_START + 123) /* PMU3        */
#define SUNXI_IRQ_PMU         	 SUNXI_IRQ_PMU0
#define SUNXI_IRQ_AXI_ERROR   	(SUNXI_GIC_START + 124) /* AXI_ERROR   */

#define SUNXI_IRQ_RALARM0		SUNXI_IRQ_ALARM0
#define SUNXI_IRQ_RALARM1		SUNXI_IRQ_ALARM1
#define SUNXI_IRQ_TCON			SUNXI_IRQ_LCD0

#else

#error "please select a platform"

#endif

#define SUNXI_IRQ_MAX           (SUNXI_GIC_START + 256)

#endif    /* __IRQS_SUN8I_W8P1_H */
