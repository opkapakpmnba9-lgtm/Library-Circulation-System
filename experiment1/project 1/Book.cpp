#include "Book.h"

#include <cmath>
#include <ostream>
#include <stdexcept>

Book::Book() : price_(0.0), pages_(0), available_(false) {}

Book::Book(const std::string& title, const std::string& isbn,
    const std::string& publisher, double price, int pages,
    bool available)
    : price_(0.0), pages_(0), available_(available) {
    if (!setTitle(title) || !setIsbn(isbn) || !setPublisher(publisher) ||
        !setPrice(price) || !setPages(pages)) {
        throw std::invalid_argument("Invalid book information");
    }
}

const std::string& Book::getTitle() const { return title_; }
const std::string& Book::getIsbn() const { return isbn_; }
const std::string& Book::getPublisher() const { return publisher_; }
double Book::getPrice() const { return price_; }
int Book::getPages() const { return pages_; }
bool Book::isAvailable() const { return available_; }

bool Book::setTitle(const std::string& title) {
    if (title.find_first_not_of(" \t\r\n") == std::string::npos) return false;
    title_ = title;
    return true;
}

bool Book::setIsbn(const std::string& isbn) {
    if (!isValidIsbn(isbn)) return false;
    isbn_ = isbn;
    return true;
}

bool Book::setPublisher(const std::string& publisher) {
    if (publisher.find_first_not_of(" \t\r\n") == std::string::npos) return false;
    publisher_ = publisher;
    return true;
}

bool Book::setPrice(double price) {
    if (!std::isfinite(price) || price < 0.0) return false;
    price_ = price;
    return true;
}

bool Book::setPages(int pages) {
    if (pages <= 0) return false;
    pages_ = pages;
    return true;
}

bool Book::borrow() {
    if (!available_ || isbn_.empty()) return false;
    available_ = false;
    return true;
}

bool Book::returnBook() {
    if (available_ || isbn_.empty()) return false;
    available_ = true;
    return true;
}

void Book::print(std::ostream& out) const {
    out << "Title: " << title_ << '\n'
        << "ISBN: " << isbn_ << '\n'
        << "Publisher: " << publisher_ << '\n'
        << "Price: " << price_ << '\n'
        << "Pages: " << pages_ << '\n'
        << "Status: " << (available_ ? "Available" : "Borrowed") << '\n';
}

bool Book::isValidIsbn(const std::string& isbn) {
    std::string digits;
    for (char ch : isbn) {
        if (ch == '-' || ch == ' ') continue;
        digits += ch;
    }

    if (digits.size() == 10) {
        int sum = 0;
        for (int i = 0; i < 10; ++i) {
            const char ch = digits[i];
            int value = 0;
            if (i == 9 && (ch == 'X' || ch == 'x')) {
                value = 10;
            }
            else if (ch >= '0' && ch <= '9') {
                value = ch - '0';
            }
            else {
                return false;
            }
            sum += (10 - i) * value;
        }
        return sum % 11 == 0;
    }

    if (digits.size() == 13) {
        int sum = 0;
        for (int i = 0; i < 13; ++i) {
            if (digits[i] < '0' || digits[i] > '9') return false;
            sum += (digits[i] - '0') * (i % 2 == 0 ? 1 : 3);
        }
        return sum % 10 == 0;
    }

    return false;
}
