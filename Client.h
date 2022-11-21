#ifndef CLIENT_H
#define CLIENT_H
#include "Song.h"
#include "SongArray.h"
#include "Songify.h"
#include "AlbumArray.h"
#include <iostream>
#include <string>
using namespace std;

class Client{
    public:
        Client();
        ~Client();
        bool download(Songify*, const string&, const string&);
        bool stream(Songify*, const string&, const string&, const string&);
        bool playLocal(const string&, const string&, const string&);
        void printAlbums();
        void printSongs();
    private:
        AlbumArray* pointer;
};


#endif