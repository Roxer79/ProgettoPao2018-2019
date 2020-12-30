#include "GUI/layoutricercaperoggetti.h"

LayoutRicercaPerOggetti::LayoutRicercaPerOggetti(QWidget* p): parent(p),
    contieTutto(new QVBoxLayout(this)),
    contieniCampiRicerca(new QFormLayout),
    contieniAnnullaCerca(new QHBoxLayout),
    contieniModCanc(new QHBoxLayout),
    sceltaDerivateRic(new QComboBox(this)),
    lineTitoloVideogioco(new QLineEdit(this)),
    lineCasaProduttrice(new QLineEdit(this)),
    lineAnnoPubblicazione(new QLineEdit(this)),
    lineGenereGioco(new QLineEdit(this)),
    bottonAnnullaRic(new QPushButton("Annulla ricerca", this)),
    bottoneCercaOgg(new QPushButton("Cerca", this)),
    listaRicOgg(new VideogameWidgetLista(this)),
    bottoneModificaOggRic(new QPushButton("Modifica", this)),
    bottoneEliminaOggRic(new QPushButton("Rimuovi", this)),
    sizeconstBtn(QSize(300, 40)) {

    contieTutto->addWidget(sceltaDerivateRic);
    sceltaDerivateRic->addItem("Selezionare tipo di prodotto");
    sceltaDerivateRic->addItem("Key");
    sceltaDerivateRic->addItem("Dlc");
    sceltaDerivateRic->addItem("Collector's edition");
    sceltaDerivateRic->addItem("Gioco nuovo");
    sceltaDerivateRic->addItem("Gioco usato");

    contieTutto->addLayout(contieniCampiRicerca);
    contieniCampiRicerca->addRow("Titolo videogame: ", lineTitoloVideogioco);
    lineTitoloVideogioco->setEnabled(false);
    lineTitoloVideogioco->setPlaceholderText("Inserire titolo videogioco");
    contieniCampiRicerca->addRow("Casa produttrice: ", lineCasaProduttrice);
    lineCasaProduttrice->setEnabled(false);
    lineCasaProduttrice->setPlaceholderText("Inserire casa produttrice");
    contieniCampiRicerca->addRow("Anno pubblicazione: ", lineAnnoPubblicazione);
    lineAnnoPubblicazione->setEnabled(false);
    lineAnnoPubblicazione->setPlaceholderText("Inserire anno di pubblicazione");
    lineAnnoPubblicazione->setValidator(new QIntValidator(1970, 9999, this));
    contieniCampiRicerca->addRow("Genere gioco: ", lineGenereGioco);
    lineGenereGioco->setEnabled(false);
    lineGenereGioco->setPlaceholderText("Inserire genere gioco");

    contieTutto->addLayout(contieniAnnullaCerca);
    contieniAnnullaCerca->addWidget(bottoneCercaOgg);
    bottoneCercaOgg->setEnabled(false);
    bottoneCercaOgg->setFixedSize(sizeconstBtn);
    bottoneCercaOgg->setStyleSheet("font: bold; font-size: 20px;");
    contieniAnnullaCerca->addWidget(bottonAnnullaRic);
    bottonAnnullaRic->setEnabled(false);
    bottonAnnullaRic->setFixedSize(sizeconstBtn);
    bottonAnnullaRic->setStyleSheet("font: bold; font-size: 20px;");

    contieTutto->addWidget(listaRicOgg);
    listaRicOgg->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    listaRicOgg->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    contieTutto->addLayout(contieniModCanc);
    contieniModCanc->addWidget(bottoneModificaOggRic);
    bottoneModificaOggRic->setEnabled(false);
    bottoneModificaOggRic->setFixedSize(sizeconstBtn);
    bottoneModificaOggRic->setStyleSheet("font: bold; font-size: 20px;");
    contieniModCanc->addWidget(bottoneEliminaOggRic);
    bottoneEliminaOggRic->setEnabled(false);
    bottoneEliminaOggRic->setFixedSize(sizeconstBtn);
    bottoneEliminaOggRic->setStyleSheet("font: bold; font-size: 20px;");

    //fare SIGNAL e SLOT
    connect(sceltaDerivateRic, SIGNAL(activated(int)), this, SLOT(disabilitaInBaseAlComboBox(int)));
    connect(bottonAnnullaRic, SIGNAL(clicked()), this, SLOT(disabilitaQLineEdit()));
    connect(listaRicOgg, SIGNAL(itemSelectionChanged()), this, SLOT(elementoSelezionatoDallaLista()));
}

