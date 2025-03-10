#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to store book data
typedef struct {
    int book_id;
    char title[50];
    char author[50];
    float price;
} Book;

Book books[MAX_BOOKS];
int count = 0;

// Function to add a book
void addBook() {
    if (count >= MAX_BOOKS) {
        printf("\nMaximum book limit reached!\n");
        return;
    }
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].book_id);
    printf("Enter Title: ");
    scanf(" %49[^]", books[count].title);
    printf("Enter Author: ");
    scanf(" %49[^]", books[count].author);
    printf("Enter Price: ");
    scanf("%f", &books[count].price);
    count++;
    printf("\nBook added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (count == 0) {
        printf("\nNo book records available.\n");
        return;
    }
    printf("\nBook Records:\n");
    printf("----------------------------------------------------\n");
    printf("Book ID | Title                | Author               | Price\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%7d | %-20s | %-20s | %.2f\n", books[i].book_id, books[i].title, books[i].author, books[i].price);
    }
}

// Function to save books to file
void saveToFile() {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %s %.2f\n", books[i].book_id, books[i].title, books[i].author, books[i].price);
    }
    fclose(file);
    printf("\nData saved to file successfully!\n");
}

// Function to load books from file
void loadFromFile() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("\nNo previous records found.\n");
        return;
    }
    count = 0;
    while (fscanf(file, "%d %49s %49s %f", &books[count].book_id, books[count].title, books[count].author, &books[count].price) == 4) {
        count++;
    }
    fclose(file);
    printf("\nData loaded from file successfully!\n");
}

int main() {
    int choice;
    loadFromFile();
    do {
        printf("\nBook Store Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Save to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
