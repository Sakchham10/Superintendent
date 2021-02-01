#ifndef PATRONS_H
#define PATRONS_H
#include <string>
#include "Patron.h"
#include <vector>

using namespace std;

class Patrons
{
    public:
        Patrons();
        Patron* search_patron(int patron_id);
        void add_patron();
        void edit_patron(int patron_id);
        void delete_patron(int patron_id);
        void print_patrons();
        void print_patron_details(int patron_id);
        int pay_fines();
        int get_patronCount();
        vector <Patron> &get_patronList();
        void increament_patron_count();
        void increament_patron_id();
    private:
        int patron_count;
        vector <Patron> patron_list;
        int patrons_id;
};     
#endif