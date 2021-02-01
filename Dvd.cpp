#include "Dvd.h"
#include <iostream>
#include <fstream>
#include "LibraryItem.h"

Dvd::Dvd(int id):LibraryItem()
{
    string category;
    int runTime;
    string studio;
    string releaseDate;

    cout << "Enter the category of DVD" << endl;
    getline(cin,category);
    cout << "Enter the runTime of DVD in seconds" << endl;
    cin >> runTime;
    cin.ignore();
    cout << "Enter the studio of DVD" << endl;
    getline(cin,studio);
    cout << "Enter the releaseDate of DVD"<<endl;
    getline(cin,releaseDate);

    this->category = category;
    this->runTime = runTime;
    this->studio = studio;
    this->releaseDate = releaseDate;
    this->id = id;
    
}

Dvd::Dvd(int id,double cost, string status, int loanPeriod,string category, int runTime, string studio, string releaseDate,string title):LibraryItem(cost,status,loanPeriod,title)
{
    this->id = id;
    this->category = category;
    this->runTime = runTime;
    this->studio = studio;
    this->releaseDate = releaseDate;

}
void Dvd:: set_category(string category)
{
    this->category = category;
}
void Dvd:: set_runTime(int runTime)
{
    this->runTime = runTime;
}
void Dvd:: set_studio(string studio)
{
    this->studio = studio;
}
void Dvd:: set_releaseDate(string releaseDate)
{
    this->releaseDate = releaseDate;
}

string Dvd:: get_category()
{
    return category;
}
int Dvd:: get_runTime()
{
    return runTime;
}
string Dvd:: get_studio()
{
    return studio;
}
string Dvd:: get_releaseDate()
{
    return releaseDate;
}  

int Dvd::get_id()
{
    return id;
}

void Dvd::save(ofstream &file)
{
    LibraryItem::save(file);
    Dvd* dvd;
    file << "D" << " " << this->get_id() << " " << this->get_category() << " " << this->get_runTime() << " ";
    file << this->get_studio() << " " << this->get_releaseDate() << endl;
}  

void Dvd::edit()
{
    string new_category;
    int new_run_time;
    string new_studio;
    string new_release_date;

    cout << "Enter the new category" << endl;
    getline(cin,new_category);
    cout << "Enter the new run time" << endl;
    cin >> new_run_time;
    cin.ignore();
    cout <<"Enter the new studio" << endl;
    getline(cin,new_studio);
    cout << "Enter the new release date" << endl;
    getline(cin,new_release_date);

    category = new_category;
    runTime = new_run_time;
    studio = new_studio;
    releaseDate = new_release_date;
}