#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 50

typedef struct complex {
	float re, im;
} Complex;

typedef struct alien {
	char name[MAX_LEN];
	Complex ages[3];
	float real_age;
} Alien;


float modulus(Complex c) {
	return sqrt(c.re * c.re + c.im * c.im);
}

int main() {
	srand(time(NULL));
	
	int population_size, num_of_complex_nums_in_age = 3;
	printf("Enter the population size of aliens: ");
	scanf("%d", &population_size);
	Alien *aliens = (Alien *)malloc(population_size * sizeof(Alien));
	
	float max_age = 0;
	Alien leader;

	for (int i = 0; i < population_size; i++) {
		printf("Enter name for alien %d: ", i + 1);
		scanf("%s", aliens[i].name);
		
		for (int j = 0; j < num_of_complex_nums_in_age; j++) {
			printf("\tEnter complex number (real, imaginary) in age[%d]: ", j);
			scanf("%f %f", &aliens[i].ages[j].re, &aliens[i].ages[j].im);
		}
		
		// we can immediately calculate real age
		aliens[i].real_age = 0;
		for (int j = 0; j < num_of_complex_nums_in_age; j++) {
			aliens[i].real_age += modulus(aliens[i].ages[j]);
		}
		aliens[i].real_age /= num_of_complex_nums_in_age;
		
		if (aliens[i].real_age > max_age) {
			max_age = aliens[i].real_age;
			leader = aliens[i];
		}
	}
	printf("\n");
	
	int max_count = 0;
	
	for (int i = 0; i < population_size; i++) {
		printf("Finding for '%s':\n", aliens[i].name);
		printf("\tAge --> %f\n", aliens[i].real_age);
		if (aliens[i].real_age == max_age) max_count++;
	}
	printf("\n");
	

	
	if (max_count == 1) {
		printf("Selected '%s' as leader.\n", leader.name);
	} else {
		int contenders[MAX_LEN];
		int len = 0;
		printf("The following %d persons have the same age: \n", max_count);
		for (int i = 0; i < population_size; i++) {
			if (aliens[i].real_age == max_age) {
				printf("%s\n", aliens[i].name);
				contenders[len++] = i;
			}
		}
		
		int rng = contenders[rand() % max_count];
		leader = aliens[rng];
		
		printf("\nRandomly selected '%s' as leader.\n", leader.name);
	}
	
	free(aliens);
	
	return 0;
}
