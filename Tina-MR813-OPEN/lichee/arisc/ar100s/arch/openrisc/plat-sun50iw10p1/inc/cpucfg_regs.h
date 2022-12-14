/*
*********************************************************************************************************
*                                                AR100 SYSTEM
*                                     AR100 Software System Develop Kits
*                                                cpucfg module
*
*                                    (c) Copyright 2012-2016, Sunny China
*                                             All Rights Reserved
*
* File    : cpucfg_regs.h
* By      : Sunny
* Version : v1.0
* Date    : 2012-5-7
* Descript: cpu config register defines.
* Update  : date                auther      ver     notes
*           2012-5-7 18:54:47   Sunny       1.0     Create this file.
*********************************************************************************************************
*/

#ifndef __CPUCFG_REGS_H__
#define __CPUCFG_REGS_H__

/* the number of cpus */
typedef enum cpucfg_cpu_reset_ctrl {
	CPUCFG_C0_CPU0 = 0x0,
	CPUCFG_C0_CPU1 = 0x1,
	CPUCFG_C0_CPU2 = 0x2,
	CPUCFG_C0_CPU3 = 0x3,
	CPUCFG_CPU_NUMBER = 0x4,
} cpucfg_cpu_reset_ctrl_e;
#define IS_CPU0_WFI() (readl(0x09010000 + 0x80) & (0x1 << 16))

/* cpus little-endian space number */
#define CPUCFG_LE_SPACE_NUMBER      (4)

/* RTC REGS */
#define IOSC_CLK_AUTO_CALI	(RTC_REG_BASE + 0x000C)
#define XO_CTRL			(RTC_REG_BASE + 0x0160)
#define SUPER_STANDBY_FLAG_REG  (RTC_REG_BASE + 0x01F8)
#define PRIVATE_REG0            (RTC_REG_BASE + 0x01BC)
#define PRIVATE_REG1            (RTC_REG_BASE + 0x01FC)
#define BOOT_CPU_HOTPLUG_REG    (RTC_REG_BASE + 0x01B8)
#define SUNXI_SOFT_ENTRY			  (RTC_REG_BASE + 0x1bc)
#define SUNXI_BOOT_CPU_HOTPLUG			  (RTC_REG_BASE + 0x1b8)

/* TIMESTAMP REGS */
#define CNT_LOW_REG             (TS_STAT_REG_BASE + 0x0000)
#define CNT_HIGH_REG            (TS_STAT_REG_BASE + 0x0004)
#define CNT_CTRL_REG            (TS_CTRL_REG_BASE + 0x0000)
#define CNT_LOW_REG_SET         (TS_CTRL_REG_BASE + 0x0008)
#define CNT_HIGH_REG_SET        (TS_CTRL_REG_BASE + 0x000C)
#define CNT_FREQID_REG          (TS_CTRL_REG_BASE + 0x0020)

/* CPU SUBSYSTEM REGS : old register layout for sun50iw10p1 Version ABCDE */
#define GENER_CTRL_REG0         (CPUSUBSYS_REG_BASE + 0x0000)
#define GENER_CTRL_REG1         (CPUSUBSYS_REG_BASE + 0x0004)
#define GIC_JTAG_RST_CTRL_REG   (CPUSUBSYS_REG_BASE + 0x000C)
#define C0_INT_EN_REG           (CPUSUBSYS_REG_BASE + 0x0010)
#define IRQ_FIQ_STATUS_REG      (CPUSUBSYS_REG_BASE + 0x0014)
#define C0_DBG_STATE            (CPUSUBSYS_REG_BASE + 0x001C)
#define SUNXI_CPU_RVBA_L(cpu)   (CPUSUBSYS_REG_BASE + 0x40 + (cpu)*0x8)
#define SUNXI_CPU_RVBA_H(cpu)   (CPUSUBSYS_REG_BASE + 0x44 + (cpu)*0x8)

/* CPU SUBSYSTEM REGS : new register layout for sun50iw10p1 Version F and after */
#define SUB_CPU_CTRL_REG(core)  (CPUSUBSYS_REG_BASE + 0x20 + (core) * 0x4)


