#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title, author, ISBN;
    bool isIssued;

public:
    Book(string t, string a, string i) :
     title(t), author(a), ISBN(i), isIssued(false) {}

    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    void Display_fun() const {
        cout << "Title: " << title << ", Author: " << author
             << ", ISBN: " << ISBN
             << ", Issued: " << (isIssued ? "Yes" : "No") << endl;
    }

    bool Matching_fun(string key) const {
        return title == key || author == key || ISBN == key;
    }
};

class Library {
private:
    vector<Book> Books;

public:
    void AddingBook() {
        string title, author, isbn;
        cout << "Enter Title of the Book: ";
        getline(cin >> ws, title);
        cout << "Enter Author Name: ";
       getline(cin, author);
        cout << "Enter ISBN Number of the Book: ";
        getline(cin, isbn);
        Books.emplace_back(title, author, isbn);
        cout << "Book Added Successfully in the LMS!\n";
    }

    void SearchingBook() {
        string key;
        cout << "Enter title of the Book/Author Name/ISBN Number to search: ";
        getline(cin >> ws, key);
        bool found = false;
        // this will check and finding the book is present in the database  store or not
        for (const auto &b :Books) {
            if (b.Matching_fun(key))
            {
                b.Display_fun();
                found = true;
            }
        }
        if (!found)
        {
         cout << "Book not found.\n";
        }
    }

    void issuingBook() {
        string isbn;
        cout << "Enter ISBN to issue: ";
        getline(cin >> ws, isbn);
        for (auto &b : Books) {
            if (b.getISBN() == isbn && !b.getIssuedStatus()) {
                b.issueBook();
                cout << "Book issued successfully.\n";
                return;
            }
        }
        cout << "Book not available or already issued.\n";
    }

    void ReturningBook() {
        string isbn;
        cout << "Enter ISBN to return: ";
        getline(cin >> ws, isbn);
        for (auto &b : Books) {
            if (b.getISBN() == isbn && b.getIssuedStatus()) {
                b.returnBook();
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found or not issued.\n";
    }

    void CalculatingFine() {
        int day_lates;
        cout << "Enter No of Days to overdue: ";
        cin >> day_lates;
        if (day_lates > 0) {
            cout << "Total Fine is: Rs " << day_lates * 5 << endl;
        } else {
            cout << "No fine u have to Pay.\n";
        }
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Adding the Book\n2. Searching Book\n3. Issuing Book\n4. Returning Book\n5. Calculating Fine\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.AddingBook(); 
            break;
            case 2: lib.SearchingBook(); 
            break;
            case 3: lib.issuingBook();
             break;
            case 4: lib.ReturningBook();
             break;
            case 5: lib.CalculatingFine();
             break;
            case 0: cout << "Exiting From This...\n";
             break;
            default: cout << "This is the invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
