#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 30
typedef char str[MAX_LEN];

typedef struct {
	str name;
	int num_cities;
	str *cities;
} State;


void err() {
	printf("Memory allocation failed.\n");
	exit(1);
}

void fix(str input) {
	// helper function to "fix" input taken from fgets() to remove trailing \n.
	int i = 0; 
	while (input[i] != '\n' && input[i] != '\0') i++;
	input[i] = '\0';
}


int state_exists(State *directory, int num_states, str state) {
	for (int i = 0; i < num_states; i++) {
		if (!strcmp(directory[i].name, state)) return 1;
	}
	return 0;
}

int city_exists(State *directory, int num_states, str city) {
	for (int i = 0; i < num_states; i++) {
		for (int j = 0; j < directory[i].num_cities; j++)  {
			if (!strcmp(directory[i].cities[j], city)) return 1;
		}
	}
	return 0;
}

void display_directory(State *directory, int num_states) {
	for (int i = 0; i < num_states; i++) {
		State state = directory[i];
		printf("%s: ", state.name);
		for (int j = 0; j < state.num_cities; j++) {
			printf("%s", state.cities[j]);
			if (j != state.num_cities - 1) printf(", ");
		}
		printf("\n");
	}
}

void print_cities(State *directory, int num_states, str state) {
	for (int i = 0; i < num_states; i++) {
		if (!strcmp(directory[i].name, state)) {
			printf("%s: ", directory[i].name);
			for (int j = 0; j < directory[i].num_cities; j++) {
				printf("%s", directory[i].cities[j]);
				if (j != directory[i].num_cities - 1) printf(", ");
			}
			printf("\n");
			return;
		}
	}
	printf("State %s doesn't exist in directory.\n", state);
}

void print_states(State *directory, int num_states) {
	for (int i = 0; i < num_states; i++) {
		printf("%s", directory[i].name);
		if (i != num_states - 1) printf(", ");
	}
	printf("\n");
}

void find_state(State *directory, int num_states, str city) {
	for (int i = 0; i < num_states; i++) {
		State s = directory[i];
		for (int j = 0; j < s.num_cities; j++) {
			if (!strcmp(s.cities[j], city)) {
				printf("%s\n", s.name);
				return;
			}
		}
	}
	printf("City %s doesn't exist in directory.\n", city);
}

void sort_states(State *directory, int num_states) {
	for (int i = 0; i < num_states; i++) {
		// find minimum
		int min_index = i;
		for (int j = i + 1; j < num_states; j++) {
			if (strcmp(directory[i].name, directory[j].name) > 0) {
				min_index = j;
			}
		}
		
		if (min_index != i) {
			// swap i and min_index
			State temp = directory[i];
			directory[i] = directory[min_index];
			directory[min_index] = temp;
		}
	}
}

void sort_cities_of(State *directory, int num_states, str state) {
	for (int i = 0; i < num_states; i++) {
		if (!strcmp(directory[i].name, state)) {
			
			State s = directory[i];
			
			for (int j = 0; j < s.num_cities; j++) {
				int min_index = j;
				for (int k = j + 1; k < s.num_cities; k++) {
					if (strcmp(s.cities[min_index], s.cities[k]) > 0) min_index = k;
				}
				
				if (min_index != j) {
					// swap j and min_index
					str temp;
					strcpy(temp, s.cities[j]);
					strcpy(s.cities[j], s.cities[min_index]);
					strcpy(s.cities[min_index], temp);
				}
			}
			
			return;
		}
	}
	printf("State %s doesn't exist in directory.\n", state);
}

void sort_cities_and_states(State *directory, int num_states) {
	sort_states(directory, num_states);
	for (int i = 0; i < num_states; i++) {
		sort_cities_of(directory, num_states, directory[i].name);
	}
}

int main() {
	int num_states;
	printf("Enter the number of states: ");
	scanf("%d", &num_states);
	State *directory = (State *) malloc(num_states * sizeof(State));

	if (directory == NULL) err();
	
	int i;
	for (i = 0; i < num_states; i++) {
	
		int num_cities;
		printf("Enter the number of cities under state %d: ",  i + 1);
		scanf("%d", &num_cities);
		directory[i].num_cities = num_cities;
		
		directory[i].cities = (str *) malloc(num_cities * sizeof(str));
		if (directory[i].cities == NULL) err();
		
		printf("Enter name of state %d and its cities: ", i + 1);
		int curr_index = 0;
		int curr_len = 0;
		char c;
		while (1) {
			scanf("%c", &c);
			if (c == '\n') {
				if (curr_index == num_cities) break;
				continue;
			}
			if (c == ' ' && curr_len == 0) continue;
			if (c == ',') {
				if (curr_index == 0) directory[i].name[curr_len] = '\0';
				else directory[i].cities[curr_index-1][curr_len] = '\0';
				curr_index++;
				curr_len = 0;
				if (curr_index > num_cities) break;
			} else {
				if (curr_index == 0) directory[i].name[curr_len] = c;
				else directory[i].cities[curr_index-1][curr_len] = c;
				curr_len++;
			}
		}
	}
	
	str input;
	
	printf("\n(a) Display the entire directory: \n");
	display_directory(directory, num_states);
	
	do {
		printf("\n(b) Provide the cities of state: ");
		fgets(input, MAX_LEN, stdin);
		fix(input);
		print_cities(directory, num_states, input);
	} while (!state_exists(directory, num_states, input));
	
	do {
		printf("\n(c) Find which state a city belongs to: ");
		fgets(input, MAX_LEN, stdin);
		fix(input);
		find_state(directory, num_states, input);
	} while (!city_exists(directory, num_states, input));
		
	printf("\n(d) Sort the states alphabetically: \n");
	sort_states(directory, num_states);
	print_states(directory, num_states);
	
	do {
		printf("\n(e) Sort the cities of a particular state alphabetically: ");
		//scanf("%s", input);
		fgets(input, MAX_LEN, stdin);
		fix(input);
		sort_cities_of(directory, num_states, input);
	} while (!state_exists(directory, num_states, input));
	print_cities(directory, num_states, input);
	
	
	printf("\n(f) Sort cities and states alphabetically: \n");
	sort_cities_and_states(directory, num_states);
	display_directory(directory, num_states);
	
	
	for (i = 0; i < num_states; i++) {
		free(directory[i].cities);
	}
	free(directory);
	
	return 0;
	
}










