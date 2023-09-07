#include <stdio.h>

int main(void) {
	const double CmPerInch = 2.54;
	const double CmPerMetre = 100.00;
	const int InchesPerFoot = 12;
	const int InchesPerYard = 36;
	
	double distance;
	printf("Please provide a distance in metres: ");
	scanf("%lf", &distance);
	
	double distanceInInches = distance * CmPerMetre / CmPerInch;
	
	// truncate fractional part to get # of inches
	int inches = (int) distanceInInches;
	double inchesRemainder = distanceInInches - inches;
	
	int yards = inches / InchesPerYard;
	
	// how many inches are left after extracting yards
	int inchesAfterYards = inches % InchesPerYard;
	
	int feet = inchesAfterYards / InchesPerFoot;
	
	// how many inches are left after extracting feet
	int inchesAfterFeet = inchesAfterYards % InchesPerFoot;
	
	printf("%d yards, %d feet, %d inches, %.2lf inches remainder\n", yards, feet, inchesAfterFeet, inchesRemainder);
	
	return 0;
}
