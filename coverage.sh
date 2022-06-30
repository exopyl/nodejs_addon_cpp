#!/usr/bin/env bash

set -eu
set -o pipefail

# http://clang.llvm.org/docs/UsersManual.html#profiling-with-instrumentation
# https://www.bignerdranch.com/blog/weve-got-you-covered/
# https://www.osadl.org/Dumping-gcov-data-at-runtime-simple-ex.online-coverage-analysis.0.html
# https://github.com/mapbox/cpp#code-coverage
# https://github.com/mapbox/node-cpp-skel/blob/main/scripts/coverage.sh

#make clean

export CXX=/usr/bin/clang++-10
export LINK=/usr/bin/clang++-10
export GYP_DEFINES="clang=1"

export CXXFLAGS="-fprofile-instr-generate -fcoverage-mapping"
export LDFLAGS="-fprofile-instr-generate"

#make debug
#node-gyp rebuild --loglevel=error --debug
npm run build_debug

rm -f *profraw
rm -f *gcov
rm -f *profdata
LLVM_PROFILE_FILE="code-%p.profraw" node index.js #npm test
CXX_MODULE="./build/Debug/addon_animals.node"

llvm-profdata merge -output=code.profdata code-*.profraw
llvm-cov report ${CXX_MODULE} -instr-profile=code.profdata -use-color
#llvm-cov show ${CXX_MODULE} -instr-profile=code.profdata srccpp/*.cpp -path-equivalence -use-color
#llvm-cov show ${CXX_MODULE} -instr-profile=code.profdata srccpp/*.cpp -path-equivalence -use-color --format html > coverage.html
#echo "open coverage.html for HTML version of this report"
