#!/bin/bash

pushd `dirname $0`
devtools/bin/vpc /csbox +game /mksln games
popd
