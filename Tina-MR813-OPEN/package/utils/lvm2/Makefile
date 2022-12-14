#
# Copyright (C) 2009-2010 Stefan Monnier
# Copyright (C) 2011-2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v3+.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=LVM2
PKG_VERSION:=2.02.177
PKG_RELEASE:=1
PKG_LICENSE:=GPL-2.0 LGPL-2.1

PKG_SOURCE:=$(PKG_NAME).$(PKG_VERSION).tgz
PKG_SOURCE_URL:=ftp://sources.redhat.com/pub/lvm2/releases \
		http://ftp.gwdg.de/pub/linux/sources.redhat.com/lvm2/
PKG_HASH:=4025a23ec9b15c2cb7486d151c29dc953b75efc4d452cfe9dbbc7c0fac8e80f2
PKG_MAINTAINER:=Daniel Golle <daniel@makrotopia.org>

HOST_BUILD_DIR:=$(COMPILE_DIR_HOST)/$(PKG_NAME).$(PKG_VERSION)
PKG_BUILD_DIR:=$(COMPILE_DIR)/$(PKG_NAME).$(PKG_VERSION)

HOST_BUILD_PARALLEL:=1
include $(BUILD_DIR)/host-build.mk
include $(BUILD_DIR)/package.mk

define Package/libdevmapper
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=The Linux Kernel Device Mapper userspace library
  URL:=http://sourceware.org/dm/
  DEPENDS:=+kmod-dm +libpthread +libuuid +librt
endef

define Package/libdevmapper/description
 The device-mapper is a component of the 2.6 linux kernel that supports logical
 volume management. It is required by LVM2 and EVMS.
endef

define Package/lvm2
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Disc
  TITLE:=The Linux Logical Volume Manager
  URL:=http://sourceware.org/lvm2/
  DEPENDS:=+libdevmapper +libblkid +libreadline +libncurses
endef

define Package/lvm2/description
 LVM2 refers to a new userspace toolset that provide logical volume management
 facilities on linux. It is reasonably backwards-compatible with the original
 LVM toolset.
endef

CONFIGURE_ARGS += --disable-o_direct --disable-selinux

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CFLAGS="$(TARGET_CFLAGS) $(TARGET_CPPFLAGS) $(FPIC)" \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/include/libdevmapper.h $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libdevmapper.so* $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/libdm/libdevmapper.pc $(1)/usr/lib/pkgconfig
endef

define Package/libdevmapper/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/usr/lib/libdevmapper.so.* $(1)/usr/lib
endef

define Package/lvm2/install
	$(INSTALL_DIR) $(1)/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/lvm $(1)/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/dmsetup $(1)/sbin
	$(INSTALL_DIR) $(1)/etc/lvm
	$(SED) '/^[[:space:]]*\(#\|$$$$\)/d; /cache_dir/s@.*@	cache_dir = "/tmp/lvm/cache"@' $(PKG_INSTALL_DIR)/etc/lvm/lvm.conf
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/lvm/lvm.conf $(1)/etc/lvm/
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/lvm/lvmlocal.conf $(1)/etc/lvm/
	$(INSTALL_DIR) $(1)/etc/lvm/profile
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/etc/lvm/profile/* $(1)/etc/lvm/profile/
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/lvm2.init $(1)/etc/init.d/lvm2
	$(FIND) $(PKG_INSTALL_DIR)/usr/sbin/ -type l -exec $(CP) -a {} $(1)/sbin/ \;
endef

define Package/lvm2/conffiles
/etc/lvm/lvm.conf
endef

HOST_CONFIGURE_ARGS += --disable-o_direct --disable-selinux

define Host/Install
	$(MAKE) -C $(HOST_BUILD_DIR)/libdm install
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,libdevmapper))
$(eval $(call BuildPackage,lvm2))
