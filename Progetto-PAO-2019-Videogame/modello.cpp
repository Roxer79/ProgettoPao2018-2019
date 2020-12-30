#include "modello.h"
#include "GUI/fileeccezioniprintaschermo.h"

Modello::Modello(std::string per):
    negozio(new Container<Videogame*>),
    percorsoXML(per),
    salvaSeModifica(true) {}

Modello::~Modello() {
    delete negozio;
}

std::string Modello::getPercorsoXML() const { return  percorsoXML; }

bool Modello::getSalvaSeModifica() const { return salvaSeModifica; }

void Modello::setSalvaSeModifica(bool b) { salvaSeModifica = b; }

Container<Videogame*>::iterator Modello::Begin() const { return negozio->it_Begin(); }

Container<Videogame*>::iterator Modello::End() const { return  negozio->it_End(); }

Container<Videogame*>::constiterator Modello::cBegin() const { return negozio->cit_Begin(); }

Container<Videogame*>::constiterator Modello::cEnd() const { return negozio->cit_End(); }

//void Modello::inserisci(Videogame* info, Videogame* prev, Videogame* next) { negozio->insertLibero(info, prev, next); }

void Modello::inserisciAdInizio(Videogame* nuovo) { negozio->insertInFront(nuovo); }

void Modello::inserisciInFine(Videogame* nuovo) { negozio->insertInBack(nuovo); }

Videogame* Modello::ricercaPerPuntatori(Videogame* daCercare) const { return negozio->ricercaContainerPuntatori(daCercare); }

void Modello::settaNuovoPercorsoFileXML(std::string p){
    percorsoXML = p;
    delete negozio;
    salvaSeModifica = false;
    negozio = new Container<Videogame*>();
}

