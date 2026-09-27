#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int issued;
};

struct Book library[MAX];
int count = 0;

void addBook() {
    if (count >= MAX) {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[count].author);

    library[count].issued = 0;
    count++;

    printf("\nBook added successfully!\n");
}

void displayBooks() {
    int i;

    if (count == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n----------- LIBRARY BOOKS -----------\n");

    for (i = 0; i < count; i++) {
        printf("\nBook ID     : %d", library[i].id);
        printf("\nTitle       : %s", library[i].title);
        printf("\nAuthor      : %s", library[i].author);
        printf("\nStatus      : %s\n",
               library[i].issued ? "Issued" : "Available");
    }
}

void searchBook() {
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("Book ID : %d\n", library[i].id);
            printf("Title   : %s\n", library[i].title);
            printf("Author  : %s\n", library[i].author);
            printf("Status  : %s\n",
                   library[i].issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nBook not found!\n");
}

void issueBook() {
    int id, i;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (library[i].id == id) {

            if (library[i].issued) {
                printf("\nBook is already issued!\n");
            } else {
                library[i].issued = 1;
                printf("\nBook issued successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

void returnBook() {
    int id, i;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (library[i].id == id) {

            if (!library[i].issued) {
                printf("\nBook was not issued.\n");
            } else {
                library[i].issued = 0;
                printf("\nBook returned successfully!\n");
            }

            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n\n=================================");
        printf("\n      LIBRARY MANAGEMENT SYSTEM");
        printf("\n=================================");
        printf("\n1. Add Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");
        printf("\n=================================");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                printf("\nThank you for using Library Management System!\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
