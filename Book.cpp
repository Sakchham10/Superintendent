#include "Book.h"
#include <string>
#include <iostream>
#include <fstream>
#include "LibraryItem.h"

using namespace std;


Book::Book(int id):LibraryItem()
{
    string author;
    int isbn;
 
    cout << "Enter the author of the book" << endl;
    getline(cin,author);
    cout << "Enter the isbn of the book" << endl;
    cin >> isbn;
    cin.ignore();

    this->author = author;
    this->isbn = isbn;
    this->id = id;
}

Book::Book(int id,double cost, string status, int loanPeriod, string author, string title, int isbn):LibraryItem(cost,status,loanPeriod,title)
{
    this->id = id;
    this->author = author;
    this->isbn = isbn;   
}
void Book::set_author(string author)
{
    this->author = author;
}

string Book::get_author()
{
    return author;
}


void Book::set_isbn(int isbn)
{
    this->isbn = isbn;
}

int Book::get_isbn()
{
    return isbn;
}

int Book::get_id()
{
    return id;
}


void Book::edit()
{
    string new_author;
    string new_title;
    int new_isbn;
    double new_cost;
    cout << "Enter new author of book" << endl;
    getline(cin, new_author);
    cout << "Enter the new title of book" << endl;
    getline (cin, new_title);
    cout << "Enter the new isbn of book" << endl;
    cin >> new_isbn;
    cin.ignore();
    cout << "Enter the new cost of book"<< endl;
    cin >> new_cost;
    cin.ignore();

    
    author= new_author;
    title= new_title;
    isbn= new_isbn;
    cost= new_cost;
}

void Book:: save(ofstream &file)
{
    LibraryItem::save(file);
    Book* book;
    file << "B" << " " << this->get_id() << " " << this->get_author() << " " << this->get_isbn() << " " << endl;;
 
}


