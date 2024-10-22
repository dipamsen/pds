#include <stdio.h>
#include <string.h>

typedef struct {
	char name[100]; 
	char city[50]; 
	int year;
} publisher;

struct book {
	char name[100]; 
	char author[100]; 
	publisher p; 
	int price;
};


void input(char *s, int len) {
	// helper function take in input with spaces
	s[0] = '\0';
	while (s[0] == '\0' || s[0] == '\n')
		fgets(s, len, stdin);
	int i = 0; 
	while (s[i] != '\n' && s[i] != '\0') i++;
	s[i] = '\0';
}


void add_book(struct book *books, int *num_books) {
	printf("\nAdd details of book\n");
	printf("---------------------------\n");
	
	struct book new;
	
	printf("Enter Book Name: ");
	input(new.name, 100);
	
	printf("Enter Author Name: ");
	input(new.author, 100);
	
	printf("Enter Publication Name: ");
	input(new.p.name, 100);
	
	printf("Enter Publication City: ");
	input(new.p.city, 50);
	
	printf("Enter Publication Year: ");
	scanf("%d", &new.p.year);
	
	printf("Enter Price: ");
	scanf("%d", &new.price);
	
	books[*num_books] = new;
	
	printf("\n");
	(*num_books)++;
}

void display_books(struct book *books, int *num_books) {
	printf("\nDetails of all books: \n");
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Book Name\tAuthor Name\tPrice\tPub_Name\tPub_City\tPub_Year\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");	
	for (int i = 0; i < *num_books; i++) {
		struct book b = books[i];
		printf("%s\t\t%s\t\t%d\t%s\t\t%s\t%d\n", b.name, b.author, b.price, b.p.name, b.p.city, b.p.year);
	}
	printf("-------------------------------------------------------------------------------------------------------------\n");
}


void list_books_by_author(struct book *books, int *num_books) {
	printf("\nList books by author: \n");
	printf("Enter author name: ");
	char author[100];
	input(author, 100);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Book Name\tAuthor Name\tPrice\tPub_Name\tPub_City\tPub_Year\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");	
	for (int i = 0; i < *num_books; i++) {
		struct book b = books[i];
		if (!strcmp(b.author, author))
			printf("%s\t\t%s\t\t%d\t%s\t\t%s\t%d\n", b.name, b.author, b.price, b.p.name, b.p.city, b.p.year);
	}
	printf("-------------------------------------------------------------------------------------------------------------\n");
}


void list_books_over_price(struct book *books, int *num_books) {
	printf("\nList books over price: \n");
	printf("Enter minimum price: ");
	int price;
	scanf("%d", &price);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Book Name\tAuthor Name\tPrice\tPub_Name\tPub_City\tPub_Year\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");	
	for (int i = 0; i < *num_books; i++) {
		struct book b = books[i];
		if (b.price > price)
			printf("%s\t\t%s\t\t%d\t%s\t\t%s\t%d\n", b.name, b.author, b.price, b.p.name, b.p.city, b.p.year);
	}
	printf("-------------------------------------------------------------------------------------------------------------\n");
}

void list_books_by_city(struct book *books, int *num_books) {
	printf("\nList books by city: \n");
	printf("Enter city name: ");
	char city[50];
	input(city, 50);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Book Name\tAuthor Name\tPrice\tPub_Name\tPub_City\tPub_Year\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");	
	for (int i = 0; i < *num_books; i++) {
		struct book b = books[i];	
		if (!strcmp(b.p.city, city))
			printf("%s\t\t%s\t\t%d\t%s\t\t%s\t%d\n", b.name, b.author, b.price, b.p.name, b.p.city, b.p.year);
	}
	printf("-------------------------------------------------------------------------------------------------------------\n");
}

void list_books_by_publisher_over_price(struct book *books, int *num_books) {
	printf("\nList books by publisher over price: \n");
	printf("Enter publisher name: ");
	char publisher[100];
	input(publisher, 100);
	printf("Enter minimum price: ");
	int price;
	scanf("%d", &price);
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Book Name\tAuthor Name\tPrice\tPub_Name\tPub_City\tPub_Year\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");	
	for (int i = 0; i < *num_books; i++) {
		struct book b = books[i];
		if (!strcmp(b.p.name, publisher) && b.price > price)
			printf("%s\t\t%s\t\t%d\t%s\t\t%s\t%d\n", b.name, b.author, b.price, b.p.name, b.p.city, b.p.year);
	}
	printf("-------------------------------------------------------------------------------------------------------------\n");
}


void sort_books_by_price(struct book *books, int *num_books) {
	printf("\nSorted books by price: \n");
	
	for (int i = 0; i < *num_books; i++) {
		int min = i;
		for (int j = i + 1; j < *num_books; j++) {
			if (books[min].price > books[j].price) min = j;
		}
		
		if (min != i) {
			struct book b = books[i];
			books[i] = books[min];
			books[min] = b;
		}
	}
	
	printf("-------------------------------------------------------------------------------------------------------------\n");
	printf("Book Name\tAuthor Name\tPrice\tPub_Name\tPub_City\tPub_Year\n");
	printf("-------------------------------------------------------------------------------------------------------------\n");	
	for (int i = 0; i < *num_books; i++) {
		struct book b = books[i];
			printf("%s\t\t%s\t\t%d\t%s\t\t%s\t%d\n", b.name, b.author, b.price, b.p.name, b.p.city, b.p.year);
	}
	printf("-------------------------------------------------------------------------------------------------------------\n");
}


int main() {
	struct book books[100];
	int num_books = 0;
	
	printf("============================================\n");
	printf("MENU\n");
	printf("============================================\n");
	printf("Press 1: Add book details.\n");
	printf("Press 2: Display book details.\n");
	printf("Press 3: List all books of a given author.\n");
	printf("Press 4: List of books in the shop over the given price.\n");
	printf("Press 5: List of books published in a given city.\n");
	printf("Press 6: List of books from a given publisher with the price above some value.\n");
	printf("Press 7: Sorted list of books in shop based on price.\n");
	printf("Press 8: Exit.\n");
	printf("============================================\n");
	
	while (1) {
		printf("\nEnter your choice: ");
		int choice;
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				add_book(books, &num_books);
				break;
			case 2:
				display_books(books, &num_books);
				break;
			case 3:
				list_books_by_author(books, &num_books);
				break;
			case 4:
				list_books_over_price(books, &num_books);
				break;
			case 5:
				list_books_by_city(books, &num_books);
				break;	
			case 6:
				list_books_by_publisher_over_price(books, &num_books);
				break;
			case 7:
				sort_books_by_price(books, &num_books);
				break;
			case 8:
				break;
		}
		if (choice == 8) break;
	}
	
	return 0;
}
