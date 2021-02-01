#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <string>
using namespace std;

class LibraryItem
{
    protected:
        int id;
        double cost;
        string status;
        int loanPeriod;
        string title;
    public:
        LibraryItem();
        LibraryItem(double cost,string status,int loanPeriod,string title);
        void set_title(string title);
        string get_title();
        void set_id(int id);
        int get_id();
        void set_cost(double cost);
        double get_cost();
        void set_status(string status);
        string get_status();
        void set_loanPeriod(int loanPeriod);
        int get_loanPeriod();
        virtual void edit()
        {}
        friend ostream & operator << (ostream &out, const LibraryItem &item);
        virtual void save(ofstream &file);
};
#endif