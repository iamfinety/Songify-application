#ifndef SONGARRAY_H
#define SONGARRAY_H
#include "Song.h"
#include "defs.h"

#include <string>

class SongArray{
    public:
        SongArray();
        ~SongArray();
        bool add(Song*);
        bool add(int, Song*);
        bool get(const string&, const string&, Song**);
        bool get(int, Song**);
        bool remove(const string&, const string&, Song**);
        bool remove(int, Song**);
        int size();
        bool isFull();
        void print();
    private:
        Song** songsPointers;
        int number;
};

#endif