/* CPUXCFG REGS : old register layout for sun50iw10p1 Version ABCDE */
#define C0_RST_CTRL_REG         (CPUCFG_REG_BASE + 0x0000)
#define C0_CTRL_REG0            (CPUCFG_REG_BASE + 0x0010)
#define C0_CTRL_REG1            (CPUCFG_REG_BASE + 0x0014)
#define C0_CTRL_REG2            (CPUCFG_REG_BASE + 0x0018)
#define CACHE_CFG_REG           (CPUCFG_REG_BASE + 0x0024)
#define C0_CPU_STATUS_REG       (CPUCFG_REG_BASE + 0x0080)
#define L2_STATUS_REG           (CPUCFG_REG_BASE + 0x0084)

#define SUNXI_DBG_REG0          (CPUCFG_REG_BASE + 0xC0)
#define SUNXI_DBG_REG1          (CPUCFG_REG_BASE + 0xC4)

#define SUNXI_CPU_RST_CTRL(cluster)               (CPUCFG_REG_BASE + 0x00 + (cluster<<2))
#define SUNXI_CLUSTER_CTRL0(cluster)              (CPUCFG_REG_BASE + 0x10 + (cluster<<4))
#define SUNXI_CLUSTER_CTRL1(cluster)              (CPUCFG_REG_BASE + 0x14 + (cluster<<4))
#define SUNXI_CLUSTER_CTRL2(cluster)              (CPUCFG_REG_BASE + 0x18 + (cluster<<4))
#define SUNXI_CLUSTER_CPU_STATUS(cluster)         (CPUCFG_REG_BASE + 0x80 + (cluster<<2))

/* CPUXCFG REGS : new register layout for sun50iw10p1 Version F and after */
#define CO_CPU_CTRL_REG(core)         (CPUCFG_REG_BASE + 0x0060 + (core) * 0x04)


/* CPUSCFG REGS : old register layout for sun50iw10p1 Version ABCDE*/
#define CPUS_RST_CTRL_REG       (R_CPUCFG_REG_BASE + 0x0000)
#define CPUS_SPACE_LE_CTRL_REG  (R_CPUCFG_REG_BASE + 0x000C)
#define CPUS_SPACE_START_REG(n) (R_CPUCFG_REG_BASE + 0x0010 + n * 8)
#define CPUS_SPACE_END_REG(n)   (R_CPUCFG_REG_BASE + 0x0014 + n * 8)

#define C0_CPUX_RESET_REG            (R_CPUCFG_REG_BASE + 0x0040)
#define C0_CPUX_POWEROFF_GATING_REG  (R_CPUCFG_REG_BASE + 0x0044)

#define SUNXI_CLUSTER_PWRON_RESET(cluster)        (R_CPUCFG_REG_BASE + 0x40 + (cluster<<2))
#define SUNXI_CLUSTER_PWROFF_GATING(cluster)      (R_CPUCFG_REG_BASE + 0x44 + (cluster<<2))
#define SUNXI_CPU_PWR_CLAMP(cluster, cpu)         (R_CPUCFG_REG_BASE + 0x50 + (cluster<<4) + (cpu<<2))

#define SUNXI_CPU_SYS_RESET                       (R_CPUCFG_REG_BASE + 0x0A0)
#define SUNXI_CPUIDLE				  (R_CPUCFG_REG_BASE + 0x100)
#define SUNXI_F1F2_FLAG				  (R_CPUCFG_REG_BASE + 0x104)
#define SUNXI_IDLE_IRQ_FIQ_STATE		  (R_CPUCFG_REG_BASE + 0x108)
#define SUNXI_IRQ_FIQ_MASK			  (R_CPUCFG_REG_BASE + 0x10c)
#define SUNXI_IDLE_STATE			  (R_CPUCFG_REG_BASE + 0x110)
#define SUNXI_PWR_SW_DELAY			  (R_CPUCFG_REG_BASE + 0x140)
#define SUNXI_F1F2_CONFIG_DELAY			  (R_CPUCFG_REG_BASE + 0x144)

/* CPUSCFG REGS : new register layout for sun50iw10p1 Version F and after */
#define CPUS_C0_CPU_CFG_REG(core)                 (R_CPUCFG_REG_BASE + 0x70 + (core) * 0x04)


#define CLUSTER0    0
#define CLUSTER1    1

#define DCXO_CALI_INTEGER_OFFSET 20
#define DCXO_CALI_DECIMAL_OFFSET 4

#endif /* __CPUCFG_REGS_H__ */
