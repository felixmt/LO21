/**
 * \file	documentEditeur.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de la fenêtre d'edition de document, hérite de notesEditeur
 */

#ifndef DOCUMENTEDITEUR_H
#define DOCUMENTEDITEUR_H

#include "NotesEditeur.h"
#include "NotesManager.h"
#include "document.h"
#include "ArticleEditeur.h"
#include "ImageEditeur.h"
#include "VideoEditeur.h"
#include "AudioEditeur.h"

#include <QWidget>
#include <QSignalMapper>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QIcon>
#include <QList>
#include <QScrollArea>
#include <QListWidget>
/**
* \class DocumentEditeur documentEditeur.h
*/
class DocumentEditeur : public NotesEditeur {
    Q_OBJECT
    QWidget * conteneur;
    QVBoxLayout * layConteneur;
    QScrollArea *scrollArea;
    QList <NotesEditeur*> liste;
    Document *document;
    QHBoxLayout *layout_add;
    QPushButton *addArticle;
    QPushButton *addImage;
    QPushButton *addVideo;
    QPushButton *addAudio;
    QPushButton *addFrom;
    QSignalMapper *mapper;
    unsigned int scrollsize;
public:
/**
 * \brief		Constructeur de document
 */
    explicit DocumentEditeur(Note* d, QWidget *parent=0);
    QLineEdit& getTitle() const {return *title;}
    Document* getNote() const;
    NotesEditeur* getEditeur(unsigned int i) const {return liste[i];}
    //créer un signal si un article a été modifié pour activerSave de document
    //ajouter dans le foldable widget, la possibilité de removeNote
    //créer la possibilité de moveUp et moveDown
signals :

public slots :
/**
 * \brief		Slot qui sauve le document
 */
    void saveNote();
/**
 * \brief		Slot qui actualise le document
 */
    void updateNote();
	
/**
 * \brief		Slot qui ajoute un editeur 
 */
    void addEditor();
	
/**
 * \brief		Slot qui ajoute un article vide au document
 */
    void addEmptyArticle();
	
/**
 * \brief		Slot qui ajoute une image vide au document
 */
    void addEmptyImage();

/**
 * \brief		Slot qui ajoute une video vide au document
 */
    void addEmptyVideo();
	
/**
 * \brief		Slot qui ajoute une note audio vide au document
 */
    void addEmptyAudio();
	
/**
 * \brief		Slot qui ajoute une note existante au document
 */
    void addExistingFrom();
	
/**
 * \brief		Slot qui supprime un editeur 
 */
    void removeEditor(int i);

private slots :
    void activerSave(QString str="");
};

#endif // DOCUMENTEDITEUR_H
