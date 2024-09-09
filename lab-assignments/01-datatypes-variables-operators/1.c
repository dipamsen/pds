/*
Write a C program to find the perimeter and squared area of a
triangle. The corners of a triangle [A(x1, y1), B(x2, y2) and C(x3, y3)]
should be provided by the user through keyboard. Use appropriate
prompts to the user for passing the inputs from the keyboard and display
the output. [25 marks]
Perimeter of a triangle = AB+BC+CA, where AB, BC and CA are the
lengths of sides of triangle.
Squared area = S(S-AB)(S-BC)(S-CA), where S = Perimeter/2
*/

#include <stdio.h>
#include <math.h>

int main() {
	
	float x1, y1, x2, y2, x3, y3;
	
	printf("Enter coordinates of first point: \n");
	scanf("%f %f", &x1, &y1);
	
	printf("Enter coordinates of second point: \n");
	scanf("%f %f", &x2, &y2);
	
	printf("Enter coordinates of third point: \n");
	scanf("%f %f", &x3, &y3);
	
	float AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	float BC = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	float CA = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	
	float perimeter = AB + BC + CA;
	
	float S = perimeter / 2;
	
	float sarea = S * (S - AB) * (S - BC) * (S - CA);
	
	printf("Perimeter of given triangle: %.2f\n", perimeter);
	
	printf("Squared Area of given triangle: %.2f\n", sarea);
		
	return 0;
}