QComboBox* LayoutRicercaPerOggetti::getSceltaDerivateRic() const { return sceltaDerivateRic; }

QLineEdit* LayoutRicercaPerOggetti::getLineTitoloVideogioco() const { return lineTitoloVideogioco; }

QLineEdit* LayoutRicercaPerOggetti::getLineCasaProduttrice() const { return lineCasaProduttrice; }

QLineEdit* LayoutRicercaPerOggetti::getLineAnnoPubblicazione() const { return lineAnnoPubblicazione; }

QLineEdit* LayoutRicercaPerOggetti::getLineGenereGioco() const { return lineGenereGioco; }

QPushButton* LayoutRicercaPerOggetti::getBottonAnnullaRic() const { return bottonAnnullaRic; }

QPushButton* LayoutRicercaPerOggetti::getBottoneCercaOgg() const { return bottoneCercaOgg; }

QPushButton* LayoutRicercaPerOggetti::getBottoneModificaOggRic() const { return  bottoneModificaOggRic; }

QPushButton* LayoutRicercaPerOggetti::getBottoneEliminaOggRic() const { return bottoneEliminaOggRic; }

VideogameWidgetLista* LayoutRicercaPerOggetti::getListaRicOgg() const { return listaRicOgg; }

void LayoutRicercaPerOggetti::abilitaQLineEdit() const {
    lineTitoloVideogioco->deselect();
    lineTitoloVideogioco->clear();
    lineTitoloVideogioco->setEnabled(true);
    lineCasaProduttrice->deselect();
    lineCasaProduttrice->clear();
    lineCasaProduttrice->setEnabled(true);
    lineAnnoPubblicazione->deselect();
    lineAnnoPubblicazione->clear();
    lineAnnoPubblicazione->setEnabled(true);
    lineGenereGioco->deselect();
    lineGenereGioco->clear();
    lineGenereGioco->setEnabled(true);

    bottonAnnullaRic->setEnabled(true);
    bottoneCercaOgg->setEnabled(true);
    listaRicOgg->clear();
    //bottoneModificaOggRic->setEnabled(true);
    //bottoneEliminaOggRic->setEnabled(true);
}

void LayoutRicercaPerOggetti::disabilitaInBaseAlComboBox(int index) const {
    switch(index) {
    case 0:
        disabilitaQLineEdit();
    break;

    case 1:
        abilitaQLineEdit();
    break;

    case 2:
        abilitaQLineEdit();
    break;

    case 3:
        abilitaQLineEdit();
    break;

    case 4:
        abilitaQLineEdit();
    break;

    case 5:
        abilitaQLineEdit();
    break;
    }
}

void LayoutRicercaPerOggetti::elementoSelezionatoDallaLista() const {
    bottoneModificaOggRic->setEnabled(true);
    bottoneEliminaOggRic->setEnabled(true);
}

void LayoutRicercaPerOggetti::disabilitaQLineEdit() const {
    sceltaDerivateRic->setCurrentIndex(0);
    lineTitoloVideogioco->deselect();
    lineTitoloVideogioco->clear();
    lineTitoloVideogioco->setEnabled(false);
    lineCasaProduttrice->deselect();
    lineCasaProduttrice->clear();
    lineCasaProduttrice->setEnabled(false);
    lineAnnoPubblicazione->deselect();
    lineAnnoPubblicazione->clear();
    lineAnnoPubblicazione->setEnabled(false);
    lineGenereGioco->deselect();
    lineGenereGioco->clear();
    lineGenereGioco->setEnabled(false);

    //bottonAnnullaRic->setChecked(false);
    bottonAnnullaRic->setEnabled(false);
    bottoneCercaOgg->setEnabled(false);
    listaRicOgg->clear();
    //bottoneModificaOggRic->setChecked(false);
    bottoneModificaOggRic->setEnabled(false);
    bottoneEliminaOggRic->setEnabled(false);
}
