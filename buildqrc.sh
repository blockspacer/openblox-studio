#!/bin/bash
# Do not invoke this directly

SRCDIR=$1
RCC=$2

cd $SRCDIR/../rc
$RCC -o $SRCDIR/qrc_resources.cpp resources.qrc
