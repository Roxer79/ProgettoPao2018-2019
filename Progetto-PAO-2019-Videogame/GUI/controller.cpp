#include "GUI/controller.h"

Controller::Controller(Modello* mod, QWidget* p):
    parent(p),
    miomenu(new MenuProgetto(this)),
    mainwind(new MainWindow(this)),
    layIns(new LayoutInserisci(this)),
    layRicPerOgg(new LayoutRicercaPerOggetti(this)),
    layRic(new LayoutRicerca(this)),
    layoutPrincipale(new QVBoxLayout(this)),
    popGen(new PopUpGenerico(this)),
    model(mod),
    file(/*"../Progetto-PAO-2019-Videogame/Salvataggio_Dati_XML/dati progetto.xml" // ":/Salvataggio_Dati_XML/dati progetto.xml"*/ QFileDialog::getOpenFileName(this, tr("Scegli file"), "../Progetto-PAO-2019-Videogame/Salvataggio_Dati_XML" , "File XML(*.xml)")) {

    //move(QApplication::desktop()->screen()->rect().center() - rect().center());

    layoutPrincipale->setMenuBar(miomenu);

    layoutPrincipale->addWidget(mainwind);
    mainwind->setEnabled(false);
    layoutPrincipale->addWidget(layIns);
    layIns->setEnabled(false);
    layIns->hide();
    layoutPrincipale->addWidget(layRicPerOgg);
    layRicPerOgg->setEnabled(false);
    layRicPerOgg->hide();
    layoutPrincipale->addWidget(layRic);
    layRic->setEnabled(false);
    layRic->hide();

    popGen->setEnabled(false);
    popGen->hide();

    caricaDati();

    setLayout(layoutPrincipale);

    //IMPORTANTE ricordarsi di centrare la fnestra, eventualmente riordinare la lista quando la si crea nel modello e correggere path xml e immagini

    setMinimumSize(800, 900);
    setGeometry(QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, size(), qApp->desktop()->availableGeometry()));

    //connect modifica e rimuovi mainlayout
    connect(mainwind->getModifica(), SIGNAL(clicked()), this, SLOT(modificaCaricaPopUp()));
    //connect(mainwind->getLista(), SIGNAL(itemDoubleClicked(VideogameOggettiLista*)), this, SLOT(modificaCaricaPopUp(VideogameOggettiLista*)));
    //connect(mainwind->getModifica(), SIGNAL(toggled(bool)), this, SLOT(setDisabled(bool)));
    connect(mainwind->getRimuovi(), SIGNAL(clicked()), this, SLOT(rimuoviDallaListaContainer()));

    //connect bottone aggiungi layoutinserisci
    connect(layIns->getBottoneAggiungi(), SIGNAL(clicked()), this, SLOT(aggiungiElementoAllaLista()));

    //connect bottone layoutspecifico
    connect(layRicPerOgg->getBottoneCercaOgg(), SIGNAL(clicked()), this, SLOT(ricercaOggetto()));
    connect(layRicPerOgg->getBottoneModificaOggRic(), SIGNAL(clicked()), this, SLOT(modificaCaricaPopUp()));
    connect(layRicPerOgg->getBottoneEliminaOggRic(), SIGNAL(clicked()), this, SLOT(rimuoviDallaListaContainer()));

    //connect bottone ricerca layout ricerca generica
    connect(layRic->getBottoneRicerca(), SIGNAL(clicked()), this, SLOT(ricercaOggettoPerStringa()));
    connect(layRic->getBottoneModifica(), SIGNAL(clicked()), this, SLOT(modificaCaricaPopUp()));
    connect(layRic->getBotRimuovi(), SIGNAL(clicked()), this, SLOT(rimuoviDallaListaContainer()));

    //connect popup
    connect(popGen->getBottoneSalvaModifiche(), SIGNAL(clicked()), this, SLOT(salvaModificheDatoXML()));
}

void Controller::caricaDati() const {
    if(file != ""){
        abilitaTutto();
        //*if(mainwind->isVisible())*/ mainwind->getLista()->clear();
        //*if(layRicPerOgg->isVisible())*/ layRicPerOgg->getListaRicOgg()->clear();
        //*if(layRic->isVisible())*/ layRic->getCasellaLista()->clear();
        model->settaNuovoPercorsoFileXML(file.toStdString());
        model->caricaXML();

        if(controlloNumeroElementiLista() == 0) {
            //mainwind->getLista()->clear();
            //layRicPerOgg->getListaRicOgg()->clear();
            //layRic->getCasellaLista()->clear();
            //model->settaNuovoPercorsoFileXML(file.toStdString());
            //disabilitaTutto();
            QMessageBox::warning(parent, "Attenzione!", "Non ci sono elementi all'interno della lista, caricare un altro file!");
        }
        else {
            Container<Videogame*>::constiterator aux = model->cBegin();
            Container<Videogame*>::constiterator auxEnd = model->cEnd();

            for(; aux != auxEnd; ++aux) { mainwind->getLista()->aggiungiVideogioco(*aux); }

            model->setSalvaSeModifica(true);
            //metMainWindow();
        }
    } else {
        //mainwind->getLista()->clear();
        //layRicPerOgg->getListaRicOgg()->clear();
        //layRic->getCasellaLista()->clear();
        model->settaNuovoPercorsoFileXML(file.toStdString());
        disabilitaTutto();
        QMessageBox::warning(parent, "Caricare dati", "Caricare un file .xml!");
    }
}

void Controller::disabilitaTutto() const {
    miomenu->getFunzionalitaGestore()->setEnabled(false);
    miomenu->getSalva()->setEnabled(false);
    miomenu->getSalvaEdEsci()->setEnabled(false);
    mainwind->getLista()->clear();
    mainwind->setEnabled(false);
    layIns->setEnabled(false);
    layRicPerOgg->getListaRicOgg()->clear();
    layRicPerOgg->setEnabled(false);
    layRic->getCasellaLista()->clear();
    layRic->setEnabled(false);
    //layoutPrincipale->setEnabled(false);
    popGen->setEnabled(false);

}

void Controller::abilitaTutto() const {
    miomenu->getFunzionalitaGestore()->setEnabled(true);
    miomenu->getSalva()->setEnabled(true);
    miomenu->getSalvaEdEsci()->setEnabled(true);
    mainwind->setEnabled(true);
    mainwind->getLista()->clear();
    layIns->setEnabled(true);
    layRicPerOgg->setEnabled(true);
    layRicPerOgg->getListaRicOgg()->clear();
    layRic->setEnabled(true);
    layRic->getCasellaLista()->clear();
    //layoutPrincipale->setEnabled(true);
    popGen->setEnabled(true);
}

unsigned int Controller::controlloNumeroElementiLista() const { return model->numeroElementiInNegozio(); }

void Controller::metMainWindow() const {
   mainwind->show();
   layIns->hide();
   layRicPerOgg->hide();
   layRic->hide();

   layIns->clearTutteQLineEdit();
   layIns->changeIndexBoxScelteDerivateInserisci();
   //layRic->changeIndexBoxSceltaDerivataRicerca();
   layRicPerOgg->disabilitaQLineEdit();
   layRic->disabilitaTutto();
}

void Controller::metLayoutInserisci() const {
    mainwind->hide();
    layIns->show();
    layRicPerOgg->hide();
    layRic->hide();

    //mainwind->getLista()->releaseKeyboard();
    layIns->clearTutteQLineEdit();
    layIns->changeIndexBoxScelteDerivateInserisci();
    //layRic->changeIndexBoxSceltaDerivataRicerca();
    layRicPerOgg->disabilitaQLineEdit();
    layRic->disabilitaTutto();
}

