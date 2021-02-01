#include <iostream>
#include <string>
#include "Loan.h"
#include "Loans.h"
#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "LibraryItems.h"
#include <ctime>

using namespace std;

Loans::Loans()
{
    loan_count = 0;
    loans_id = 0;
    
}

Loan* Loans::search_loan(int loan_id)
{
    for(int i = 0; i < loan_count; i++)
    {
        if (loan_id== loan_list[i].get_loan_id())
        return &loan_list[i];
    }
    cout << "No match found" << endl;
   return nullptr;
}

void Loans::checkout(Patrons &patrons,LibraryItems& items)
{
    int loan_id;
    int patron_id;
    int item_id;
    string due_date;
    string current_status;
    LibraryItem* item;
    cout << "Enter patron id" << endl;
    cin >> patron_id;
    cin.ignore();
    Patron patron;
    Patron* patron_searched = patrons.search_patron(patron_id);
    if (patron_searched != nullptr)
    {
        int num_items = patron_searched->get_num_items();
        if (patron_searched->get_num_items() > 5)
    {
        cout << "You cannot take out anymore items" << endl;
    }
        else
        {   
            cout << "Enter the item id" << endl;
            cin >> item_id;
            cin.ignore();
            current_status = "out";
            increament_loan_id();
            Loan new_loan = Loan(loans_id, item_id, patron_id, due_date, current_status);
            loan_list.push_back(new_loan);
            loan_count++;
            patron_searched->set_num_items(num_items+1);
            item = items.search_item(item_id);
            item->set_status("out");
        }
    }
    
}

void Loans::checkin(Patrons &patrons, LibraryItems& items)
{
    int loan_id;
    int patron_id;
    int total_items;
    double total_fees;
    int item_id;
    int flag = 0;

    cout << "Enter Loan id" << endl;
    cin >> loan_id;
    cin.ignore();
    Loan jpt;
    Loan* searched_loan = search_loan(loan_id);
    if (searched_loan != nullptr)
    Patron patron;
    patron_id = searched_loan->get_patron_id();
    Patron* searched_patron = patrons.search_patron(patron_id);
    if (searched_patron!=nullptr)
    {
        total_fees = searched_patron->get_fine_balance();
        total_items = searched_patron->get_num_items();
        item_id = searched_loan->get_item_id();
        LibraryItem* searched_item = items.search_item(item_id);
        if (searched_item !=nullptr)
        {
            if (total_fees > 0)
            {
                flag = patrons.pay_fines();
                if(flag == 2 )
                {
                    cout << "Please pay your dues first" << endl;
                }

                else if (flag == 1)
                {
                    searched_patron->set_num_items(total_items-1);
                    searched_item->set_status("in");
                    delete_loan(loan_id);
                }    
            }
            searched_item->set_status("in");
            searched_patron->set_num_items(total_items-1);
        }
    }
}

void Loans::list_patron_items(int patron_id, LibraryItems& items)
{
    LibraryItem* item;
    int searched_item_id;
    for (int i = 0 ; i < loan_count ; i++)
    {
        if (patron_id == loan_list[i].get_patron_id())
        {
            searched_item_id = loan_list[i].get_item_id();
            item = items.search_item(searched_item_id);
            if (item!=nullptr)
            {
                cout << item->get_title() << endl;
            }
            
        }
    }
}

void Loans::list_all_overdue()
{
    int overdue_loan;
    for (int i = 0; i < loan_count ; i++)
    {
        if (loan_list[i].get_current_status() == "overdue" )
        {
            overdue_loan = loan_list[i].get_loan_id();
            cout << overdue_loan << endl;
        }
    }
}

void Loans::report_lost(int loan_id, LibraryItems& items)
{
    LibraryItem item;
    int searched_item_id;
    Loan jpt;
    Loan* searched = search_loan(loan_id);
    if (loan_id == searched->get_loan_id())
    {
        searched_item_id = searched->get_item_id();
        LibraryItem* searched_item = items.search_item(searched_item_id);
        if (searched_item!=nullptr)
        {
            searched_item->set_status("Lost");
        }
    }
}

void Loans::delete_loan(int loan_id)
{
    for (int i = 0; i < loan_count ; i++)
    {
        if (loan_list[i].get_loan_id() == loan_id)
        {
            loan_list.erase(loan_list.begin()+i);
            loan_count--;
        }
    }
}

vector<Loan> &Loans::get_loan_list()
{
    return loan_list;
}

int Loans::get_loan_count()
{
    return loan_count;
}

void Loans::increament_loan_id()
{
    loans_id++;
}

void Loans::increament_loan_count()
{
    loan_count++;
}

       
