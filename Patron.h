#ifndef PATRON_H
#define PATRON_H
#include <string>

using namespace std;

class Patron
{
    public:
        Patron(string name, int patron_id);
        Patron();
        void set_name(string name);
        string get_name();
        void set_patron_id(int patron_id);
        int get_patron_id();
        void set_fine_balance(int days);
        double get_fine_balance();
        void set_num_items(int num_items);
        int get_num_items();
       
    private:
        string name;
        int patron_id;
        double fine_balance;
        int num_items;          
};
#endif