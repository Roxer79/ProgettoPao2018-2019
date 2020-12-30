#include "GUI/popupgioconuovo.h"

PopUpGiocoNuovo::PopUpGiocoNuovo(QWidget* parent, Game* ogg):
    contenitoreGioNuo(new QVBoxLayout),
    popUpVidNuo(new LayoutInserisciVideogame(parent)),
    popUpPhyNuo(new LayoutInserisciPhysical(parent)),
    popUpGinNuo(new LayoutInserisciGiocoNuovo(parent)),
    contieniLabelEBottone(new QHBoxLayout),
    aggiungiImmagine(new QLabel(parent)),
    icona(QString::fromStdString(ogg->getPercorsoImmagine())),
    bottoneModificaFoto(new QPushButton(parent)),
    contieniBottoniSmAm(new QHBoxLayout),
    bottoneSalvaModifiche(new QPushButton("Salva modifiche", parent)),
    bottoneAnnullaModifiche(new QPushButton("Annualla modifiche", parent)) {

    setWindowTitle("Gioco nuovo");

    contenitoreGioNuo->addWidget(popUpVidNuo);
    popUpVidNuo->getTitVideogioco()->insert(QString::fromStdString(ogg->getTitoloVideogioco()));
    ogg->getDisponibile() ? popUpVidNuo->getDisponibil()->setCurrentIndex(1) : popUpVidNuo->getDisponibil()->setCurrentIndex(0);
    popUpVidNuo->getPrezBase()->insert(QString::fromStdString(std::to_string(ogg->getPrezzoBase())));
    popUpVidNuo->getQuantInStock()->insert(QString::fromStdString(std::to_string(ogg->getQuantitaInStock())));
    popUpVidNuo->getCasProduttice()->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    popUpVidNuo->getAnnoPubl()->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    popUpVidNuo->getPeg()->insert(QString::fromStdString(std::to_string(ogg->getPegi())));
    popUpVidNuo->getGenGioco()->insert(QString::fromStdString(ogg->getGenereGioco()));
    popUpVidNuo->getTipoDiPiatta()->insert(QString::fromStdString(ogg->getTipoDiPiattaforma()));
    ogg->getApplicaSconto() ? popUpVidNuo->getAppliSconto()->setCurrentIndex(1) : popUpVidNuo->getAppliSconto()->setCurrentIndex(0);

    contenitoreGioNuo->addWidget(popUpPhyNuo);
    popUpPhyNuo->getBarCod()->insert(QString::fromStdString(std::to_string(ogg->getBarCode())));
    popUpPhyNuo->getDescrizioneEti()->insert(QString::fromStdString(ogg->getDescrizioneEtichetta()));

    contenitoreGioNuo->addWidget(popUpGinNuo);
    ogg->getEdizioneLimitata() ? popUpGinNuo->getEdizioneLim()->setCurrentIndex(1) : popUpGinNuo->getEdizioneLim()->setCurrentIndex(0);
    popUpGinNuo->getSovraPrezzoEdizioneLim()->insert(QString::fromStdString(std::to_string(ogg->getSovraPrezzoEdizioneLimitata())));
    popUpGinNuo->getScontoAnnualGam()->insert(QString::fromStdString(std::to_string(ogg->getScontoGameAnnuale())));

    contenitoreGioNuo->addLayout(contieniLabelEBottone);
    contieniLabelEBottone->addWidget(aggiungiImmagine);
    aggiungiImmagine->setText(QString("Aggiungi immagine: "));
    contieniLabelEBottone->addWidget(bottoneModificaFoto);
    bottoneModificaFoto->setIcon(icona);
    bottoneModificaFoto->setFixedSize(300, 200);
    bottoneModificaFoto->setIconSize(QSize(250, 190));
    //bottoneModificaFoto->setText(QString("Aggiungi immagine"));
    contieniLabelEBottone->setMargin(10);

    contenitoreGioNuo->addLayout(contieniBottoniSmAm);
    contieniBottoniSmAm->addWidget(bottoneSalvaModifiche);
    contieniBottoniSmAm->addWidget(bottoneAnnullaModifiche);

    setLayout(contenitoreGioNuo);

    setMinimumSize(400, 700);
}

QPushButton* PopUpGiocoNuovo::getBottoneModificaFoto() const { return bottoneModificaFoto; }

QPushButton* PopUpGiocoNuovo::getBottoneSalvaModifiche() const { return bottoneSalvaModifiche; }

QPushButton* PopUpGiocoNuovo::getBottoneAnnullaModifiche() const { return bottoneAnnullaModifiche; }
