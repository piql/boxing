#!/bin/sh
bin=""
if [ -d "LNX" ]; then
    if [ "$OSTYPE" == "darwin16" ]; then
       bin="LNX/release/unboxer.app/Contents/MacOS/unboxer"
    else
       bin="LNX/debug/unboxer"
    fi
elif [ -d "LNX64" ]; then
    bin="LNX64/debug/unboxer"
elif [ -f "./unboxer" ]; then
    bin="./unboxer"
else
    bin="W64\debug\unboxer"
fi

base=${srcdir}/..
if [ -z "${srcdir}" ] ; then
    base=".."
fi

$bin -i $base/testdata/12288x6878_4kv6.image8 -s 12288 6878 -f 4kv6 -o out-4kv6.dat || exit 1
$bin -i $base/testdata/12288x6879_4kv9.image8 -s 12288 6879 -f 4kv9 -o out-4kv9.dat || exit 1
$bin -i $base/testdata/12288x6878_4kv6_analog.image8 -s 12288 6878 -f 4kv6 -o out-4kv6_analog.dat || exit 1 
$bin -i $base/testdata/4kv6_*d.raw -f 4kv6 -s 4096 2160 -o out_4kv6.dat -is_raw || exit 1

# Convert analog to image:
#convert -size 4028x2092 -depth 8 GRAY:out-4kv6_analog.dat out-4kv6_analog.png

# Cleanup
rm out_4kv6.dat out-4kv6.dat out-4kv9.dat out-4kv6_analog.dat
