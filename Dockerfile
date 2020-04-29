FROM ubuntu:18.04
MAINTAINER cyan <cyan@0x00a1e9.dev>

RUN rm /bin/sh && ln -s /bin/bash /bin/sh

ENV DEBIAN_FRONTEND noninteractive
ENV DEBCONF_NOWARNINGS yes
ENV TERM linux

RUN sed -i.bak -e "s%http://archive.ubuntu.com/ubuntu/%http://ftp.iij.ad.jp/pub/linux/ubuntu/archive/%g" /etc/apt/sources.list

RUN mkdir /dev/net \
    && mknod /dev/net/tun c 10 200 

RUN mkdir -p /xv6
WORKDIR /xv6
ADD ./requirements/apt.txt apt.txt

RUN rm -rf /var/lib/apt/lists/* \
    && apt-get autoclean \
    && apt-get clean \
    && apt-get update

RUN apt-get -y --no-install-recommends install software-properties-common \
    && xargs apt-get -y --no-install-recommends install < apt.txt \
    && apt-get clean \
    && rm -rf /var/cache/apt/archives/* /var/lib/apt/lists/*

RUN locale-gen ja_JP.UTF-8
ENV LC_ALL ja_JP.UTF-8

ADD . /xv6
