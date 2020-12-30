#include "GUI/popupcollectorsedition.h"

PopUpCollEdition::PopUpCollEdition(QWidget* parent, CollectorEdition* ogg):
    contenitoreColEdit(new QVBoxLayout),
    popUpVidCol(new LayoutInserisciVideogame(parent)),
    popUpPhyCol(new LayoutInserisciPhysical(parent)),
    popUpColCol(new LayoutInserisciCollectorsEdition(parent)),
    contieniLabelEBottone(new QHBoxLayout),
    aggiungiImmagine(new QLabel(parent)),
    icona(QString::fromStdString(ogg->getPercorsoImmagine())),
    bottoneModificaFoto(new QPushButton(parent)),
    contieniBottoniSmAm(new QHBoxLayout),
    bottoneSalvaModifiche(new QPushButton("Salva modifiche", parent)),
    bottoneAnnullaModifiche(new QPushButton("Annulla modifiche", parent)) {

    //setWindowTitle("Collector's edition");

    contenitoreColEdit->addWidget(popUpVidCol);
    popUpVidCol->getTitVideogioco()->insert(QString::fromStdString(ogg->getTitoloVideogioco()));
    ogg->getDisponibile() ? popUpVidCol->getDisponibil()->setCurrentIndex(1) : popUpVidCol->getDisponibil()->setCurrentIndex(0);
    popUpVidCol->getPrezBase()->insert(QString::fromStdString(std::to_string(ogg->getPrezzoBase())));
    popUpVidCol->getQuantInStock()->insert(QString::fromStdString(std::to_string(ogg->getQuantitaInStock())));
    popUpVidCol->getCasProduttice()->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    popUpVidCol->getAnnoPubl()->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    popUpVidCol->getPeg()->insert(QString::fromStdString(std::to_string(ogg->getPegi())));
    popUpVidCol->getGenGioco()->insert(QString::fromStdString(ogg->getGenereGioco()));
    popUpVidCol->getTipoDiPiatta()->insert(QString::fromStdString(ogg->getTipoDiPiattaforma()));
    ogg->getApplicaSconto() ? popUpVidCol->getAppliSconto()->setCurrentIndex(1) : popUpVidCol->getAppliSconto()->setCurrentIndex(0);

    contenitoreColEdit->addWidget(popUpPhyCol);
    popUpPhyCol->getBarCod()->insert(QString::fromStdString(std::to_string(ogg->getBarCode())));
    popUpPhyCol->getDescrizioneEti()->insert(QString::fromStdString(ogg->getDescrizioneEtichetta()));

    contenitoreColEdit->addWidget(popUpColCol);
    ogg->getActionFigure() ? popUpColCol->getActionFig()->setCurrentIndex(1) : popUpColCol->getActionFig()->setCurrentIndex(0);
    popUpColCol->getSovraPrezzoActionFig()->insert(QString::fromStdString(std::to_string(ogg->getSovraPrezzoActionFigure())));
    popUpColCol->getScontoCollEdit()->insert(QString::fromStdString(std::to_string(ogg->getScontoCollectorEditionAnnuale())));

    contenitoreColEdit->addLayout(contieniLabelEBottone);
    contieniLabelEBottone->addWidget(aggiungiImmagine);
    aggiungiImmagine->setText(QString("Aggiungi immagine: "));
    contieniLabelEBottone->addWidget(bottoneModificaFoto);
    bottoneModificaFoto->setIcon(icona);
    bottoneModificaFoto->setFixedSize(300, 200);
    bottoneModificaFoto->setIconSize(QSize(250, 190));
    //bottoneModificaFoto->setText(QString("Aggiungi immagine"));
    contieniLabelEBottone->setMargin(10);

    contenitoreColEdit->addLayout(contieniBottoniSmAm);
    contieniBottoniSmAm->addWidget(bottoneSalvaModifiche);
    contieniBottoniSmAm->addWidget(bottoneAnnullaModifiche);

    setLayout(contenitoreColEdit);

    setMinimumSize(400, 700);

    //contenitoreColEdit->insertStretch(2,1)
}

QPushButton* PopUpCollEdition::getBottoneModificaFoto() const { return bottoneModificaFoto; }

QPushButton* PopUpCollEdition::getBottoneSalvaModifiche() const { return bottoneSalvaModifiche; }

QPushButton* PopUpCollEdition::getBottoneAnnullaModifiche() const { return bottoneAnnullaModifiche; }
