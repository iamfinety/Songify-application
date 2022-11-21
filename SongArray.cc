#include <iostream>
using namespace std;

#include "SongArray.h"
SongArray::SongArray(){
    number =0;
    songsPointers = new Song*[MAX_ARRAY];
    for(int i=0;i<MAX_ARRAY;++i){
        songsPointers[i] = NULL;
    } 
}

SongArray::~SongArray(){
    for(int i=0;i<number;++i){
        delete songsPointers[i];
    }
    delete[] songsPointers;
}
bool SongArray::add(Song* s){
    if(number >= MAX_ARRAY){
        return false;
    }
    songsPointers[number]=s;
    ++number;
    return true;
}
bool SongArray::add(int index, Song* s){
    if(index<0 || index > number || number >= MAX_ARRAY){
        return false;
    }
    ++number;
    for(int i=number-1;i>index;--i) {
        songsPointers[i] = songsPointers[i-1];
    }
    songsPointers[index] = s;
    return true;
}
bool SongArray::get(const string& a, const string& t, Song** song){
  
    for(int i=0;i<number;++i){
        if(a == songsPointers[i]->getArtist()){
            if(t == songsPointers[i]->getTitle()){
                *song = songsPointers[i];
                return true;
            }
        }
    }
    return false;
   
}
bool SongArray::get(int index, Song** song){
    
    if(index<0 || index >= number){
        return false;
    }
    *song = songsPointers[index];
    return true;
  
}
bool SongArray::remove(const string& a, const string& t, Song** song){
  
    int index =0;
    while((songsPointers[index]->matches(a,t) == false) && index < number){
        ++index;
    }
    if(index == number){
        return false;
    }
    *song = songsPointers[index];
    while(index < number-1){
        songsPointers[index] = songsPointers[index+1];
        ++index;
    }
    --number;
    return true;
  
}
bool SongArray::remove(int index, Song** song){

    if(!get(index, song)) {
        return false;
    }
    for(int i=index;i<number-1;++i){
        songsPointers[i] = songsPointers[i+1];
    }
    --number;
    return true;

}
int SongArray::size(){
    return number;
}
bool SongArray::isFull(){
    if(number>=MAX_ARRAY){
        return true;
    }
    return false;
}
void SongArray::print(){
    cout << endl << "Songs:" << endl;
    for(int i=0;i<number;++i){
        songsPointers[i]->play();
    }
    cout << endl;
}