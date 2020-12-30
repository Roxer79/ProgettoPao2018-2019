#include "GUI/popupdigitaldlc.h"

PopUpDigitalDlc::PopUpDigitalDlc(QWidget* parent, Dlc* ogg):
    contenitoreDigDlc(new QVBoxLayout),
    popUpVidDlc(new LayoutInserisciVideogame(parent)),
    popUpDigDlc(new LayoutInserisciDigital(parent)),
    popUpDlcDlc(new LayoutInserisciDlc(parent)),
    contieniLabelEBottone(new QHBoxLayout),
    aggiungiImmagine(new QLabel(parent)),
    icona(QString::fromStdString(ogg->getPercorsoImmagine())),
    bottoneModificaFoto(new QPushButton(parent)),
    contieniBottoniSmAm(new QHBoxLayout),
    bottoneSalvaModifiche(new QPushButton("Salva modifche", parent)),
    bottoneAnnullaModifiche(new QPushButton("Annulla modifiche", parent)) {

    setWindowTitle("Dlc");

    contenitoreDigDlc->addWidget(popUpVidDlc);
    popUpVidDlc->getTitVideogioco()->insert(QString::fromStdString(ogg->getTitoloVideogioco()));
    ogg->getDisponibile() ? popUpVidDlc->getDisponibil()->setCurrentIndex(1) : popUpVidDlc->getDisponibil()->setCurrentIndex(0);
    popUpVidDlc->getPrezBase()->insert(QString::fromStdString(std::to_string(ogg->getPrezzoBase())));
    popUpVidDlc->getQuantInStock()->insert(QString::fromStdString(std::to_string(ogg->getQuantitaInStock())));
    popUpVidDlc->getCasProduttice()->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    popUpVidDlc->getAnnoPubl()->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    popUpVidDlc->getPeg()->insert(QString::fromStdString(std::to_string(ogg->getPegi())));
    popUpVidDlc->getGenGioco()->insert(QString::fromStdString(ogg->getGenereGioco()));
    popUpVidDlc->getTipoDiPiatta()->insert(QString::fromStdString(ogg->getTipoDiPiattaforma()));
    ogg->getApplicaSconto() ? popUpVidDlc->getAppliSconto()->setCurrentIndex(1) : popUpVidDlc->getAppliSconto()->setCurrentIndex(0);

    contenitoreDigDlc->addWidget(popUpDigDlc);
    popUpDigDlc->getPiattaRiscattoCodice()->insert(QString::fromStdString(ogg->getPiattaformaRiscattoCodice()));
    popUpDigDlc->getCodiceAlfaNum()->insert(QString::fromStdString(ogg->getCodiceAlfanumerico()));
    popUpDigDlc->getDescrizioneDigi()->insert(QString::fromStdString(ogg->getDescrizioneDigital()));

    contenitoreDigDlc->addWidget(popUpDlcDlc);
    popUpDlcDlc->getNomDlc()->insert(QString::fromStdString(ogg->getNomeDlc()));
    popUpDlcDlc->getScontoDlcAnnual()->insert(QString::fromStdString(std::to_string(ogg->getScontoDlc())));

    contenitoreDigDlc->addLayout(contieniLabelEBottone);
    contieniLabelEBottone->addWidget(aggiungiImmagine);
    aggiungiImmagine->setText(QString("Aggiungi immagine: "));
    contieniLabelEBottone->addWidget(bottoneModificaFoto);
    bottoneModificaFoto->setIcon(icona);
    bottoneModificaFoto->setFixedSize(300, 200);
    bottoneModificaFoto->setIconSize(QSize(250, 190));
    //bottoneModificaFoto->setText(QString("Aggiungi immagine"));
    contieniLabelEBottone->setMargin(10);

    contenitoreDigDlc->addLayout(contieniBottoniSmAm);
    contieniBottoniSmAm->addWidget(bottoneSalvaModifiche);
    contieniBottoniSmAm->addWidget(bottoneAnnullaModifiche);

    setLayout(contenitoreDigDlc);

    setMinimumSize(400, 700);
}

QPushButton* PopUpDigitalDlc::getBottoneModificaFoto() const { return  bottoneModificaFoto; }

QPushButton* PopUpDigitalDlc::getBottoneSalvaModifiche() const { return bottoneSalvaModifiche; }

QPushButton* PopUpDigitalDlc::getBottoneAnnullaModifiche() const { return bottoneAnnullaModifiche; }
