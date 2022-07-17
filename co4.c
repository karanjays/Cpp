//1. Implement Booth’s Algorithm in C. Show the output of multiplication of your implementation for the following cases: 
//(i) Both positive numbers 
//(ii) Positive multiplier and negative multiplicand 
//(iii) Negative multiplier and positive multiplicand 
//(iv) Both numbers negative 
//Code:- 


#include <stdio.h> 
#include <math.h> 
int a = 0, b = 0; 
int a_bin[8] = {0}, b_bin[8] = {0}, p_bin[8] = {0}; 
int a_comp[8] = {0}, b_comp[8] = {0}, anumcp[8] = {0}; 
int res[8] = {0}, comp[8] = {1,0,0,0,0,0,0,0}; 
void binary (); 
void arshift (); 
void add ( int num[] );
int main () 
{ 
 int i, q = 0; 
  
 printf ( "\n Enter A : " ); 
 scanf ( "%d",&a ); 
 printf ( "\n Enter B : " ); 
 scanf ( "%d", &b ); 
  
 binary (); 
 printf ( "\n Binary Equivalents are : " );  printf ( "\n A (Q) = " ); 
 for ( i = 7; i >= 0; i-- ) 
 printf ( "%d", a_bin[i] ); 
 printf ( "\n B (M) = " ); 
 for ( i = 7; i >= 0; i--) 
 printf ( "%d", b_bin[i] ); 
 printf ( "\n B'' (-M) = "); 
 for ( i = 7; i >= 0; i-- ) 
 printf ( "%d", b_comp[i] ); 
  
 for ( i = 0; i <= 7; i++ ) 
 { 
 if ( a_bin[i] == q )
 { //just shift for 00 or 11 
 arshift (); 
 q = a_bin[i]; 
 } 
 else if ( a_bin[i] == 1 && q == 0) 
 { //subtract and shift for 10 
 add ( b_comp ); //add two's complement to implement subtraction  arshift (); 
 q = a_bin[i]; 
 } 
 else 
 { //add ans shift for 01 
 add ( b_bin ); //add to implement addition 
 arshift (); 
 q = a_bin[i]; 
 } 
 } 
 printf ( "\n\n Product is :\n" ); 
 printf ( " Decimal = %d\n", a * b ); 
 printf ( " Binary = " ); 
 for ( i = 7; i >= 0; i-- ) 
 printf ( "%d", p_bin[i] ); 
 for ( i = 7; i >= 0; i-- ) 
 printf ( "%d", anumcp[i] );
 return 0; 
} 
void binary () 
{ 
 int a1, b1, r1, r2, i, temp, carry;  a1 = a; 
 b1 = b; 
 for ( i = 0; i <= 7; i++ ) 
 { 
 r1 = a1 % 2; 
 a1 = a1 / 2; 
 r2 = b1 % 2; 
 b1 = b1 / 2; 
  
 a_bin[i] = r1; 
 b_bin[i] = r2; 
 anumcp[i] = r1; 
 if ( r2 == 0 ) 
 b_comp[i] = 1; 
 if ( r1 == 0 ) 
 a_comp[i] = 1; 
 } 
 carry = 0; 
 for ( i = 0; i <= 7; i++ )
 { 
 res[i] = comp[i] + b_comp[i] + carry;  if ( res[i] >= 2 ) 
 carry = 1; 
 else 
 carry = 0; 
 res[i] = res[i] % 2; 
 } 
  
 for ( i = 7; i >= 0; i-- ) 
 b_comp[i] = res[i]; 
  
 if ( a < 0 ) 
 { 
 carry = 0; 
 for ( i = 7; i >= 0; i-- ) 
 res[i] = 0; 
 for ( i = 7; i >= 0; i-- ) 
 { 
 res[i] = comp[i] + a_comp[i] + carry;  if ( res[i] >= 2) 
 carry = 1; 
 else 
 carry = 0; 
 res[i] = res[i] % 2;
 } 
 for ( i = 7; i >= 0; i-- ) 
 { 
 a_bin[i] = res[i]; 
 anumcp[i] = res[i]; 
 } 
 } 
  
 if ( b < 0 ) 
 for ( i = 0; i <= 7; i++ ) 
 { 
 temp = b_bin[i]; 
 b_bin[i] = b_comp[i]; 
 b_comp[i] = temp; 
 } 
} 
void arshift () 
{ 
 int temp1 = p_bin[7], temp2 = p_bin[0], i;  for ( i = 1; i <= 7; i++ ) 
 p_bin[i-1] = p_bin[i]; 
 p_bin[7] = temp1; 
 for ( i = 1; i <= 7; i++ ) 
 anumcp[i-1] = anumcp[i];
 anumcp[7] = temp2; 
  
} 
  
void add ( int num[] ) 
{ 
 int i, carry = 0; 
 for ( i = 0; i <= 7; i++ ) 
 { 
 res[i] = p_bin[i] + num[i] + carry;  if ( res[i] >= 2 ) 
 carry = 1; 
 else 
 carry = 0; 
 res[i] = res[i] % 2; 
 } 
 for ( i = 7; i >= 0; i-- ) 
 p_bin[i] = res[i]; 
 for ( i = 7; i >= 0; i-- ) 
 p_bin[i] = res[i]; 
} 

