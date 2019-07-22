#!/usr/bin/env sh
set -e

CFLAGS="-nostdlib -static -Os -Wall -fno-exceptions -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-stack-protector"

# Change these as appropriate for your platform or for cross-compiling
CC="gcc -march=x86-64"
ARCH="x86_64"

$CC $CFLAGS -o "${1/\.*/}.$ARCH" "$1"
