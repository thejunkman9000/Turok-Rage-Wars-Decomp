#!/usr/bin/env bash
# install the melalawi/ragewars-decomp toolchain into ~/sn (run in WSL once; sources: D:/Projects/ext, downloaded + sha256-checked from
# github.com/melalawi/abu-mas-n64 (n64link), pmret/gcc-papermario (gcc 2.8.1 sn64 cc1) and decompals/mips-gcc-2.7.2 (KMC cc1))
set -e
E=/mnt/d/Projects/ext; D=$HOME/sn; mkdir -p $D
cp $E/n64link/n64link-v0.2.0-linux-x86_64/n64link $D/n64link
cp $E/gcc281sn64/cc1 $D/cc1_281
cp $E/gcc272/cc1 $D/cc1_272
chmod +x $D/*
ls -la $D
