#include "Album.h"

Album::Album(const string& a, const string& t){
    artist = a;
    title = t;
    pointer = new SongArray();
}
Album::Album(const Album& album){
    artist = album.artist;
    title = album.title;
    pointer = new SongArray();
    for(int i =0; i<album.pointer->size();++i){
        Song* song;
        if(album.pointer -> get(i, &song)){
            pointer->add(i, new Song(*song));
        }
    }
}
Album::~Album(){
    delete pointer;
}
string Album::getArtist(){
    return artist;
}
string Album::getTitle(){
    return title;
}
bool Album::matches(const string& artist, const string& title){

    if(this->artist.compare(artist) == 0){
        if(this->title.compare(title) == 0){
            return true;
        }
    }
    return false;
 
}
bool Album::lessThan(Album& alb){
    if(artist.compare(alb.artist)<0){
        return true;
    }
    else if(artist.compare(alb.artist) == 0){
        if(title.compare(alb.title)<0){
            return true;
        }
    }
    return false;
}
bool Album::addSong(Song* s){
    if(artist.compare(s->getArtist()) == 0){
        return pointer->add(s);
    }
    return false;
}
bool Album::addSong(int index, Song* s){
   if(artist.compare(s->getArtist()) == 0){
        return pointer->add(index, s);
    }
    return false;
}
bool Album::getSong(const string& t, Song** song){
    return pointer->get(this->artist, t, song);
}
bool Album::getSong(int index, Song** song){
    return pointer->get(index, song);
}
bool Album::removeSong(const string& t, Song** song){
    return pointer->remove(this->artist, t, song);
}
bool Album::removeSong(int index, Song** song){
    return pointer->remove(index, song);
}
void Album::print(){

    cout<<"Title of the album is: "<<getTitle()<<endl;
    cout << "Artist of the album is: "<<getArtist()<<endl;
    pointer->print();

}
void Album::printShort(){
    cout<<"Title of the album is: "<<getTitle()<<endl;
    cout << "Artist of the album is: "<<getArtist()<<endl;
}