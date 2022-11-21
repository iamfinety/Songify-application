# Songify-application
It mimics a streaming service for music.
please use makefile to compile
./a2 to get the output

Any Song on the Songify network must belong to an Album.Albums have a title and an artist and a data structure for storing Songs. 
Each Song will have a title, artist, album, content. Songs may be printed (which is to have their metadata displayed) or played, which is to display
their metadata and content. 
The Songify network will consist of 0 or more Albums. A Client class will be able connect to the Songifynetwork where they can “stream” Songs from any Album. 
In addition, the Client will be able to “download” Albums. 
This copies the Album to “local storage”, which is a data structurein the Client class. 
Subscribers can then play the Album locally, which should work even if the Songify network deletes the original Album.
