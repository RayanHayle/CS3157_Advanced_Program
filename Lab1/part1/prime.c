#include <stdio.h>
#include "prime.h"



int prime(int x, int y) {

// 1 - determine: whether each number is a prime number or not 

// int to check if my x and y are prime    
int x_prime = 1;
int y_prime = 1;

if(x <=1){ // x less than 0 --> not prime
         x_prime =0;}
         
if(y <=1){ // y less than 0 --> not prime
         y_prime =0;}
    
    // Check if x and y are both equal to 1, 1 is not prime
if (x == 1 && y == 1) {
        x_prime = 0;
        y_prime = 0;}
    
 
 // Check if x is equal to 2, my index 2 starts at 2
  // Check if y is equal to 2, my index 2 starts at 2

if (x == 2) { x_prime = 1;}
    
if (y == 2) { y_prime = 1;}
        

for(int i = 2; i < x; i){
    if (x % i == 0){
         x_prime = 0; // x is not prime
         break;}}

for(int i = 2; i < y; i){
    if (y % i ==0){
         y_prime = 0; // y is not prime
         break;}}

    
    // PRINTING RESULTS
    if (x_prime == 0) {printf (" %d is NOT Prime. \n", x);}
    else if (x_prime == 1) {printf (" %d IS Prime.\n", x);}
    

    if (y_prime == 0) {printf (" %d is NOT Prime.\n", y);}
    else if (y_prime == 1) {printf (" %d IS Prime.\n", y);    }
  
   return 0;
   
}
