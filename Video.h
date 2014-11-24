#ifndef VIDEO_H
#define VIDEO_H

#include "note.h"

class Video: public Note {
    friend class NotesManager;
    QString vid;
    Video(const Video& v): Note(v.title,v.filename,"vid",v.vid,v.id),vid(v.vid){}
    Video& operator=(const Video&);
public:
    Video(const QString& f, const QString& ti, const QString& p, unsigned int i, const QString& pa=(QString)""):Note(ti,f,"vid",p,i),vid(pa){}
    const QString& getVid() const { return vid;}
    void setVid(const QString& p){vid=p; setModified();}
    void load(QString& vid);
    void save();
    void setModified(){modified=true;}


    QString exportText();
    QString exportHtml(bool appartenanceDoc=0);
    QString exportLatex(bool appartenanceDoc=0);

};


#endif // VIDEO_H
