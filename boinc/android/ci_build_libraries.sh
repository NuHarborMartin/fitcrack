#!/bin/sh
set -e

#
# See: https://boinc.berkeley.edu/trac/wiki/AndroidBuildClient
#

# Script to compile BOINC libs for Android

# check working directory because the script needs to be called like: ./android/ci_build_libs.sh
if [ ! -d "android" ]; then
    echo "start this script in the source root directory"
    exit 1
fi

echo '===== BOINC libs for all platforms build start ====='
android/build_component.sh --ci --component libs
echo '===== BOINC libs for all platforms build done ====='