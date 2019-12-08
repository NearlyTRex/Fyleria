-- Configuration
libGCrypt_extradir = "Libs/C/GCrypt/extra/"
libGCrypt_origdir = "Libs/C/GCrypt/orig/"
libGCrypt_srcdir = libGCrypt_origdir
libGCrypt_incdir = libGCrypt_origdir

-- Includes
libGCrypt_includedirs = {
    libGCrypt_incdir,
    libGCrypt_incdir .. "cipher/",
    libGCrypt_incdir .. "mpi/",
    libGCrypt_incdir .. "src/"
}
if os.host() == "linux" then
    table.insert(libGCrypt_includedirs, libGCrypt_extradir .. "linux/")
    table.insert(libGCrypt_includedirs, libGCrypt_extradir .. "linux/cipher/")
    table.insert(libGCrypt_includedirs, libGCrypt_extradir .. "linux/mpi/")
    table.insert(libGCrypt_includedirs, libGCrypt_extradir .. "linux/src/")
end

-- Defines
libGCrypt_defines = {
    "HAVE_CONFIG_H"
}
libGCrypt_debugdefines = {
}
libGCrypt_releasedefines = {
}

-- Libs
libGCrypt_libs = {
}

-- Options
libGCrypt_buildoptions = {
    "-fvisibility=hidden",
    "-fno-delete-null-pointer-checks",
    --"-Wa,--noexecstack"
}
libGCrypt_linkoptions = {
}

