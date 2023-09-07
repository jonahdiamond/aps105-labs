#include <math.h>
#include <stdio.h>

int main(void) {
  double const lbsToKilos = 0.4536, inchesToMetres = 1 / 39.37,
               ftToMetres = 1 / 3.28;
  double weight, height, bodyMassIndex;
  /*need to create 2 character variables for weight and 3 for height
      since user will input either 'kg' or 'lb' for weight
      and 'in', 'ft' or 'mt' for height*/
  char weightUnit1, weightUnit2, heightUnit1, heightUnit2;
  printf("Enter the body weight: ");
  scanf("%lf %c%c", &weight, &weightUnit1, &weightUnit2);
  /*check if units are lb in order to convert to kg*/
  if (weightUnit1 == 'l') {
    weight = weight * lbsToKilos;
  }
  printf("Enter the height: ");
  scanf("%lf %c%c", &height, &heightUnit1, &heightUnit2);
  /*check if units are in or ft in order to convert to mt*/
  if (heightUnit1 == 'i') {
    height = height * inchesToMetres;
  } else if (heightUnit1 == 'f') {
    height = height * ftToMetres;
  }
  /*calculate BMI*/
  bodyMassIndex = round((weight / (height * height)) * 10) / 10;
  /*output BMI with corresponding category*/
  if (bodyMassIndex < 18.5) {
    printf(
        "\nThe Body Mass Index (BMI) is: %.1lf\n"
        "Category: Underweight",
        bodyMassIndex);
  } else if (bodyMassIndex >= 18.5 && bodyMassIndex < 25.0) {
    printf(
        "\nThe Body Mass Index (BMI) is: %.1lf\n"
        "Category: Healthy Weight",
        bodyMassIndex);
  } else if (bodyMassIndex >= 25.0 && bodyMassIndex < 30.0) {
    printf(
        "\nThe Body Mass Index (BMI) is: %.1lf\n"
        "Category: Overweight",
        bodyMassIndex);
  } else {
    printf(
        "\nThe Body Mass Index (BMI) is: %.1lf\n"
        "Category: Obesity",
        bodyMassIndex);
  }
  return 0;
}
