#include "des.h"

const int box[4][4]= {
    {10, 0, 12, 8},
    {5, 11, 3, 2},
    {1, 9, 14, 4},
    {7, 6, 15, 13}
};

const int key[3][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {0, 1, 0, 1}
};

/*
 *  Cross Wire will be presented as the example seen in class:
 *     D1->D3   D2->D1    D3->D4    D4->D2
 */
void crossWire(int *data){
  int temp[4];

  for(int i=0; i<4; i++){
    temp[i] = data[i];
  }
  data[0] = temp[2];
  data[1] = temp[0];
  data[2] = temp[3];
  data[3] = temp[1];
}

/*
*   Name: getLeft
*
*   Function: Separates the full array of bits into the first 4
*
*   Input: Array to carry the first 4 bits and array with the
*          whole number
*/
void getLeft(int *left, int number[]) {
  for(int i=0; i<4; i++){
    left[i] = number[i];
  }
}

/*
*   Name: getRight
*
*   Function: Separates the full array of bits into the last 4
*
*   Input: Array to carry the last 4 bits and array with the
*          whole number
*/
void getRight(int *right, int number[]) {
  for(int i=0; i<4; i++){
    right[i] = number[i+4];
  }
}

/*
*   Name: xorOperation
*
*   Function: Performs the xor operation to all the bits of a
*             given array
*
*   Input: Array to perform the xor with and the key on which
*          you will perform the xor
*/
void xorOperation(int *data, const int key[4]) {
  for(int i=0; i<4; i++){
    data[i] = data[i]^key[i];
  }
}

/*
*   Name: toArray
*
*   Function: Saves the string of numbers to an array
*             of numbers
*
*   Input: String containing the numbers
*/
void toArray(char* c) {
	for(int i=0; i<8; i++){
		data[i]=c[i]-48;
  }
}

/*
*   Name: toDecimal
*
*   Function: Changes 2-bit binary number into a decimal
*             number
*
*   Input: Array with a binary number to be converted
*
*   Output: Returns the decimal conversion
*/
int toDecimal(int *binaryNum) {
  int decimalNum = 0;
  decimalNum = binaryNum[1] + binaryNum[0]*2;
  return decimalNum;
}

/*
*   Name: toBinary
*
*   Function: Changes a 4 digit decimal number to a binary
*             number
*
*   Input: Decimal number to be converted and array to store
*          the binary number
*/
void toBinary(int decimalNum, int * binaryNum) {
  int k;
  int tempNum[5];
  int i=3;

  for (int c=4; c>=0; c--){
    k = decimalNum >> c;
    if(k&1)
      tempNum[c] = 1;
    else
      tempNum[c]=0;
  }

  for(int j=0; j<4; j++){
    binaryNum[j] = tempNum[i];
    i--;
  }
}


/*
*   Name: appendMessage
*
*   Function: joins the first and the second part of a
*             message into a complete one
*
*   Input: Array to store the final message, the first
*          and second message arrays
*/
void appendMessage(int *message, int *first, int *second){
  for (int i=0; i<4; i++) {
    message[i] = first[i];
    message[i+4] = second[i];
  }
}

/*
*   Name: printNumber
*
*   Function: prints the complete list of numbers
*
*   Input: The number to be printed
*/
void printNumber(int *number) {
  for (int i=0; i<8; i++) {
    printf("%d", number[i]);
  }
  printf("\n");
}

/*
 *  DES FUNCTION
 */
void des(int number[]){

  // Dividing Variables
  int leftPart[4];
  int rightPart[4];
  int changedPart[4];

  // Table looking variables
  int firstTable[2];
  int secondTable[2];

  int binaryNum[4];

  printf("\nEncrypting message...\n");

  for(int j=0; j<3; j++){
    // Separate into 2 arrays
    getLeft(leftPart, number);
    getRight(rightPart, number);
    getRight(changedPart, number);

    // Mix the right array
    crossWire(changedPart);

    // Perform key xor
    xorOperation(changedPart, key[j]);

    firstTable[0] = changedPart[0];
    firstTable[1] = changedPart[3];
    secondTable[0] = changedPart[1];
    secondTable[1] = changedPart[2];

    int row = toDecimal(firstTable);
    int column = toDecimal(secondTable);

    // trasform the decimal value from the box to a binary one
    toBinary(box[row][column], binaryNum);

    // Xor with table
    xorOperation(changedPart, binaryNum);

    // xor with left
    xorOperation(changedPart, leftPart);

    // join the two parts of the final number
    appendMessage(number, rightPart, changedPart);

    printf("\t> Iteration number %d: ",j);
    printNumber(number);
  }
  printf("The Encrypted Message is: ");
  printNumber(number);
}
