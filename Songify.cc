#include "Songify.h"

Songify::Songify(){
    pointer = new AlbumArray();
}
Songify::~Songify(){
    delete pointer;
}
bool Songify::addAlbum(const string& a, const string& t){
    if(!pointer->isFull()){
        Album* album = new Album(a, t);
        return pointer->add(album);
    }
    cout << "Failed to add album."<<endl;
    return false;
}
bool Songify::removeAlbum(const string& a, const string& t){
    Album* album;
    if(pointer->remove(a, t, &album)){
        delete album;
        return true;
    }
    cout << "Failed to remove album."<<endl;
    return false;
}
bool Songify::addSong(const string& tOfAlbum, Song song){
    Album* album;
    if(!pointer->get(song.getArtist(), tOfAlbum, &album)) {
        return false;
    }
    Song* p = new Song(song);
    if(album->addSong(p)){
        return true;
    }
    delete p;
    cout << "Failed to add song."<<endl;
    return false;
}
bool Songify::removeSong(const string& a, const string& tOfAlbum, const string& tOfSong){
    Album* album;
    Song* song;
    if(pointer->get(a, tOfAlbum, &album)){
        if(album->getSong(tOfSong, &song)){
            album->removeSong(tOfSong, &song);
            delete song;
            return true;
        }
    }
    cout << "Failed to remove song."<<endl;
    return false;
}
bool Songify::downloadAlbum(const string& a, const string& tOfAlbum, Album** album){
    if(pointer->get(a, tOfAlbum, album)){
        return true;
    }
    cout << "Failed to download the album."<<endl;
    return false;
}
bool Songify::streamSong(const string& a, const string& tOfAlbum, const string& tOfSong, Song** song){
    Album* album;
    if(pointer->get(a, tOfAlbum, &album)){
        if(album->getSong(tOfSong, song)){
            return true;
        }
    }
    cout << "Failed to stream song."<<endl;
    return false;
}
void Songify::printAlbums(){
    pointer->printShort();
}
void Songify::printSongs(){ 
    Album* album; 
    for(int i =0; i< pointer->size();++i){
        
        pointer->get(i, &album);
        album -> print();
    }
}