-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA512

Format: 3.0 (quilt)
Source: libvirt
Binary: libvirt-clients, libvirt-login-shell, libvirt-daemon, libvirt-daemon-driver-qemu, libvirt-daemon-driver-lxc, libvirt-daemon-driver-vbox, libvirt-daemon-driver-xen, libvirt-daemon-driver-storage-gluster, libvirt-daemon-driver-storage-iscsi-direct, libvirt-daemon-driver-storage-rbd, libvirt-daemon-driver-storage-zfs, libvirt-daemon-system, libvirt-daemon-system-systemd, libvirt-daemon-system-sysv, libvirt-daemon-config-network, libvirt-daemon-config-nwfilter, libvirt0, libvirt-doc, libvirt-dev, libvirt-sanlock, libnss-libvirt, libvirt-wireshark
Architecture: any all
Version: 7.4.0-0ubuntu3
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Uploaders:  Guido Günther <agx@sigxcpu.org>, Laurent Léonard <laurent@open-minds.org>,
Homepage: https://libvirt.org/
Standards-Version: 4.5.1
Vcs-Browser: https://salsa.debian.org/libvirt-team/libvirt
Vcs-Git: https://salsa.debian.org/libvirt-team/libvirt.git
Testsuite: autopkgtest
Testsuite-Triggers: build-essential, libxml2-utils, linux-generic, linux-image-amd64, pkg-config, qemu-kvm, qemu-system
Build-Depends: augeas-tools, bash-completion, debhelper-compat (= 13), dh-apparmor [linux-any], dnsmasq-base, iptables (>= 1.8.1) [linux-any], kmod [linux-any], libapparmor-dev [linux-any], libattr1-dev [linux-any], libaudit-dev [linux-any], libcap-ng-dev [linux-any], libcurl4-gnutls-dev, libdevmapper-dev [linux-any], libfuse-dev [linux-any], libgcrypt20-dev, libglusterfs-dev [linux-any], libgnutls28-dev, libiscsi-dev [linux-any], libnl-3-dev [linux-any], libnl-route-3-dev [linux-any], libnuma-dev [linux-any], libparted-dev (>= 2.2), libpcap0.8-dev, libpciaccess-dev, libpolkit-gobject-1-dev [linux-any], librados-dev [linux-any], librbd-dev [linux-any], libreadline-dev, libsanlock-dev [linux-any], libsasl2-dev, libselinux1-dev (>= 2.0.82) [linux-any], libtirpc-dev, libudev-dev [linux-any], libwireshark-dev (>= 1.11.3), libwiretap-dev, libxen-dev (>= 4.3) [amd64 arm64 armhf i386], libxml2-dev (>= 2.9.2+really2.9.1+dfsg1-0.2), libxml2-utils, libyajl-dev, libzfslinux-dev [linux-amd64 linux-arm64 linux-armhf linux-i386 linux-ppc64el linux-s390x], lvm2 [linux-any], meson (>= 0.54.0~), nfs-common, numad [linux-any], open-iscsi [linux-any], openssh-client, parted (>= 2.2), po-debconf, policykit-1 (>= 0.105-4~) [linux-any], python3, python3-docutils, qemu-system-common, qemu-utils, radvd [linux-any], systemtap-sdt-dev [linux-any], uuid-dev, xsltproc, zfsutils [kfreebsd-amd64 kfreebsd-i386], zlib1g-dev
Build-Conflicts: dpkg-dev (= 1.15.3)
Package-List:
 libnss-libvirt deb admin optional arch=linux-any
 libvirt-clients deb admin optional arch=any
 libvirt-daemon deb admin optional arch=any
 libvirt-daemon-config-network deb admin optional arch=all
 libvirt-daemon-config-nwfilter deb admin optional arch=all
 libvirt-daemon-driver-lxc deb admin optional arch=alpha,amd64,arm64,armel,armhf,hppa,i386,m68k,mips64el,mipsel,powerpc,ppc64,ppc64el,riscv64,s390x,sh4,sparc64,x32
 libvirt-daemon-driver-qemu deb admin optional arch=linux-any
 libvirt-daemon-driver-storage-gluster deb admin optional arch=linux-any
 libvirt-daemon-driver-storage-iscsi-direct deb admin optional arch=linux-any
 libvirt-daemon-driver-storage-rbd deb admin optional arch=linux-any
 libvirt-daemon-driver-storage-zfs deb admin optional arch=linux-any
 libvirt-daemon-driver-vbox deb admin optional arch=amd64,i386
 libvirt-daemon-driver-xen deb admin optional arch=amd64,arm64,armhf,i386
 libvirt-daemon-system deb admin optional arch=any
 libvirt-daemon-system-systemd deb admin optional arch=all
 libvirt-daemon-system-sysv deb admin optional arch=all
 libvirt-dev deb libdevel optional arch=any
 libvirt-doc deb doc optional arch=all
 libvirt-login-shell deb admin optional arch=alpha,amd64,arm64,armel,armhf,hppa,i386,m68k,mips64el,mipsel,powerpc,ppc64,ppc64el,riscv64,s390x,sh4,sparc64,x32
 libvirt-sanlock deb admin optional arch=linux-any
 libvirt-wireshark deb admin optional arch=any
 libvirt0 deb libs optional arch=any