void Modello::salvataggioDatiXML() {
    QSaveFile fileSalvataggio(QString::fromStdString(percorsoXML));

    if(!fileSalvataggio.open(QIODevice::WriteOnly)) {
        //qWarning() << "problemi";
        throw FileEccezioniPrintSchermo("Errore");
    }

    QXmlStreamWriter scriviSuFile(&fileSalvataggio);

    scriviSuFile.setAutoFormatting(true);
    scriviSuFile.writeStartDocument();
    scriviSuFile.writeComment("!!!Questo file NON deve essere modificato!!!");

    scriviSuFile.writeStartElement("root");

    auto cit = cBegin();
    while(cit != cEnd()) {

        const Videogame* nuovoSalvataggio = *cit;
        const QString tipoDaSalvare = QString::fromStdString(nuovoSalvataggio->getTipologiaProdotto());
        scriviSuFile.writeEmptyElement(tipoDaSalvare);

        scriviSuFile.writeAttribute("titoloVideogioco", QString::fromStdString(nuovoSalvataggio->getTitoloVideogioco()));
        scriviSuFile.writeAttribute("disponibile", nuovoSalvataggio->getDisponibile() ? "Si" : "No");
        scriviSuFile.writeAttribute("prezzoBase", QString("%1").arg(nuovoSalvataggio->getPrezzoBase()));
        scriviSuFile.writeAttribute("quantitaInStock", QString("%1").arg(nuovoSalvataggio->getQuantitaInStock()));
        scriviSuFile.writeAttribute("casaProduttrice", QString::fromStdString(nuovoSalvataggio->getCasaProduttrice()));
        scriviSuFile.writeAttribute("annoPubblicazione", QString("%1").arg(nuovoSalvataggio->getAnnoPubblicazione()));
        scriviSuFile.writeAttribute("pegi", QString("%1").arg(nuovoSalvataggio->getPegi()));
        scriviSuFile.writeAttribute("genereGioco", QString::fromStdString(nuovoSalvataggio->getGenereGioco()));
        scriviSuFile.writeAttribute("tipoDiPiattaforma", QString::fromStdString(nuovoSalvataggio->getTipoDiPiattaforma()));
        scriviSuFile.writeAttribute("applicaSconto", nuovoSalvataggio->getApplicaSconto() ? "Si" : "No");
        scriviSuFile.writeAttribute("percorsoImmagine", QString::fromStdString(nuovoSalvataggio->getPercorsoImmagine()));

        if(tipoDaSalvare == "Key") {
            const Key* salvaKey = static_cast<const Key*>(nuovoSalvataggio);

            scriviSuFile.writeAttribute("piattaformaRiscattoCodice", QString::fromStdString(salvaKey->getPiattaformaRiscattoCodice()));
            scriviSuFile.writeAttribute("codiceAlfanumerico", QString::fromStdString(salvaKey->getCodiceAlfanumerico()));
            scriviSuFile.writeAttribute("descrizioneDigital", QString::fromStdString(salvaKey->getDescrizioneDigital()));
            scriviSuFile.writeAttribute("scontoKeyAnnuale", QString("%1").arg(salvaKey->getScontoKeyAnnuale()));
        }
        else if(tipoDaSalvare == "Dlc") {
            const Dlc* salvaDlc = static_cast<const Dlc*>(nuovoSalvataggio);

            scriviSuFile.writeAttribute("piattaformaRiscattoCodice", QString::fromStdString(salvaDlc->getPiattaformaRiscattoCodice()));
            scriviSuFile.writeAttribute("codiceAlfanumerico", QString::fromStdString(salvaDlc->getCodiceAlfanumerico()));
            scriviSuFile.writeAttribute("descrizioneDigital", QString::fromStdString(salvaDlc->getDescrizioneDigital()));
            scriviSuFile.writeAttribute("nomeDlc", QString::fromStdString(salvaDlc->getNomeDlc()));
            scriviSuFile.writeAttribute("scontoDlcAnnuale", QString("%1").arg(salvaDlc->getScontoDlc()));
        }
        else if(tipoDaSalvare == "CollectorEdition") {
            const CollectorEdition* salvaColEdit = static_cast<const CollectorEdition*>(nuovoSalvataggio);

            scriviSuFile.writeAttribute("barCode", QString("%1").arg(salvaColEdit->getBarCode()));
            scriviSuFile.writeAttribute("descrizioneEtichetta", QString::fromStdString(salvaColEdit->getDescrizioneEtichetta()));
            scriviSuFile.writeAttribute("actionFigure", salvaColEdit->getActionFigure() ? "Si" : "No");
            scriviSuFile.writeAttribute("sovraPrezzoActionFigure", QString("%1").arg(salvaColEdit->getSovraPrezzoActionFigure()));
            scriviSuFile.writeAttribute("scontoCollectorEditionAnnuale", QString("%1").arg(salvaColEdit->getScontoCollectorEditionAnnuale()));
        }
        else if(tipoDaSalvare == "GiocoNuovo") {
            const Game* salvaGame = static_cast<const Game*>(nuovoSalvataggio);

            scriviSuFile.writeAttribute("barCode", QString("%1").arg(salvaGame->getBarCode()));
            scriviSuFile.writeAttribute("descrizioneEtichetta", QString::fromStdString(salvaGame->getDescrizioneEtichetta()));
            scriviSuFile.writeAttribute("edizioneLimitata", salvaGame->getEdizioneLimitata() ? "Si" : "No");
            scriviSuFile.writeAttribute("sovraPrezzoEdizioneLimitata", QString("%1").arg(salvaGame->getSovraPrezzoEdizioneLimitata()));
            scriviSuFile.writeAttribute("scontoGameAnnuale", QString("%1").arg(salvaGame->getScontoGameAnnuale()));
        }
        else if(tipoDaSalvare == "GiocoUsato") {
            const SecondHand* salvaSecHan = static_cast<const SecondHand*>(nuovoSalvataggio);

            scriviSuFile.writeAttribute("barCode", QString("%1").arg(salvaSecHan->getBarCode()));
            scriviSuFile.writeAttribute("descrizioneEtichetta", QString::fromStdString(salvaSecHan->getDescrizioneEtichetta()));
            scriviSuFile.writeAttribute("scatolaIntegra", salvaSecHan->getScatolaIntegra() ? "Si" : "No");
            scriviSuFile.writeAttribute("sovraPrezzoScatolaIntegra", QString("%1").arg(salvaSecHan->getSovraPrezzoSCatolaIntegra()));
            scriviSuFile.writeAttribute("scontoSecondHandAnnuale", QString("%1").arg(salvaSecHan->getScontoSecondHandAnnuale()));
        }

        if(scriviSuFile.hasError()) throw std::exception();
        delete *cit; //aggiunto dopo non c'è nel progetto originale
        ++cit;
    }
    scriviSuFile.writeEndElement();
    scriviSuFile.writeEndDocument();
    salvaSeModifica = true;
    fileSalvataggio.commit();
}

