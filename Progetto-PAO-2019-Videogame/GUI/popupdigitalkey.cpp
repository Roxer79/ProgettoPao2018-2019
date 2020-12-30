#include "GUI/popupdigitalkey.h"

PopUpDigitalKey::PopUpDigitalKey(QWidget* p): parent(p),
    contenitoreDigKey(new QVBoxLayout(this)),
    popUpVidKey(new LayoutInserisciVideogame(parent)),
    popUpDigKey(new LayoutInserisciDigital(parent)),
    popUpKeyKey(new LayoutInserisciKey(parent)),
    contieniLabelEBottone(new QHBoxLayout),
    aggiungiImmagine(new QLabel(parent)),
    //icona(QString::fromStdString(ogg->getPercorsoImmagine())),
    bottoneModificaFoto(new QPushButton(parent)),
    contieniBottoniSmAm(new QHBoxLayout),
    bottoneSalvaModifiche(new QPushButton("Salva modifche", parent)),
    bottoneAnnullaModifiche(new QPushButton("Annulla modifiche", parent)) {

    //setWindowTitle("Key");

    contenitoreDigKey->addWidget(popUpVidKey);
    //popUpVidKey->getTitVideogioco()->insert(QString::fromStdString(ogg->getTitoloVideogioco()));
    //ogg->getDisponibile() ? popUpVidKey->getDisponibil()->setCurrentIndex(1) : popUpVidKey->getDisponibil()->setCurrentIndex(0);
    ////double perQDouble = ogg->getPrezzoBase();
    ////QDoubleValidator* prezzo = new QDoubleValidator(0.00, perQDouble, 2);
    ////prezzo->setNotation(QDoubleValidator::StandardNotation);
    ////popUpVidKey->getPrezBase()->insert(QString::fromStdString(std::to_string(prezzo->top())));
    //popUpVidKey->getPrezBase()->insert(QString::fromStdString(std::to_string(ogg->getPrezzoBase())));
    ////double prezzo = ogg->getPrezzoBase();
    ////std::string prezzo1 = std::to_string(prezzo);
    ////popUpVidKey->getPrezBase()->insert(QString::fromStdString(prezzo1));
    //popUpVidKey->getQuantInStock()->insert(QString::fromStdString(std::to_string(ogg->getQunatitaInStock())));
    //popUpVidKey->getCasProduttice()->insert(QString::fromStdString(ogg->getCasaProduttrice()));
    //popUpVidKey->getAnnoPubl()->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
    //popUpVidKey->getPeg()->insert(QString::fromStdString(std::to_string(ogg->getPegi())));
    //popUpVidKey->getGenGioco()->insert(QString::fromStdString(ogg->getGenereGioco()));
    //popUpVidKey->getTipoDiPiatta()->insert(QString::fromStdString(ogg->getTipoDiPiattaforma()));
    //ogg->getApplicaSconto() ? popUpVidKey->getAppliSconto()->setCurrentIndex(1) : popUpVidKey->getAppliSconto()->setCurrentIndex(0);

    contenitoreDigKey->addWidget(popUpDigKey);
    //popUpDigKey->getPiattaRiscattoCodice()->insert(QString::fromStdString(ogg->getPiattaformaRiscattoCodice()));
    //popUpDigKey->getCodiceAlfaNum()->insert(QString::fromStdString(ogg->getCodiceAlfanumerico()));
    //popUpDigKey->getDescrizioneDigi()->insert(QString::fromStdString(ogg->getDescrizioneDigital()));

    contenitoreDigKey->addWidget(popUpKeyKey);
    //popUpKeyKey->getScontoKeyAnnual()->insert(QString::fromStdString(std::to_string(ogg->getScontoKeyAnnuale())));

    contenitoreDigKey->addLayout(contieniLabelEBottone);
    contieniLabelEBottone->addWidget(aggiungiImmagine);
    aggiungiImmagine->setText(QString("Aggiungi immagine: "));
    contieniLabelEBottone->addWidget(bottoneModificaFoto);
    //bottoneModificaFoto->setIcon(icona);
    bottoneModificaFoto->setFixedSize(300, 200);
    //bottoneModificaFoto->setIconSize(QSize(250, 190));
    //bottoneModificaFoto->setText(QString("Aggiungi immagine"));
    contieniLabelEBottone->setMargin(10);

    contenitoreDigKey->addLayout(contieniBottoniSmAm);
    contieniBottoniSmAm->addWidget(bottoneSalvaModifiche);
    contieniBottoniSmAm->addWidget(bottoneAnnullaModifiche);

    setLayout(contenitoreDigKey);

    setMinimumSize(400, 700);

}

LayoutInserisciVideogame* PopUpDigitalKey::getLayoutInserisciVideogame() const { return popUpVidKey; }

QPushButton* PopUpDigitalKey::getBottoneModificaFoto() const { return bottoneModificaFoto; }

QPushButton* PopUpDigitalKey::getBottoneSalvaModifiche() const { return bottoneSalvaModifiche; }

QPushButton* PopUpDigitalKey::getBottoneAnnullaModifiche() const { return bottoneAnnullaModifiche; }
