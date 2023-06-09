#!/bin/bash

DIR=`pwd` 
echo "Current Path:$DIR"

source /home/uss/qnx710_sdp_desay/qnx710/qnxsdp-env.sh
source $DIR/env_setup.sh --platform=ipu02

mkdir -p $DIR/build
rm -rf $DIR/build/*
rm -rf $DIR/output/*

sync

cd $DIR/build && cmake -DCMAKE_TOOLCHAIN_FILE=../qnx.cmake .. && make install -j4
