/**
 * \file	document.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	gestion de notes de type document
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "note.h"
#include "NoteFactory.h"
#include "NotesManager.h"


#include <QList>
/**
* \class Document document.h
*/
class Document : public Note {

    friend class NotesManager;
    QList <Note*> notes;

    Document(const Document& d) //elle ne marche pas si on le définie dans le .cpp 0_o
    {
        Document(d.title,d.filename, d.notePath, d.id);
        for(int i=0; i<d.notes.size(); i++) notes[i]=d.notes[i];
    }

    Document& operator=(const Document& m);
public:
/**
 * \brief		Constructeur de document
 * \param		f		nom du fichier
 * \param		t		titre de l'article
 * \param		p		chemin d'accès au fichier
 * \param		i		id de l'article
 */
    Document(const QString& t, const QString& f, const QString& p, unsigned int i): Note(t,f,"doc",p,i){}
    ~Document() { notes.clear(); }
    Document&  operator<<(Note* a);
    Note* getNote(unsigned int i);
    const Note* getNote(unsigned int i) const;

	/**
 * \brief		Fonction qui ajoute une note au document
 * \param		n		note a ajouter
 */
    void addNote(Note* n);
    Note* getNoteByPos(int pos){ return notes[pos]; }
    unsigned int getPosNote(Note* note) const;
	
/**
 * \brief		Fonction qui supprimer une note du document
 * \param		i		position de la note dans le tableau de notes du document
 */
    void removeNote(unsigned int i);
	
/**
 * \brief		Fonction qui remonte une note dans le tableau de notes
 * \param		i		position de la note dans le tableau de notes du document
 */
    void moveNoteUp(unsigned int i);
	
/**
 * \brief		Fonction qui descend une note dans le tableau de notes
 * \param		i		position de la note dans le tableau de notes du document
 */
    void moveNoteDown(unsigned int i);
	
/**
 * \brief		Fonction qui lit un fichier pour recuperer les valeurs d'attributs a attribuer a l'instance courante
 * \param		path	chemin d'accès du fichier a lire
 */
    void load(QString& path);
	
/**
 * \brief		Fonction qui sauve l'article dans un fichier
 */
    void save();
	
    unsigned int getSize(){ return notes.size(); }

	/**
 * \brief		Fonction qui exporte un article au format texte
 * \return		Un QString correspondant au contenu de l'article
 */
    QString exportText();
	
/**
 * \brief		Fonction qui exporte un article au format html
 * \param		appartenanceDoc		booléen a zero si l'article n'appartient pas a un document, 1 sinon
 * \return		Un QString correspondant au html
 */
    QString exportHtml(bool appartenanceDoc=0);
	
/**
 * \brief		Fonction qui exporte un article au format latex
 * \param		appartenanceDoc		booléen a zero si l'article n'appartient pas a un document, 1 sinon
 * \return		Un QString correspondant au latex
 */
    QString exportLatex(bool appartenanceDoc=0);
};

#endif // DOCUMENT_H
