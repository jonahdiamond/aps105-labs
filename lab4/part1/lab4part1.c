#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int getAscendingOrderedDigits(int number) { /*don't submit on examify!!!*/
  int digits[10] = {0};

  while (number > 0) {
    digits[number % 10]++;
    number /= 10;
  }

  int i = 0;
  while (i < 10) {
    if (digits[i] > 0) {
      number *= 10;
      number += i;
      digits[i]--;
    } else {
      i++;
    }
  }
  return number;
}

int reverseNumber(int number) {
  int dig1, dig2, dig3, dig4, result;
  for (int i = 0; i < 4; i++) {
    switch (i) {
      case 0:
        dig1 = number % 10;
        number /= 10;
        result = dig1 * 1000;
        break;
      case 1:
        dig2 = number % 10;
        number /= 10;
        result += dig2 * 100;
        break;
      case 2:
        dig3 = number % 10;
        number /= 10;
        result += dig3 * 10;
        break;
      case 3:
        dig4 = number % 10;
        number /= 10;
        result += dig4;
        break;
    }
  }
  return result;
}

int getNumber() {
  int number = 0, numDigits = 0, numCopy;
  bool fourDigits = false;
  while (fourDigits == false) {
    number = 0, numDigits = 0;
    printf("Enter a number (-1 to stop): ");
    scanf(" %d", &number);
    if (number == -1) {
      fourDigits = true;
    } else {
      numCopy = number;
      while (numCopy > 0) {
        numDigits++;
        numCopy /= 10;
      }
      if (numDigits < 4) {
        printf("Error: The number is too small.\n");
        number = 0;
      } else if (numDigits > 4) {
        printf("Error: The number is too large.\n");
        number = 0;
      } else {
        fourDigits = true;
      }
    }
  }
  return number;
}

int main() {
  int number;
  bool neg1 = false;
  while (neg1 == false) {
    number = getNumber();
    int numIterations = 0;
    if (number == -1) {
      neg1 = true;
    } else {
      
       while (number != 6174) {
        printf("Number %d: %d\n", numIterations+1, number);
        numIterations++;
        int ascendNum = getAscendingOrderedDigits(number);
        int descendNum = reverseNumber(ascendNum);
        number = descendNum - ascendNum;
        
        }
      printf("Number %d: %d\nKaprekar's Constant was reached in %d iteration(s)\n", numIterations+1, number,
                (numIterations));
    }
  }
  return 0;
}
