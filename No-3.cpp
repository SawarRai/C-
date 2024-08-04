#include <iostream>
#include <string>
#include <map>

class Library {
private:
    struct Book {
        std::string author;
        int numberOfCopies;
    };
    std::map<std::string, Book> books;

public:
    void addNewBook(const std::string& bookTitle, const std::string& author, int numberOfCopies) {
        if (books.find(bookTitle) != books.end()) {
            books[bookTitle].numberOfCopies += numberOfCopies;
        } else {
            books[bookTitle] = {author, numberOfCopies};
        }
    }

    void issueBook(const std::string& bookTitle) {
        if (books.find(bookTitle) != books.end() && books[bookTitle].numberOfCopies > 0) {
            books[bookTitle].numberOfCopies--;
            std::cout << "Issued: " << bookTitle << std::endl;
        } else {
            std::cout << "Book not available: " << bookTitle << std::endl;
        }
    }

    void returnBook(const std::string& bookTitle) {
        if (books.find(bookTitle) != books.end()) {
            books[bookTitle].numberOfCopies++;
            std::cout << "Returned: " << bookTitle << std::endl;
        } else {
            std::cout << "Book not found: " << bookTitle << std::endl;
        }
    }

    void displayBooks() const {
        for (const auto& pair : books) {
            std::cout << "Title: " << pair.first << ", Author: " << pair.second.author << ", Copies: " << pair.second.numberOfCopies << std::endl;
        }
    }
};
class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNumber, double bal) : accountNumber(accNumber), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    void displayBalance() const {
        std::cout << "Account Number: " << accountNumber << ", Balance: " << balance << std::endl;
    }
};
int main() {
    // Create a library
    Library library;
    library.addNewBook("1984", "George Orwell", 5);
    library.addNewBook("To Kill a Mockingbird", "Harper Lee", 3);
    
    // Display books in the library
    library.displayBooks();
    
    // Issue and return books
    library.issueBook("1984");
    library.returnBook("1984");
    
    // Display books again to see changes
    library.displayBooks();
    
    // Create an account
    Account myAccount(123456, 1000.0);
    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.displayBalance();

    return 0;
}
