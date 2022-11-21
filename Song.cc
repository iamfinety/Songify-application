#include "Song.h"

Song::Song(const string& a, const string& t, const string& c){
    this->artist = a;
    this->title = t;
    this->content = c;
}
Song::Song(){
    this->title = "";
    this->artist = "";
    this->content = "";
}
Song::Song(const Song& s){
    this->title = s.title;
    this->artist = s.artist;
    this->content = "A message from the RCMP about violating copyright infringement";
}
Song::~Song(){
    
}
string Song::getArtist(){
    return artist;
}
string Song::getTitle(){
    return title;
}
bool Song::matches(const string& artist, const string& title){
    if(this->artist.compare(artist) == 0){
        if(this->title.compare(title) == 0){
            return true;
        }
    }
    return false;
}
void Song::print(){
    cout << "Artist of the song is: "<<getArtist()<<endl;
    cout << "Title of the song is: "<<getTitle()<<endl;
}
void Song::play(){
    print();
    cout << "Content of the song is: "<<this->content <<endl;
}