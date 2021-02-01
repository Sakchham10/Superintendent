#include <iostream>
#include <string>
#include "Patrons.h"
#include "Patron.h"

using namespace std;

Patrons:: Patrons()
{
    patron_count = 0;
    patrons_id = 0;
}

Patron* Patrons::search_patron(int patron_id)
{   
    for (int i=0; i< patron_count; i++)
    {

        if (patron_id == patron_list[i].get_patron_id())
        {
            return &patron_list[i];
        }
    }   
    cout << "No match found " << endl;
    return nullptr;
}

void Patrons::add_patron()
{
    string name;
    cout << "Please enter name: ";
    getline(cin,name);
    increament_patron_id();
    Patron new_patron = Patron(name,patrons_id);
    patron_list.push_back(new_patron);
    patron_count++;
}

void Patrons::edit_patron(int patron_id)
{
    string new_name;
    cout << "Enter new name of patron" << endl;
    getline(cin,new_name);
    Patron* edited_patron = search_patron(patron_id);
    edited_patron->set_name(new_name);
}

void Patrons::print_patron_details(int patron_id)
{
    Patron* sanji = search_patron(patron_id);
    if (sanji != nullptr)
    {
        cout << "name " << sanji->get_name() << endl;
        cout << "id " << sanji->get_patron_id() << endl;
        cout << "fine balance " << sanji->get_fine_balance() << endl;
        cout << "items " << sanji->get_num_items() << endl;
    }
}    

void Patrons::print_patrons() 
{   
    for (auto p: patron_list)
    {
        cout << "name " << p.get_name() << endl; 
        cout << "fine balance " << p.get_fine_balance() << endl;
        cout << "num items " <<p.get_num_items() << endl;
        cout << "patron id "<< p.get_patron_id() << endl << endl;
    }
}

void Patrons::delete_patron(int patron_id)
{
    for (int i = 0; i < patron_count; i++)
    {
        Patron nami = patron_list[i]; 
        if(patron_id == nami.get_patron_id())
        {
            patron_list.erase(patron_list.begin()+i);
            patron_count--;  
        }
    }
}

int Patrons::pay_fines()
{
    int patron_id;
    string choice;
    cout << "Please enter the patron id you want to pay fine for" << endl;
    cin >> patron_id;
     cin.ignore();;
    Patron* searched = search_patron(patron_id);
    cout << "The fine of the patron you have searched is $ " << searched->get_fine_balance() << endl;
    cout << "Continue on the credit card terminal" << endl;
    cout << "Was the trasnsaction sucessful? Press 'y' for yes and 'n' for no" << endl;
    getline(cin,choice);
    if (choice == "y" || "Y")
    {
        searched->set_fine_balance(0);
        return 1;
    } 

    else if (choice == "n" || "N")
    {
        cout << "Your payment was declined." << endl;
        return 2;
    }

    else 
    {
        return 3;
    }
}

int Patrons::get_patronCount()
{
    return patron_count;
}

vector<Patron> &Patrons:: get_patronList()
{
    return patron_list;
}

void Patrons::increament_patron_count()
{
    patron_count++;
}

void Patrons::increament_patron_id()
{
    patrons_id++;
}

       


