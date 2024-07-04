#!/bin/sh

source ./script/setenv.sh
sleep 2
echo "*************** Compiling *************** project"
source ./script/Make.sh clean_idl

sleep 2
source ./script/Make.sh clean_src

sleep 2
source ./script/Make.sh idl

sleep 2
source ./script/Make.sh src
