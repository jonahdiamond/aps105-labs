#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int convert(int num, int base, int ndigits);

int main(void) {
  int baseInput, int1, int2, baseOutput, num1Digits = 0, num2Digits = 0, mod1,
                                         mod2;
  int num1Base10Digits, num2Base10Digits;
  int firstNumBaseTen = 0;
  int int1Copy /*copy of int1*/, int2Copy /*copy of int2*/, digit1,
      digit2 /*will check each indivudal digit for valid base*/;
  char operation;
  bool run = true;
  bool invalidOperand =
      false; /*used for exiting for loop when checking if operand is valid*/
  while (run) {
    printf("Give input ($ to stop): ");  // user input
    scanf(" %c", &operation);
    if (operation == '$') {
      run = false;
    } else {
      scanf(" %d %d %d %d", &baseInput, &int1, &int2, &baseOutput);
      int1Copy =
          int1;  // use num1 as representative of int1 that can be manipulated
      int2Copy = int2;  // same as above
      // check if operation is simple arithmetic operation
      if (operation != '+' && operation != '-' && operation != '/' &&
          operation != '*') {
        printf("Invalid operator\n");
        continue;
        //  check if base is between 2 and 10
      } else if (baseInput > 10) {
        printf("Invalid base\n");
        continue;
      } else if (baseInput < 2) {
        printf("Invalid base\n");
        continue;
      } else if (baseOutput > 10) {
        printf("Invalid base\n");
        continue;
      } else if (baseOutput < 2) {
        printf("Invalid base\n");
        continue;
      } else {
        // check if each input integer is valid for the original base

        while (int1Copy >
               0) { /*loops thru copy of int1 to see how many digits are in it*/
          num1Digits++;
          int1Copy /= 10;
        }
        int1Copy = int1;  // reset num1 to be a copy of int1
        for (int i = 0; i < num1Digits || i < num2Digits;
             i++) { /*loop thru int1 numDigits times to see if all digits are in
                       given base*/
          digit1 =
              int1Copy - ((int1Copy / 10) *
                      10);  // num1 - (num1/10)*10 leaves only the first digit
          digit2 = int2Copy - ((int2Copy / 10) * 10);
          if (digit1 >=
              baseInput) {  // if the digit >= the input base, it's wrong
            printf("Invalid digits in operand\n");
            invalidOperand =
                true;  // this is how to break out of the for loop and then
                       // later on continue the while loop*/
            break;
          } else if (digit2 >= baseInput) {
            printf("Invalid digits in operand\n");
            invalidOperand = true;
            break;
          }
        }
        while (int2Copy > 0) {  // count num of digits
          num2Digits++;
          int2Copy /= 10;
        }
        int2Copy = int2;
        if (invalidOperand) {
          invalidOperand = false;
          continue;
        }
      }
      int1Copy = int1; /*reset num1 to copy of int1*/
      int2Copy = int2; /*same as above*/
      int num1BaseN = convert(int1Copy, baseInput, num1Digits);
      int num2BaseN = convert(int2Copy, baseInput, num2Digits);
      int result;
      switch (operation) {
        case '+':
          result = num1BaseN + num2BaseN;
          break;
        case '*':
          result = num1BaseN * num2BaseN;
          break;
        case '-':
          result = num1BaseN - num2BaseN;
          break;
        case '/':
          result = num1BaseN / num2BaseN;
          break;
        default:
          break;
      }

      // Construct the output string
      // It is constructed backwards since we don't know how long it'll be.
      // It better be smaller than 99 + 1 (null) characters, otherwise bad
      // stuff happens. This is neceassarily correct, since the longest string
      // will be in base 2, and int uses 32 bits, so the longest we can get is
      // if it uses all 32 bits plus the null termiator, so max 33 size is
      // needed.
      char outputString[100];
      int i;
      for (i = 0; result > 0; i++) {
        int rem = result % baseOutput;
        result /= baseOutput;
        outputString[i] = '0' + (char)rem;
      }
      outputString[i] = '\0';
      // Reverse the output string, to make it correct
      int len = (int)strlen(outputString);
      for (i = 0; i < len / 2; i++) {
        char tmp = outputString[i];
        outputString[i] = outputString[len - i - 1];
        outputString[len - i - 1] = tmp;
      }
      printf("%d %c %d (base %d) = %d %c %d = %s (base %d)\n", int1, operation,
             int2, baseInput, num1BaseN, operation, num2BaseN, outputString,
             baseOutput);
    }
  }
  return 0;
}

int convert(int num, int base, int ndigits) {
  int result = 0;
  for (int i = 0; i < ndigits; i++) {
    int rem = num % 10;
    result += rem * (int)pow(base, i);
    num /= 10;
  }
  return result;
}
