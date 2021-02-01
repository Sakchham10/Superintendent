#ifndef LOANS_H 
#define LOANS_H
#include <string>
#include "Loan.h"
#include "Patrons.h"
#include "LibraryItems.h"
#include<vector>

using namespace std;

class Loans
{
    public:
        Loans();
        void checkout(Patrons &patrons,  LibraryItems& items);
        void checkin(Patrons &patrons, LibraryItems& items);
        void list_all_overdue();
        void list_patron_items(int patron_id, LibraryItems& items);
        void update_loans();
        void recheck_item(int loan_id);
        void report_lost(int loan_id, LibraryItems& items);
        Loan* search_loan(int loan_id);
        void delete_loan(int loan_id);
        vector <Loan> &get_loan_list();
        int get_loan_count();
        void increament_loan_count();
        void increament_loan_id();
    private:
        vector<Loan> loan_list;
        int loan_count;
        int loans_id;
};
#endif