void Modello::caricaXML() {

    QFile fileXML(QString::fromStdString(percorsoXML));

    /*if(!fileXML.open(QIODevice::ReadOnly)) {
            qWarning() << "Non è stato possibile aprire il file" << fileXML.errorString();
            return ;
        }*/

    if(!fileXML.open(QIODevice::ReadOnly)) throw FileEccezioniPrintSchermo("Errore caricamento del file");

    QXmlStreamReader letturaXML(&fileXML);

    if(letturaXML.readNextStartElement()) {
        if(letturaXML.name() == "root") { //da fare
            while(letturaXML.readNextStartElement()){
                const QXmlStreamAttributes attributiXML = letturaXML.attributes();

                std::string titoloVideogioco = attributiXML.hasAttribute("titoloVideogioco") ? attributiXML.value("titoloVideogioco").toString().toStdString() : "";
                bool disponibile = attributiXML.hasAttribute("disponibile") ? attributiXML.value("disponibile").toString() == "Si" ? true : false : false;
                double prezzoBase = attributiXML.hasAttribute("prezzoBase") ? attributiXML.value("prezzoBase").toDouble() : 0;
                unsigned int quantitaInStock = attributiXML.hasAttribute("quantitaInStock") ? attributiXML.value("quantitaInStock").toUInt() : 0;
                std::string casaProduttrice = attributiXML.hasAttribute("casaProduttrice") ? attributiXML.value("casaProduttrice").toString().toStdString() : "";
                unsigned int annoPubblicazione = attributiXML.hasAttribute("annoPubblicazione") ? attributiXML.value("annoPubblicazione").toUInt() : 0;
                unsigned int pegi = attributiXML.hasAttribute("pegi") ? attributiXML.value("pegi").toUInt() : 0;
                std::string genereGioco = attributiXML.hasAttribute("genereGioco") ? attributiXML.value("genereGioco").toString().toStdString() : "";
                std::string tipoDiPiattaforma = attributiXML.hasAttribute("tipoDiPiattaforma") ? attributiXML.value("tipoDiPiattaforma").toString().toStdString() : "";
                bool applicaSconto = attributiXML.hasAttribute("applicaSconto") ? attributiXML.value("applicaSconto").toString() == "Si" ? true : false : false;
                std::string percorsoImmagine = attributiXML.hasAttribute("percorsoImmagine") ? attributiXML.value("percorsoImmagine").toString().toStdString() : "";

                Videogame* daButtareDentro = nullptr;

                if(letturaXML.name() == "Key") {
                    std::string piattaformaRiscattoCodice = attributiXML.hasAttribute("piattaformaRiscattoCodice") ? attributiXML.value("piattaformaRiscattoCodice").toString().toStdString() : "";
                    std::string codiceAlfanumerico = attributiXML.hasAttribute("codiceAlfanumerico") ? attributiXML.value("codiceAlfanumerico").toString().toStdString() : "";
                    std::string descrizioneDigital = attributiXML.hasAttribute("descrizioneDigital") ? attributiXML.value("descrizioneDigital").toString().toStdString() : "";
                    unsigned int scontoKeyAnnuale = attributiXML.hasAttribute("scontoKeyAnnuale") ? attributiXML.value("scontoKeyAnnuale").toUInt() : 0;

                    daButtareDentro = new Key(titoloVideogioco, disponibile, prezzoBase, quantitaInStock, casaProduttrice, annoPubblicazione, pegi, genereGioco, tipoDiPiattaforma, applicaSconto, percorsoImmagine, piattaformaRiscattoCodice, codiceAlfanumerico, descrizioneDigital, scontoKeyAnnuale);
                }
                else if(letturaXML.name() == "Dlc") {
                    std::string piattaformaRiscattoCodice = attributiXML.hasAttribute("piattaformaRiscattoCodice") ? attributiXML.value("piattaformaRiscattoCodice").toString().toStdString() : "";
                    std::string codiceAlfanumerico = attributiXML.hasAttribute("codiceAlfanumerico") ? attributiXML.value("codiceAlfanumerico").toString().toStdString() : "";
                    std::string descrizioneDigital = attributiXML.hasAttribute("descrizioneDigital") ? attributiXML.value("descrizioneDigital").toString().toStdString() : "";
                    std::string nomeDlc = attributiXML.hasAttribute("nomeDlc") ? attributiXML.value("nomeDlc").toString().toStdString() : "";
                    unsigned int scontoDlcAnnuale = attributiXML.hasAttribute("scontoDlcAnnuale") ? attributiXML.value("scontoDlcAnnuale").toUInt() : 0;

                    daButtareDentro = new Dlc(titoloVideogioco, disponibile, prezzoBase, quantitaInStock, casaProduttrice, annoPubblicazione, pegi, genereGioco, tipoDiPiattaforma, applicaSconto, percorsoImmagine, piattaformaRiscattoCodice, codiceAlfanumerico, descrizioneDigital, nomeDlc, scontoDlcAnnuale);
                }
                else if(letturaXML.name() == "CollectorEdition") {
                    unsigned int barCode = attributiXML.hasAttribute("barCode") ? attributiXML.value("barCode").toUInt() : 0;
                    std::string descrizioneEtichetta = attributiXML.hasAttribute("descrizioneEtichetta") ? attributiXML.value("descrizioneEtichetta").toString().toStdString() : "";
                    bool actionFigure = attributiXML.hasAttribute("actionFigure") ? attributiXML.value("actionFigure").toString() == "Si" ? true : false : false;
                    unsigned int sovraPrezzoActionFigure = attributiXML.hasAttribute("sovraPrezzoActionFigure") ? attributiXML.value("sovraPrezzoActionFigure").toUInt() : 0;
                    unsigned int scontoCollectorEditionAnnuale = attributiXML.hasAttribute("scontoCollectorEditionAnnuale") ? attributiXML.value("scontoCollectorEditionAnnuale").toUInt() : 0;

                    daButtareDentro = new CollectorEdition(titoloVideogioco, disponibile, prezzoBase, quantitaInStock, casaProduttrice, annoPubblicazione, pegi, genereGioco, tipoDiPiattaforma, applicaSconto, percorsoImmagine, barCode, descrizioneEtichetta, actionFigure, sovraPrezzoActionFigure, scontoCollectorEditionAnnuale);
                }
                else if(letturaXML.name() == "GiocoNuovo") {
                    unsigned int barCode = attributiXML.hasAttribute("barCode") ? attributiXML.value("barCode").toUInt() : 0;
                    std::string descrizioneEtichetta = attributiXML.hasAttribute("descrizioneEtichetta") ? attributiXML.value("descrizioneEtichetta").toString().toStdString() : "";
                    bool edizioneLimitata = attributiXML.hasAttribute("edizioneLimitata") ? attributiXML.value("edizioneLimitata").toString() == "Si" ? true : false : false;
                    unsigned int sovraPrezzoEdizioneLimitata = attributiXML.hasAttribute("sovraPrezzoEdizioneLimitata") ? attributiXML.value("sovraPrezzoEdizioneLimitata").toUInt() : 0;
                    unsigned int scontoGameAnnuale = attributiXML.hasAttribute("scontoGameAnnuale") ? attributiXML.value("scontoGameAnnuale").toUInt() : 0;

                    daButtareDentro = new Game(titoloVideogioco, disponibile, prezzoBase, quantitaInStock, casaProduttrice, annoPubblicazione, pegi, genereGioco, tipoDiPiattaforma, applicaSconto, percorsoImmagine, barCode, descrizioneEtichetta, edizioneLimitata, sovraPrezzoEdizioneLimitata, scontoGameAnnuale);
                }
                else if(letturaXML.name() == "GiocoUsato") {
                    unsigned int barCode = attributiXML.hasAttribute("barCode") ? attributiXML.value("barCode").toUInt() : 0;
                    std::string descrizioneEtichetta = attributiXML.hasAttribute("descrizioneEtichetta") ? attributiXML.value("descrizioneEtichetta").toString().toStdString() : "";
                    bool scatolaIntegra = attributiXML.hasAttribute("scatolaIntegra") ? attributiXML.value("scatolaIntegra").toString() == "Si" ? true : false : false;
                    unsigned int sovraPrezzoScatolaIntegra = attributiXML.hasAttribute("sovraPrezzoScatolaIntegra") ? attributiXML.value("sovraPrezzoScatolaIntegra").toUInt() : 0;
                    unsigned int scontoSecondHandAnnuale = attributiXML.hasAttribute("scontoSecondHandAnnuale") ? attributiXML.value("scontoSecondHandAnnuale").toUInt() : 0;

                    daButtareDentro = new SecondHand(titoloVideogioco, disponibile, prezzoBase, quantitaInStock, casaProduttrice, annoPubblicazione, pegi, genereGioco, tipoDiPiattaforma, applicaSconto, percorsoImmagine, barCode, descrizioneEtichetta, scatolaIntegra, sovraPrezzoScatolaIntegra, scontoSecondHandAnnuale);
                }

                if(daButtareDentro != nullptr) negozio->insertInBack(daButtareDentro);

                if(!letturaXML.isEndDocument()) letturaXML.skipCurrentElement();
            }
        }
    }
    fileXML.close();
    salvaSeModifica = true;
}

void Modello::rimuoviElementoDallaLista(Videogame* rimuovi) {
    negozio->rimuoviElemento(rimuovi);
}

unsigned int Modello::numeroElementiInNegozio() const { return  negozio->numElementiQontainer(); }

double Modello::totaleCostoProdottiInNegozio() const {
    double totale = 0;
    auto cit = cBegin();
    for( ; cit != cEnd(); ++cit) {
        totale += (*cit)->prezzoVisualizzatoDopoScontoAnnuo();
        //totale += (*cit)->info->getPegi();
    }
    return totale;
}
