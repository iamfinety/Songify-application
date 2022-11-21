#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;
class Song{
    public:
        Song(const string&, const string&, const string&);
        Song();
        Song(const Song&);
        string getArtist();
        string getTitle();
        bool matches(const string&, const string&);
        void print();
        void play();
        ~Song();
    private:
        string artist;
        string title;
        string content;
};
#endif