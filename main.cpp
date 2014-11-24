#include <QApplication>
#include "Fenetre.h"
#include "TagEditeur.h"
#include "Corbeille.h"
#include "Image.h"
#include "ImageEditeur.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Fenetre fen;
    fen.show();
    return app.exec();
}

