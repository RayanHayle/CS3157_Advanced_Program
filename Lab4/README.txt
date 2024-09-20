  - your name
  - your UNI
  - lab assignment number
  - your name: Rayan Hayle
  - your UNI: Rah2236
  - lab assignment number: 4
  - description for each part
   
 The description should indicate whether your solution for the part is
 working or not.  You may also want to include anything else you would
 like to communicate to the grader such as extra functionalities you
 implemented or how you tried to fix your non-working code.





Part 1: Works and functions as discribed in the lab.
---------------------------------------------------------

I have cited my source in part 1 to futher explain there use:

Source 1: //Source: https://cplusplus.com/reference/cstring/memcpy/
this website helped me undersand memcpy and how its functions and used in code syntax


Source 2: https://stackoverflow.com/questions/76078825/delete-all-nodes-in-a-linked-list-in-c
i was stuck on removing the stroage used in my code to not have memory leak or error.
This website helped me udnersand the format to do so, I asked TA's if this is acceptedable currently waiting on response.

Valgrind:
----------------------
- best file to test: ./mdb-lookup  mdb-lookup

$ make valgrind
valgrind --leak-check=yes ./mdb-lookup ap-mdb
==1774525== Memcheck, a memory error detector
==1774525== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1774525== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1774525== Command: ./mdb-lookup ap-mdb
==1774525== 
lookup: jae
118: {i luv jae} said {my man jae is bae}
139: {jae woo lee} said {3 words, 3 letters, 1 s}
149: {Jae Kwon} said {Follow -> @jaeeekwon}
156: {jae woo bee} said {buzz buzz}
159: {jae} said {you all get A :)}
250: {jae the bae} said {no wae i'm feelin kinda}
lookup: ==1774525== 
==1774525== HEAP SUMMARY:
==1774525==     in use at exit: 0 bytes in 0 blocks
==1774525==   total heap usage: 866 allocs, 866 frees, 34,848 bytes allocated
==1774525== 
==1774525== All heap blocks were freed -- no leaks are possible
==1774525== 
==1774525== For lists of detected and suppressed errors, rerun with: -s
==1774525== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

