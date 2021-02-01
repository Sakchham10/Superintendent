#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H
#include <vector>
#include "LibraryItem.h"

class LibraryItems
{
    private:
        int item_count;
        vector<LibraryItem*> item_list;
        int items_id;

    public:
        LibraryItems();
        ~LibraryItems()
        {
            for (int i = 0 ; i < item_count; i++ )
            {
                delete item_list[i];
            }
        }
        void add_item();
        void edit_item(int id);
        void delete_item(int id);
        LibraryItem* search_item(int id);
        void print_items();
        void print_item_details(int id);
        int get_item_count();
        vector <LibraryItem*> &get_item_list();
        void increament_item_count();
        void increament_item_id();

};
#endif