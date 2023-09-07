#include <math.h>
#include <stdio.h>

int main(void) {
  printf("Enter the radius of the circle: ");
  int radius;
  scanf("%d", &radius);
  for (int y = -radius; y <= radius; y++) {
    for (int x = -radius; x <= radius; x++) {
      if ((radius * radius) >= (x * x) + (y * y)) {
        printf("o");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

/*#include <math.h>
#include <stdio.h>

int main(void) {
  printf("Enter the radius of the circle: ");
  int radius;
  char o = 'o';
  char dot = '.';
  scanf("%d", &radius);
  for (int y = -radius; y <= radius; y++) {
    for (int x = -radius; x <= radius; x++) {
      if ((radius * radius) >= (x * x) + (y * y)) {
        printf("%2c", o);
      } else {
        printf("%2c", dot);
      }
    }
    printf("\n");
  }
}
*/
