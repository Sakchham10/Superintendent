#ifndef SAVE_H
#define SAVE_H

#include "Patron.h"
#include "Patrons.h"
#include "LibraryItem.h"
#include "LibraryItems.h"
#include "Loan.h"
#include "Loans.h"

class Save
{
    public:
        void save_patrons(Patrons &patrons);
        void save_loans(Loans &loans);
        void save_items(LibraryItems &items);
        void load_patrons(Patrons &patrons);
        void load_items(LibraryItems &items);
        void load_loans(Loans &loans);
};

#endif