  - Rayan Hayle
  - rah226
  - lab 3

****************
IMPORTANT: 
I did not code lab 3, this is the solutions that I cloned from professor Jae Lee
We are allowed to drop one labs, and due to personal reason I could not complete this lab.
I need this lab so that lab 4, lab 5, and lab 6 work because they depend on lab 3 files. 
****************
  
Descriptions: How it should look after running the programs. 
------------
Part 1 without make:
- gcc -o mylist-test mylist-test.c mylist.o -I. -L../solutions_part2 -lmylist
- ./mylist-test

==3249935== Memcheck, a memory error detector
==3249935== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3249935== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3249935== Command: ./mylist-test
==3249935== 
testing addFront(): 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing flipSignDouble(): -9.0 -8.0 -7.0 -6.0 -5.0 -4.0 -3.0 -2.0 -1.0 
testing flipSignDouble() again: 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing findNode(): OK
popped 9.0, the rest is: [ 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 8.0, the rest is: [ 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 7.0, the rest is: [ 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 6.0, the rest is: [ 5.0 4.0 3.0 2.0 1.0 ]
popped 5.0, the rest is: [ 4.0 3.0 2.0 1.0 ]
popped 4.0, the rest is: [ 3.0 2.0 1.0 ]
popped 3.0, the rest is: [ 2.0 1.0 ]
popped 2.0, the rest is: [ 1.0 ]
popped 1.0, the rest is: [ ]
testing addAfter(): 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 
popped 1.0, and reversed the rest: [ 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 ]
popped 9.0, and reversed the rest: [ 2.0 3.0 4.0 5.0 6.0 7.0 8.0 ]
popped 2.0, and reversed the rest: [ 8.0 7.0 6.0 5.0 4.0 3.0 ]
popped 8.0, and reversed the rest: [ 3.0 4.0 5.0 6.0 7.0 ]
popped 3.0, and reversed the rest: [ 7.0 6.0 5.0 4.0 ]
popped 7.0, and reversed the rest: [ 4.0 5.0 6.0 ]
popped 4.0, and reversed the rest: [ 6.0 5.0 ]
popped 6.0, and reversed the rest: [ 5.0 ]
popped 5.0, and reversed the rest: [ ]
==3249935== 
==3249935== HEAP SUMMARY:
==3249935==     in use at exit: 0 bytes in 0 blocks
==3249935==   total heap usage: 19 allocs, 19 frees, 800 bytes allocated
==3249935== 
==3249935== All heap blocks were freed -- no leaks are possible
==3249935== 
==3249935== For lists of detected and suppressed errors, rerun with: -s
==3249935== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


Part 2 Valgrind:

==3251128== Memcheck, a memory error detector
==3251128== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3251128== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3251128== Command: ./revecho hello world friend dude
==3251128== 
dude
friend
world
hello

dude found
==3251128== 
==3251128== HEAP SUMMARY:
==3251128==     in use at exit: 0 bytes in 0 blocks
==3251128==   total heap usage: 5 allocs, 5 frees, 2,624 bytes allocated
==3251128== 
==3251128== All heap blocks were freed -- no leaks are possible
==3251128== 
==3251128== For lists of detected and suppressed errors, rerun with: -s
==3251128== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
