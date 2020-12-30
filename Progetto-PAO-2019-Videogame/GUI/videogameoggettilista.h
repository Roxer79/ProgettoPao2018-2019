#ifndef VIDEOGAMEOGGETTILISTA_H
#define VIDEOGAMEOGGETTILISTA_H

#include "Gerarchia/gerarchiavideogame.h"

#include <QListWidgetItem>

class VideogameOggettiLista: public QListWidgetItem {
private:
    QWidget* parent;
    Videogame* oggetti;
public:
    VideogameOggettiLista(QWidget* = nullptr, Videogame* = nullptr);
    Videogame* getOggettoPunt() const;
    void aggiornaOggetto();
};

#endif // VIDEOGAMEOGGETTILISTA_H
