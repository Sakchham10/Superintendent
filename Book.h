#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "LibraryItem.h"

using namespace std;

class Book : public LibraryItem
{
    public:
        Book(int id,double cost, string status, int loanPeriod, string author, string title, int isbn);
        Book(int id);
        void set_author(string author);
        string get_author();
        void set_isbn(int isbn);
        int get_isbn();
        void set_category();
        string get_category();
        int get_id();
        void edit();
        void save(ofstream &file) override;

    private:
        string author;
        int isbn;
};
#endif