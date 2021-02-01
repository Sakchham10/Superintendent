#include "LibraryItems.h"
#include "LibraryItem.h"
#include "Book.h"
#include "Audio.h"
#include "Dvd.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

LibraryItems::LibraryItems()
{
    item_count = 0;
    items_id = 0;
}

LibraryItem* LibraryItems::search_item(int id)
{
    for (int i = 0 ; i < item_count ; i++) 
    {
        if (id == item_list[i]->get_id())
        {
            return item_list[i];
        }
    }
    cout << "No item found" << endl;
    return nullptr;
} 

void LibraryItems::add_item()
{
    string choice;
    int id;
    cout << "Please enter the type of item you want to add" << endl;
    cout << "A for Audio" << endl;
    cout << "B for Book" << endl;
    cout << "D for DVD" << endl;
    getline(cin,choice);

    if(choice == "A")
    {
        increament_item_id();
        Audio* audio = new Audio(items_id);
        item_count++;
        item_list.push_back(audio);

    }
    else if(choice == "B")

    {
        increament_item_id();
        Book* book = new Book(items_id);
        item_count++;
        item_list.push_back(book);
    }

    else if(choice == "D")
    {
        increament_item_id();
        Dvd* dvd = new Dvd(items_id);
        item_count++;
        item_list.push_back(dvd);
    }

    else
    {
        cout << "Invalid choice" << endl;
    }
    
}

void LibraryItems::edit_item(int id)
{
    LibraryItem* edit_item = nullptr;
    cout << id << endl;
    edit_item = search_item(id);
    if(edit_item == nullptr)
    {
        return;
    }
    edit_item->edit();
}

void LibraryItems::delete_item(int id)
{  
    for (int i = 0 ; i < item_count; i++)
    {
        if (item_list[i]->get_id() == id)
        {
            LibraryItem* item = item_list[i];
            item_list.erase(item_list.begin()+i);
            item_count--;
            delete item;
        }
    }
}

void LibraryItems::print_items()
{
  
    for (int i=0; i<item_count ; i++)
    {
        LibraryItem total = *item_list[i];
        cout << total <<endl;
    }
}

void LibraryItems::print_item_details(int id)
{
    LibraryItem* edit_item = search_item(id);
   
    LibraryItem total = *edit_item;
    cout << total <<endl;
}

int LibraryItems::get_item_count()
{
    return item_count;
}

vector <LibraryItem*> &LibraryItems::get_item_list()
{
    return item_list;
}

void LibraryItems::increament_item_count()
{
    item_count++;
}

void LibraryItems::increament_item_id()
{
    items_id++;
}