//
// APS105-W23 Lab 2 Part 4
//
// Program that reads in an encoded 4-digit combination, and
// prints the original combination. A combination is simply encrypted
// by swapping the 1st and 4th digits and replacing the 2nd and
// the 3rd digits by their 9's complement.
//
// Assumption: The input is a valid 4-digit integer
//
// The program works for 0000, but not for other numbers!

#include <stdio.h>

int main(void) {
  int encComb;
  printf("Enter an encrypted 4-digit combination: ");
  scanf("%d", &encComb);

  // Determine the 4 digits of the encrypted combination.
  int d4, d3, d2, d1;
  d4 = encComb / 1000;       // get the first digit
  encComb = encComb % 1000;  // remove the first digit
  d3 = encComb / 100;        // get the second digit
  encComb = encComb % 100;   // remove the second digit
  d2 = encComb / 10;         // get the third digit
  encComb = encComb % 10;    // remove the third digit
  d1 = encComb;              // get the remaining digit
  /*the only thing I did was switch each / for a % and vice versa,
  and then put the d_ lines before the lines that changed the input code*/

  // printing the decrypted combination: d4 and d1 are swapped. d3 and d2 are
  // are 9's complemented
  printf("\nThe real combination is: %d%d%d%d\n", d1, 9 - d3, 9 - d2, d4);

  return 0;
}
