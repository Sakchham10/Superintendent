#include "Loan.h"
#include <string>
using namespace std;

Loan::Loan(int loan_id, int item_id, int patron_id, string due_date, string current_status)
{
    this->loan_id = loan_id;
    this->item_id = item_id;
    this->patron_id = patron_id;
    this->due_date = due_date;
    this->current_status = current_status;
}  

Loan::Loan()
{
    this->loan_id = 0;
    this->item_id = 0;
    this->patron_id = 0;
    this->due_date = "None";
    this->current_status = "None";
}

void Loan::set_loan_id(int loan_id)
{
    this->loan_id = loan_id;
}

int Loan::get_loan_id()
{
    return loan_id;
}

void Loan::set_item_id(int item_id)
{
    this->item_id = item_id;
}

int Loan::get_item_id()
{
    return item_id;
}

void Loan::set_patron_id(int patron_id)
{
    this->patron_id = patron_id;
}

int Loan::get_patron_id()
{
    return patron_id;
}

void Loan::set_due_date(string due_date)
{
    this->due_date = due_date;
}

string Loan::get_due_date()
{
    return  due_date;
}
void Loan::set_current_status(string current_status)
{
    this->current_status = current_status;
}

string Loan::get_current_status()
{
    return current_status;
}


