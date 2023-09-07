#include <stdio.h>

int main(void) {
  printf(
      "Enter number to convert to base 2: ");  // user input number less than 16
  int numInput;                                // initiate integer
  scanf("%d", &numInput);                      // assign integer to numInput
  int leastSigDig = numInput % 2;  // find remainder of (numInput/(2^0))/2
  int thirdMostSigDig =
      (numInput / 2) % 2;  // find remainder of (numInput/(2^1))/2
  int secMostSigDig =
      (numInput / 4) % 2;               // find remainder of (numInput/(2^2))/2
  int mostSigDig = (numInput / 8) % 2;  // find remainder of (numInput/(2^3))/2
  printf("The four digits of that number are as follows:\n");
  printf("Most significant digit: %d\n", mostSigDig);
  printf("Next digit: %d\n", secMostSigDig);
  printf("Next digit: %d\n", thirdMostSigDig);
  printf("Least significant digit: %d\n", leastSigDig);
  return 0;
}
