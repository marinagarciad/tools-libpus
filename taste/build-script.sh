#!/bin/bash -e

# This script will build your TASTE system.

# You should not change this file as it was automatically generated.

# If you need additional preprocessing, there are three hook files
# that you can provide and that are called dring the build:
# user_init_pre.sh, user_init_post.sh and user_init_last.sh
# These files will never get overwritten by TASTE.'

# Inside these files you may set some environment variables:
#    C_INCLUDE_PATH=/usr/include/xenomai/analogy/:${C_INCLUDE_PATH}
#    unset USE_POHIC   

CWD=$(pwd)

if [ -t 1 ] ; then
    COLORON="\e[1m\e[32m"
    COLOROFF="\e[0m"
else
    COLORON=""
    COLOROFF=""
fi
INFO="${COLORON}[INFO]${COLOROFF}"

if [ -f user_init_pre.sh ]
then
    echo -e "${INFO} Executing user-defined init script"
    source user_init_pre.sh
fi

# Set up the cache to limit the calls to ASN1SCC in DMT tools
mkdir -p .cache
export PROJECT_CACHE=$(pwd)/.cache

# Use PolyORB-HI-C runtime
USE_POHIC=1

# Set Debug mode by default
DEBUG_MODE=--debug

# Detect models from Ellidiss tools v2, and convert them to 1.3
INTERFACEVIEW=InterfaceView.aadl
grep "version => \"2" InterfaceView.aadl >/dev/null && {
    echo -e "${INFO} Converting interface view from V2 to V1.3"
    TASTE --load-interface-view InterfaceView.aadl --export-interface-view-to-1_3 __iv_1_3.aadl
    INTERFACEVIEW=__iv_1_3.aadl
};

if [ -z "$DEPLOYMENTVIEW" ]
then
    DEPLOYMENTVIEW=DeploymentView.aadl
fi

# Detect models from Ellidiss tools v2, and convert them to 1.3
grep "version => \"2" "$DEPLOYMENTVIEW" >/dev/null && {
    echo -e "${INFO} Converting deployment view from V2 to V1.3"
    TASTE --load-deployment-view "$DEPLOYMENTVIEW" --export-deployment-view-to-1_3 __dv_1_3.aadl
    DEPLOYMENTVIEW=__dv_1_3.aadl
};

SKELS="./"

# Check if Dataview references existing files 
mono $(which taste-extract-asn-from-design.exe) -i "$INTERFACEVIEW" -j /tmp/dv.asn

cd "$SKELS" && rm -f ground.zip && zip -r ground ground/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f tcqueue.zip && zip -r tcqueue tcqueue/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f tcdispatch.zip && zip -r tcdispatch tcdispatch/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f tmdispatch.zip && zip -r tmdispatch tmdispatch/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f tmqueue.zip && zip -r tmqueue tmqueue/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st17.zip && zip -r st17 st17/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st01.zip && zip -r st01 st01/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st08.zip && zip -r st08 st08/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f onboardapid.zip && zip -r onboardapid onboardapid/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st09.zip && zip -r st09 st09/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f timereportapid.zip && zip -r timereportapid timereportapid/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f events.zip && zip -r events events/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st05.zip && zip -r st05 st05/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st19.zip && zip -r st19 st19/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f housekeeping.zip && zip -r housekeeping housekeeping/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st03.zip && zip -r st03 st03/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st12.zip && zip -r st12 st12/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st11.zip && zip -r st11 st11/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st18.zip && zip -r st18 st18/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st23.zip && zip -r st23 st23/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f filemanagement.zip && zip -r filemanagement filemanagement/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f st20.zip && zip -r st20 st20/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f onboardparams.zip && zip -r onboardparams onboardparams/* && cd $OLDPWD || exit -1

cd "$SKELS" && rm -f onboardsoftware.zip && zip -r onboardsoftware onboardsoftware/* && cd $OLDPWD || exit -1

[ ! -z "$CLEANUP" ] && rm -rf binary*

if [ -f ConcurrencyView.pro ]
then
    ORCHESTRATOR_OPTIONS+=" -w ConcurrencyView.pro "
elif [ -f ConcurrencyView_Properties.aadl ]
then
    ORCHESTRATOR_OPTIONS+=" -w ConcurrencyView_Properties.aadl "
fi

if [ -f user_init_post.sh ]
then
    echo -e "${INFO} Executing user-defined post-init script"
    source user_init_post.sh
fi

if [ -f additionalCommands.sh ]
then
    source additionalCommands.sh
fi

if [ ! -z "$USE_POHIC" ]
then
    OUTPUTDIR=binary.c
    ORCHESTRATOR_OPTIONS+=" -p "
elif [ ! -z "$USE_POHIADA" ]
then
    OUTPUTDIR=binary.ada
else
    OUTPUTDIR=binary
fi

NO_BITFILE=""
while getopts :-: o
do
case "$o$OPTARG"
in
(-no-bitfile) NO_BITFILE="--no-bitfile";;
esac
done

cd "$CWD" && assert-builder-ocarina.py \
	--fast \
	$DEBUG_MODE \
	--aadlv2 \
	--keep-case \
	$NO_BITFILE \
	--interfaceView "$INTERFACEVIEW" \
	--deploymentView "$DEPLOYMENTVIEW" \
	-o "$OUTPUTDIR" \
	--subC ground:"$SKELS"/ground.zip \
	--subC tcqueue:"$SKELS"/tcqueue.zip \
	--subC tcdispatch:"$SKELS"/tcdispatch.zip \
	--subC tmdispatch:"$SKELS"/tmdispatch.zip \
	--subC tmqueue:"$SKELS"/tmqueue.zip \
	--subC st17:"$SKELS"/st17.zip \
	--subC st01:"$SKELS"/st01.zip \
	--subC st08:"$SKELS"/st08.zip \
	--subC onboardapid:"$SKELS"/onboardapid.zip \
	--subC st09:"$SKELS"/st09.zip \
	--subC timereportapid:"$SKELS"/timereportapid.zip \
	--subC events:"$SKELS"/events.zip \
	--subC st05:"$SKELS"/st05.zip \
	--subC st19:"$SKELS"/st19.zip \
	--subC housekeeping:"$SKELS"/housekeeping.zip \
	--subC st03:"$SKELS"/st03.zip \
	--subC st12:"$SKELS"/st12.zip \
	--subC st11:"$SKELS"/st11.zip \
	--subC st18:"$SKELS"/st18.zip \
	--subC st23:"$SKELS"/st23.zip \
	--subC filemanagement:"$SKELS"/filemanagement.zip \
	--subC st20:"$SKELS"/st20.zip \
	--subC onboardparams:"$SKELS"/onboardparams.zip \
	--subC onboardsoftware:"$SKELS"/onboardsoftware.zip \
	$ORCHESTRATOR_OPTIONS

if [ -f user_init_last.sh ]
then
    echo -e "${INFO} Executing user-defined post-build script"
    source user_init_last.sh
fi

