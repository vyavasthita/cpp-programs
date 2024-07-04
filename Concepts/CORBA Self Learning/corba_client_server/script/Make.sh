#!/bin/sh
#
#
# Build the hole project

IDL_DIRS="\
    PM_OM_CORBA/interface
"

SRC_DIRS="\
    source/myclient \
    source/myserver
"

do_in() # $1 = comment, $2 = action, $3 = dirs
{
    comment="$1"
    action="$2"
    dirs="$3"

    printf "\n### $comment ###\n\n"

    for dir in $dirs
    do
        if test -d $dir
        then
            printf "### $comment in $dir\n"
            ( cd $dir; $action )
        fi
    done
}

#
# Main
#
 stime=`date`
#
(
if test x"$1" = "xclean_idl"
then
    do_in "clean idl"           "make clean"   "$IDL_DIRS"

elif test x"$1" = "xclean_src"
then
    do_in "clean src"           "make clean"   "$SRC_DIRS"

elif test x"$1" = "xidl"
then
    do_in "compile idl"         "make -j 2"    "$IDL_DIRS"

elif test x"$1" = "xsrc"
then
    do_in "compile src" "make"  "$SRC_DIRS"
	
else
    do_in "compile idl"         "make"    	"$IDL_DIRS"
    do_in "compile src"         "make" 		"$SRC_DIRS"
fi

)  2>&1 | tee Make.log

printf "\n\nvvvvvvvvvv errorlist vvvvvvvvvvv\n\n"
egrep -e '\*\*\*|error:' Make.log
printf "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
printf "\n\n"

etime=`date`

echo ""  >> Make.log
echo "start time = $stime"  >> Make.log
echo "end   time = $etime"  >> Make.log
echo ""  >> Make.log

echo ""
echo "start time = $stime"
echo "end   time = $etime"
