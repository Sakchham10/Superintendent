#ifndef LOAN_H 
#define LOAN_H
#include <string>

using namespace std;

class Loan
{
    private:
        int loan_id;
        int item_id;
        int patron_id;
        string due_date;
        string current_status; 
    public:
        Loan(int loan_id, int item_id, int patron_id, string due_date, string current_status);
        Loan();
        void set_loan_id(int loan_id);
        int get_loan_id();
        void set_item_id(int item_id);
        int get_item_id();
        void set_patron_id(int patron_id);
        int get_patron_id();
        void set_due_date(string due_date);
        string get_due_date();
        void set_current_status(string current_status);
        string get_current_status();

};
#endif