void Controller::metLayoutRicercaPerOggetti() const {
    mainwind->hide();
    layIns->hide();
    layRicPerOgg->show();
    layRic->hide();

    layIns->clearTutteQLineEdit();
    layIns->changeIndexBoxScelteDerivateInserisci();
    //layRic->changeIndexBoxSceltaDerivataRicerca();
    layRicPerOgg->disabilitaQLineEdit();
    layRic->disabilitaTutto();
}

void Controller::metLayoutRicerca() const {
    mainwind->hide();
    layIns->hide();
    layRicPerOgg->hide();
    layRic->show();

    layIns->clearTutteQLineEdit();
    layIns->changeIndexBoxScelteDerivateInserisci();
    //layRic->changeIndexBoxSceltaDerivataRicerca();
    layRicPerOgg->disabilitaQLineEdit();
    layRic->abilitaTutto();
}

void Controller::caricaDatiXML(){
    QString newFile = QFileDialog::getOpenFileName(this, tr("Scegli file"), "../Progetto-PAO-2019-Videogame/Salvataggio_Dati_XML" , "File XML(*.xml)");
    if(newFile != "") {
        file = newFile;
    //else { QMessageBox::warning(...)
    //file = QFileDialog::getOpenFileName(this, tr("Scegli file"), ":/Salvataggio_Dati_XML/dati.xml" , "File XML(*.xml)");

    //if(file != ""){
        abilitaTutto();
        //mainwind->getLista()->clear();
        //layRicPerOgg->getListaRicOgg()->clear();
        //layRic->getCasellaLista()->clear();
        model->settaNuovoPercorsoFileXML(file.toStdString());
        model->caricaXML();

        if(controlloNumeroElementiLista() == 0) QMessageBox::warning(parent, "Attenzione!", "Non ci sono elementi all'interno della lista, caricare un altro file!");
        else {
            Container<Videogame*>::constiterator aux = model->cBegin();
            Container<Videogame*>::constiterator auxEnd = model->cEnd();

            for(; aux != auxEnd; ++aux) { mainwind->getLista()->aggiungiVideogioco(*aux); }

            model->setSalvaSeModifica(true);
            metMainWindow();
        }
    } else {
        //mainwind->getLista()->clear();
        //layRicPerOgg->getListaRicOgg()->clear();
        //layRic->getCasellaLista()->clear();
        //model->settaNuovoPercorsoFileXML(file.toStdString());
        //disabilitaTutto();
        QMessageBox::warning(parent, "Caricare dati", "Caricare un file .xml!");
    }
}

void Controller::salvaDatiXML() const {
    if(file != "" && controlloNumeroElementiLista() != 0) {
        model->salvataggioDatiXML();
        model->setSalvaSeModifica(true);
        //disabilitaTutto();
        caricaDati();
        QMessageBox::information(parent, "Salva dati", "Salvataggio riuscito!");
    } else {
        QMessageBox::warning(parent, "Salva dati", "Non ho nulla da salvare, inserire un oggetto!");
    }
}

