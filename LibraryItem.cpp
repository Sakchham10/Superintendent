#include "LibraryItem.h"
#include <iostream>
#include <fstream>
using namespace std;

LibraryItem::LibraryItem()
{
    string status;
    string title;
    double cost;
    int loanPeriod;

    cout << "Enter the title of the item" << endl;
    getline(cin, title);
    cout <<"Enter the cost of the item" << endl;
    cin >> cost;
    cin.ignore();
    loanPeriod = 10;
    status = "In";

    this->status= status;
    this->title= title;
    this->cost= cost;
    this->loanPeriod= loanPeriod;

}

LibraryItem::LibraryItem(double cost,string status,int loanPeriod,string title)
{
    this->status= status;
    this->title= title;
    this->cost= cost;
    this->loanPeriod = loanPeriod;
}

void LibraryItem::set_cost(double cost)
{
    this->cost = cost;
}

void LibraryItem::set_loanPeriod(int loanPeriod)
{
    this->loanPeriod = loanPeriod;
}

void LibraryItem::set_status(string status)
{
    this->status = status;
}

int LibraryItem::get_id()
{
    return id;
}

double LibraryItem::get_cost()
{
    return cost;
}

string LibraryItem::get_status()
{
    return status;
}

int LibraryItem::get_loanPeriod()
{
    return loanPeriod;
}
void LibraryItem:: set_title(string title)
{
    this->title =title;
}

string LibraryItem::get_title()
{
    return title;
}
ostream & operator << (ostream &out, const LibraryItem &item) 
{ 
    out<< "id: " << item.id<< endl;
    out<< "cost: " << item.cost<< endl;
    out<< "status: " << item.status<< endl;
    out<< "loanPeriod: " << item.loanPeriod << endl;
    out<< "title: " << item.title << endl; 
    return out; 
}

void LibraryItem:: save(ofstream &file)
{
    file << "I" << " " << this->get_cost()<< " " << this->get_status();
    file <<" " << this->get_title() << " ";
    
}


