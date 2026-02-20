#!/bin/bash

version="0.2.0"
app_name="raylib_boilerplate"
home_dir=$HOME
current_dir=$home_dir/Programming/$app_name
dir=$current_dir

cmake=$(which cmake)
run_app=./bin/$app_name

version() {
    echo -e "version v$version\n$app_name build script"
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

init() {
    echo "Initializing new project..."
    echo "NOTE: This will copy the boilerplate files to a new directory and update the project name in CMakeLists.txt. You must rename the app_name variable in this script to match the name of the boilerplate project folder. The default is $app_name."
    echo "Enter folder name for the project (default: ~/Programming/$app_name): "
    read -r input
    if [ -n "$input" ]; then
        dir="$home_dir/$input"
    fi
    echo "Initializing project directory..."
    mkdir -p "$dir"
    echo "Copying boilerplate files..."
    cp -r ./* "$dir"
    echo "Project structure initialized."
    echo "Give your project a name (default: $app_name): "
    read -r project_name
    echo "Updating references in CMakeLists.txt..."
    sed -i "s|$app_name|$project_name|g" $dir/CMakeLists.txt
    echo "Initialization complete."
    echo "Navigate to $dir, rename app_name in $dir/make and run './make -a' to build and run your project."
}

usage() {
    version
    echo "Usage: $(basename "$0") [-h] [-v] [-i] [-c] [-b] [-r] [-a]"
    echo "Where:"
    echo "  -h  --help      Show this help text"
    echo "  -v  --version   Show version information"
    echo "  -i  --init      Initialize a new project"
    echo "  -c  --clean     Clean the build directory"
    echo "  -b  --build     Build the project"
    echo "  -r  --run       Run the project"
    echo "  -a  --all       Perform all steps: clean, build, and run the project"
}
# This script sets up the build environment for raylib boilerplate project.

while getopts ":abcrhvi" OPT; do
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
        i|--init) init ;;
        h|--help) usage ;;
        v|--version) version ;;
        \?) echo "Unknown parameter passed: $1"; usage; exit 1 ;;
    esac
    shift
done

shift $(($OPTIND - 1))