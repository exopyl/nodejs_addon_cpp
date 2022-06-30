FROM ubuntu:20.04

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get install --no-install-recommends -y python3 build-essential nodejs npm yarn mocha llvm clang-10
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
    
WORKDIR /mnt
