#include "patron.h"
#include <string> 

using namespace std;


Patron::Patron(string name, int patron_id)
{
    this->name = name;
    this->patron_id = patron_id;
    this->num_items =0;
    this->fine_balance=0;
}

Patron::Patron()
{
    this->name = "None";
    this->patron_id = 0;
    this->num_items = 0;
    this->fine_balance= 0;
}


void Patron::set_name(string name)
{
    this->name = name;
}

string Patron::get_name()
{
    return name;
}

void Patron::set_patron_id(int patron_id)
{
    this->patron_id = patron_id;
}

int Patron:: get_patron_id()
{
    return patron_id;
}

void Patron:: set_fine_balance(int days)
{
    fine_balance = days* 0.25;
}

double Patron:: get_fine_balance()
{
    return fine_balance;
}

 void Patron:: set_num_items(int num_items)
 {
    this->num_items = num_items;
 }

 int Patron::get_num_items()
 {
    return num_items;
 }


