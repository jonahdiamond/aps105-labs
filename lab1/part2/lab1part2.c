#include <stdio.h>

int main(void) {
  printf("Enter the conversion rate: ");
  double convRate;
  scanf("%lf",
        &convRate);  // assigns number of CAD equivalent to variable convRate
  printf("Enter the amount to be converted (in foreign currency): ");
  double currencyAmount;
  scanf("%lf", &currencyAmount);
  double canadianAmount = convRate * currencyAmount;
  printf("The amount in Canadian Dollars is: %.2lf", canadianAmount);
  return 0;
}
