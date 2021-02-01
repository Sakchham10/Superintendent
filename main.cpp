#include <iostream>
#include "Patron.h"
#include "Book.h"
#include "Loan.h"
#include "Patrons.h"
#include "LibraryItems.h"
#include "Loans.h"
#include "LibraryItem.h"
#include "save.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void menu()
{
    cout << endl;
    cout << "               MENU                " << endl;
    cout << endl;
    cout << "   AP  - Add Patron" << endl;
    cout << "   EP  - Edit Patron" << endl;
    cout << "   DP  - Delete Patron" << endl;
    cout << "   PAP - Print All Patrons" << endl;   
    cout << "   PPD - Print Patron Details"<< endl;
    cout << "   PF  - Pay Fines"<< endl;
    cout << "   SP  - Search Patrons" << endl;
    cout << "   AI  - Add item" << endl;
    cout << "   EI  - Edit item" << endl; 
    cout << "   DI  - Delete item"<< endl;
    cout << "   SI  - Search item"<< endl;
    cout << "   PAI - Print All items" << endl;
    cout << "   PID - Print item Details" << endl;
    cout << "   CHO - Check Out" << endl;
    cout << "   CHI - Check In" << endl;
    cout << "   LAO - List All Overdue" << endl;
    cout << "   LPI - List All items for a Patron" << endl;
    cout << "   RL  - Report Lost" << endl;
    cout << "   SL  - Search Loan" << endl;
    cout << "   DL  - Delete Loan" << endl;
    cout << "   SAVE- Save data" << endl;
    cout << "   LOAD- Load data" << endl;
    cout << "   Q   - Quit" << endl; 
    cout << "Enter an option: ";    
}
int main()

{
    string option = "default";
    Patrons patrons;
    LibraryItems items;
    Loans loans;
    Save save;
    int patron_id;
    int item_id;
    int loan_id;
    while(option != "q" && option !="Q")
    {
        menu();
        getline(cin,option);
        
        if (option == "AP")
        {
            patrons.add_patron();
        }

        else if (option == "EP")
        {
            
            cout << "Enter the Patron Id you want to edit" << endl;
            cin >> patron_id;
             cin.ignore();
            patrons.edit_patron(patron_id);
        }   

        else if (option == "DP")
        {   
          
            cout << "Enter the Patron Id you want to delete" << endl;
            cin >> patron_id;
             cin.ignore();
            patrons.delete_patron(patron_id);
        }

        else if (option == "PAP")
        {
            patrons.print_patrons();
        }

        else if (option == "PPD")
        {
            cout<< "Enter the patron id you want to search for " << endl;
            cin >> patron_id; 
            cin.ignore();
            patrons.print_patron_details(patron_id);
        }

        else if (option == "PF")
        {
            patrons.pay_fines();
        }

        else if (option == "SP")
        {
            cout << "Enter the patron id you want to search" << endl;
            cin >> patron_id;
            cin.ignore();
            Patron *patron;
            patron = patrons.search_patron(patron_id);
            if (patron!= nullptr)
            {
                cout<< patron->get_name() << endl;
            }  
        }

        else if (option == "AI")
        {
            items.add_item();
        }
        
        else if (option == "EI")
        {
            cout << "Enter the item id you want to edit" << endl;
            cin >> item_id;
            cin.ignore();
            items.edit_item(item_id);
        }

        else if (option == "DI")
        {
            cout << "Enter the item id you want to delete" << endl;
            cin >> item_id;
            cin.ignore();
            items.delete_item(item_id);
        }
        else if(option == "SI")
        {
            cout << "Enter the item id you want to search for" << endl;
            cin >> item_id;
            cin.ignore();
            LibraryItem* item;
            item = items.search_item(item_id);
            if (item != nullptr)
            {
                cout << item->get_title() << endl;
            }
        }
        else if (option == "PAI")
        {
            items.print_items();
        }

        else if (option == "PID")
        {
            cout << "Enter the item id you want to search for" << endl;
            cin >> item_id;
            cin.ignore();
            items.print_item_details(item_id);
        }

        else if (option == "CHO")
        {
            loans.checkout(patrons,items);
        }
        
        else if (option == "CHI")
        {
            loans.checkin(patrons, items);
        }

        else if (option == "LAO")
        {
            loans.list_all_overdue();
        }

        else if(option == "LPI")
        {
            cout << "Enter the patron id you want to search for" << endl;
            cin >> patron_id;
            cin.ignore();
            loans.list_patron_items(patron_id, items);
        }

        else if (option == "RL")
        {
            cout << "Enter the loan id you want to report lost" << endl;
            cin >> loan_id;
            cin.ignore();
            loans.report_lost(loan_id, items);
        }

        else if (option == "SL")
        {
            cout << "Enter the loan id you want to search for" << endl;
            cin >> loan_id;
            cin.ignore();
            loans.search_loan(loan_id);
        }

        else if (option == "DL")
        {
            cout << "Enter the loan id you want to delete" << endl;
            cin >> loan_id;
            cin.ignore();
            loans.delete_loan(loan_id); 
        }

        else if (option == "SAVE" )
        {
            save.save_patrons(patrons);
            save.save_loans(loans);
            save.save_items(items);
        }

        else if (option == "LOAD")
        {
            save.load_patrons(patrons);
            save.load_loans(loans);
            save.load_items(items);
        }
    }  
}