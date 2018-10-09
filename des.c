#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int box[4][4]= {
    {10, 0, 12, 8},
    {5, 11, 3, 2},
    {1, 9, 14, 4},
    {7, 6, 15, 13}
};

const int key1[4] = {0, 0, 0, 0};
const int key2[4] = {1, 1, 1, 1};
const int key3[4] = {0, 1, 0, 1};

int data[8];

/*
 *  Cross Wire will be presented as the example seen in class:
 *     D1->D3   D2->D1    D3->D4    D4->D2
 */
void crossWire(int data[]){

}

void getLeft(int *left, int number[]) {
  for(int i=0; i<4; i++){
    left[i] = number[i];
  }
}

void getRight(int *right, int number[]) {
  for(int i=0; i<4; i++){
    right[i] = number[i+4];
  }
}

void des(int number[]){
  int firstPart[4];
  int secondPart[4];

  getLeft(firstPart, data);
  getRight(secondPart, data);

   for(int i=0; i<4; i++)
     printf("%d", secondPart[i]);
}


void toArray(char* c){
	for(int i=0;i<8;i++){
		data[i]=c[i]-48;
  }
}

int main() {
  // Asumes correct input of user
  char number[8];

  printf("Enter a 8 bit binary number\n");
  printf("INSERT DATA: ");
  scanf("%s", number);

  if(strlen(number)>8){
    printf("ERROR THE PROGRAM WILL END");
    return 0;
  }
  else {
    toArray(number);
    des(data);
  }
}
