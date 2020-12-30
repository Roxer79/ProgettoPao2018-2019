#include "GUI/popupgiocousato.h"

PopUpGiocoUsato::PopUpGiocoUsato(QWidget* parent, SecondHand* ogg):
    contenitoreGioUsa(new QVBoxLayout),
    popUpVidUsa(new LayoutInserisciVideogame(parent)),
    popUpPhyUsa(new LayoutInserisciPhysical(parent)),
    popUpUsaUsa(new LayoutInserisciGiocoUsato(parent)),
    contieniLabelEBottone(new QHBoxLayout),
    aggiungiImmagine(new QLabel(parent)),
    icona(QString::fromStdString(ogg->getPercorsoImmagine())),
    bottoneModificaFoto(new QPushButton(parent)),
    contieniBottoniSmAm(new QHBoxLayout),
    bottoneSalvaModifiche(new QPushButton("Salva modifiche", parent)),
    bottoneAnnuallaModiche(new QPushButton("Annulla modifiche", parent)) {

    setWindowTitle("Gioco usato");

    contenitoreGioUsa->addWidget(popUpVidUsa);
    popUpVidUsa->getTitVideogioco()->insert(QString::fromStdString(ogg->getTitoloVideogioco()));
    ogg->getDisponibile() ? popUpVidUsa->getDisponibil()->setCurrentIndex(1) : popUpVidUsa->getDisponibil()->setCurrentIndex(0);
    popUpVidUsa->getPrezBase()->insert(QString::fromStdString(std::to_string(ogg->getPrezzoBase())));
    popUpVidUsa->getQuantInStock()->insert(QString::fromStdString(std::to_string(ogg->getQuantitaInStock())));
    popUpVidUsa->getCasProduttice()->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    popUpVidUsa->getAnnoPubl()->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    popUpVidUsa->getPeg()->insert(QString::fromStdString(std::to_string(ogg->getPegi())));
    popUpVidUsa->getGenGioco()->insert(QString::fromStdString(ogg->getGenereGioco()));
    popUpVidUsa->getTipoDiPiatta()->insert(QString::fromStdString(ogg->getTipoDiPiattaforma()));
    ogg->getApplicaSconto() ? popUpVidUsa->getAppliSconto()->setCurrentIndex(1) : popUpVidUsa->getAppliSconto()->setCurrentIndex(0);

    contenitoreGioUsa->addWidget(popUpPhyUsa);
    popUpPhyUsa->getBarCod()->insert(QString::fromStdString(std::to_string(ogg->getBarCode())));
    popUpPhyUsa->getDescrizioneEti()->insert(QString::fromStdString(ogg->getDescrizioneEtichetta()));

    contenitoreGioUsa->addWidget(popUpUsaUsa);
    ogg->getScatolaIntegra() ? popUpUsaUsa->getScatolaInteg()->setCurrentIndex(1) : popUpUsaUsa->getScatolaInteg()->setCurrentIndex(0);
    popUpUsaUsa->getSovraPrezzoScatolaInt()->insert(QString::fromStdString(std::to_string(ogg->getSovraPrezzoSCatolaIntegra())));
    popUpUsaUsa->getScontoAnnualSH()->insert(QString::fromStdString(std::to_string(ogg->getScontoSecondHandAnnuale())));

    contenitoreGioUsa->addLayout(contieniLabelEBottone);
    contieniLabelEBottone->addWidget(aggiungiImmagine);
    aggiungiImmagine->setText(QString("Aggiungi immagine: "));
    contieniLabelEBottone->addWidget(bottoneModificaFoto);
    bottoneModificaFoto->setIcon(icona);
    bottoneModificaFoto->setFixedSize(300, 200);
    bottoneModificaFoto->setIconSize(QSize(250, 190));
    //bottoneModificaFoto->setText(QString("Aggiungi immagine"));
    contieniLabelEBottone->setMargin(10);

    contenitoreGioUsa->addLayout(contieniBottoniSmAm);
    contieniBottoniSmAm->addWidget(bottoneSalvaModifiche);
    contieniBottoniSmAm->addWidget(bottoneAnnuallaModiche);

    setLayout(contenitoreGioUsa);

    setMinimumSize(400, 700);
}

QPushButton* PopUpGiocoUsato::getBottoneModificaFoto() const { return bottoneModificaFoto; }

QPushButton* PopUpGiocoUsato::getBottoneSalvaModifiche() const { return bottoneSalvaModifiche; }

QPushButton* PopUpGiocoUsato::getBottoneAnnullaModifiche() const { return bottoneAnnuallaModiche; }
