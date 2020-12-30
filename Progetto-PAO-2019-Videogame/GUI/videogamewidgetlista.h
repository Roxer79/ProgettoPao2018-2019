#ifndef VIDEOGAMEWIDGETLISTA_H
#define VIDEOGAMEWIDGETLISTA_H

#include "GUI/videogameoggettilista.h"

#include <QListWidget>
#include <QPushButton>
#include <QScrollBar>

class VideogameWidgetLista: public QListWidget {
    Q_OBJECT
private:
    QWidget* parent;
    //QAction* primaAzione;
    //QAction* secondaAzione;
public:
    VideogameWidgetLista(QWidget* = nullptr);
    void aggiungiVideogioco(Videogame*);
    VideogameOggettiLista* currentItem() const;
};

#endif // VIDEOGAMEWIDGETLISTA_H
