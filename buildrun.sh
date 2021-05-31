#!/bin/bash
cd `dirname $0`

docker build \
    ./ \
    -t xv6

docker run --privileged \
    -d \
    -it \
    --name xv6-ubuntu \
    -h xv6-ubuntu \
    -v `pwd`/xv6-public:/xv6/xv6-public \
    xv6 \
    bash
