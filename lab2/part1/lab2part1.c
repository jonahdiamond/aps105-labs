#include <math.h>
#include <stdio.h>

int main(void) {
  double xLength, yLength, hLength, angle, PI = M_PI, radToDeg = 180 / PI;
  printf("Enter X: ");
  scanf("%lf", &xLength);
  printf("Enter Y:");
  scanf("%lf", &yLength);
  /*take the x and y lengths,
  square and then add them,
  then take the sqrt to get the hyopteneuse*/
  hLength = sqrt(xLength * xLength + yLength * yLength);
  /*inverse sin of y side divided by hypoteneuse will return a radian value
  so we turn it to degrees at the end*/
  angle = asin(yLength / hLength) * radToDeg;
  printf(
      " The Hypotenuse Length is: %.1lf\n"
      "The Angle Theta is: %.1lf degrees",
      hLength, angle);
  return 0;
}
