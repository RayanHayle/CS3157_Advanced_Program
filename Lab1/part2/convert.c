#include <stdio.h>

int main() { // main function 
    int x;
    scanf("%d", &x); // numer
    
    printf("signed dec: %d\n", x);
    printf("unsigned dec: %u\n", x);
    printf("hex dec: %x\n", x);
        
        
        /* convert 7 to binary 
    (a) modul 7(x) % 2 ---> r: 1
    (b) int 7 (x) / 2 ---> new x:  3
    (c) i =0 ----> index go up, index = 0
     
    (a) modul 3(x) % 2 ---> r: 1
    (b) int 3 (x) / 2 ---> new x: 1.5 but take int of it 
    (c) i = 1 ----> index go up, index = 0
    
    (a) modul 1(x) % 2 ---> r: 1
    (b) int 1 (x) / 2 ---> new x: 0.5 but take int of it 
    (c) i = 2 ----> index go up, index = 0
        
    (a) modul 0(x) % 2 ---> r: 0
    (b) int  0 (x) / 2 ---> new x: 0 but take int of it 
    (c) i = 3 ----> index go up, index = 0
    
    binary take the r from index ---> i =3, i =2, i =1, i =0
    go from MSB to LSB
    7 to binary == 0 1 1 0
    */
    
    printf("binary: ");
    
    /*
    - for loop: ilterate from the inex set at 31
    - thus will go down from 32 bit intger all the way down to i=0
    - i =0 is the least sig bit, it is the start precidure
    - i = 31 is the most signifit big, the last remainder stored here
    */
    for (int i = 31; i >= 0; i--) {
        
        /*
        - set a int varible so i can store somethign and print it
        - shift x to the right of index i postions; 
        - this will get LSP and MSP
        */
        int my_rem = (x >> i) & 1; // Extract each bit from left to right
        printf("%d", my_rem);
        
        // space after every 4 digits
        // the index is from 32, and i want spacing between each four digits
        // 32 and 4 are muitples of each other
        //and when i becomes a mutiple of 4 and no remiander will exit
        // i =4,8,16,32....
        // space will be added
        // 32 numbers will be showed in 8 groups, each with 4 digits
        if (i % 4 == 0) { // i = index
            printf(" ");
        }
    }
    printf("\n");
    return 0;

    
    
}
