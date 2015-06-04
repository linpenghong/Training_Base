#! /bin/bash

func()
{
    # getops optstring arg
    # this command is IMPORTANT; it means -a -b -c are available options
    # -a can have an arugment
    # -b can have an arugment
    # -c can not have an arugment
    # option will be stored in arg
    # argument will be stored in OPTARG
    while getopts "a:b:c" arg
    do
        case "$arg" in
            a)
                echo "a's argument is $OPTARG"
                ;;
            b)
                echo "b's argument is $OPTARG"
                ;;
            c)
                echo "c"
                ;;
            ?)
                echo "unknown argument"
                exit 1
                ;;
        esac
    done
}

func -a hello -b world
