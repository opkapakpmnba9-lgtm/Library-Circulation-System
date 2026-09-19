#pragma once

#include <iosfwd>
#include <string>

class Book {
public:
    Book();
    Book(const std::string& title, const std::string& isbn,
        const std::string& publisher, double price, int pages,
        bool available = true);

    const std::string& getTitle() const;
    const std::string& getIsbn() const;
    const std::string& getPublisher() const;
    double getPrice() const;
    int getPages() const;
    bool isAvailable() const;

    bool setTitle(const std::string& title);
    bool setIsbn(const std::string& isbn);
    bool setPublisher(const std::string& publisher);
    bool setPrice(double price);
    bool setPages(int pages);

    bool borrow();
    bool returnBook();
    void print(std::ostream& out) const;
    static bool isValidIsbn(const std::string& isbn);

private:
    std::string title_;
    std::string isbn_;
    std::string publisher_;
    double price_;
    int pages_;
    bool available_;
};
