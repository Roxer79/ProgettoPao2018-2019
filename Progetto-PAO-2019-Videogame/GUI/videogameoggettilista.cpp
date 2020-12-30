#include "GUI/videogameoggettilista.h"

VideogameOggettiLista::VideogameOggettiLista(QWidget* p, Videogame* v): parent(p),
    oggetti(v) { aggiornaOggetto(); }

Videogame* VideogameOggettiLista::getOggettoPunt() const { return oggetti; }

void VideogameOggettiLista::aggiornaOggetto() {

    QString percorsoImmagine = QString::fromStdString(oggetti->getPercorsoImmagine());
    QPixmap immagine(percorsoImmagine);
    setIcon(immagine.scaled(500, 600, Qt::AspectRatioMode::KeepAspectRatio));

    setText(QString::fromStdString(oggetti->getInfoOggetto()));
}
