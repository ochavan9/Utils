#!/bin/bash

BUILD_DIR=buildLinux

rm -rf ${BUILD_DIR}
mkdir ${BUILD_DIR}

# Additional options for cmake
if [ $# -ne 0 ]; then
	echo -e "Adding cmake options: $@\n"
	CMAKE_CUSTOM_OPTS+="$@"
fi

DIR_NAME=`dirname $0`

cd ${BUILD_DIR}
cmake "$CMAKE_CUSTOM_OPTS" -G "Unix Makefiles" "${DIR_NAME}/.."
cd ..
