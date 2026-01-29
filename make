#!/bin/bash

version="0.1.0"
dir=/home/acidburner/Programming/raylib_boilerplate
cmake=$(which cmake)
run_app=./bin/raylib_boilerplate

version() {
    echo -e "version v$version\nraylib_boilerplate build script"
}

clean() {
    cd $dir
    echo removing build
    rm -rf build
    echo creating build directory
    mkdir build
}

configure() {
    cd $dir/build
    $cmake ..
}

build() {
    cd $dir/build
    $cmake --build .
}

run() {
    cd $dir/build
    $run_app
}

usage() {
    version
    echo "Usage: $(basename "$0") [-h] [-c] [-b] [-r] [-a]"
    echo "Where:"
    echo "  -h  --help      Show this help text"
    echo "  -v  --version   Show version information"
    echo "  -c  --clean     Clean the build directory"
    echo "  -b  --build     Build the project"
    echo "  -r  --run       Run the project"
    echo "  -a  --All       All of the above"
}
# This script sets up the build environment for raylib boilerplate project.

while getopts ":abcrhv" OPT; do
    case "$OPT" in
        c|--clean) clean ;;
        b|--build)
            configure
            build
            ;;
        r|--run) run ;;
        a|--all)
            clean
            configure
            build
            run
            ;;
        h|--help) usage ;;
        v|--version) version ;;
        \?) echo "Unknown parameter passed: $1"; usage; exit 1 ;;
    esac
    shift
done

shift $(($OPTIND - 1))