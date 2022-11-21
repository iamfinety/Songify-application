#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H
#include "Song.h"
#include "defs.h"
#include "Album.h"
#include <string>

class AlbumArray{
    public:
        AlbumArray();
        ~AlbumArray();
        bool add(Album*);
        bool get(const string&, const string&, Album**);
        bool get(int, Album**);
        bool remove(const string&, const string&, Album**);
        bool remove(int, Album**);
        int size();
        bool isFull();
        void printShort();
    private:
        Album** albumsPointers;
        int number;
};

#endif