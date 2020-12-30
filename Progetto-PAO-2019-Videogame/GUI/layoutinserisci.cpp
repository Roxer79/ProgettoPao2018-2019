#include "GUI/layoutinserisci.h"

LayoutInserisci::LayoutInserisci(QWidget* p): parent(p),
    contieniTut(new QVBoxLayout(this)),
    avvisoCampiObbligatori(new QLabel(p)),
    contieniLayout(new QVBoxLayout),
    contieniVideogame(new QHBoxLayout),
    contieniDigitalPhysical(new QHBoxLayout),
    contieniKeDlCeGnGu(new QHBoxLayout),
    contientiAggCan(new QHBoxLayout),
    boxSceltaDerivateInserisci(new QComboBox(this)),
    layInsVid(new LayoutInserisciVideogame),
    layInsPhy(new LayoutInserisciPhysical),
    layInsDig(new LayoutInserisciDigital),
    layInsKey(new LayoutInserisciKey),
    layInsDlc(new LayoutInserisciDlc),
    layInsCse(new LayoutInserisciCollectorsEdition),
    layInsNuo(new LayoutInserisciGiocoNuovo),
    layInsUsa(new LayoutInserisciGiocoUsato),
    contieniLabelBottone(new QHBoxLayout),
    scrittaLabel(new QLabel),
    bottoneAggiungiImmagine(new QPushButton(this)),
    bottoneAggiungi(new QPushButton("Aggiungi", this)),
    bottoneCancellaTutto(new QPushButton("Cancella tutto", this)),
    icona(),
    sizBtn(QSize(300, 40)) {

    contieniTut->addWidget(avvisoCampiObbligatori);
    avvisoCampiObbligatori->setText(QString("I campi con '*' sono obbligatori"));

    contieniTut->addWidget(boxSceltaDerivateInserisci);
    boxSceltaDerivateInserisci->addItem("Selezionare tipo di prodotto");
    boxSceltaDerivateInserisci->addItem("Key");
    boxSceltaDerivateInserisci->addItem("Dlc");
    boxSceltaDerivateInserisci->addItem("Collector's edition");
    boxSceltaDerivateInserisci->addItem("Gioco nuovo");
    boxSceltaDerivateInserisci->addItem("Gioco usato");

    contieniTut->addLayout(contieniLayout);//giusto
    contieniLayout->addLayout(contieniVideogame);//giusto
    //contieniTut->addLayout(contieniVideogame);
    contieniVideogame->addWidget(layInsVid);//giusto
    //contieniTut->addWidget(layInsVid);
    layInsVid->hide();//giusto
    //contieniTut->addLayout(contientiLayout);
    contieniLayout->addLayout(contieniDigitalPhysical);//giusto
    //contieniTut->addLayout(contieniDigitalPhysical);
    contieniDigitalPhysical->addWidget(layInsPhy);//giusto
    layInsPhy->hide();//giusto
    contieniDigitalPhysical->addWidget(layInsDig);//giusto
    layInsDig->hide();//giusto
    contieniLayout->addLayout(contieniKeDlCeGnGu); //sbagliato
    //contieniTut->addLayout(contieniKeDlCeGnGu); //giusto
    contieniKeDlCeGnGu->addWidget(layInsKey);//giusto
    layInsKey->hide();//giusto
    contieniKeDlCeGnGu->addWidget(layInsDlc);//giusto
    layInsDlc->hide();//giusto
    contieniKeDlCeGnGu->addWidget(layInsCse);//giusto
    layInsCse->hide();//giusto
    contieniKeDlCeGnGu->addWidget(layInsNuo);//giusto
    layInsNuo->hide();//giusto
    contieniKeDlCeGnGu->addWidget(layInsUsa);//giusto
    layInsUsa->hide();//giusto

    contieniTut->addLayout(contieniLabelBottone);
    contieniLabelBottone->addWidget(scrittaLabel);
    scrittaLabel->setText(QString("Aggiungi immagine: "));
    contieniLabelBottone->addWidget(bottoneAggiungiImmagine);
    bottoneAggiungiImmagine->setIcon(QIcon(icona));
    bottoneAggiungiImmagine->setMinimumSize(500, 300);//giusto 500, 300
    bottoneAggiungiImmagine->setIconSize(QSize(390, 290));//giusto

    contieniTut->addLayout(contientiAggCan);
    contientiAggCan->addWidget(bottoneAggiungi);
    bottoneAggiungi->setFixedSize(sizBtn);
    bottoneAggiungi->setStyleSheet("font: bold; font-size: 20px;");
    contientiAggCan->addWidget(bottoneCancellaTutto);
    bottoneCancellaTutto->setFixedSize(sizBtn);
    bottoneCancellaTutto->setStyleSheet("font: bold; font-size: 20px;");

    contieniLayout->setStretch(2, 1); //giusto

    //contieniTut->setStretch(5, 1);

    setLayout(contieniTut);

    connect(boxSceltaDerivateInserisci, SIGNAL(activated(int)), this, SLOT(metLayoutInserisciVideogame(int)));
    connect(bottoneAggiungiImmagine, SIGNAL(clicked()), this, SLOT(cambiaIconaInserisci()));
    connect(bottoneCancellaTutto, SIGNAL(clicked()), this, SLOT(clearTutteQLineEdit()));
};

QComboBox* LayoutInserisci::getSceltaDerivate() const { return boxSceltaDerivateInserisci; }

LayoutInserisciVideogame* LayoutInserisci::getLayoutInserisciVideogame() const { return layInsVid; }