Checksums-Sha1:
 0be7a7947d6a31850df6147f9c8d2a4a1768cb4c 8617788 libvirt_7.4.0.orig.tar.xz
 2fd3736d50e7527438596c57361a2e90d9353b6d 833 libvirt_7.4.0.orig.tar.xz.asc
 fe4de02919605ba55dd6f6881dbe9746b090431f 140868 libvirt_7.4.0-0ubuntu3.debian.tar.xz
Checksums-Sha256:
 b366d73dee6ce77a226bedef592e0620ceb8e22e5998f60768017f79fc4ead26 8617788 libvirt_7.4.0.orig.tar.xz
 09ec1411cece080c730489c047e39a3c60e5b38869d9b880c7e748bd6b69cf38 833 libvirt_7.4.0.orig.tar.xz.asc
 e4b90dd04f78af8124c3b29cf0f05354bf455dfa462ff7a0c0acd31b4a7a15c7 140868 libvirt_7.4.0-0ubuntu3.debian.tar.xz
Files:
 4c46c832a76b24a13eb616e3211b6816 8617788 libvirt_7.4.0.orig.tar.xz
 3528ffd69e817371232b62ddbc66302a 833 libvirt_7.4.0.orig.tar.xz.asc
 c0e88d1220f751847343df099e4a3058 140868 libvirt_7.4.0-0ubuntu3.debian.tar.xz
Original-Maintainer: Debian Libvirt Maintainers <pkg-libvirt-maintainers@lists.alioth.debian.org>

-----BEGIN PGP SIGNATURE-----

iQIzBAEBCgAdFiEEktYY9mjyL47YC+71uj4pM4KAskIFAmDm7gYACgkQuj4pM4KA
skLNQRAAkuOazoHY2Qv1NiCUVcf6GREbnwlQ11pk3Q+kXZmf4O7H908MFYxfUwHL
/ba4KqHvIAC5SnUvXjhOEUoypUoH/B9bImaDdyqyB+5fKlS/Cwh6Pye2gSJtfIfE
jGb91KPk41FIQGvPNtn3yDD0FZNueD+x8W23pMA/+pEBZffeLNOVvBhGe9QTJyhM
dyuRM2acz73QGwb2DOlrq1tLALOLc/6rm3rhT/3WRniDkx64wDXuhfTAnkXQP6tO
c9a+2vnXnGl2qB5MM13Sscb86Qs7/X1h8Itzcq61V3s71201VvIo+fKtjSWAphGE
XbgcoPYTr95uIBbF/0iOqrFx07DY/ygQneEnycSYlUcyK0Rj6aS+aalzE52sG6Wx
zbYwLZ7BIVd8DChBIEnt+VMWQQiVL4qj7HP5Bf4KDU2hxgCYkTXq89vWp+WxAcLp
yBjiv3CFdpTW9cp7dSId9PqO20Ne1ioZ7jXHh3AJ+Hwme9x9zSKi4tx9gvKVbksR
hsQRXTV1jFQFPKWuev+6YRuSM6pKneN/0PtE9wBpAK1Zy26u1xf0f+R1hhptiTlB
C55+rukt+OkuvTzJRHjjVSBKWiKpAndl0SkjcoJsW54+6KmPDl1MXOQtZHBeZ5zA
26dqBjBNryVPOXlzRStPExsE3bSJeJU79ygKwFyHuIYq9rbRd9Y=
=ceoQ
-----END PGP SIGNATURE-----
