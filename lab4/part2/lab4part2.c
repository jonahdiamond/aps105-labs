#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
  bool run = true;  // if order is -1, run= false, stop running code
  while (run) {
    int order = 0, x0Coeff = 0, x1Coeff = 0, x2Coeff = 0, x3Coeff = 0;
    printf("Enter the order of the function: ");
    scanf(" %d", &order);
    if (order == -1) {
      run = false;  // if order is -1, end run
    } else if (order <= 3 &&
               order >=
                   0) {  // order has to be between 0 and 3, otherwise don't run
      for (int i = 0; i <= (order); i++) {  // request coefficients equal amount
                                            // of times to order of function
        printf("Enter coefficient of x^%d: ", i);
        switch (i) {
          case 0:
            scanf(" %d", &x0Coeff);
            break;
          case 1:
            scanf(" %d", &x1Coeff);
            break;
          case 2:
            scanf(" %d", &x2Coeff);
            break;
          case 3:
            scanf(" %d", &x3Coeff);
            break;
        }
      }
      for (int y = 10; y >= -10; y--) {    // y values
        for (int x = -10; x <= 10; x++) {  // x values
          if (y == x * x * x * x3Coeff + x * x * x2Coeff + x * x1Coeff +
                       x0Coeff) {  // if graph = graph, graph function with *
            printf(" * ");         // priority over x and y axes
          } else if (x == 0) {     // print y axis
            printf(" | ");
          } else if (y == 0) {  // print x axis
            printf(" - ");
          } else {
            printf("   ");  // if there is no graph value for a space, print
                            // nothing
          }
        }
        printf("\n");  // go to new line after printing horizontal line
      }
    } else {
      printf("The order must be between [0, 3].\n");
    }
  }
}
