#include <stdio.h>
#include "gcd.h"

int gcd( int x, int y) {

	 // prime is found by gcd. if gcd is for x,y is 1, then it is relatively prime!

        // i have two base cases, when x or y are o, then gcd is the other

	int my_divide;
	int my_divisor;


/* to divide:
I set which int is the top as my my_divide
I set which int is the bottom as my my_divisor

*/
  
 if ( x >= y){
     my_divide = x;
     my_divisor = y;
 }
    if  (y >= x){ // if y is greater than it's top
     my_divide = y;
     my_divisor = x;
 }
 


while(my_divisor!=0){ // can't divide over a  zero 

    /* I can find remainder using modulo
    remainder large number / small number
    i used my_divide to find top number
    i used my_divisor to find bottom number  */

    // step 1) 33 % 12 --> 33 is my_divide, 12 is my_divisor
    
	int my_remainder = my_divide % my_divisor; 
    
    /* step 2) 
    (a) rest my my_divisor to be in the position of my_divide
    (b) reset  my_remainder to be in the position of my_divisor
  
    (a1) for next operation I need my_divide I get that from the current
    my_divisor
    (b1) for the next operation I need a my_divisor I get that from the current myremainder
    */
     
	my_divide =  my_divisor;
     	my_divisor = my_remainder;
     
     // now we need new remainder, the computer will go back up to the loop until  my_divisor is 0

    }
    
    // when my_divisor = 0, I will return the last my_divide as gcd 
    	
	return my_divide;

}
