
#ifndef DES_H
#define DES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int data[8];

/* Datatype functions */
void toArray(char* c);
int toDecimal(int *binaryNum);
void toBinary(int decimalNum, int *binaryNum);

/* Helper functions */
void xorOperation(int *data, const int key[4]);
void getLeft(int *left, int number[]);
void getRight(int *right, int number[]);
void printNumber(int *number);
void appendMessage(int *message, int *first, int *second);
void crossWire(int *data);

/* Main function */
void des(int number[]);

#endif