-- Sources
libGCrypt_sources = {
    libGCrypt_srcdir .. "compat/compat.c",
    libGCrypt_srcdir .. "cipher/cipher.c",
    libGCrypt_srcdir .. "cipher/cipher-cbc.c",
    libGCrypt_srcdir .. "cipher/cipher-cfb.c",
    libGCrypt_srcdir .. "cipher/cipher-ofb.c",
    libGCrypt_srcdir .. "cipher/cipher-ctr.c",
    libGCrypt_srcdir .. "cipher/cipher-aeswrap.c",
    libGCrypt_srcdir .. "cipher/cipher-ccm.c",
    libGCrypt_srcdir .. "cipher/cipher-cmac.c",
    libGCrypt_srcdir .. "cipher/cipher-gcm.c",
    libGCrypt_srcdir .. "cipher/cipher-gcm-intel-pclmul.c",
    libGCrypt_srcdir .. "cipher/cipher-gcm-armv8-aarch32-ce.S",
    libGCrypt_srcdir .. "cipher/cipher-gcm-armv8-aarch64-ce.S",
    libGCrypt_srcdir .. "cipher/cipher-poly1305.c",
    libGCrypt_srcdir .. "cipher/cipher-ocb.c",
    libGCrypt_srcdir .. "cipher/cipher-xts.c",
    libGCrypt_srcdir .. "cipher/cipher-selftest.c",
    libGCrypt_srcdir .. "cipher/pubkey.c",
    libGCrypt_srcdir .. "cipher/pubkey-util.c",
    libGCrypt_srcdir .. "cipher/md.c",
    libGCrypt_srcdir .. "cipher/mac.c",
    libGCrypt_srcdir .. "cipher/mac-hmac.c",
    libGCrypt_srcdir .. "cipher/mac-cmac.c",
    libGCrypt_srcdir .. "cipher/mac-gmac.c",
    libGCrypt_srcdir .. "cipher/mac-poly1305.c",
    libGCrypt_srcdir .. "cipher/poly1305.c",
    libGCrypt_srcdir .. "cipher/kdf.c",
    libGCrypt_srcdir .. "cipher/hmac-tests.c",
    libGCrypt_srcdir .. "cipher/primegen.c",
    libGCrypt_srcdir .. "cipher/hash-common.c",
    libGCrypt_srcdir .. "cipher/dsa-common.c",
    libGCrypt_srcdir .. "cipher/rsa-common.c",
    libGCrypt_srcdir .. "cipher/arcfour.c",
    libGCrypt_srcdir .. "cipher/arcfour-amd64.S",
    libGCrypt_srcdir .. "cipher/blowfish.c",
    libGCrypt_srcdir .. "cipher/blowfish-amd64.S",
    libGCrypt_srcdir .. "cipher/cast5.c",
    libGCrypt_srcdir .. "cipher/cast5-amd64.S",
    libGCrypt_srcdir .. "cipher/des.c",
    libGCrypt_srcdir .. "cipher/des-amd64.S",
    libGCrypt_srcdir .. "cipher/rijndael.c",
    libGCrypt_srcdir .. "cipher/rijndael-amd64.S",
    libGCrypt_srcdir .. "cipher/rijndael-ssse3-amd64.c",
    libGCrypt_srcdir .. "cipher/rijndael-ssse3-amd64-asm.S",
    libGCrypt_srcdir .. "cipher/rijndael-aesni.c",
    libGCrypt_srcdir .. "cipher/rijndael-padlock.c",
    libGCrypt_srcdir .. "cipher/twofish.c",
    libGCrypt_srcdir .. "cipher/twofish-amd64.S",
    libGCrypt_srcdir .. "cipher/twofish-avx2-amd64.S",
    libGCrypt_srcdir .. "cipher/serpent.c",
    libGCrypt_srcdir .. "cipher/serpent-sse2-amd64.S",
    libGCrypt_srcdir .. "cipher/serpent-avx2-amd64.S",
    libGCrypt_srcdir .. "cipher/rfc2268.c",
    libGCrypt_srcdir .. "cipher/seed.c",
    libGCrypt_srcdir .. "cipher/camellia.c",
    libGCrypt_srcdir .. "cipher/camellia-glue.c",
    libGCrypt_srcdir .. "cipher/camellia-aesni-avx-amd64.S",
    libGCrypt_srcdir .. "cipher/camellia-aesni-avx2-amd64.S",
    libGCrypt_srcdir .. "cipher/idea.c",
    libGCrypt_srcdir .. "cipher/salsa20.c",
    libGCrypt_srcdir .. "cipher/salsa20-amd64.S",
    libGCrypt_srcdir .. "cipher/gost28147.c",
    libGCrypt_srcdir .. "cipher/chacha20.c",
    libGCrypt_srcdir .. "cipher/chacha20-sse2-amd64.S",
    libGCrypt_srcdir .. "cipher/chacha20-ssse3-amd64.S",
    libGCrypt_srcdir .. "cipher/chacha20-avx2-amd64.S",
    libGCrypt_srcdir .. "cipher/poly1305-sse2-amd64.S",
    libGCrypt_srcdir .. "cipher/poly1305-avx2-amd64.S",
    libGCrypt_srcdir .. "cipher/dsa.c",
    libGCrypt_srcdir .. "cipher/rsa.c",
    libGCrypt_srcdir .. "cipher/elgamal.c",
    libGCrypt_srcdir .. "cipher/ecc.c",
    libGCrypt_srcdir .. "cipher/ecc-curves.c",
    libGCrypt_srcdir .. "cipher/ecc-misc.c",
    libGCrypt_srcdir .. "cipher/ecc-ecdsa.c",
    libGCrypt_srcdir .. "cipher/ecc-eddsa.c",
    libGCrypt_srcdir .. "cipher/ecc-gost.c",
    libGCrypt_srcdir .. "cipher/crc.c",
    libGCrypt_srcdir .. "cipher/crc-intel-pclmul.c",
    libGCrypt_srcdir .. "cipher/gostr3411-94.c",
    libGCrypt_srcdir .. "cipher/stribog.c",
    libGCrypt_srcdir .. "cipher/md4.c",
    libGCrypt_srcdir .. "cipher/md5.c",
    libGCrypt_srcdir .. "cipher/rmd160.c",
    libGCrypt_srcdir .. "cipher/sha256.c",
    libGCrypt_srcdir .. "cipher/sha256-ssse3-amd64.S",
    libGCrypt_srcdir .. "cipher/sha256-avx-amd64.S",
    libGCrypt_srcdir .. "cipher/sha256-avx2-bmi2-amd64.S",
    libGCrypt_srcdir .. "cipher/sha512.c",
    libGCrypt_srcdir .. "cipher/sha512-ssse3-amd64.S",
    libGCrypt_srcdir .. "cipher/sha512-avx-amd64.S",
    libGCrypt_srcdir .. "cipher/sha512-avx2-bmi2-amd64.S",
    libGCrypt_srcdir .. "cipher/keccak.c",
    libGCrypt_srcdir .. "cipher/tiger.c",
    libGCrypt_srcdir .. "cipher/whirlpool.c",
    libGCrypt_srcdir .. "cipher/whirlpool-sse2-amd64.S",
    libGCrypt_srcdir .. "cipher/blake2.c",
    libGCrypt_srcdir .. "cipher/sha1.c",
    libGCrypt_srcdir .. "cipher/sha1-ssse3-amd64.S",
    libGCrypt_srcdir .. "cipher/sha1-avx-amd64.S",
    libGCrypt_srcdir .. "cipher/sha1-avx-bmi2-amd64.S",
    libGCrypt_srcdir .. "cipher/scrypt.c",
    libGCrypt_srcdir .. "mpi/mpi-add.c",
    libGCrypt_srcdir .. "mpi/mpi-bit.c",
    libGCrypt_srcdir .. "mpi/mpi-cmp.c",
    libGCrypt_srcdir .. "mpi/mpi-div.c",
    libGCrypt_srcdir .. "mpi/mpi-gcd.c",
    libGCrypt_srcdir .. "mpi/mpi-inline.c",
    libGCrypt_srcdir .. "mpi/mpi-inv.c",
    libGCrypt_srcdir .. "mpi/mpi-mul.c",
    libGCrypt_srcdir .. "mpi/mpi-mod.c",
    libGCrypt_srcdir .. "mpi/mpi-pow.c",
    libGCrypt_srcdir .. "mpi/mpi-mpow.c",
    libGCrypt_srcdir .. "mpi/mpi-scan.c",
    libGCrypt_srcdir .. "mpi/mpicoder.c",
    libGCrypt_srcdir .. "mpi/mpih-div.c",
    libGCrypt_srcdir .. "mpi/mpih-mul.c",
    libGCrypt_srcdir .. "mpi/mpiutil.c",
    libGCrypt_srcdir .. "mpi/ec.c",
    libGCrypt_srcdir .. "mpi/ec-ed25519.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-add1.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-sub1.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-mul1.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-mul2.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-mul3.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-lshift.c",
    libGCrypt_srcdir .. "mpi/generic/mpih-rshift.c",
    libGCrypt_srcdir .. "random/random.c",
    libGCrypt_srcdir .. "random/random-csprng.c",
    libGCrypt_srcdir .. "random/random-drbg.c",
    libGCrypt_srcdir .. "random/random-system.c",
    libGCrypt_srcdir .. "random/rndjent.c",
    libGCrypt_srcdir .. "random/rndhw.c",
    libGCrypt_srcdir .. "random/rndlinux.c",
    libGCrypt_srcdir .. "src/context.c",
    libGCrypt_srcdir .. "src/fips.c",
    libGCrypt_srcdir .. "src/global.c",
    libGCrypt_srcdir .. "src/hwf-x86.c",
    libGCrypt_srcdir .. "src/hwfeatures.c",
    libGCrypt_srcdir .. "src/hmac256.c",
    libGCrypt_srcdir .. "src/misc.c",
    libGCrypt_srcdir .. "src/missing-string.c",
    libGCrypt_srcdir .. "src/secmem.c",
    libGCrypt_srcdir .. "src/sexp.c",
    libGCrypt_srcdir .. "src/stdmem.c",
    libGCrypt_srcdir .. "src/visibility.c"
}
