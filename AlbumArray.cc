#include <iostream>
using namespace std;

#include "AlbumArray.h"
AlbumArray::AlbumArray(){
    number =0;
    albumsPointers = new Album*[MAX_ARRAY];
    for(int i=0;i<MAX_ARRAY;++i){
        albumsPointers[i] = NULL;
    } 
}

AlbumArray::~AlbumArray(){
    // for(int i=0;i<number;++i){
    //     delete albumsPointers[i];
    // }
    delete[] albumsPointers;
}
bool AlbumArray::add(Album* a){
    if(number >= MAX_ARRAY){
        return false;
    }
    int index = 0;
    while(index < number && !a->lessThan(*albumsPointers[index])) {
        ++index;
    }
    for(int i=number;i>index;--i) {
        albumsPointers[i] = albumsPointers[i-1];
    }
    albumsPointers[index] = a;
    ++number;
    return true;
}
bool AlbumArray::get(const string& a, const string& t, Album** album){
  
    for(int i=0;i<number;++i){
        if(a == albumsPointers[i]->getArtist()){
            if(t == albumsPointers[i]->getTitle()){
                *album = albumsPointers[i];
                return true;
            }
        }
    }
    return false;
   
}
bool AlbumArray::get(int index, Album** album){
    
    if(index<0 || index >= number){
        return false;
    }
    *album = albumsPointers[index];
    return true;
  
}
bool AlbumArray::remove(const string& a, const string& t, Album** album){
  
    int index =0;
    while((albumsPointers[index]->matches(a,t) == false) && index < number){
        ++index;
    }
    if(index == number){
        return false;
    }
    return remove(index, album);
  
}
bool AlbumArray::remove(int index, Album** album){
    if(index<0 || index >= number){
        return false;
    }
    *album = albumsPointers[index];
    for(int i=index;i<number-1;++i){
        albumsPointers[i] = albumsPointers[i+1];
    }
    --number;

    return true;

}
int AlbumArray::size(){
    return number;
}
bool AlbumArray::isFull(){
    if(number>=MAX_ARRAY){
        return true;
    }
    return false;
}
void AlbumArray::printShort(){
    cout << endl << "Albums:" << endl;
    for(int i=0;i<number;++i){
        albumsPointers[i]->printShort();
    }
    cout << endl;
}