#include "save.h"
#include "Patrons.h"
#include "Loans.h"
#include "LibraryItems.h"
#include "Audio.h"
#include "Book.h"
#include "Dvd.h"
#include <sstream>
#include <iostream>
#include<fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void Save::save_patrons(Patrons &patrons)
{
    vector <Patron> &patronlist = patrons.get_patronList();
    ofstream file ("savefile.txt");
    Patron current;

    for (int i = 0; i< patrons.get_patronCount(); i++)
    {
        current =patronlist[i];
        file << "P" << " "<< current.get_name() << " " << current.get_patron_id() << " " <<  current.get_fine_balance() << " " << current.get_num_items() << endl;
    }

    file.close();
}

void Save::save_loans(Loans &loans)
{
    vector <Loan> &loanlist = loans.get_loan_list();
    ofstream file ("savefile.txt", ios::app);
    Loan current;
    for (int i = 0; i< loans.get_loan_count(); i++)
    {
        current =loanlist[i];
        file << "L" << " " << current.get_loan_id() << " " << current.get_item_id() << " " <<  current.get_patron_id() << " " << current.get_current_status() << endl;
    }

    file.close();
}

void Save::load_patrons(Patrons &patrons)
{

    vector <Patron> &patronlist = patrons.get_patronList();
    string type;
    string name ;
    string got_name;
    int id;
    int patron_id;
    double fine_balance;
    int num_items;
    ifstream file("savefile.txt");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        ss >> type; 
        if (type == "P")
        {
            ss >> name >> patron_id >> fine_balance >> num_items; 
            Patron patron;
            patron.set_name(name);
            patron.set_patron_id(patron_id);
            patron.set_fine_balance(fine_balance);
            patron.set_num_items(num_items);
            patronlist.push_back(patron);
            patrons.increament_patron_count();
        }
    }
}

void Save::load_loans(Loans &loans)
{

    vector <Loan> &loanlist = loans.get_loan_list();
    string type;
    int loan_id;
    int item_id;
    int patron_id;
    string current_status;
    string line;
    ifstream file("savefile.txt");
    while (getline(file,line) )
    {
       
        stringstream ss(line);
        ss >>type;
        if (type == "L")
        {
            ss>>loan_id >> item_id >> patron_id >> current_status;
            Loan loan;
            loan.set_loan_id(loan_id);
            loan.set_item_id(item_id);
            loan.set_patron_id(patron_id);
            loan.set_current_status(current_status);
            loanlist.push_back(loan);
            loans.increament_loan_count();
        }
    }
}

void Save::save_items(LibraryItems &items)
{
    vector <LibraryItem*> &itemlist = items.get_item_list();
    ofstream file ("savefile.txt",ios::app );
    LibraryItem* current;
    for (int i = 0; i< items.get_item_count(); i++)
    {
        current = itemlist[i];
        current->save(file);
    }                           

    file.close();
} 

void Save::load_items(LibraryItems& items)
{
    vector <LibraryItem*> &item_list = items.get_item_list();
    string type;
    string title;
    int item_id;
    double cost;
    string status;
    string type_2;
    string artist;
    int num_tracks;
    string release_date;
    string genre;
    string category;
    int run_time;
    string studio;
    string author;
    int isbn;
    ifstream file("savefile.txt");
    string line;
   
    while (getline(file,line))
    {
        stringstream ss(line);
        ss >> type;
        if (type == "I")
        {
          
            ss >>cost >> status >> title >>type_2;
            if(type_2 == "B")
            {
                ss >> item_id >> author >> isbn;
                Book* book = new Book(item_id, cost, status, 10 ,author,title,isbn);
                item_list.push_back(book);
                items.increament_item_count();
            }
            if(type_2 == "A")
            {
                ss >> item_id >> artist >> num_tracks >> release_date >> genre;
                Audio* audio = new Audio(item_id, cost, status, 10 ,artist,num_tracks,release_date,genre,title);
                item_list.push_back(audio);
                items.increament_item_count();
            }

            if(type_2 == "D")
            {
                ss >> item_id >> category >> run_time >> studio >> release_date;
                Dvd* dvd = new Dvd(item_id, cost, status, 10, category, run_time,studio ,release_date,title);
                item_list.push_back(dvd);
                items.increament_item_count(); 
             }
        }
    }
}                                               




