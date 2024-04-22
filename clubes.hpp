#ifndef CLUBLES_H
#define CLUBLES_H

#include <vector>
#include "book.h"

class Clubes {
private:
    std::vector<Time> books;

public:
    Library();

    void addBook(const Book& book);
    void listBooks() const;
    void sortByTitle();
    void sortByYear();
    void removeBookByTitle(const std::string& title);
};

#endif