#ifndef AUDIO_H
#define AUDIO_H
#include "LibraryItem.h"

class Audio:public LibraryItem
{
    private:
        string artist;
        int numTracks;
        string releaseDate;
        string genre;
    public:
        Audio(int id);
        Audio(int id,double cost, string status, int loanPeriod,string artist, int numTracks, string releaseDate, string genre,string title);
        void set_artist(string artist);
        void set_numTracks(int numTracks);
        void set_releaseDate(string releaseDate);
        void set_genre(string genre);
        string get_artist();
        int get_numTracks();
        string get_releaseDate();
        string get_genre();
        int get_id();
        void save(ofstream &file) override;
        void edit();
};
#endif