#ifndef ALBUM_H
#define ALBUM_H
#include "Song.h"
#include "SongArray.h"
#include "defs.h"
#include <iostream>
#include <string>

class Album{
    public:
        Album(const string&, const string&);
        Album(const Album&);
        ~Album();
        string getArtist();
        string getTitle();
        bool matches(const string&, const string&);
        bool lessThan(Album&);
        bool addSong(Song*);
        bool addSong(int, Song*);
        bool getSong(const string&, Song**);
        bool getSong(int, Song**);
        bool removeSong(const string&, Song**);
        bool removeSong(int, Song**);
        void print();
        void printShort();
    private:
        string artist;
        string title;
        SongArray* pointer;
};


#endif