-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1

Format: 3.0 (quilt)
Source: libvirt
Binary: libvirt-bin, libvirt0, libvirt0-dbg, libvirt-doc, libvirt-dev, python-libvirt
Architecture: any all
Version: 1.0.1-0ubuntu3
Maintainer: Ubuntu Developers <ubuntu-devel-discuss@lists.ubuntu.com>
Uploaders: Guido Günther <agx@sigxcpu.org>, Laurent Léonard <laurent@open-minds.org>
Dm-Upload-Allowed: yes
Homepage: http://libvirt.org
Standards-Version: 3.9.3
Build-Depends: cdbs (>= 0.4.90~), debhelper (>= 7), libxml2-dev, libncurses5-dev, libreadline-dev, zlib1g-dev, libgnutls-dev, libgcrypt11-dev, python-all-dev (>= 2.6.6-3~), libavahi-client-dev, libsasl2-dev, libxen-dev [i386 amd64], lvm2 [linux-any], open-iscsi-utils, libparted0-dev (>= 2.2), parted (>= 2.2), libdevmapper-dev [linux-any], uuid-dev, libudev-dev [linux-any], libhal-dev [!linux-any], libpciaccess-dev, module-init-tools [linux-any], policykit-1, libcap-ng-dev [linux-any], libnl-3-dev, libnl-route-3-dev, libyajl-dev, libpcap0.8-dev, libnuma-dev [amd64 i386 ia64 mips mipsel powerpc], radvd [linux-any], libnetcf-dev [linux-any], dwarves, libxml2-utils, libapparmor-dev, dnsmasq-base, openssh-client, netcat-openbsd, librbd-dev
Build-Conflicts: dpkg-dev (= 1.15.3)
Package-List: 
 libvirt-bin deb admin optional
 libvirt-dev deb libdevel optional
 libvirt-doc deb doc optional
 libvirt0 deb libs optional
 libvirt0-dbg deb debug extra
 python-libvirt deb python optional
Checksums-Sha1: 
 db681793fa7c362f717f5e9c74011953ccb4672a 22512698 libvirt_1.0.1.orig.tar.gz
 eb7304528866f785da695257a248be49871510f7 95711 libvirt_1.0.1-0ubuntu3.debian.tar.gz
Checksums-Sha256: 
 4a16c76c46ebc41a6514082b5d95b5d5a0868e7a8cc00ab2e6cc1a23ec6b5a3b 22512698 libvirt_1.0.1.orig.tar.gz
 8875fa622029c4e6a990f884c924602dafa929e9b7d4e0ee7c3cca852b195818 95711 libvirt_1.0.1-0ubuntu3.debian.tar.gz
Files: 
 86a8c0acabb01e11ac84fe00624dc54e 22512698 libvirt_1.0.1.orig.tar.gz
 2d240911f5c43b4ea6b909592205e692 95711 libvirt_1.0.1-0ubuntu3.debian.tar.gz
Original-Maintainer: Debian Libvirt Maintainers <pkg-libvirt-maintainers@lists.alioth.debian.org>

-----BEGIN PGP SIGNATURE-----
Version: GnuPG v1.4.12 (GNU/Linux)

iQEcBAEBAgAGBQJRCA1fAAoJEOn+6gaoXj+dpkAH/2F0Cryjxa7eiePxWvFlIKlV
SJC0LRJDb567/OyFS7vxpf+HPEbsELoABoSKQBE5ebUK2s0uf5sjtyB0SnLZwFb2
iZbRkpe3ZKFWKhK8mi9Jf7ZJH0cAiEnSW64354xXFDFO9VVxWQkx7K6yq+vMSU7r
bDwc7xvqlbeerPLKdijIEXlU2iUP8hUFCcnupzxvjkgUpkqMSTotlMGX/PUk1fAK
4fU07pE+2ATMd0YG7EHZS8HUPxtBR+zq/t0ZgERnbbju6Foj7Q1ZnscUtIQMsHbv
kiCPPu9vfdjUrQpIqlOAXFkYs3QsaZRH7wWOSZ9XAaTWvz3/DHKtjac+5Jnyb+8=
=O9pB
-----END PGP SIGNATURE-----
