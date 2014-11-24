/**
 * \file	Audio.h
 * \author	Félix, Victor
 * \version	1.0
 * \date	15 Juin 2013
 * \brief	Notes audio, herite de note
 */

#ifndef AUDIO_H
#define AUDIO_H

#include "note.h"

/**
* \class Audio Audio.h
*/
class Audio: public Note {
    friend class NotesManager;

    QString aud;
	
/**
 * \brief		Constructeur de note audio par recopie
 * \param		a		Note a recopier
 */
    Audio(const Audio& a): Note(a.title,a.filename,"aud",a.notePath,a.id), aud(a.aud){}
	
/**
 * \brief		Surcharge de l'operateur = , fonction privee pr empecher l'utilisation du =
 */
    Audio& operator=(const Audio&);
public:

/**
 * \brief		Constructeur de note audio
 * \param		f		nom du fichier associe à la note audio
 * \param		ti		titre de la note
 * \param		pa		chemin d'acces au fichier audio
 * \param		p		chemin d'accès au fichier de la note
 * \param		i		id de la note
 */
    Audio(const QString& f, const QString& ti, const QString& p, unsigned int i, const QString& pa=(QString)""):Note(ti,f,"aud",p,i),aud(pa){}
    const QString& getAud() const { return aud;}
	
/**
 * \brief		Mutateur de l'attribut aud
 * \param		p		chemin d'acces a lelement audio
 */	
    void setAud(const QString& p){aud=p; setModified();}
	
/**
 * \brief		Fonction de chargement d'une note audio depuis un fichier
 * \param		path chemin d'acces au fichier
 */	
    void load(QString& path);
	
/**
 * \brief		Fonction de sauvegarde d'une note audio dans un fichier
 */
    void save();
    void setModified(){modified=true;}


/**
 * \brief		Fonction virtuelle pure qui gérera l'export des notes au format texte
 */
    QString exportText();
	
/**
 * \brief		Fonction virtuelle qui gérera l'export des notes au format html
 * \param		appartenanceDoc		0 si la note n'appartient pas à un document, 1 sinon, 0 par défaut
 */
    QString exportHtml(bool appartenanceDoc=0);
	
/**
 * \brief		Fonction virtuelle qui gérera l'export des notes au format latex
 * \param		appartenanceDoc		0 si la note n'appartient pas à un document, 1 sinon, 0 par défaut
 */
   QString exportLatex(bool appartenanceDoc=0);

/**
 * \brief		Fonction qui sauve dans un fichier l'export au format texte
 */

};


#endif // AUDIO_H
