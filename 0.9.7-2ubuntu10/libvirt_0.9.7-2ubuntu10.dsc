-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1

Format: 3.0 (quilt)
Source: libvirt
Binary: libvirt-bin, libvirt0, libvirt0-dbg, libvirt-doc, libvirt-dev, python-libvirt
Architecture: any all
Version: 0.9.7-2ubuntu10
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Uploaders: Guido Günther <agx@sigxcpu.org>, Laurent Léonard <laurent@open-minds.org>
Dm-Upload-Allowed: yes
Homepage: http://libvirt.org
Standards-Version: 3.9.2
Build-Depends: cdbs (>= 0.4.90~), debhelper (>= 7), libxml2-dev, libncurses5-dev, libreadline-dev, zlib1g-dev, libgnutls-dev, python-all-dev (>= 2.6.6-3~), libavahi-client-dev, libsasl2-dev, libxen-dev [i386 amd64], lvm2 [linux-any], open-iscsi-utils, libparted0-dev (>= 2.2), parted (>= 2.2), libdevmapper-dev [linux-any], uuid-dev, libudev-dev [linux-any], libhal-dev [!linux-any], libpciaccess-dev, module-init-tools, policykit-1, libcap-ng-dev [linux-any], libnl-3-dev, libyajl-dev, libpcap0.8-dev, radvd, libxml2-utils, libapparmor-dev, dnsmasq-base, openssh-client, netcat-openbsd
Build-Conflicts: dpkg-dev (= 1.15.3)
Package-List: 
 libvirt-bin deb admin optional
 libvirt-dev deb libdevel optional
 libvirt-doc deb doc optional
 libvirt0 deb libs optional
 libvirt0-dbg deb debug extra
 python-libvirt deb python optional
Checksums-Sha1: 
 2f08609267154ad5377b3dc3952eb1e77469b570 17853636 libvirt_0.9.7.orig.tar.gz
 f0dc98648f80924117bfac662a1eb0d2cbf91bc5 77885 libvirt_0.9.7-2ubuntu10.debian.tar.gz
Checksums-Sha256: 
 29ff05bfe5177d6680c02c279ed2573dcfae993f2824bffa192a3a2cdd05af23 17853636 libvirt_0.9.7.orig.tar.gz
 84e89d1f2fcdf0960041dcb9f2d81a86909e4e02409875fd9f417a9e2484f6a0 77885 libvirt_0.9.7-2ubuntu10.debian.tar.gz
Files: 
 4308b3f4d23f5b0c5196260a9a22a38b 17853636 libvirt_0.9.7.orig.tar.gz
 fb7ed71fb052c5fa1b973bfae31b8b0f 77885 libvirt_0.9.7-2ubuntu10.debian.tar.gz
Debian-Vcs-Browser: http://git.debian.org/?p=pkg-libvirt/libvirt.git
Debian-Vcs-Git: git://git.debian.org/git/pkg-libvirt/libvirt.git
Original-Maintainer: Debian Libvirt Maintainers <pkg-libvirt-maintainers@lists.alioth.debian.org>

-----BEGIN PGP SIGNATURE-----
Version: GnuPG v1.4.11 (GNU/Linux)

iQEcBAEBAgAGBQJPCrNPAAoJEOn+6gaoXj+dCy0IAIJqnZXnWYd25ZzYl5jTENG6
EsXN9RsKEXuyX5zbDewhHePfyVD8F+ovghuBjxgmSKzxmkwVDu0XtlPkXFI0fI+b
x0EwaWQsRXhGFccJZ1VB6ffZ3p9Q0IhhdKLVGyKVQLq/Xqr3hKYGe3iD5QNYzuHD
DWdDqgAdtjAnef46srb+ZgDEp4SaoeEs16aaw9D88AO1CW4fxOeFkBYTvdHp3b9K
t981Ys1pMQimmfsYknt8ykKsJIZtAhaXK9+5jPwtwu/KhgvThRNTlUeMpNiYTuLF
WJTu9VdksNBC8GIDwjmfZ1+s2XV1lCv3X/3WaumppBicDbCKkK6fdubvGq6BAY4=
=sL9Q
-----END PGP SIGNATURE-----
