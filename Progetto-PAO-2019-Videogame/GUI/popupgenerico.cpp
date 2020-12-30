#include "GUI/popupgenerico.h"

PopUpGenerico::PopUpGenerico(QWidget* p): parent(p),
    contenitorePopUp(new QVBoxLayout(this)),
    avvisoCampiObbligatori(new QLabel(p)),
    popUpVid(new LayoutInserisciVideogame(p)),
    popUpPhy(new LayoutInserisciPhysical(p)),
    popUpDig(new LayoutInserisciDigital(p)),
    popUpKey(new LayoutInserisciKey(p)),
    popUpDlc(new LayoutInserisciDlc(p)),
    popUpCol(new LayoutInserisciCollectorsEdition(p)),
    popUpNuo(new LayoutInserisciGiocoNuovo(p)),
    popUpUsa(new LayoutInserisciGiocoUsato(p)),
    contieniLabelEBottone(new QHBoxLayout),
    aggiungiDescrizione(new QLabel(p)),
    bottoneModificaFoto(new QPushButton(p)),
    contieniBottoniSmAm(new QHBoxLayout),
    bottoneSalvaModifiche(new QPushButton("Salva modifiche", p)),
    bottoneAnnullaModifiche(new QPushButton("Annulla modifiche", p)),
    icona() {

    contenitorePopUp->addWidget(avvisoCampiObbligatori);
    avvisoCampiObbligatori->setText(QString("I campi con '*' sono obbligatori"));

    contenitorePopUp->addWidget(popUpVid);
    contenitorePopUp->addWidget(popUpPhy);
    contenitorePopUp->addWidget(popUpDig);
    contenitorePopUp->addWidget(popUpKey);
    contenitorePopUp->addWidget(popUpDlc);
    contenitorePopUp->addWidget(popUpCol);
    contenitorePopUp->addWidget(popUpNuo);
    contenitorePopUp->addWidget(popUpUsa);

    contenitorePopUp->addLayout(contieniLabelEBottone);
    contieniLabelEBottone->addWidget(aggiungiDescrizione);
    aggiungiDescrizione->setText(QString("Aggiungi immagine: "));
    contieniLabelEBottone->addWidget(bottoneModificaFoto);
    bottoneModificaFoto->setIcon(QIcon(icona)); //setIcon(QIcon(QString(icona)));
    bottoneModificaFoto->setFixedSize(350, 300);
    bottoneModificaFoto->setIconSize(QSize(350, 290));
    contieniLabelEBottone->setMargin(10);

    contenitorePopUp->addLayout(contieniBottoniSmAm);
    contieniBottoniSmAm->addWidget(bottoneSalvaModifiche);
    contieniBottoniSmAm->addWidget(bottoneAnnullaModifiche);

    setLayout(contenitorePopUp);

    contenitorePopUp->setStretch(9, 1); //(3,1) (4,1)

    setMinimumSize(600, 900);

    //connect(setLayoutHideAndClear(), SIGNAL(clicked()), this, SLOT(close()));
    //connect(this, SIGNAL(close()), this, SLOT(setLayoutHideAndClear()));
    //connect(closeEvent(), SIGNAL(clicked()), this, SLOT(setLayoutHideAndClear()));
    connect(bottoneModificaFoto, SIGNAL(clicked()), this, SLOT(cambiaIcona()));
    connect(bottoneAnnullaModifiche, SIGNAL(clicked()), this, SLOT(setLayoutHideAndClear()));
    connect(bottoneAnnullaModifiche, SIGNAL(clicked()), this, SLOT(reject()));
}
//connect(salvaModifica,SIGNAL(clicked()), this,SLOT(close())); se schiaccio su salva mi chiude la finestra
QVBoxLayout* PopUpGenerico::getContenitorePopUp() const { return contenitorePopUp; }

LayoutInserisciVideogame* PopUpGenerico::getPopUpVid() const { return popUpVid; }

LayoutInserisciPhysical* PopUpGenerico::getPopUpPhy() const { return popUpPhy; }

LayoutInserisciDigital* PopUpGenerico::getPopUpDig() const { return popUpDig; }

LayoutInserisciKey* PopUpGenerico::getPopUpKey() const { return  popUpKey; }

LayoutInserisciDlc* PopUpGenerico::getPopUpDlc() const { return popUpDlc; }

LayoutInserisciCollectorsEdition* PopUpGenerico::getPopUpCol() const { return popUpCol; }

LayoutInserisciGiocoNuovo* PopUpGenerico::getPopUpNuo() const { return popUpNuo; }

LayoutInserisciGiocoUsato* PopUpGenerico::getPopUpUsa() const { return popUpUsa; }

QPushButton* PopUpGenerico::getBottoneModificaFoto() const { return bottoneModificaFoto; }

QPushButton* PopUpGenerico::getBottoneSalvaModifiche() const { return bottoneSalvaModifiche; }

QPushButton* PopUpGenerico::getBottoneAnnullaModifiche() const { return bottoneAnnullaModifiche; }

QString PopUpGenerico::getIcona() const { return icona; }

void PopUpGenerico::setNuovaIcona(std::string nuovaIcona) {
    icona = QString::fromStdString(nuovaIcona);
    bottoneModificaFoto->setIcon(QIcon(icona));
}

void PopUpGenerico::reject() {
    setLayoutHideAndClear();
    QDialog::reject();
}

void PopUpGenerico::cambiaIcona() {
   QString newIcona = QFileDialog::getOpenFileName(parent, tr("Scegli file"), "../Progetto-PAO-2019-Videogame/Immagini" , "File immagine(*.JPG; *.PNG)"/*"File JPG(*.JPG)"*/);
   //icona = QFileDialog::getOpenFileName(parent, tr("Scegli file"), ":/Immagini" , "File JPG(*.JPG)");
   if(newIcona != "") {
       icona = newIcona;
       bottoneModificaFoto->setIcon(QIcon(icona));
   }
   //icona = newIcona;
}

void PopUpGenerico::setLayoutHideAndClear() const {
    popUpVid->hide();
    popUpPhy->hide();
    popUpDig->hide();
    popUpKey->hide();
    popUpDlc->hide();
    popUpCol->hide();
    popUpNuo->hide();
    popUpUsa->hide();

    popUpVid->clearQLineEditVideogame();
    popUpPhy->clearQLineEditPhysical();
    popUpDig->clearQLineEditDigital();
    popUpKey->clearQLineEditKey();
    popUpDlc->clearQLineEditDlc();
    popUpCol->clearQLineEditCollectosEdition();
    popUpNuo->clearQLineEditGiocoNuovo();
    popUpUsa->clearQLineEditGiocoUsato();

    //tolgo la selezione automatica del bottone che segnalava il bordino azzurro attorno
    bottoneModificaFoto->setAutoDefault(false);
    bottoneModificaFoto->setDefault(false);
    bottoneSalvaModifiche->setAutoDefault(false);
    bottoneSalvaModifiche->setDefault(false);
    bottoneAnnullaModifiche->setAutoDefault(false);
    bottoneAnnullaModifiche->setDefault(false);
}