void Controller::salvaModificheDatoXML() {
    VideogameOggettiLista* popUp = nullptr;
    Videogame* ogg = nullptr;
    bool hoModificatoQualcosa = false;
    bool boolInStock = false;
    unsigned int inStock = 0;
    Container<Videogame*>::constiterator aux = model->cBegin();
    Container<Videogame*>::constiterator auxEnd = model->cEnd();
    for( ; aux != auxEnd; ++aux) { inStock += (*aux)->getQuantitaInStock(); }

    if(mainwind->isVisible() && mainwind->getLista()->currentItem() != nullptr) {
        popUp = mainwind->getLista()->currentItem();
        ogg = popUp->getOggettoPunt();
        hoModificatoQualcosa = false;
    } else if(layRicPerOgg->isVisible() && layRicPerOgg->getListaRicOgg()->currentItem() != nullptr) {
        popUp = layRicPerOgg->getListaRicOgg()->currentItem();
        ogg = popUp->getOggettoPunt();
        hoModificatoQualcosa = false;
    } else if(layRic->isVisible() && layRic->getCasellaLista()->currentItem() != nullptr) {
        popUp = layRic->getCasellaLista()->currentItem();
        ogg = popUp->getOggettoPunt();
        hoModificatoQualcosa = false;
    }
    //da qui inizio a fare modifiche nel caso, bisogna vedere se funziona
    if(popUp != nullptr && ogg != nullptr && popGen->getPopUpVid()->getTitVideogioco()->text().toStdString() != "" && popGen->getPopUpVid()->getCasProduttice()->text().toStdString() != "" && popGen->getPopUpVid()->getAnnoPubl()->text().toUInt() != 0 && popGen->getPopUpVid()->getGenGioco()->text().toStdString() != "") {
        if(ogg->getTitoloVideogioco() != popGen->getPopUpVid()->getTitVideogioco()->text().toStdString() && popGen->getPopUpVid()->getTitVideogioco()->text().toStdString() != "") {
            ogg->setTitoloVideogioco((popGen->getPopUpVid()->getTitVideogioco()->text().toStdString()));
            hoModificatoQualcosa = true;
        }
        if(ogg->getDisponibile() != popGen->getPopUpVid()->getDisponibil()->currentIndex()) {
            ogg->setDisponibile(popGen->getPopUpVid()->getDisponibil()->currentIndex());
            hoModificatoQualcosa = true;
        }
        QString prezzo = popGen->getPopUpVid()->getPrezBase()->text();
        prezzo.replace(QString(","), QString("."));
        if(ogg->getPrezzoBase() != prezzo.toDouble() /*popGen->getPopUpVid()->getPrezBase()->text().toDouble()*/) {
            //QString prezzo = popGen->getPopUpVid()->getPrezBase()->text();
            //prezzo.replace(QString(","), QString("."));
            //ogg->setPrezzoBase(popGen->getPopUpVid()->getPrezBase()->text().toDouble());
            ogg->setPrezzoBase(prezzo.toDouble());
            hoModificatoQualcosa = true;
        }
        if(ogg->getQuantitaInStock() != popGen->getPopUpVid()->getQuantInStock()->text().toUInt()) {
            if(inStock + popGen->getPopUpVid()->getQuantInStock()->text().toUInt() - ogg->getQuantitaInStock() > ogg->getCapienzaMassimaMagazzino()) {
                inStock -= ogg->getQuantitaInStock();
                ogg->setQuantitaInStock(ogg->getCapienzaMassimaMagazzino() - inStock);
                hoModificatoQualcosa = true;
                boolInStock = true; //settare true se quantità in stock maggiore di capienza massima
            } else {
                ogg->setQuantitaInStock(popGen->getPopUpVid()->getQuantInStock()->text().toUInt());
                hoModificatoQualcosa = true;
            }
        }
        if(ogg->getCasaProduttrice() != popGen->getPopUpVid()->getCasProduttice()->text().toStdString() && popGen->getPopUpVid()->getCasProduttice()->text().toStdString() != "") {
            ogg->setCasaProduttrice(popGen->getPopUpVid()->getCasProduttice()->text().toStdString());
            hoModificatoQualcosa = true;
        }
        if(ogg->getAnnoPubblicazione() != popGen->getPopUpVid()->getAnnoPubl()->text().toUInt() && popGen->getPopUpVid()->getAnnoPubl()->text().toUInt() >= 1958) {
            ogg->setAnnoPubblicazione(popGen->getPopUpVid()->getAnnoPubl()->text().toUInt());
            hoModificatoQualcosa = true;
        }
        if(ogg->getPegi() != popGen->getPopUpVid()->getPeg()->text().toUInt()) {
            ogg->setPegi(popGen->getPopUpVid()->getPeg()->text().toUInt());
            hoModificatoQualcosa = true;
        }
        if(ogg->getGenereGioco() != popGen->getPopUpVid()->getGenGioco()->text().toStdString() && popGen->getPopUpVid()->getGenGioco()->text().toStdString() != "") {
            ogg->setGenereGioco(popGen->getPopUpVid()->getGenGioco()->text().toStdString());
            hoModificatoQualcosa = true;
        }
        if(ogg->getTipoDiPiattaforma() != popGen->getPopUpVid()->getTipoDiPiatta()->text().toStdString()) {
            ogg->setTipoDiPiattaforma(popGen->getPopUpVid()->getTipoDiPiatta()->text().toStdString());
            hoModificatoQualcosa = true;
        }
        if(ogg->getApplicaSconto() != popGen->getPopUpVid()->getAppliSconto()->currentIndex()) {
            ogg->setApplicaSconto(popGen->getPopUpVid()->getAppliSconto()->currentIndex());
            hoModificatoQualcosa = true;
        }
        if(ogg->getPercorsoImmagine() != popGen->getIcona().toStdString()) {
            ogg->setPercorsoImmagine(popGen->getIcona().toStdString());
            hoModificatoQualcosa = true;
        }
        if(dynamic_cast<Key*>(ogg)) {
            Key* oggKey = static_cast<Key*>(ogg);
            if(oggKey->getPiattaformaRiscattoCodice() != popGen->getPopUpDig()->getPiattaRiscattoCodice()->text().toStdString()) {
                oggKey->setPiattaformaRiscattoCodice(popGen->getPopUpDig()->getPiattaRiscattoCodice()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggKey->getCodiceAlfanumerico() != popGen->getPopUpDig()->getCodiceAlfaNum()->text().toStdString()) {
                oggKey->setCodiceAlfanumerico(popGen->getPopUpDig()->getCodiceAlfaNum()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggKey->getDescrizioneDigital() != popGen->getPopUpDig()->getDescrizioneDigi()->text().toStdString()) {
                oggKey->setDescrizioneDigital(popGen->getPopUpDig()->getDescrizioneDigi()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggKey->getScontoKeyAnnuale() != popGen->getPopUpKey()->getScontoKeyAnnual()->text().toUInt()) {
                oggKey->setScontoKeyAnnuale(popGen->getPopUpKey()->getScontoKeyAnnual()->text().toUInt());
                hoModificatoQualcosa = true;
            }
        } else if(dynamic_cast<Dlc*>(ogg)) {
            Dlc* oggDlc = static_cast<Dlc*>(ogg);
            if(oggDlc->getPiattaformaRiscattoCodice() != popGen->getPopUpDig()->getPiattaRiscattoCodice()->text().toStdString()) {
                oggDlc->setPiattaformaRiscattoCodice(popGen->getPopUpDig()->getPiattaRiscattoCodice()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggDlc->getCodiceAlfanumerico() != popGen->getPopUpDig()->getCodiceAlfaNum()->text().toStdString()) {
                oggDlc->setCodiceAlfanumerico(popGen->getPopUpDig()->getCodiceAlfaNum()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggDlc->getDescrizioneDigital() != popGen->getPopUpDig()->getDescrizioneDigi()->text().toStdString()) {
                oggDlc->setDescrizioneDigital(popGen->getPopUpDig()->getDescrizioneDigi()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggDlc->getNomeDlc() != popGen->getPopUpDlc()->getNomDlc()->text().toStdString()) {
                oggDlc->setNomeDlc(popGen->getPopUpDlc()->getNomDlc()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggDlc->getScontoDlc() != popGen->getPopUpDlc()->getScontoDlcAnnual()->text().toUInt()) {
                oggDlc->setScontoDlcAnnuale(popGen->getPopUpDlc()->getScontoDlcAnnual()->text().toUInt());
                hoModificatoQualcosa = true;
            }
        } else if(dynamic_cast<CollectorEdition*>(ogg)) {
            CollectorEdition* oggCol = static_cast<CollectorEdition*>(ogg);
            if(oggCol->getBarCode() != popGen->getPopUpPhy()->getBarCod()->text().toUInt()) {
                oggCol->setBarCode(popGen->getPopUpPhy()->getBarCod()->text().toUInt());
                hoModificatoQualcosa = true;
            }
            if(oggCol->getDescrizioneEtichetta() != popGen->getPopUpPhy()->getDescrizioneEti()->text().toStdString()) {
                oggCol->setDescrizioneEtichetta(popGen->getPopUpPhy()->getDescrizioneEti()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggCol->getActionFigure() != popGen->getPopUpCol()->getActionFig()->currentIndex()) {
                oggCol->setActionFigure(popGen->getPopUpCol()->getActionFig()->currentIndex());
                hoModificatoQualcosa = true;
            }
            if(oggCol->getSovraPrezzoActionFigure() != popGen->getPopUpCol()->getSovraPrezzoActionFig()->text().toUInt()) {
                oggCol->setSovraPrezzoActionFigure(popGen->getPopUpCol()->getSovraPrezzoActionFig()->text().toUInt());
                hoModificatoQualcosa = true;
            }
            if(oggCol->getScontoCollectorEditionAnnuale() != popGen->getPopUpCol()->getScontoCollEdit()->text().toUInt()) {
                oggCol->setScontoCollectorEditionAnnuale(popGen->getPopUpCol()->getScontoCollEdit()->text().toUInt());
                hoModificatoQualcosa = true;
            }
        } else if(dynamic_cast<Game*>(ogg)) {
            Game* oggGam = static_cast<Game*>(ogg);
            if(oggGam->getBarCode() != popGen->getPopUpPhy()->getBarCod()->text().toUInt()) {
                oggGam->setBarCode(popGen->getPopUpPhy()->getBarCod()->text().toUInt());
                hoModificatoQualcosa = true;
            }
            if(oggGam->getDescrizioneEtichetta() != popGen->getPopUpPhy()->getDescrizioneEti()->text().toStdString()) {
                oggGam->setDescrizioneEtichetta(popGen->getPopUpPhy()->getDescrizioneEti()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggGam->getEdizioneLimitata() != popGen->getPopUpNuo()->getEdizioneLim()->currentIndex()) {
                oggGam->setEdizioneLimitata(popGen->getPopUpNuo()->getEdizioneLim()->currentIndex());
                hoModificatoQualcosa = true;
            }
            if(oggGam->getSovraPrezzoEdizioneLimitata() != popGen->getPopUpNuo()->getSovraPrezzoEdizioneLim()->text().toUInt()) {
                oggGam->setSovraPrezzoEdizioneLimitata(popGen->getPopUpNuo()->getSovraPrezzoEdizioneLim()->text().toUInt());
                hoModificatoQualcosa = true;
            }
            if(oggGam->getScontoGameAnnuale() != popGen->getPopUpNuo()->getScontoAnnualGam()->text().toUInt()) {
                oggGam->setScontoGameAnnuale(popGen->getPopUpNuo()->getScontoAnnualGam()->text().toUInt());
                hoModificatoQualcosa = true;
            }
        } else if(dynamic_cast<SecondHand*>(ogg)) {
            SecondHand* oggSec = static_cast<SecondHand*>(ogg);
            if(oggSec->getBarCode() != popGen->getPopUpPhy()->getBarCod()->text().toUInt()) {
                oggSec->setBarCode(popGen->getPopUpPhy()->getBarCod()->text().toUInt());
                hoModificatoQualcosa = true;
            }
            if(oggSec->getDescrizioneEtichetta() != popGen->getPopUpPhy()->getDescrizioneEti()->text().toStdString()) {
                oggSec->setDescrizioneEtichetta(popGen->getPopUpPhy()->getDescrizioneEti()->text().toStdString());
                hoModificatoQualcosa = true;
            }
            if(oggSec->getScatolaIntegra() != popGen->getPopUpUsa()->getScatolaInteg()->currentIndex()) {
                oggSec->setScatolaIntegra();
                hoModificatoQualcosa = true;
            }
            if(oggSec->getSovraPrezzoSCatolaIntegra() != popGen->getPopUpUsa()->getSovraPrezzoScatolaInt()->text().toUInt()) {
                oggSec->setSovraPrezzoScatolaIntegra(popGen->getPopUpUsa()->getSovraPrezzoScatolaInt()->text().toUInt());
                hoModificatoQualcosa = true;
            }
            if(oggSec->getScontoSecondHandAnnuale() != popGen->getPopUpUsa()->getScontoAnnualSH()->text().toUInt()) {
                oggSec->setScontoSecondHandAnnuale(popGen->getPopUpUsa()->getScontoAnnualSH()->text().toUInt());
                hoModificatoQualcosa = true;
            }
        }
        if(hoModificatoQualcosa && !boolInStock) {
            model->salvataggioDatiXML();
            caricaDati();
            popGen->setLayoutHideAndClear();
            popGen->close();
            if(layRicPerOgg->isVisible()) { layRicPerOgg->abilitaQLineEdit(); layRicPerOgg->getBottoneEliminaOggRic()->setEnabled(false); layRicPerOgg->getBottoneModificaOggRic()->setEnabled(false); }  //aggiunto dopo
            else if(layRic->isVisible()) { layRic->annullaRicerca(); }  //aggiunto dopo
            QMessageBox::information(parent, "Operazione riuscita", "Modifica effettuata correttamente!");
        } else {
            if(boolInStock) {
                model->salvataggioDatiXML();
                caricaDati();
                popGen->setLayoutHideAndClear();
                popGen->close();
                if(layRicPerOgg->isVisible()) { layRicPerOgg->abilitaQLineEdit(); layRicPerOgg->getBottoneEliminaOggRic()->setEnabled(false); layRicPerOgg->getBottoneModificaOggRic()->setEnabled(false); }  //aggiunto dopo
                else if(layRic->isVisible()) { layRic->annullaRicerca(); } //aggiunto dopo
                QMessageBox::information(parent, "Operazione riuscita ma attenzione", "Modifica effettuata ma la quantità in stock immessa è stata modificata perchè era superiore alla capienza del magazzino!");
            } else {
                popGen->setLayoutHideAndClear();
                popGen->close();
                QMessageBox::warning(parent, "Operazione non riuscita", "Non hai effettuato alcuna modifica!");
            }
          }
    } else {
        if(popGen->getPopUpVid()->getTitVideogioco()->text().toStdString() == "") QMessageBox::warning(parent, "Attenzione", "Inserire titolo videogioco");
        else if(popGen->getPopUpVid()->getCasProduttice()->text().toStdString() == "") QMessageBox::warning(parent, "Attenzione", "Inserire casa produttrice");
        else if(popGen->getPopUpVid()->getAnnoPubl()->text().toUInt() <= 1958) QMessageBox::warning(parent, "Attenzione", "Inserire anno di pubblicazione maggiore di 1958");
        else if(popGen->getPopUpVid()->getGenGioco()->text().toStdString() == "") QMessageBox::warning(parent, "Attenzione", "Inserire genere gioco");
        else {
            popGen->setLayoutHideAndClear();
            popGen->close();
            QMessageBox::warning(parent, "Operazione non riuscita", "Non hai effettuato alcuna modifica!");
        }
    }
}


void Controller::modificaCaricaPopUp() const {
    if(mainwind->isVisible() && mainwind->getLista()->currentItem() == nullptr) QMessageBox::warning(mainwind, "Modifica dati", "Non ho nulla da modificare, scegli un oggetto da modificare!");
    else if(layRicPerOgg->isVisible() && layRicPerOgg->getListaRicOgg()->currentItem() == nullptr) QMessageBox::warning(layRicPerOgg, "Modifica dati", "Non ho nulla da modificare, scegli un oggetto da modificare!");
    else if(layRic->isVisible() && layRic->getCasellaLista()->currentItem() == nullptr) QMessageBox::warning(layRic, "Modifica dati", "Non ho nulla da modificare, scegli un oggetto da modificare!");
    else {
        VideogameOggettiLista* popUp = nullptr;
        const Videogame* ogg = nullptr;
        if(mainwind->isVisible()) {
            popUp = mainwind->getLista()->currentItem();
            ogg = popUp->getOggettoPunt();
        } else if(layRicPerOgg->isVisible()) {
            popUp = layRicPerOgg->getListaRicOgg()->currentItem();
            ogg = popUp->getOggettoPunt();
        } else if(layRic->isVisible()) {
            popUp = layRic->getCasellaLista()->currentItem();
            ogg = popUp->getOggettoPunt();
        }

        //PopUpGenerico* popGen = new PopUpGenerico(parent);
        //popGen->exec(); //faccio in modo che o chiudo Qdialog o non posso fare altro
        popGen->setLayoutHideAndClear();

        //QIcon icona(QString::fromStdString(ogg->getPercorsoImmagine()));
        popGen->setNuovaIcona(ogg->getPercorsoImmagine());
        //popGen->getBottoneModificaFoto()->setIcon(QIcon());
        //popGen->getPopUpVid()->clearQLineEditVideogame();
        //popGen->getBottoneModificaFoto()->clearMask();
        popGen->getPopUpVid()->getTitVideogioco()->insert(QString::fromStdString(ogg->getTitoloVideogioco()));
        ogg->getDisponibile() ? popGen->getPopUpVid()->getDisponibil()->setCurrentIndex(1) : popGen->getPopUpVid()->getDisponibil()->setCurrentIndex(0);
        // !!!!!!!!!!!!!std::string prezzo = (std::to_string(ogg->getPrezzoBase()));
        // !!!!!!!!!!!!!std::replace(prezzo.begin(), prezzo.end(), ',', '.');
        QString prezzo = (QString::fromStdString(std::to_string(ogg->getPrezzoBase())));
        prezzo.replace(QString(","), QString("."));
        popGen->getPopUpVid()->getPrezBase()->insert(prezzo);
        // @@@@@@popGen->getPopUpVid()->getPrezBase()->insert(QString::fromStdString(prezzo));
        popGen->getPopUpVid()->getQuantInStock()->insert(QString::fromStdString(std::to_string(ogg->getQuantitaInStock())));
        popGen->getPopUpVid()->getCasProduttice()->insert(QString::fromStdString(ogg->getCasaProduttrice()));
        popGen->getPopUpVid()->getAnnoPubl()->insert(QString::fromStdString(std::to_string(ogg->getAnnoPubblicazione())));
        popGen->getPopUpVid()->getPeg()->insert(QString::fromStdString(std::to_string(ogg->getPegi())));
        popGen->getPopUpVid()->getGenGioco()->insert(QString::fromStdString(ogg->getGenereGioco()));
        popGen->getPopUpVid()->getTipoDiPiatta()->insert(QString::fromStdString(ogg->getTipoDiPiattaforma()));
        ogg->getApplicaSconto() ? popGen->getPopUpVid()->getAppliSconto()->setCurrentIndex(1) : popGen->getPopUpVid()->getAppliSconto()->setCurrentIndex(0);
        //popGen->setIcona(QString::fromStdString(ogg->getPercorsoImmagine()));
        //popGen->getIcona()->swap(icona); //setThemeName(QString::fromStdString(ogg->getPercorsoImmagine())); //fromTheme(QString::fromStdString(ogg->getPercorsoImmagine())); //addFile(QString::fromStdString(ogg->getPercorsoImmagine()));

        popGen->getPopUpVid()->show();

        if(dynamic_cast<const Key*>(ogg)) {
            const Key* oggKey = static_cast<const Key*>(ogg);
            popGen->setWindowTitle("Key");
            //PopUpDigitalKey* popKey = new PopUpDigitalKey(parent, oggKey);
            //popGen->getPopUpDig()->clearQLineEditDigital();
            popGen->getPopUpDig()->getPiattaRiscattoCodice()->insert(QString::fromStdString(oggKey->getPiattaformaRiscattoCodice()));
            popGen->getPopUpDig()->getCodiceAlfaNum()->insert(QString::fromStdString(oggKey->getCodiceAlfanumerico()));
            popGen->getPopUpDig()->getDescrizioneDigi()->insert(QString::fromStdString(oggKey->getDescrizioneDigital()));
            popGen->getPopUpDig()->show();

            //popGen->getPopUpKey()->clearQLineEditKey();
            popGen->getPopUpKey()->getScontoKeyAnnual()->insert(QString::fromStdString(std::to_string(oggKey->getScontoKeyAnnuale())));
            popGen->getPopUpKey()->show();

            popGen->getContenitorePopUp()->setStretch(4, 1);

            popGen->exec();
            //popGen->show();
        } else if(dynamic_cast<const Dlc*>(ogg)) {
            const Dlc* oggDlc = static_cast<const Dlc*>(ogg);
            popGen->setWindowTitle("Dlc");
            //PopUpDigitalDlc* popDlc = new PopUpDigitalDlc(parent, oggDlc);
            //popGen->getPopUpDig()->clearQLineEditDigital();
            popGen->getPopUpDig()->getPiattaRiscattoCodice()->insert(QString::fromStdString(oggDlc->getPiattaformaRiscattoCodice()));
            popGen->getPopUpDig()->getCodiceAlfaNum()->insert(QString::fromStdString(oggDlc->getCodiceAlfanumerico()));
            popGen->getPopUpDig()->getDescrizioneDigi()->insert(QString::fromStdString(oggDlc->getDescrizioneDigital()));
            popGen->getPopUpDig()->show();

            //popGen->getPopUpDlc()->clearQLineEditDlc();
            popGen->getPopUpDlc()->getNomDlc()->insert(QString::fromStdString(oggDlc->getNomeDlc()));
            popGen->getPopUpDlc()->getScontoDlcAnnual()->insert(QString::fromStdString(std::to_string(oggDlc->getScontoDlc())));
            popGen->getPopUpDlc()->show();

            popGen->getContenitorePopUp()->setStretch(5, 1);

            popGen->exec();
            //popGen->show();
        } else if(dynamic_cast<const CollectorEdition*>(ogg)) {
            const CollectorEdition* oggCEd = static_cast<const CollectorEdition*>(ogg);
            popGen->setWindowTitle("Collector's edition");
            //PopUpCollEdition* popCol = new PopUpCollEdition(parent, oggCEd);
            //popGen->getPopUpPhy()->clearQLineEditPhysical();
            popGen->getPopUpPhy()->getBarCod()->insert(QString::fromStdString(std::to_string(oggCEd->getBarCode())));
            popGen->getPopUpPhy()->getDescrizioneEti()->insert(QString::fromStdString(oggCEd->getDescrizioneEtichetta()));
            popGen->getPopUpPhy()->show();

            //popGen->getPopUpCol()->clearQLineEditCollectosEdition();
            oggCEd->getActionFigure() ? popGen->getPopUpCol()->getActionFig()->setCurrentIndex(1) : popGen->getPopUpCol()->getActionFig()->setCurrentIndex(0);
            popGen->getPopUpCol()->getSovraPrezzoActionFig()->insert(QString::fromStdString(std::to_string(oggCEd->getSovraPrezzoActionFigure())));
            popGen->getPopUpCol()->getScontoCollEdit()->insert(QString::fromStdString(std::to_string(oggCEd->getScontoCollectorEditionAnnuale())));
            popGen->getPopUpCol()->show();

            popGen->getContenitorePopUp()->setStretch(6, 1);

            popGen->exec();
            //popGen->show();
        } else if(dynamic_cast<const Game*>(ogg)) {
            const Game* oggGam = static_cast<const Game*>(ogg);
            popGen->setWindowTitle("Gioco nuovo");
            //PopUpGiocoNuovo* popNuo = new PopUpGiocoNuovo(parent, oggGam);
            popGen->getPopUpPhy()->clearQLineEditPhysical();
            popGen->getPopUpPhy()->getBarCod()->insert(QString::fromStdString(std::to_string(oggGam->getBarCode())));
            popGen->getPopUpPhy()->getDescrizioneEti()->insert(QString::fromStdString(oggGam->getDescrizioneEtichetta()));
            popGen->getPopUpPhy()->show();

            //popGen->getPopUpNuo()->clearQLineEditGiocoNuovo();
            oggGam->getEdizioneLimitata() ? popGen->getPopUpNuo()->getEdizioneLim()->setCurrentIndex(1) : popGen->getPopUpNuo()->getEdizioneLim()->setCurrentIndex(0);
            popGen->getPopUpNuo()->getSovraPrezzoEdizioneLim()->insert(QString::fromStdString(std::to_string(oggGam->getSovraPrezzoEdizioneLimitata())));
            popGen->getPopUpNuo()->getScontoAnnualGam()->insert(QString::fromStdString(std::to_string(oggGam->getScontoGameAnnuale())));
            popGen->getPopUpNuo()->show();

            popGen->getContenitorePopUp()->setStretch(7, 1);

            popGen->exec();
            //popGen->show();
        } else if(dynamic_cast<const SecondHand*>(ogg)) {
            const SecondHand* oggSHa = static_cast<const SecondHand*>(ogg);
            popGen->setWindowTitle("Gioco usato");
            //PopUpGiocoUsato* popUsa = new PopUpGiocoUsato(parent, oggSHa);
            //popGen->getPopUpPhy()->clearQLineEditPhysical();
            popGen->getPopUpPhy()->getBarCod()->insert(QString::fromStdString(std::to_string(oggSHa->getBarCode())));
            popGen->getPopUpPhy()->getDescrizioneEti()->insert(QString::fromStdString(oggSHa->getDescrizioneEtichetta()));
            popGen->getPopUpPhy()->show();

            oggSHa->getScatolaIntegra() ? popGen->getPopUpUsa()->getScatolaInteg()->setCurrentIndex(1) : popGen->getPopUpUsa()->getScatolaInteg()->setCurrentIndex(0);
            popGen->getPopUpUsa()->getSovraPrezzoScatolaInt()->insert(QString::fromStdString(std::to_string(oggSHa->getSovraPrezzoSCatolaIntegra())));
            popGen->getPopUpUsa()->getScontoAnnualSH()->insert(QString::fromStdString(std::to_string(oggSHa->getScontoSecondHandAnnuale())));
            popGen->getPopUpUsa()->show();

            popGen->getContenitorePopUp()->setStretch(8, 1);

            popGen->exec();
            //popGen->show();
        }
    }
}

void Controller::aggiungiElementoAllaLista() {

    Container<Videogame*>::constiterator aux = model->cBegin(); //da qui
    Container<Videogame*>::constiterator auxEnd = model->cEnd();
    std::string titoloVideogioco = layIns->getLayoutInserisciVideogame()->getTitVideogioco()->text().toStdString();
    std::string casaProduttrice = layIns->getLayoutInserisciVideogame()->getCasProduttice()->text().toStdString();
    unsigned int annoDiPubbicazione = layIns->getLayoutInserisciVideogame()->getAnnoPubl()->text().toUInt();
    std::string genereGioco = layIns->getLayoutInserisciVideogame()->getGenGioco()->text().toStdString();

    bool trovatoDoppione = false;
    std::string tipoOggettoTrovato = "";
    unsigned int oggettiInStock = 0; //aggiunto dopo

    int index = layIns->getSceltaDerivate()->currentIndex();
    if(index != 0) {
        switch(index) {
        case 1: {
            for( ; aux != auxEnd; ++aux) {
                if((*aux)->getTipologiaProdotto() == "Key" && (*aux)->getTitoloVideogioco() == titoloVideogioco && (*aux)->getCasaProduttrice() == casaProduttrice && (*aux)->getAnnoPubblicazione() == annoDiPubbicazione && (*aux)->getGenereGioco() == genereGioco) {
                    trovatoDoppione = true;
                    tipoOggettoTrovato = (*aux)->getTipologiaProdotto();
                }
                oggettiInStock += (*aux)->getQuantitaInStock();
            }
        }
        break;

        case 2: {
            for( ; aux != auxEnd; ++aux) {
                if((*aux)->getTipologiaProdotto() == "Dlc" && (*aux)->getTitoloVideogioco() == titoloVideogioco && (*aux)->getCasaProduttrice() == casaProduttrice && (*aux)->getAnnoPubblicazione() == annoDiPubbicazione && (*aux)->getGenereGioco() == genereGioco) {
                    trovatoDoppione = true;
                    tipoOggettoTrovato = (*aux)->getTipologiaProdotto();
                }
                oggettiInStock += (*aux)->getQuantitaInStock();
            }
        }
        break;

        case 3: {
            for( ; aux != auxEnd; ++aux) {
                if((*aux)->getTipologiaProdotto() == "CollectorEdition" && (*aux)->getTitoloVideogioco() == titoloVideogioco && (*aux)->getCasaProduttrice() == casaProduttrice && (*aux)->getAnnoPubblicazione() == annoDiPubbicazione && (*aux)->getGenereGioco() == genereGioco) {
                    trovatoDoppione = true;
                    tipoOggettoTrovato = (*aux)->getTipologiaProdotto();
                }
                oggettiInStock += (*aux)->getQuantitaInStock();
            }
        }
        break;

        case 4: {
            for( ; aux != auxEnd; ++aux) {
                if((*aux)->getTipologiaProdotto() == "GiocoNuovo" && (*aux)->getTitoloVideogioco() == titoloVideogioco && (*aux)->getCasaProduttrice() == casaProduttrice && (*aux)->getAnnoPubblicazione() == annoDiPubbicazione && (*aux)->getGenereGioco() == genereGioco) {
                    trovatoDoppione = true;
                    tipoOggettoTrovato = (*aux)->getTipologiaProdotto();
                }
                oggettiInStock += (*aux)->getQuantitaInStock();
            }
        }
        break;

        case 5: {
            for( ; aux != auxEnd; ++aux) {
                if((*aux)->getTipologiaProdotto() == "GiocoUsato" && (*aux)->getTitoloVideogioco() == titoloVideogioco && (*aux)->getCasaProduttrice() == casaProduttrice && (*aux)->getAnnoPubblicazione() == annoDiPubbicazione && (*aux)->getGenereGioco() == genereGioco) {
                    trovatoDoppione = true;
                    tipoOggettoTrovato = (*aux)->getTipologiaProdotto();
                }
                oggettiInStock += (*aux)->getQuantitaInStock();
            }
        }
        break;

        }
        //for( ; aux != auxEnd && !trovatoDoppione; ++aux) {
        //    if((*aux)->getTitoloVideogioco() == titoloVideogioco && (*aux)->getCasaProduttrice() == casaProduttrice && (*aux)->getAnnoPubblicazione() == annoDiPubbicazione && (*aux)->getGenereGioco() == genereGioco) trovatoDoppione = true;
        //}
    }
    if(!trovatoDoppione && index != 0) { //a qui aggiunto dopo
        if(/*index != 0 &&*/ titoloVideogioco != "" && casaProduttrice != "" && annoDiPubbicazione != 0 && genereGioco != "") { // fatto modifica dopo
            Videogame* nuovoElemento = nullptr;

            //std::string titoloVideogioco = layIns->getLayoutInserisciVideogame()->getTitVideogioco()->text().toStdString();
            bool disponibile = false;
            layIns->getLayoutInserisciVideogame()->getDisponibil()->currentIndex() ? disponibile = true : disponibile = false;
            //ho appena fatto modifiche@@@
            QString prezzo = layIns->getLayoutInserisciVideogame()->getPrezBase()->text();
            prezzo.replace(QString(","), QString("."));
            double prezBase = prezzo.toDouble();
            //devo modifcare anche qui attenzione!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            unsigned int quantitaInStock = layIns->getLayoutInserisciVideogame()->getQuantInStock()->text().toUInt();
            if(quantitaInStock + oggettiInStock > nuovoElemento->getCapienzaMassimaMagazzino()) { quantitaInStock = nuovoElemento->getCapienzaMassimaMagazzino() - oggettiInStock; }//aggiunto dopo
            //std::string casaProduttrice = layIns->getLayoutInserisciVideogame()->getCasProduttice()->text().toStdString();
            //unsigned int annoDiPubbicazione = layIns->getLayoutInserisciVideogame()->getAnnoPubl()->text().toUInt();
            unsigned int pegi = layIns->getLayoutInserisciVideogame()->getPeg()->text().toUInt();
            //std::string genereGioco = layIns->getLayoutInserisciVideogame()->getGenGioco()->text().toStdString();
            std::string tipoPiattaforma = layIns->getLayoutInserisciVideogame()->getTipoDiPiatta()->text().toStdString();
            bool applicaLoSconto = false;
            layIns->getLayoutInserisciVideogame()->getAppliSconto()->currentIndex() ? applicaLoSconto = true : applicaLoSconto = false;
            std::string percorsoImmagine = layIns->getIcona().toStdString();

            if(index == 1) {
                std::string piattaRiscattoCodice = layIns->getLayoutInserisciDigital()->getPiattaRiscattoCodice()->text().toStdString();
                std::string codiceAlfaNum = layIns->getLayoutInserisciDigital()->getCodiceAlfaNum()->text().toStdString();
                std::string descrizioneDigi = layIns->getLayoutInserisciDigital()->getDescrizioneDigi()->text().toStdString();

                unsigned int scontoAnnKey = layIns->getLayoutInserisciKey()->getScontoKeyAnnual()->text().toUInt();

                nuovoElemento = new Key(titoloVideogioco, disponibile, prezBase, quantitaInStock, casaProduttrice, annoDiPubbicazione, pegi, genereGioco, tipoPiattaforma, applicaLoSconto, percorsoImmagine, piattaRiscattoCodice, codiceAlfaNum, descrizioneDigi, scontoAnnKey);

            } else if(index == 2) {
                std::string piattaRiscattoCodice = layIns->getLayoutInserisciDigital()->getPiattaRiscattoCodice()->text().toStdString();
                std::string codiceAlfaNum = layIns->getLayoutInserisciDigital()->getCodiceAlfaNum()->text().toStdString();
                std::string descrizioneDigi = layIns->getLayoutInserisciDigital()->getDescrizioneDigi()->text().toStdString();

                std::string nomDlc = layIns->getLayoutInserisciDlc()->getNomDlc()->text().toStdString();
                unsigned int scontoAnnDlc = layIns->getLayoutInserisciDlc()->getScontoDlcAnnual()->text().toUInt();

                nuovoElemento = new Dlc(titoloVideogioco, disponibile, prezBase, quantitaInStock, casaProduttrice, annoDiPubbicazione, pegi, genereGioco, tipoPiattaforma, applicaLoSconto, percorsoImmagine, piattaRiscattoCodice, codiceAlfaNum, descrizioneDigi, nomDlc, scontoAnnDlc);

            } else if(index == 3) {
                unsigned int barcode = layIns->getLayoutInserisciPhysical()->getBarCod()->text().toUInt();
                std::string descrizioneFisica = layIns->getLayoutInserisciPhysical()->getDescrizioneEti()->text().toStdString();

                bool actionFigure = false;
                layIns->getLayoutInserisciCollectorsEdition()->getActionFig()->currentIndex() ? actionFigure = true : actionFigure = false;
                unsigned int sovraActionFigure = layIns->getLayoutInserisciCollectorsEdition()->getSovraPrezzoActionFig()->text().toUInt();
                unsigned int scontoAnnColEd = layIns->getLayoutInserisciCollectorsEdition()->getScontoCollEdit()->text().toUInt();

                nuovoElemento = new CollectorEdition(titoloVideogioco, disponibile, prezBase, quantitaInStock, casaProduttrice, annoDiPubbicazione, pegi, genereGioco, tipoPiattaforma, applicaLoSconto, percorsoImmagine, barcode, descrizioneFisica, actionFigure, sovraActionFigure, scontoAnnColEd);

            } else if(index == 4) {
                unsigned int barcode = layIns->getLayoutInserisciPhysical()->getBarCod()->text().toUInt();
                std::string descrizioneFisica = layIns->getLayoutInserisciPhysical()->getDescrizioneEti()->text().toStdString();

                bool ediLim = false;
                layIns->getLayoutInserisciGiocoNuovo()->getEdizioneLim()->currentIndex() ? ediLim = true : ediLim = false;
                unsigned int sovraEdiLim = layIns->getLayoutInserisciGiocoNuovo()->getSovraPrezzoEdizioneLim()->text().toUInt();
                unsigned int scontoAnnGam = layIns->getLayoutInserisciGiocoNuovo()->getScontoAnnualGam()->text().toUInt();

                nuovoElemento = new Game(titoloVideogioco, disponibile, prezBase, quantitaInStock, casaProduttrice, annoDiPubbicazione, pegi, genereGioco, tipoPiattaforma, applicaLoSconto, percorsoImmagine, barcode, descrizioneFisica, ediLim, sovraEdiLim, scontoAnnGam);

            } else if(index == 5) {
                unsigned int barcode = layIns->getLayoutInserisciPhysical()->getBarCod()->text().toUInt();
                std::string descrizioneFisica = layIns->getLayoutInserisciPhysical()->getDescrizioneEti()->text().toStdString();

                bool scatolaInt = false;
                layIns->getLayoutInserisciGiocoUsato()->getScatolaInteg()->currentIndex() ? scatolaInt = true : scatolaInt = false;
                unsigned int sovraScaInt = layIns->getLayoutInserisciGiocoUsato()->getSovraPrezzoScatolaInt()->text().toUInt();
                unsigned int scontoAnnSec = layIns->getLayoutInserisciGiocoUsato()->getScontoAnnualSH()->text().toUInt();

                nuovoElemento = new SecondHand(titoloVideogioco, disponibile, prezBase, quantitaInStock, casaProduttrice, annoDiPubbicazione, pegi, genereGioco, tipoPiattaforma, applicaLoSconto, percorsoImmagine, barcode, descrizioneFisica, scatolaInt, sovraScaInt, scontoAnnSec);

            }

            if(nuovoElemento != nullptr /*&& titoloVideogioco != "" && casaProduttrice != "" && annoDiPubbicazione != 0 && genereGioco != ""*/) {// fare && titolovid != "" ecc per i campi che voglio
                model->inserisciInFine(nuovoElemento);
                //delete nuovoElemento;
                model->salvataggioDatiXML();
                caricaDati();
                QMessageBox::information(this, "Operazione riuscita", "Il nuovo prodotto è stato aggiunto nel tuo negozio!");
                metMainWindow();
            } /*else {
                if(titoloVideogioco == "") { QMessageBox::warning(parent, "Attenzione", "Inserisci titolo videogioco"); }
                else if(casaProduttrice == "") { QMessageBox::warning(parent, "Attenzione", "Inserisci casa produttrice"); }
                else if(annoDiPubbicazione == 0) { QMessageBox::warning(parent, "Attenzione", "Inserisci anno di pubblicazione"); }
                else if(genereGioco == "") { QMessageBox::warning(parent, "Attenzione", "Inserisci genere gioco"); }*/
        } else {
            if(titoloVideogioco == "") { QMessageBox::warning(parent, "Attenzione", "Inserisci titolo videogioco"); }
            else if(casaProduttrice == "") { QMessageBox::warning(parent, "Attenzione", "Inserisci casa produttrice"); }
            else if(annoDiPubbicazione == 0) { QMessageBox::warning(parent, "Attenzione", "Inserisci anno di pubblicazione"); }
            else if(genereGioco == "") { QMessageBox::warning(parent, "Attenzione", "Inserisci genere gioco"); }
        }
    } else {
        if(index == 0 && !trovatoDoppione) { QMessageBox::warning(this, "Attenzione", "Non hai inserito nessun elemento!"); }
        else {
            Container<Videogame*>::iterator inizio = model->Begin(); //da qui
            Container<Videogame*>::iterator fine = model->End();
            bool riTrovatoDoppione = false;
            for( ; inizio != fine && !riTrovatoDoppione; ++inizio) {
                if((*inizio)->getTipologiaProdotto() == tipoOggettoTrovato && (*inizio)->getTitoloVideogioco() == titoloVideogioco && (*inizio)->getCasaProduttrice() == casaProduttrice && (*inizio)->getAnnoPubblicazione() == annoDiPubbicazione && (*inizio)->getGenereGioco() == genereGioco) {
                    (*inizio)->setAggiungiSeEsistente(layIns->getLayoutInserisciVideogame()->getQuantInStock()->text().toUInt(), oggettiInStock, (*inizio)->getQuantitaInStock());
                    riTrovatoDoppione = true;
                }
            }
            model->salvataggioDatiXML();
            caricaDati();
            metMainWindow();
            QMessageBox::warning(this, "Attenzione", "È stata aggiornata la quantità in stock di un prodotto identico in magazzino!");
        }
    }
}

void Controller::rimuoviDallaListaContainer() {
    VideogameOggettiLista* popUp = nullptr;
    Videogame* ogg = nullptr;
    if(mainwind->isVisible() && mainwind->getLista()->currentItem() != nullptr) {
        popUp = mainwind->getLista()->currentItem();
        ogg = popUp->getOggettoPunt();
    } else if(layRicPerOgg->isVisible() && layRicPerOgg->getListaRicOgg()->currentItem() != nullptr) {
        popUp = layRicPerOgg->getListaRicOgg()->currentItem();
        ogg = popUp->getOggettoPunt();
    } else if(layRic->isVisible() && layRic->getCasellaLista()->currentItem() != nullptr) {
        popUp = layRic->getCasellaLista()->currentItem();
        ogg = popUp->getOggettoPunt();
    }

    if(popUp != nullptr && ogg != nullptr) {
        model->rimuoviElementoDallaLista(ogg);
        model->salvataggioDatiXML();
        caricaDati();
        QMessageBox::information(parent, "Operazione riuscita", "Il prodotto è stato eliminato dal tuo negozio correttamente!");
    } else {
        QMessageBox::warning(parent, "Operazione non riuscita", "Attenzione non è selezionato alcun prodotto da eliminare!");
    }
}

void Controller::ricercaOggetto() const {
    layRicPerOgg->getListaRicOgg()->clear();
    std::string titoloVideogioco = layRicPerOgg->getLineTitoloVideogioco()->text().toStdString();
    std::string casaProduttrice = layRicPerOgg->getLineCasaProduttrice()->text().toStdString();
    unsigned int annoPubblicazione = layRicPerOgg->getLineAnnoPubblicazione()->text().toUInt();
    std::string genereGioco = layRicPerOgg->getLineGenereGioco()->text().toStdString();
    int index = layRicPerOgg->getSceltaDerivateRic()->currentIndex();
    if(index != 0 && titoloVideogioco != "" && casaProduttrice != "" && annoPubblicazione != 0 && genereGioco != "") {
        switch(index) {
          case 1: {
              Key* oggKey = new Key(titoloVideogioco, false, 0, 0, casaProduttrice, annoPubblicazione, 0, genereGioco);
              Key* nuovo = static_cast<Key*>(model->ricercaPerPuntatori(oggKey));
              if(nuovo != nullptr) {
                  layRicPerOgg->getListaRicOgg()->aggiungiVideogioco(nuovo);
                  QMessageBox::information(parent, "Informazione", "La ricerca ha avuto successo!");
              }
              else { QMessageBox::warning(parent, "Attenzione", "Oggetto non trovato in negozio!"); }
              delete oggKey;
          }
          break;

          case 2: {
              Dlc* oggDlc = new Dlc(titoloVideogioco, false, 0, 0, casaProduttrice, annoPubblicazione, 0, genereGioco);
              Dlc* nuovo = static_cast<Dlc*>(model->ricercaPerPuntatori(oggDlc));
              if(nuovo != nullptr) {
                  layRicPerOgg->getListaRicOgg()->aggiungiVideogioco(nuovo);
                  QMessageBox::information(parent, "Informazione", "La ricerca ha avuto successo!");
              }
              else { QMessageBox::warning(parent, "Attenzione", "Oggetto non trovato in negozio!"); }
              delete oggDlc;
          }
          break;

          case 3: {
              CollectorEdition* oggCle = new CollectorEdition(titoloVideogioco, false, 0, 0, casaProduttrice, annoPubblicazione, 0, genereGioco);
              CollectorEdition* nuovo = static_cast<CollectorEdition*>(model->ricercaPerPuntatori(oggCle));
              if(nuovo != nullptr) {
                  layRicPerOgg->getListaRicOgg()->aggiungiVideogioco(nuovo);
                  QMessageBox::information(parent, "Informazione", "La ricerca ha avuto successo!");
              }
              else { QMessageBox::warning(parent, "Attenzione", "Oggetto non trovato in negozio!"); }
              delete oggCle;
          }
          break;

          case 4: {
              Game* oggGam = new Game(titoloVideogioco, false, 0, 0, casaProduttrice, annoPubblicazione, 0, genereGioco);
              Game* nuovo = static_cast<Game*>(model->ricercaPerPuntatori(oggGam));
              if(nuovo != nullptr) {
                  layRicPerOgg->getListaRicOgg()->aggiungiVideogioco(nuovo);
                  QMessageBox::information(parent, "Informazione", "La ricerca ha avuto successo!");
              }
              else { QMessageBox::warning(parent, "Attenzione", "Oggetto non trovato in negozio!"); }
              delete oggGam;
          }
          break;

          case 5: {
            SecondHand* oggSec = new SecondHand(titoloVideogioco, false, 0, 0, casaProduttrice, annoPubblicazione, 0, genereGioco);
            SecondHand* nuovo = static_cast<SecondHand*>(model->ricercaPerPuntatori(oggSec));
            if(nuovo != nullptr) {
                layRicPerOgg->getListaRicOgg()->aggiungiVideogioco(nuovo);
                QMessageBox::information(parent, "Informazione", "La ricerca ha avuto successo!");
            }
            else { QMessageBox::warning(parent, "Attenzione", "Oggetto non trovato in negozio!"); }
            delete oggSec;
          }
          break;

        }
    } else {
        if(titoloVideogioco == "") {
            QMessageBox::warning(parent, "Titolo videogioco", "Inserire titolo videogioco!");
        } else if(casaProduttrice == "") {
            QMessageBox::warning(parent, "Casa produttrice", "Inserire casa produttrice!");
        } else if(annoPubblicazione < 1958) {
            QMessageBox::warning(parent, "Anno di pubblicazione", "Inserire anno di publicazione maggiore di 1958!");
        } else if(genereGioco == "") {
            QMessageBox::warning(parent, "Genere gioco", "Inserire genere gioco!");
        }
    }
}

void Controller::ricercaOggettoPerStringa() const {
    std::string confronta = layRic->getBarraRicerca()->text().toStdString();
    if(confronta != ""){
        layRic->getCasellaLista()->clear();
        bool oggettiTrovato = false;
        Container<Videogame*>::constiterator aux = model->cBegin();
        Container<Videogame*>::constiterator auxEnd = model->cEnd();
        for( ; aux != auxEnd; ++aux) {
            if((*aux)->ricercaPerStringa(confronta)) {
                layRic->getCasellaLista()->aggiungiVideogioco(*aux);
                if(!oggettiTrovato) oggettiTrovato = true;
            }
        }
        if(oggettiTrovato) QMessageBox::information(parent, "Informazione", "La ricerca ha avuto successo!");
        else QMessageBox::warning(parent, "Informazione", "Non sono stati trovati prodotti corrispondenti alla ricerca");
    } else {
        QMessageBox::warning(parent, "Attenzione", "Scrivere qualcosa nel campo di ricerca");
    }
}

void Controller::controlloNumeroElementiListaMessageBox() const {
    QString prima;
    QString seconda;
    if(file != "") { //presente funzione nel container che dice se container vuoto o meno;
        Container<Videogame*>::constiterator aux = model->cBegin();
        Container<Videogame*>::constiterator auxEnd = model->cEnd();
        unsigned int numEle = model->numeroElementiInNegozio();
        unsigned int keyStock = 0;
        unsigned int dlcStock = 0;
        unsigned int colStock = 0;
        unsigned int nuoStock = 0;
        unsigned int usaStock = 0;
        unsigned int capienzaNegozio = (*aux)->getCapienzaMassimaMagazzino();
        unsigned int quantTot = 0;
        prima = "Elementi nel negozio: ";
        seconda = "Nel negozio sono presenti %1 videogiochi di tipo diverso. Di questi videogiochi abbiamo le seguenti quantità:";
        seconda = seconda.arg(numEle);
        for( ; aux != auxEnd; ++aux) {
            quantTot += (*aux)->getQuantitaInStock();
            if((*aux)->getTipologiaProdotto() == "Key") keyStock += (*aux)->getQuantitaInStock();
            else if((*aux)->getTipologiaProdotto() == "Dlc") dlcStock += (*aux)->getQuantitaInStock();
            else if((*aux)->getTipologiaProdotto() == "CollectorEdition") colStock += (*aux)->getQuantitaInStock();
            else if((*aux)->getTipologiaProdotto() == "GiocoNuovo") nuoStock += (*aux)->getQuantitaInStock();
            else if((*aux)->getTipologiaProdotto() == "GiocoUsato") usaStock += (*aux)->getQuantitaInStock();
        }
        seconda.append(QString::fromStdString("\n - " + std::to_string(keyStock) + " sono key;"))
                .append(QString::fromStdString("\n - " + std::to_string(dlcStock) + " sono dlc;"))
                .append(QString::fromStdString("\n - " + std::to_string(colStock) + " sono collector's edition;"))
                .append(QString::fromStdString("\n - " + std::to_string(nuoStock) + " sono giochi nuovi;"))
                .append(QString::fromStdString("\n - " + std::to_string(usaStock) + " sono giochi usati;"))
                .append(QString::fromStdString("\nCapienza massima magazzino di " + std::to_string(capienzaNegozio) + " pezzi."))
                .append(QString::fromStdString("\nPosti occupati: " + std::to_string(quantTot)))
                .append(QString::fromStdString("\nPosti rimanenti: " + std::to_string(capienzaNegozio - quantTot)));
    } else {
        prima = "Attenzione!";
        seconda = "Non sono presenti prodotti nel negozio, aggiungi un prodotto";
    }
    QMessageBox::information(parent, prima, seconda);
}

void Controller::informazioniQMessage() const { QMessageBox::about(parent, "Informazioni", "Questo programma è stato creato da Daniele Larosa. Num. matricola: 1097821."); }

void Controller::riportaBugQmessage() const { QMessageBox::about(parent, "Riporta bug", "Per riportare un bug scrivere all'email daniele.larosa@studenti.unipd.it"); }
