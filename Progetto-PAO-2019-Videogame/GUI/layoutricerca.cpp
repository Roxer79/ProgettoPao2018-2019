#include "GUI/layoutricerca.h"
#include "GUI/controller.h"

LayoutRicerca::LayoutRicerca(QWidget* p): parent(p),
    conTutto(new QVBoxLayout(this)),
    contieniRicerca(new QFormLayout),
    conButRicerca(new QHBoxLayout),
    conButRimMod(new QHBoxLayout),
    barraRicerca(new QLineEdit(this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    botRimuovi(new QPushButton("Rimuovi", this)),
    bottoneRicerca(new QPushButton("Cerca", this)),
    bottoneAnnullaRicerca(new QPushButton("Annulla ricerca", this)),
    casellaLista(new VideogameWidgetLista(this)),
    sizeBtn(QSize(300, 40)) {

    conTutto->addLayout(contieniRicerca);
    contieniRicerca->addRow("Ricerca: ", barraRicerca);
    barraRicerca->setPlaceholderText("Inserire testo ricerca");

    conButRicerca->addWidget(bottoneRicerca);
    bottoneRicerca->setFixedSize(sizeBtn);
    bottoneRicerca->setStyleSheet("font: bold; font-size: 20px;");
    conTutto->addLayout(conButRicerca);
    conButRicerca->addWidget(bottoneAnnullaRicerca);
    bottoneAnnullaRicerca->setFixedSize(sizeBtn);
    bottoneAnnullaRicerca->setStyleSheet("font: bold; font-size: 20px;");

    conTutto->addWidget(casellaLista);
    casellaLista->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    casellaLista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    conTutto->addLayout(conButRimMod);

    conButRimMod->addWidget(bottoneModifica);
    bottoneModifica->setEnabled(false);
    bottoneModifica->setFixedSize(sizeBtn);
    bottoneModifica->setStyleSheet("font: bold; font-size: 20px;");
    conButRimMod->addWidget(botRimuovi);
    botRimuovi->setEnabled(false);
    botRimuovi->setFixedSize(sizeBtn);
    botRimuovi->setStyleSheet("font: bold; font-size: 20px;");

    connect(casellaLista, SIGNAL(itemSelectionChanged()), this, SLOT(elementoSelezionatoDallaLista()));
    connect(bottoneAnnullaRicerca, SIGNAL(clicked()), this, SLOT(annullaRicerca()));
}

QLineEdit* LayoutRicerca::getBarraRicerca() const { return barraRicerca; }

QPushButton* LayoutRicerca::getBottoneModifica() const { return bottoneModifica; }

QPushButton* LayoutRicerca::getBotRimuovi() const { return botRimuovi; }

QPushButton* LayoutRicerca::getBottoneRicerca() const { return bottoneRicerca; }

QPushButton* LayoutRicerca::getBottoneAnnullaRicerca() const { return bottoneAnnullaRicerca; }

VideogameWidgetLista* LayoutRicerca::getCasellaLista() const { return casellaLista; }

void LayoutRicerca::disabilitaTutto() const {
    barraRicerca->deselect();
    barraRicerca->clear();
    barraRicerca->setEnabled(false);

    casellaLista->clear();
    casellaLista->setEnabled(false);

    bottoneRicerca->setEnabled(false);
    bottoneAnnullaRicerca->setEnabled(false);
    bottoneModifica->setEnabled(false);
    botRimuovi->setEnabled(false);
}

void LayoutRicerca::abilitaTutto() const {
    barraRicerca->deselect();
    barraRicerca->clear();
    barraRicerca->setEnabled(true);

    casellaLista->clear();
    casellaLista->setEnabled(true);

    bottoneRicerca->setEnabled(true);
    bottoneAnnullaRicerca->setEnabled(true);
    //bottoneModifica->setEnabled(true);
    //botRimuovi->setEnabled(true);
}

void LayoutRicerca::annullaRicerca() const {
    barraRicerca->deselect();
    barraRicerca->clear();

    casellaLista->clear();

    bottoneModifica->setEnabled(false);
    botRimuovi->setEnabled(false);
}

void LayoutRicerca::elementoSelezionatoDallaLista() const {
    bottoneModifica->setEnabled(true);
    botRimuovi->setEnabled(true);
}

/*void LayoutRicerca::attivaDopoAverInseritoTesto() const { //prova da rivedere
    bottoneRicerca->setEnabled(true);
    bottoneAnnullaRicerca->setEnabled(false);
    //casellaLista->addItem(barraRicerca->text());
    //barraRicerca->clear();
    //abilitaTutto();
}

void LayoutRicerca::rimuoviDallaRicerca() const { //prova
    qDeleteAll(casellaLista->selectedItems());
}*/