LayoutInserisciPhysical* LayoutInserisci::getLayoutInserisciPhysical() const { return layInsPhy; }

LayoutInserisciDigital* LayoutInserisci::getLayoutInserisciDigital() const { return layInsDig; }

LayoutInserisciKey* LayoutInserisci::getLayoutInserisciKey() const { return layInsKey; }

LayoutInserisciDlc* LayoutInserisci::getLayoutInserisciDlc() const { return layInsDlc; }

LayoutInserisciCollectorsEdition* LayoutInserisci::getLayoutInserisciCollectorsEdition() const { return layInsCse; }

LayoutInserisciGiocoNuovo* LayoutInserisci::getLayoutInserisciGiocoNuovo() const { return layInsNuo; }

LayoutInserisciGiocoUsato* LayoutInserisci::getLayoutInserisciGiocoUsato() const { return layInsUsa; }

QPushButton* LayoutInserisci::getBottoneAggiungiImmagine() const { return bottoneAggiungiImmagine; }

QPushButton* LayoutInserisci::getBottoneAggiungi() const { return bottoneAggiungi; }

QPushButton* LayoutInserisci::getBottoneCancellaTutto() const { return bottoneCancellaTutto; }

QString LayoutInserisci::getIcona() const { return icona; }

void LayoutInserisci::changeIndexBoxScelteDerivateInserisci() const {
    boxSceltaDerivateInserisci->setCurrentIndex(0);
    metLayoutInserisciVideogame(0);
    layInsVid->hide();
    layInsPhy->hide();
    layInsDig->hide();
    layInsKey->hide();
    layInsDlc->hide();
    layInsCse->hide();
    layInsNuo->hide();
    layInsUsa->hide();
    clearTutteQLineEdit();
}

void LayoutInserisci::clearTutteQLineEdit() const {
    layInsVid->clearQLineEditVideogame();
    layInsPhy->clearQLineEditPhysical();
    layInsDig->clearQLineEditDigital();
    layInsKey->clearQLineEditKey();
    layInsDlc->clearQLineEditDlc();
    layInsCse->clearQLineEditCollectosEdition();
    layInsNuo->clearQLineEditGiocoNuovo();
    layInsUsa->clearQLineEditGiocoUsato();
    QString newIcon;
    bottoneAggiungiImmagine->setIcon(QIcon(newIcon));
}

void LayoutInserisci::metLayoutInserisciVideogame(int index) const {
    switch(index) {
    case 0:
        layInsVid->hide();
        layInsPhy->hide();
        layInsDig->hide();
        layInsKey->hide();
        layInsDlc->hide();
        layInsCse->hide();
        layInsNuo->hide();
        layInsUsa->hide();
        clearTutteQLineEdit();
        bottoneAggiungiImmagine->setEnabled(false);
        bottoneAggiungi->setEnabled(false);
        bottoneCancellaTutto->setEnabled(false);
        //contieniTut->update();
    break;

    case 1:
        layInsVid->show();
        layInsPhy->hide();
        layInsDig->show();
        layInsKey->show();
        layInsDlc->hide();
        layInsCse->hide();
        layInsNuo->hide();
        layInsUsa->hide();
        clearTutteQLineEdit();
        bottoneAggiungiImmagine->setEnabled(true);
        bottoneAggiungi->setEnabled(true);
        bottoneCancellaTutto->setEnabled(true);
        //contieniTut->update();
    break;

    case 2:
        layInsVid->show();
        layInsPhy->hide();
        layInsDig->show();
        layInsKey->hide();
        layInsDlc->show();
        layInsCse->hide();
        layInsNuo->hide();
        layInsUsa->hide();
        clearTutteQLineEdit();
        bottoneAggiungiImmagine->setEnabled(true);
        bottoneAggiungi->setEnabled(true);
        bottoneCancellaTutto->setEnabled(true);
        //contieniTut->update();
    break;

    case 3:
        layInsVid->show();
        layInsPhy->show();
        layInsDig->hide();
        layInsKey->hide();
        layInsDlc->hide();
        layInsCse->show();
        layInsNuo->hide();
        layInsUsa->hide();
        clearTutteQLineEdit();
        bottoneAggiungiImmagine->setEnabled(true);
        bottoneAggiungi->setEnabled(true);
        bottoneCancellaTutto->setEnabled(true);
        //contieniTut->update();
    break;

    case 4:
        layInsVid->show();
        layInsPhy->show();
        layInsDig->hide();
        layInsKey->hide();
        layInsDlc->hide();
        layInsCse->hide();
        layInsNuo->show();
        layInsUsa->hide();
        clearTutteQLineEdit();
        bottoneAggiungiImmagine->setEnabled(true);
        bottoneAggiungi->setEnabled(true);
        bottoneCancellaTutto->setEnabled(true);
        //contieniTut->update();
    break;

    case 5:
        layInsVid->show();
        layInsPhy->show();
        layInsDig->hide();
        layInsKey->hide();
        layInsDlc->hide();
        layInsCse->hide();
        layInsNuo->hide();
        layInsUsa->show();
        clearTutteQLineEdit();
        bottoneAggiungiImmagine->setEnabled(true);
        bottoneAggiungi->setEnabled(true);
        bottoneCancellaTutto->setEnabled(true);
        //contieniTut->update();
    break;
    }
}

void LayoutInserisci::cambiaIconaInserisci() {
    icona = QFileDialog::getOpenFileName(parent, tr("Scegli file"), "../Progetto-PAO-2019-Videogame/Immagini" , "File immagine(*.JPG; *.PNG)");
    bottoneAggiungiImmagine->setIcon(QIcon(icona));
}
