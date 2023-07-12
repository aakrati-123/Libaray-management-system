#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool available;
};

const int MAX_BOOKS = 100;
Book books[MAX_BOOKS];
int numBooks = 0;

// Add New Book: Using Array
void addNewBook() {
    if (numBooks >= MAX_BOOKS) {
        cout << "Maximum book capacity reached." << endl;
        return;
    }

    Book newBook;
    cout << "Enter book ID: ";
    cin >> newBook.id;
    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, newBook.title);

    cout << "Enter book author: ";
    getline(cin, newBook.author);

    newBook.available = true;
    books[numBooks] = newBook;
    numBooks++;

    cout << "Book added successfully." << endl;
}

// Search for a Book: Using Linear Search
void searchBook() {
    string keyword;
    cout << "Enter book title or ID to search: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].title == keyword || to_string(books[i].id) == keyword) {
            cout << "Book found!" << endl;
            cout << "ID: " << books[i].id << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Status: " << (books[i].available ? "Available" : "Issued") << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Issue a Book: Using Queue
void issueBook() {
    int bookID;
    cout << "Enter book ID to issue: ";
    cin >> bookID;

    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == bookID) {
            if (books[i].available) {
                books[i].available = false;
                cout << "Book issued successfully." << endl;
            } else {
                cout << "Book is already issued." << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Return a Book
void returnBook() {
    int bookID;
    cout << "Enter book ID to return: ";
    cin >> bookID;

    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == bookID) {
            if (!books[i].available) {
                books[i].available = true;
                cout << "Book returned successfully." << endl;
            } else {
                cout << "Book is already available." << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found." << endl;
    }
}

// List All Books: Using Quick Sort
int partition(Book arr[], int low, int high) {
    Book pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].id < pivot.id) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Book arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void listAllBooks() {
    if (numBooks == 0) {
        cout << "No books available." << endl;
        return;
    }

    cout << "Listing all books:" << endl;
    cout << "------------------" << endl;

    quickSort(books, 0, numBooks - 1);

    for (int i = 0; i < numBooks; i++) {
        cout << "ID: " << books[i].id << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Status: " << (books[i].available ? "Available" : "Issued") << endl;
        cout << "------------------" << endl;
    }
}

// Delete a Book
void deleteBook() {
    int bookID;
    cout << "Enter book ID to delete: ";
    cin >> bookID;

    bool found = false;
    for (int i = 0; i < numBooks; i++) {
        if (books[i].id == bookID) {
            for (int j = i; j < numBooks - 1; j++) {
                books[j] = books[j + 1];
            }
            numBooks--;
            found = true;
            cout << "Book deleted successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Book not found." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Library Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Search for a Book" << endl;
        cout << "3. Issue a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. List All Books" << endl;
        cout << "6. Delete a Book" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNewBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                listAllBooks();
                break;
            case 6:
                deleteBook();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
