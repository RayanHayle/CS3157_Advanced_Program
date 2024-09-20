Part 1: Works and functions as discribed in the lab.
 
 part a : shell scrpit works 
 source for part a function that i used :  https://stackoverflow.com/questions/36335186/bash-exit-and-cleanup-on-error
---------
 
 part c: displays a prompt, prints the messags, and termiantes 
 source: //Source: https://www.geeksforgeeks.org/exit-status-child-process-linux/
 this source helped me with the use of  the non-blocking version of waitpid() system call 
 
my code works, when i watched the recication, professor jae format looks slightly differnt. when he terminates a process, it does not  automatically prints "[pid=%d] mdb-lookup-server terminated"
it prints it only after he presses enter. I've tried to do it that format for muiptle days, but mine will automatically prints "[pid=%d] mdb-lookup-server terminated" right after it prints "Removing FIFO"

Solution: i asked the ta, and Phoebe Lu says that "While I cannot comment on the rubric, I can assure you that we have no requirement that the termination message has to be shown only after the user presses enter. " So i will submit it with the format of the termination message currently printing automatically.




---------
 part b: Find the process tree that contains ALL ancestors and children of this program, and include it in your README.txt.
 Identify the files that are shell scripts and list them in your README.txt. 
 







      0       1       1       1 ?             -1 Ss       0  23:42 /lib/systemd/systemd --system --deserialize 40 

 379268 2503314 2503314 2503314 ?             -1 Ss       0   0:00  \_ sshd: rah2236 [priv]
2503314 2503320 2503314 2503314 ?             -1 S     1900   0:00  |   \_ sshd: rah2236@pts/92
2503320 2503321 2503321 2503321 pts/92   2575581 Ss    1900   0:00  |       \_ -bash
2503321 2575581 2575581 2503321 pts/92   2575581 S    1900   0:00  |           \_ ./mdb-lookup-server-nc-1 20900
2575581 2575582 2575581 2503321 pts/92   2575581 S    1900   0:00  |               \_ /bin/bash ./mdb-lookup-server-nc.sh 20900 
2575582 2575584 2575581 2503321 pts/92   2575581 S    1900   0:00  |                   \_ cat mypipe-2575582
2575582 2575585 2575581 2503321 pts/92   2575581 S    1900   0:00  |                   \_ nc -l 20900
2575582 2575586 2575581 2503321 pts/92   2575581 S    1900   0:00  |                   \_ /bin/sh /home/jae/cs3157-pub/bin/mdb-lookup-cs3157  
2575586 2575587 2575581 2503321 pts/92   2575581 S    1900   0:00  |                       \_ /home/jae/cs3157-pub/bin/mdb-lookup /home/jae/cs3157-pub/bin/mdb-cs3157




the shell scripts in this process tree are:

1. \_ /bin/bash ./mdb-lookup-server-nc.sh 20900 
2. \_ /bin/sh /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 

TESTING:
make
./mdb-lookup-server-nc2
