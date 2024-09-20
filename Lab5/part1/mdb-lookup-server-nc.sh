#!/bin/bash

on_ctrl_c() {
echo "Ignoring Ctrl-C"
}
# Call on_ctrl_c() when the interrupt signal is received.
# The interrupt signal is sent when you press Ctrl-C. 

trap on_ctrl_c INT



#1 The script takes one parameter, port number, on which nc will listen using argv 1
#"$1" to refer to the first parameter passed to the script by the user. and then necat to listen for connection using -l flag, and $port as will be scanf with user input
# 2 The script should create a named pipe named mypipe-<pid>, where <pid>  indicates the process ID of the shell running the script. 


port="$1"

#$$  Expands to the process ID of the shell

pipe="mypipe-$$"


 mkfifo $pipe
# cat mypipe | nc -l some_port_num | /some_path/mdb-lookup-cs3157 > mypipe 

cat "$pipe"| nc -l "$port"| /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > "$pipe" 

 
#rm "$pipe"

#source for cleanup() function: https://stackoverflow.com/questions/36335186/bash-exit-and-cleanup-on-error

cleanup(){
rm "$pipe"
}


trap cleanup EXIT

echo "Removing FIFO" 
