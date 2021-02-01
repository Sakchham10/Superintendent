#ifndef DVD_H
#define DVD_H
#include "LibraryItem.h"

class Dvd: public LibraryItem
{
    private:
        string category;
        int runTime;
        string studio;
        string releaseDate;

    public:
        Dvd(int id);
        Dvd(int id,double cost, string status, int loanPeriod,string category, int runTime, string studio, string releaseDate,string get_title);
        void set_category(string category);
        void set_runTime(int runTime);
        void set_studio(string studio);
        void set_releaseDate(string releaseDate);
        string get_category();
        int get_runTime();
        string get_studio();
        string get_releaseDate();
        int get_id();
        void save(ofstream &file) override;  
        void edit();    
};      
#endif