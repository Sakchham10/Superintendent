#include "Audio.h"
#include "LibraryItem.h"
#include <iostream>
#include <fstream>
Audio::Audio(int id):LibraryItem()
{
    string artist;
    int numTracks;
    string releaseDate;
    string genre;  

    cout << "Enter the artist of the audio" << endl;
    getline(cin,artist);
    cout << "Enter the number of tracks of the audio" << endl;
    cin >> numTracks;
    cin.ignore();
    cout << "Enter the releaseDate of the audio" << endl;
    getline(cin,releaseDate);
    cout << "Enter the genre of the aduio" << endl;
    getline(cin,genre);
    
    this->artist= artist;
    this->numTracks= numTracks;
    this->releaseDate= releaseDate;
    this->genre= genre; 
    this->id = id;
}
Audio::Audio(int id,double cost, string status, int loanPeriod,string artist, int numTracks, string releaseDate, string genre, string title):LibraryItem(cost,status,loanPeriod,title)
{
    this->id = id;
    this->artist= artist;
    this->numTracks= numTracks;
    this->releaseDate= releaseDate;
    this->genre= genre; 
}


void Audio:: set_artist(string artist)
{
    this->artist =artist;
}

void Audio:: set_numTracks(int numTracks)
{
    this->numTracks =numTracks;
}

void Audio:: set_releaseDate(string releaseDate)
{
    this->releaseDate =releaseDate;
}

void Audio:: set_genre(string genre)
{
    this->genre =genre;
}

string Audio:: get_artist()
{
    return artist;
}

int Audio:: get_numTracks()
{
    return numTracks;
}

string Audio:: get_releaseDate()
{
    return releaseDate;
}

string Audio:: get_genre()
{
    return genre;
}

int Audio::get_id()
{
    return id;
}
void Audio::save(ofstream &file)
{
    LibraryItem::save(file);
    Audio* audio;
    file << "A" << " " << this->get_id() << " " << this->get_artist() << " " << this->get_numTracks() << " " << this->get_releaseDate() << " " ;
    file << this->get_genre() << " " << endl;
}

void Audio::edit()
{   
    string new_record;
    string new_artist;
    string new_releaseDate;
    string new_genre;
    cout << "Enter the new record" << endl;
    getline(cin,new_record);
    cout << "Enter the new artist" << endl;
    getline(cin,new_artist);
    cout << "Enter the new release date" << endl;
    getline(cin,new_releaseDate);
    cout << "Enter the new genre" << endl;
    getline(cin,new_genre);

    title = new_record;
    artist = new_artist;
    releaseDate = new_releaseDate;
    genre = new_genre;
}


