   - your name
   - your UNI
   - lab assignment number
   - name: Rayan Hayle
   - UNI: Rah2236
   - lab assignment number: Lab 1
   - answers to academic honesty questions
   - description for each part

Please answer the academic honesty questions.

[1] [ANSWER: YES CHEATING: You cannot use a tutor to assist with labs, it's your job to do it and if your'er stuck go to TA's.]
 
[2] [ANSWER: YES CHEATING: Looking at other labs answers is clearly cheating, you were infulenced by others labor.]

[3] [ANSWER: YES CHEATING: Having access to a cheatsheet is cheating regardless of usage of such cheatsheet. ]

[4] 
       [A] [ANSWER: NO CHEATING: You are simply talking about a subject not showing each other labs.]

       [B] [ANSWER: YES CHEATING:  you might be stuck and therefore you see their solution.

       [C] [ANSWER: NO CHEATING: Discussion on learning subject is not cheating, no labs and exams are being discussion, it is just about opinions on course subjects] 

[5] [ANSWER: YES CHEATING: I'm not fully sure on this, we can search on the internet if we are stuck on a task like how to delete a file or such things, but searching on the internet for solutions about your lab is inherently cheating.]

[6] [ANSWER: NO CHEATING: Issues such as errors and compilation errors can be searched on google, because it does not give you solution to your lab it only provides guidance on how to undersand your editor.

[7] [ANSWER: YES CHEATING: You searched for solutions, that is cheating regardless of what did to understand the solution.  

Part 0
 Please write your answers after [ANSWER] on the same line.  Our auto-grading
 script will look for lines that contain [ANSWER].

-[0.1][ANSWER] 
[0.1][ANSWER] git int  -->  init creates a empty git repository, which you do not need for labs after cloning. 

[0.2][ANSWER] git clone 

[0.3][ANSWER] git checkout --> it let's you check out updates in the working directory and reverted back to the previous version. 

-[0.2][ANSWER] 
[0.4][ANSWER] git reset HEAD -->  this command resets the current HEAD and discard the staged change, and you'll have last committed version. 

-[0.3][ANSWER] 

-[0.4][ANSWER] 




--------------------------------------------------------------------------

Part 1
------

In Main.c: uses gcdh.h and prime.h 
------
First i calculate the average main.c;
And then i went to gcd.c file to calculator the gcd and called the function in main.c using a header called gcd.h
In prime.c  i called the gcd.c function to get the result, if the gcd from gcd.h is 1, then the two numbers are relatively prime
I will print the result from prime.c in main.c using a header and accessing its output value 
And then in prime.c i calculated if each user input integer is prime or not

In gcd.c
------

To find the prime relativity of a number,I know that two numbers are relatively prime if their gcd is 1.
To find the gcd of two integers, these are the steps i toke:

To divide, I need to make a number the dividend (top number in a friction) and a number the divisor (bottom number in a fraction)

To do this: i created two if methods
If x is greater than y : then x is the dividend and y is the divisor 
If y is greater than y : then y is the dividend and x is the divisor 

 While my divorce is not 0, because you cannot dive over a zero: i took these further steps in a while:
Find my remainder using module 
Next → set the remainder as  my new divisor 
Next → set my previous divisor and my new dividend
Next → repeat the loop until my diviors is 0
When my divisor is zero → break out of while loop and return my last dividend as the gcd 
When i found my gcd by getting my last dividend as gcd
In main.c → call gcd.h using #include “gcd.h”
Set an int and a variable name to store the accessed value from gc.d
Then print the result from gcd

In prime.c:  uses gcd.h
------
In prime.c  i called the gcd.c function to get the result, if the gcd from gcd.h is 1, then the two numbers are relatively prime 
To find if a number is prime i took the following actions: I need to will test each number input 
I created a int variable that is set to 1, as an indication of that the number is prime until it goes through the if and for loops tests
I tested if x and y are less than or equal to 1.because prime number is a whole number 
I tested if x = 1 and y =1 because 1 is not a prime number.
I tested if y= 2 and y=2. The reason for this is because: in my for loop, my index starts at i = 2, which skips to test if my (x,y) are 2.

In my test I made a two for loop with an index i =2 to start and loop until the i is one less than the x and y.
 Then I calculated the remainder of i and x,y in my two for loops.
 When I tested them I set my int variable to 0, if the remainder was 0. And that means its not prime. I set my int variable to 1, if the remainder was 1 or more, which means the number is prime.
Then I printed what int 1 meant and int 2.
Then i accessed this in my main.c using the function header prime.h

