#include "Tag.h"
#include <iostream>

void Tag::AddNote(Note* n)
{
    std::cout<<"J'ai utilisé addNote(int pos)\n";
    for(int i=0;i<tabNotes.size();i++)
        if(tabNotes[i]->getId() == n->getId())
            return;
    tabNotes<<n;
    n->addTag(this);
}

int Tag::getPosNote(Note* n)
{
    std::cout<<"J'ai utilisé getPosNote(Note* n)\n";
    for (unsigned int i = 0 ; i<tabNotes.size() ; i++)
    {
        if(tabNotes[i]==n) return i;
    }
    throw ("La note recherchée n'existe pas.");
}


void Tag::deleteNote(int i )
{
    std::cout<<"J'ai utilisé deleteNote()\n";
    tabNotes.removeAt(i);
//    std::cout<<"Taille du tableau"<<tabNotes.size();
}

Note* Tag::getNote(int i){
    std::cout<<"J'ai utilisé getNote(int i)\n";
    return tabNotes[i];

}
