#include <stdio.h>
#include "gcd.h"
#include "prime.h"
  
 
// so i will do all the coding in this
// create a directive fuunction call at the beginning
// call those functions in here
// create a code file that works on gcd and prime and i will call them in here
// main code will be done here

// 
 

int main(){

/* STEP ONE: AVERAGE
read TWO  positive integers (of type int) from the user using scanf() function prints the following information, and then terminates: */

   int x;
   int y;
   float avg;

    printf("Enter 2 positive integers to find the average:\n ");

    scanf(" %d",&x);
    scanf(" %d",&y);

     	avg = (float) (x + y)/2;

	printf("You typed in %d and %d\n", x, y);
	printf("The average is: %f\n",avg);

   // STEP TWO: ACCESS GCD
  //In order to see if two numbers are relatively prime, you should calculate the GCD using Euclidean algorithm.
   // first make gcd file, then call gcd.h header, and in main.c do the math needed to find prime


	    // use parameter from scanf and the  function declaration from gcd.h and prime.h

     int my_gcd = gcd(x,y); 
     
	printf("The gcd is: %d\n",my_gcd);   


// STEP THREE: PRIME 
//// this gets the prime and relatively prime 

//  - determine: whether both number relative prime number or not 

 // take result from gcd.c, if gcd =1 then relative prime  
 int my_prme = gcd(x,y);

// access gcd.h
  if(my_prme == 1){ // main.c is printing this
    printf("The two numbers are relatively prime. \n");}
else{ printf("The two numbers are NOT relatively prime. \n");}



// this gets the prime from prime.h
// determines if x is prime, if y is prime
    int my_prime = prime(x,y); 

 
 }

