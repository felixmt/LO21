/**
 * \file	NotesManager.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Gestionnaire de tags, classe singleton
 */

#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H

#include <QSet>
#include "note.h"
#include "NoteFactory.h"
#include "ArticleFactory.h"
#include "Article.h"
#include "document.h"
#include "TagManager.h"
#include "Corbeille.h"

class Corbeille;
/**
* \class NotesManager NotesManager.h
*/
    class NotesManager {
        friend class NoteFactory; // pour pouvoir une utiliser getNote dans note factory
        protected:
        static NotesManager* instance; // pointeur sur l'unique instance
        QList <Note*> tab;
        QString workPath; // path de la forme : .../.../.../ ne pas oublier le slash à la fin
        //NotesManager(const NotesManager&); // non défini mais privé pour empêcher la duplication
        NotesManager& operator=(const NotesManager&); // même chose

        NotesManager(QString& p):workPath(p){ /*TagManager::getInstance();*///Corbeille::getInstance();//
                                            }//A checker pour le fonctionnement du Singleton


        QString getFileType(QString& path);
       // NotesManager():workPath(""){}

    public:
         virtual ~NotesManager();
 /**
 * \brief		Fonction qui cree une instance de NotesManager s'il n'en existe pas une (NotesManager est une classe singleton)
 */
        static NotesManager& getInstance(){ if(!instance){
                QString path = getLastNameWS();
                instance=new NotesManager(path);
                TagManager::getInstance();
            }
            return *instance;}
        static QString getLastNameWS();
 /**
 * \brief		Fonction qui libère l'instance si elle existe, via le destructeur de la classe
 */
     		
        static void libererInstance(){if(instance) instance->~NotesManager();}
        virtual Note* getNewNote(QString& title,QString& type);//retourne un nouvel objet note, fait appel à chooseFactory() de NoteFactory
        // static parce que singleton de notesmanager ne marche pas pour le moment
        Note& getNote(unsigned int id); // renvoie un objet Note existant dans le notesmanager
        Note* getNoteByPos(int pos);
        void addNote(Note* n); // ajoute une note à la liste tab
        Note* getFileNote(QString& path,QString& type);
        Note* getTab(int i){return tab[i];}
        QString& getWorkPath() {return workPath;}
        int getTabSize(){ return tab.size(); }
        Note* getNoteByTitle(QString& title);
		
 /**
 * \brief		Fonction qui créé un nouvel espace de travail
 * \param		wp		chemin du nouvel espace
 */
        void createNewWorkspace(QString& wp);
		
/**
 * \brief		Fonction qui change l'espace de travail
 * \param		wp		chemin du nouvel espace
 */
        void createNewWorkspaceFrom(QString& wp);
		
/**
 * \brief		Fonction qui sauve l'espace de travail
 * \param		wp		chemin du nouvel espace
 */
        void saveWorkSpace();
		
/**
 * \brief		Fonction qui sauve une note
 * \param		n		note à sauver
 */
        void saveNote(Note& n);
		
/**
 * \brief		Fonction qui supprime une note
 * \param		n		note a supprimer
 */
        void deleteNote(Note* n);

		/**
 * \brief		Fonction qui ouvre un espace de travail
 * \param		workPath	chemin de l'espace à ouvrir
 */
        void loadWorkSpace(QString& workPath);
        int getFileId(QString& path);

};

#endif // NOTESMANAGER_H
