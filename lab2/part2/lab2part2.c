#include <math.h>
#include <stdio.h>

int main(void) {
  double xValue, yValue;
  const int origin = 0;
  printf("Enter the x-coordinate in floating point: ");
  scanf("%lf", &xValue);
  printf("Enter the y-coordinate in floating point: ");
  scanf("%lf", &yValue);
  xValue = round(xValue * 100) / 100;
  yValue = round(yValue * 100) / 100;
  if (xValue > origin && yValue > origin) {
    printf("\n(%.2lf, %.2lf) is in quadrant I.\n", xValue, yValue);
  } else if (xValue < origin && yValue > origin) {
    printf("\n(%.2lf, %.2lf) is in quadrant II.\n", xValue, yValue);
  } else if (xValue < origin && yValue < origin) {
    printf("\n(%.2lf, %.2lf) is in quadrant III.\n", xValue, yValue);
  } else if (xValue < origin && yValue > origin) {
    printf("\n(%.2lf, %.2lf) is in quadrant II.\n", xValue, yValue);
  } else if (xValue > origin && yValue < origin) {
    printf("\n(%.2lf, %.2lf) is in quadrant IV.\n", xValue, yValue);
  } else if (xValue == origin && yValue != origin) {
    printf("\n(%.2lf, %.2lf) is on the y axis.\n", xValue, yValue);
  } else if (xValue != origin && yValue == origin) {
    printf("\n(%.2lf, %.2lf) is on the x axis.\n", xValue, yValue);
  } else {
    printf("\n(%.2lf, %.2lf) is at the origin.\n", xValue, yValue);
  }
  return 0;
}
