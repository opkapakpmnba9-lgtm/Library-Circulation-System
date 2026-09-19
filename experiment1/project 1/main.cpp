#include "Book.h"

#include <iostream>

int main() {
    Book emptyBook;  // 调用默认构造函数
    std::cout << "Default book available: " << std::boolalpha
        << emptyBook.isAvailable() << "\n\n";

    Book book("Clean Code", "978-0-13-235088-4",
        "Prentice Hall", 59.90, 464);  // 调用带参构造函数
    book.print(std::cout);

    std::cout << "\nBorrow: " << book.borrow() << '\n';
    std::cout << "Borrow again: " << book.borrow() << '\n';
    std::cout << "Return: " << book.returnBook() << '\n';

    std::cout << "Update price: " << book.setPrice(49.90) << '\n';
    std::cout << "Current price: " << book.getPrice() << '\n';

    std::cout << "Invalid ISBN accepted: "
        << book.setIsbn("1234567890") << '\n';
    std::cout << "Current ISBN: " << book.getIsbn() << '\n';

    return 0;
}
