/**
 * \file	Corbeille.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Gestion de la corbeille
 */

#ifndef CORBEILLE_H
#define CORBEILLE_H

#include <iostream>
#include <QSet>
#include <QList>
#include "note.h"


#include <QWidget>
#include <QListWidget>

#include <QListWidgetItem>

#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QMessageBox>

class Note;
/**
* \class Corbeille Corbeille.h
*/
class Corbeille{

private :
    QList<Note*> dust;
    Corbeille();
    Corbeille(const Corbeille& c);
    Corbeille& operator=(const Corbeille& c);
    static Corbeille* instance;
    ~Corbeille(){}
    Note* getNoteId(int id);

public :
/**
 * \brief		Fonction qui cree une instance de Corbeille s'il n'en existe pas une (Corbeille est une classe singleton)
 */
    static Corbeille& getInstance();

	/**
 * \brief		Fonction qui supprime une instance de Corbeille s'il en existe une.
 */
    static void deleteInstance(){if(instance) delete instance;}
	
	/**
 * \brief		Fonction qui vide la corbeille(vide le tableau de note)
 */
    void viderCorbeille(){dust.clear();}
	
	/**
 * \brief		Fonction qui renvoie la taille du tableau de notes
 */	
    int getSizeDust() const {return dust.size();}
    Note* getNoteViaName(QString name);
    void deleteNote(Note* n);

    Note* getNote(int id);
    Note* getNoteByPos(int pos){ return dust[pos]; }
	
	/**
 * \brief		Fonction qui supprime une note de la corbeille
* \param		n		note a retirer de la corbeille
 */	
    void addNote(Note*n);
	
	/**
 * \brief		Fonction qui remet la note dans les notes actives (dans le tableau de notes de TagManager)
* \param		n		note a restaurer
 */	
    void putBackNote(Note* n);
    int getPosNote(Note*n);
};


#endif // CORBEILLE_H
