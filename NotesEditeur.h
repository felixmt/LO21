/**
 * \file	NotesEditeur.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	fenetre d'edition de notes, classe abstraite
 */

#ifndef NOTESEDITEUR_H
#define NOTESEDITEUR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "note.h"
#include "TagManager.h"
#include "NotesManager.h"
#include "TagEditeur.h"

class addTag;

/**
* \class NotesEditeur NotesEditeur.h
*/
class NotesEditeur : public QWidget {
    Q_OBJECT
protected :
    QLineEdit *title;
    QPushButton *save;
    QPushButton *addTag;
    QPushButton *supp;
    QVBoxLayout *layout;
    QHBoxLayout *buttonLayout;
	bool saved;
public:

/**
 * \brief		Constructeur de NotesEditeur
 * \param		n note a recopier
 * \param		parent QWidget, 0 par defaut
 */
    NotesEditeur(Note* n, QWidget* parent=0);
    QLineEdit& getTitle() const {return *title;}
    virtual Note* getNote() const=0;
    QPushButton* getAddTag(){ return addTag; }
	QPushButton* getSuppButton() {return supp;}
    QPushButton* getSaveButton() {return save;}
	bool getSaved() const {return saved;}
    bool setSaved(bool s);	
	 /**
 * \brief		Slot qui sauve l'article en cours d'edition
 */
   virtual void saveNote() =0;
	
 /**
 * \brief		Slot qui actualise la note en fonction des modifications effectuees par l'utilisateur dans l'editeur
 */
    virtual void updateNote() =0;

signals :

public slots :
};

#endif // NOTESEDITEUR_H
