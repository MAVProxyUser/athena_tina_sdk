cmd_driver/pin/pin_int.o := or32-elf-gcc -Wp,-MD,driver/pin/.pin_int.o.d -Wp,-MT,driver/pin/pin_int.o -Iinclude -Iinclude/driver -Iinclude/service -Iinclude/system -Ilibrary/libfdt/include -Iarch/openrisc/plat-sun50iw10p1/inc -Iservice/standby/suspend_resume/mem-sun50iw10p1/ -Iinclude/generated -include include/generated/autoconf.h -include conf.h -g -c -nostdlib -Wall -Werror -Os -mhard-mul -msoft-div -msoft-float -Idriver/pin/ -D"BUILD_STR(s)=$(pound)s" -D"KBUILD_NAME=BUILD_STR(pin_int)" -c -o driver/pin/pin_int.o driver/pin/pin_int.c

source_driver/pin/pin_int.o := driver/pin/pin_int.c

deps_driver/pin/pin_int.o := \
  include/generated/autoconf.h \
  include/generated/conf.h \
  driver/pin/pin_i.h \
  include/include.h \
  arch/openrisc/plat-sun50iw10p1/inc/platform_regs.h \
  arch/openrisc/plat-sun50iw10p1/inc/cpucfg_regs.h \
  arch/openrisc/plat-sun50iw10p1/inc/irqnum_config.h \
  /home/xuquan/work/aw/Tina-MR813-OPEN/lichee/arisc/ar100s/tools/toolchain/bin/../lib/gcc/or32-elf/4.5.1-or32-1.0rc4/include/stdarg.h \
  /home/xuquan/work/aw/Tina-MR813-OPEN/lichee/arisc/ar100s/tools/toolchain/bin/../lib/gcc/or32-elf/4.5.1-or32-1.0rc4/include/stddef.h \
  include/generated/autoconf.h \
  arch/openrisc/plat-sun50iw10p1/inc/platform_config.h \
  include/./types.h \
  include/./error.h \
  include/./messages.h \
  include/./system/cpu.h \
  include/./system/daemon.h \
  include/./system/debugger.h \
  include/./system/notifier.h \
  include/./system/message_manager.h \
  include/./system/para.h \
  include/./system/../driver/dram.h \
  include/./system/../driver/ir.h \
  include/./system/../driver/pmu.h \
  include/./system/../service/standby.h \
  include/./driver/prcm.h \
  include/./driver/cpucfg.h \
  include/./driver/dram.h \
  include/./driver/hwmsgbox.h \
  include/./driver/intc.h \
  include/./driver/twi.h \
  include/./driver/pin.h \
  include/./driver/pmu.h \
  include/./driver/timer.h \
  include/./driver/uart.h \
  include/./driver/watchdog.h \
  include/./service/standby.h \
  include/./service/mem_include.h \
  include/./dbgs.h \
  include/./library.h \
  driver/pin/pin_regs.h \

driver/pin/pin_int.o: $(deps_driver/pin/pin_int.o)

$(deps_driver/pin/pin_int.o):
