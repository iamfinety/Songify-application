#ifndef SONGIFY_H
#define SONGIFY_H
#include "Song.h"
#include "SongArray.h"
#include "Album.h"
#include "AlbumArray.h"
#include <iostream>
#include <string>
using namespace std;

class Songify{
    public:
        Songify();
        ~Songify();
        bool addAlbum(const string&, const string&);
        bool removeAlbum(const string&, const string&);
        bool addSong(const string&, Song);
        bool removeSong(const string&, const string&, const string&);
        bool downloadAlbum(const string&, const string&, Album**);
        bool streamSong(const string&, const string&, const string&, Song**);
        void printAlbums();
        void printSongs();
    private:
        AlbumArray* pointer;
};


#endif