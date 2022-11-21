#include "Client.h"

Client::Client(){
    pointer = new AlbumArray();
}
Client::~Client(){
    delete pointer;
}
bool Client::download(Songify* songify, const string& a, const string& tOfAlbum){
    Album* album;
    if(songify->downloadAlbum(a, tOfAlbum, &album)){
        if(pointer->size() < MAX_ARRAY){
            Album* newAlbum = new Album(*album);
            if(pointer->add(newAlbum)){
                return true;
            }
        }
    }
    cout << "Failed to download the album from Songify."<<endl;
    return false;
}
bool Client::stream(Songify* songify, const string& a, const string& tOfAlbum, const string& tOfSong){
    Song* song;
    if(songify->streamSong(a, tOfAlbum, tOfSong, &song)){
        song->play();
        return true;
    }
    cout << "Failed to stream the song from Songify."<<endl;
    return false;
}
bool Client::playLocal(const string& a, const string& tOfAlbum, const string& tOfSong){
    Album* album;
    Song* song;
    if(pointer->get(a, tOfAlbum, &album)){
        if(album->getSong(tOfSong, &song)){
            song->play();
            return true;
        }
    }
    cout << "Failed to play the song from Songify."<<endl;
    return false;
}
void Client::printAlbums(){
     pointer->printShort();
}
void Client::printSongs(){
    Album* album; 
    for(int i =0; i< pointer->size();++i){
        pointer->get(i, &album);
        album -> print();
    }
}