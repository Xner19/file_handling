#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int bookID;
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

#define MAX_BOOKS 100
Book books[MAX_BOOKS];
int N = 0;

int main() {
    FILE *file = fopen("books.dat", "rb");
    if (file) {
        fread(&N, sizeof(int), 1, file);
        fread(books, sizeof(Book), N, file);
        fclose(file);
    }

    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for Book by ID Number\n");
        printf("4. Calculate Total Value of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1 && N < MAX_BOOKS) {
            printf("Enter book ID: ");
            scanf("%d", &books[N].bookID);
            getchar();
            printf("Enter title: ");
            fgets(books[N].title, sizeof(books[N].title), stdin);
            books[N].title[strcspn(books[N].title, "\n")] = 0;
            printf("Enter author: ");
            fgets(books[N].author, sizeof(books[N].author), stdin);
            books[N].author[strcspn(books[N].author, "\n")] = 0;
            printf("Enter year: ");
            scanf("%d", &books[N].year);
            printf("Enter price: ");
            scanf("%f", &books[N].price);
            N++;

            file = fopen("books.dat", "wb");
            fwrite(&N, sizeof(int), 1, file);
            fwrite(books, sizeof(Book), N, file);
            fclose(file);
        } 
        else if (choice == 2) {
            for (int i = 0; i < N; i++) {
                printf("ID: %d, Title: %s, Author: %s, Year: %d, Price: %f SAR\n",
                       books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
            }
        } 
        else if (choice == 3) {
            int id, found = 0;
            printf("Enter book ID to search: ");
            scanf("%d", &id);
            for (int i = 0; i < N; i++) {
                if (books[i].bookID == id) {
                    printf("Found - ID: %d, Title: %s, Author: %s, Year: %d, Price: %.2f SAR\n",
                           books[i].bookID, books[i].title, books[i].author, books[i].year, books[i].price);
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Book not found.\n");
        } 
        else if (choice == 4) {
            float total = 0;
            for (int i = 0; i < N; i++) total += books[i].price;
            printf("Total Value: %.2f SAR\n", total);
        } 
        else if (choice == 5) {
            file = fopen("books.dat", "wb");
            fwrite(&N, sizeof(int), 1, file);
            fwrite(books, sizeof(Book), N, file);
            fclose(file);
            printf("Exiting\n");
        } 
        else {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}

