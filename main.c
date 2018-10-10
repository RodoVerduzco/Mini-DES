/*
*
*   Program :   main.c
*
*   Author  :  Jose Rodolfo Verduzco Torres
*              Maria Fernanda Delgado Radillo
*
*   Purpose :
*              This program generates the mini DES algorithm for
*              encryption and decryption.
*
*   Usage  :
*              The program asks for an 8-bit number to be encrypted,
*              and the program does everything
*
*   Restrictions:
*              The Encrypted and decrypted message has to be of exactly
*              8-bit
*/

#include "des.h"

/*
*
*   Name: main
*
*   Purpose:  Handles the whole program by calling the main
*             functions. The program only works for 8-bit
*             numbers
*/
int main() {
  char number[8];

  // Asumes correct input of user
  printf("Enter a 8 bit binary number\n");
  printf("INSERT DATA: ");
  scanf("%s", number);

  // Passes the number to an array
  toArray(number);

  // Main encryption function
  des(data);
}
