#include <stdbool.h>
#include <stdio.h>

bool isShuffled(int);
int getNumDigits(int);
int getSmallestDigit(int);
bool lookForDigit(int, int);

int main(void) {
  int num = 0;
  printf("Enter the number to check: ");
  scanf("%d", &num);
  if (isShuffled(num)) {
    printf("Shuffled!");
  } else {
    printf("Not shuffled!");
  }
  return 0;
}

bool isShuffled(int shuffledOrder) {
  bool isShuffled = true;
  int numOfDigits = getNumDigits(shuffledOrder);
  int smallestDigit = getSmallestDigit(shuffledOrder);

  for (int place = 0; (place < numOfDigits); place++) {
    if (!lookForDigit(shuffledOrder, smallestDigit + place)) {
      isShuffled = false;
    }
  }
  return isShuffled;
}

int getNumDigits(int num) {
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  //printf("Count: %d\n", count);
  return count;
}

int getSmallestDigit(int num) {
  int smallestDigit=10;
  int digit = 0;
  while (num != 0) {
    digit = num % 10;
    if (digit < smallestDigit) {
      smallestDigit = digit;
    }
    num /= 10;
  }
  //printf("Smallest: %d\n", smallestDigit);
  return smallestDigit;
}

bool lookForDigit(int num, int searchDigit) {
  int digit = 0;
  int foundDigit = 0;
  while (num != 0) {
    digit = num % 10;
    if (digit == searchDigit) {
      foundDigit++;
    }
    num /= 10;
  }
  //printf("Founddigit: %d\n", foundDigit);
  return foundDigit == 1;
}
