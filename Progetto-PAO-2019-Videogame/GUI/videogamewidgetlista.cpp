#include "GUI/videogamewidgetlista.h"

VideogameWidgetLista::VideogameWidgetLista(QWidget* p): parent(p) {

    setIconSize(QSize(150,150));
    addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);

}

void VideogameWidgetLista::aggiungiVideogioco(Videogame* nuovoOggetto) {

    VideogameOggettiLista* inserisciNuovo = new VideogameOggettiLista(parent, nuovoOggetto);

    addItem(inserisciNuovo);
}

VideogameOggettiLista* VideogameWidgetLista::currentItem() const {
    return static_cast<VideogameOggettiLista*>(QListWidget::currentItem());
}
