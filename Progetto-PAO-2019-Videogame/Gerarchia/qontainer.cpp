#include "Gerarchia/qontainer.h"
#include "Gerarchia/gerarchiavideogame.h"

//==========================================================================

const unsigned int Videogame::capienzaMassimaMagazzino = 10000;

Videogame::Videogame ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma ):
    titoloVideogioco(titoloV), disponibile(disponibil), prezzoBase(prezzoBas), quantitaInStock(quantitaInSt), casaProduttrice(casaP), annoPubblicazione(annoPubl),
    pegi(peg), genereGioco(genereG), tipoDiPiattaforma(tipoPiattafor), applicaSconto(applicaSc), percorsoImmagine(percorsoImma)  {}

/*bool Videogame::operator==(const Videogame& vg) const {
    return titoloVideogioco == vg.titoloVideogioco && disponibile == vg.disponibile && prezzoBase == vg.prezzoBase && quantitaInStock == vg.quantitaInStock && casaProduttrice == vg.casaProduttrice && annoPubblicazione == vg.annoPubblicazione
            && pegi == vg.pegi && genereGioco == vg.genereGioco && tipoDiPiattaforma == vg.tipoDiPiattaforma && applicaSconto == vg.applicaSconto;
}*/

bool Videogame::operator==(const Videogame& vg) const {
    return vg.titoloVideogioco == titoloVideogioco && vg.casaProduttrice == casaProduttrice && vg.annoPubblicazione == annoPubblicazione && vg.genereGioco == genereGioco;
}

bool Videogame::operator!=(const Videogame & vg) const {
    return vg.titoloVideogioco != titoloVideogioco || vg.casaProduttrice != casaProduttrice || vg.annoPubblicazione != annoPubblicazione || vg.genereGioco != genereGioco;
}

std::string Videogame::getInfoOggetto() const {
    std::stringstream stream;
    std::stringstream stream1;
    stream << std::fixed << std::setprecision(2) << getPrezzoBase();
    stream1 << std::fixed << std::setprecision(2) << prezzoVisualizzatoDopoScontoAnnuo();
    std::string str = getTipologiaProdotto();
    return str.append("\nTitolo videogioco: " + getTitoloVideogioco())
            .append("\nDisponibile: ").append(getDisponibile() ? "Si" : "No")
            .append("\nPrezzo base: " + stream.str().append("€"))
            .append("\nSconto prezzo: " + ottieniScontoTotale())
            .append("\nPrezzo finale: " + stream1.str().append("€"))
            .append("\nQuantità in stock: " + std::to_string(getQuantitaInStock()))
            .append("\nCasa produttrice: " + getCasaProduttrice())
            .append("\nAnno di pubblicazione: " + std::to_string(getAnnoPubblicazione()))
            .append("\nPegi: " + std::to_string(getPegi()))
            .append("\nGenere gioco: " + getGenereGioco())
            .append("\nTipo di piattaforma: " + getTipoDiPiattaforma())
            .append("\nApplica sconto: ").append(getApplicaSconto() ? "Si" : "No");
}

//std::string Videogame::getTipologiaProdotto() const { return "Videogame"; }

bool Videogame::ricercaPerStringa(std::string confronto) const {
    return confronto == titoloVideogioco || confronto == std::to_string(prezzoBase) || confronto == casaProduttrice || confronto == std::to_string(annoPubblicazione) || confronto == std::to_string(pegi) || confronto == genereGioco || confronto == tipoDiPiattaforma;
}

std::string Videogame::getTitoloVideogioco() const { return titoloVideogioco; }

bool Videogame::getDisponibile() const { return disponibile; }

double Videogame::getPrezzoBase() const{ return prezzoBase; }

unsigned int Videogame::getQuantitaInStock() const { return quantitaInStock; }

std::string Videogame::getCasaProduttrice() const { return casaProduttrice; }

unsigned int Videogame::getAnnoPubblicazione() const { return annoPubblicazione; }

unsigned int Videogame::getPegi() const { return pegi; }

std::string Videogame::getGenereGioco() const { return genereGioco; }

std::string Videogame::getTipoDiPiattaforma() const { return tipoDiPiattaforma; }

bool Videogame::getApplicaSconto() const { return applicaSconto; }

std::string Videogame::getPercorsoImmagine() const { return percorsoImmagine; }

unsigned int Videogame::getCapienzaMassimaMagazzino() const{ return capienzaMassimaMagazzino; }

void Videogame::setTitoloVideogioco(std::string titolo) { titoloVideogioco = titolo; }

void Videogame::setDisponibile(bool disponib) {
    disponibile = disponib;
    //if(quantitaInStock > 0) quantitaInStock = true; //maybe conviene togliere sta parte
    //else quantitaInStock = false;
}

void Videogame::setPrezzoBase(double prezzo) { prezzoBase = prezzo; }

void Videogame::setQuantitaInStock(unsigned int togliDaStock) { quantitaInStock = togliDaStock; }

void Videogame::setAggiungiSeEsistente(unsigned int aggiungi, unsigned int totaleInStock, unsigned int totElemento) {
    quantitaInStock += aggiungi;
    if(quantitaInStock > capienzaMassimaMagazzino) quantitaInStock = (capienzaMassimaMagazzino - (totaleInStock - totElemento));
}

void Videogame::setCasaProduttrice(std::string casaProd) { casaProduttrice = casaProd; }

void Videogame::setAnnoPubblicazione(unsigned int annoPubl) { annoPubblicazione = annoPubl; }

void Videogame::setPegi(unsigned int peg) { pegi = peg; }

void Videogame::setGenereGioco(std::string genere) { genereGioco = genere; }

void Videogame::setTipoDiPiattaforma(std::string tipoPiatta) { tipoDiPiattaforma = tipoPiatta; }

void Videogame::setApplicaSconto(bool sconto) {
    applicaSconto = sconto;
    //if(applicaSconto) applicaSconto = false;
    //else applicaSconto = true;
}

void Videogame::setPercorsoImmagine(std::string nuovoPercorso) { percorsoImmagine = nuovoPercorso; }

/*bool Videogame::ricercaPerStringa(std::string ricerca) const {
    return ricerca == titoloVideogioco || ricerca == std::to_string(prezzoBase) || ricerca == casaProduttrice || ricerca == std::to_string(annoPubblicazione) || ricerca == std::to_string(pegi) || ricerca == genereGioco || ricerca == tipoDiPiattaforma;
}*/

//===========================================================================

const unsigned int Physical::anniPerPrezzoFissoUno = 3;

const unsigned int Physical::anniPerPrezzoFissoDue = 6;

const unsigned int Physical::massimoScontoAnnuoApplicabile = 20;

Physical::Physical ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, unsigned int barCod, std::string descrizioneE ):
    Videogame(titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma), barCode(barCod), descrizioneEtichetta(descrizioneE) {}

/*bool Physical::operator==(const Videogame& vg) const {
    const Physical* ph = dynamic_cast<const Physical*>(&vg);
    return ph && Videogame::operator==(vg) && descrizioneEtichetta == ph->descrizioneEtichetta;
}*/

bool Physical::operator==(const Videogame& vg) const {
    const Physical* ph = dynamic_cast<const Physical*>(&vg);
    return ph && Videogame::operator==(vg);
}

bool Physical::operator!=(const Videogame & vg) const {
    const Physical* ph = dynamic_cast<const Physical*>(&vg);
    return !ph || Videogame::operator!=(vg);
}

std::string Physical::getInfoOggetto() const {
    std::string ogg = Videogame::getInfoOggetto();
    return ogg.append("\nBar code: " + std::to_string(getBarCode()))
            .append("\nDescrizione etichetta: " + getDescrizioneEtichetta());
}

//std::string Physical::getTipologiaProdotto() const { return "Physical"; }

bool Physical::ricercaPerStringa(std::string confronto) const {
    return Videogame::ricercaPerStringa(confronto) || confronto == std::to_string(barCode) || confronto == descrizioneEtichetta;
}

unsigned int Physical::getBarCode() const { return barCode; }

std::string Physical::getDescrizioneEtichetta() const { return descrizioneEtichetta;  }

unsigned int Physical::getAnniPerPrezzoFissoUno() const { return anniPerPrezzoFissoUno; }

unsigned int Physical::getAnniPerPrezzoFissoDue() const { return anniPerPrezzoFissoDue; }

unsigned int Physical::getMassimoScontoAnnuoApplicabile() const { return massimoScontoAnnuoApplicabile; }

void Physical::setBarCode(unsigned int bar) { barCode = bar; }

void Physical::setDescrizioneEtichetta(std::string descrzione) { descrizioneEtichetta = descrzione; }

//===========================================================================

const unsigned int Digital::anniPerPrezzoFissoUno = 2;

const unsigned int Digital::anniPerPrezzoFissoDue = 5;

const unsigned int Digital::massimoScontoAnnuoApplicabile = 30;

Digital::Digital ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, std::string piattaformaRiscattoC, std::string codiceAlfanum, std::string descrizioneDigi ):
    Videogame (titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma), piattaformaRiscattoCodice(piattaformaRiscattoC), codiceAlfanumerico(codiceAlfanum), descrizioneDigital(descrizioneDigi) {}

/*bool Digital::operator==(const Videogame& vg) const {
    const Digital* di = dynamic_cast<const Digital*>(&vg);
    return di && Videogame::operator==(vg) && piattaformaRiscattoCodice == di->piattaformaRiscattoCodice && codiceAlfanumerico == di->codiceAlfanumerico && descrizioneDigital == di->descrizioneDigital;
}*/

bool Digital::operator==(const Videogame& vg) const {
    const Digital* di = dynamic_cast<const Digital*>(&vg);
    return di && Videogame::operator==(vg);
}

bool Digital::operator!=(const Videogame & vg) const {
    const Digital* di = dynamic_cast<const Digital*>(&vg);
    return !di || Videogame::operator!=(vg);
}

std::string Digital::getInfoOggetto() const {
    std::string ogg = Videogame::getInfoOggetto();
    return ogg.append("\nPiattaforma riscatto codice: " + getPiattaformaRiscattoCodice())
            .append("\nCodice alfanumerico: " + getCodiceAlfanumerico())
            .append("\nDescrizione digitale: " + getDescrizioneDigital());
}

//std::string Digital::getTipologiaProdotto() const { return "Digital"; }

bool Digital::ricercaPerStringa(std::string confronto) const {
    return Videogame::ricercaPerStringa(confronto) || confronto == piattaformaRiscattoCodice || confronto == codiceAlfanumerico || confronto == descrizioneDigital;
}

std::string Digital::getPiattaformaRiscattoCodice() const { return piattaformaRiscattoCodice; }

std::string Digital::getCodiceAlfanumerico() const { return codiceAlfanumerico; }

std::string Digital::getDescrizioneDigital() const { return descrizioneDigital; }

unsigned int Digital::getAnniPerPrezzoFissoUno() const { return anniPerPrezzoFissoUno; }

unsigned int Digital::getAnniPerPrezzoFissoDue() const { return anniPerPrezzoFissoDue; }

unsigned int Digital::getMassimoScontoAnnuoApplicabile() const { return massimoScontoAnnuoApplicabile; }

void Digital::setPiattaformaRiscattoCodice(std::string riscatto) { piattaformaRiscattoCodice = riscatto; }

void Digital::setCodiceAlfanumerico(std::string codice) { codiceAlfanumerico = codice; }

void Digital::setDescrizioneDigital(std::string descrizione) { descrizioneDigital = descrizione; }

//===========================================================================

const double Key::prezzoFissoKeyPerUno = 9.99;

const double Key::prezzoFissoKeyPerDue = 4.99;

Key::Key ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, std::string piattaformaRiscattoC, std::string codiceAlfanum, std::string descrizioneDigi, unsigned int scontoKey ):
    Digital (titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma, piattaformaRiscattoC, codiceAlfanum, descrizioneDigi), scontoKeyAnnuale(scontoKey) {}

/*bool Key::operator==(const Videogame& vg) const {
    const Key* ke = dynamic_cast<const Key*>(&vg);
    return ke && Digital::operator==(vg) && scontoKeyAnnuale == ke->scontoKeyAnnuale;
}*/

bool Key::operator==(const Videogame& vg) const {
    const Key* ke = dynamic_cast<const Key*>(&vg);
    return ke && Digital::operator==(vg);
}

bool Key::operator!=(const Videogame & vg) const {
    const Key* ke = dynamic_cast<const Key*>(&vg);
    return !ke || Digital::operator!=(vg);
}

std::string Key::getInfoOggetto() const {
    std::string ogg = Digital::getInfoOggetto();
    return ogg.append("\nSconto key annuale: " + std::to_string(getScontoKeyAnnuale())).append("%");
}

//Key* Key::clone() const { return new Key(*this); }

double Key::prezzoVisualizzatoDopoScontoAnnuo() const {
    if(!getDisponibile()) {
        if(getPrezzoBase() == 0) return 0;
    }
    if(getApplicaSconto() && scontoKeyAnnuale != 0) {
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoKeyPerDue;
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoKeyPerUno;
        double sconto = (::AnnoCorrente() - getAnnoPubblicazione()) * scontoKeyAnnuale;
        return (getPrezzoBase() - ((getPrezzoBase()*sconto)/100));
    }
    return getPrezzoBase();
}

//void Key::modificaScontoAnnuo() { setScontoKeyAnnuale(); }

std::string Key::ottieniScontoTotale() const {
    std::string ritorno = "";
    if(!getDisponibile()) ritorno = "non disponibile nel catalogo ";
    if(getApplicaSconto()) {
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 4.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 9.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        return ritorno + "sconto del " + std::to_string((::AnnoCorrente() - getAnnoPubblicazione()) * scontoKeyAnnuale) + "%";
    } else {
        if(ritorno != "") return ritorno + "non applico sconto";
        else ritorno = "non applico sconto";
    }
    return ritorno;
}

bool Key::ricercaPerStringa(std::string confronto) const {
    return Digital::ricercaPerStringa(confronto) || confronto == std::to_string(scontoKeyAnnuale);
}

std::string Key::getTipologiaProdotto() const { return "Key"; }

unsigned int Key::getScontoKeyAnnuale() const { return scontoKeyAnnuale; }

double Key::getPrezzoFissoKeyPerUno() const { return prezzoFissoKeyPerUno; }

double Key::getPrezzoFissoKeyPerDue() const { return prezzoFissoKeyPerDue; }

void Key::setScontoKeyAnnuale(unsigned int sconto) {
    scontoKeyAnnuale = sconto;
    if(scontoKeyAnnuale > getMassimoScontoAnnuoApplicabile()) scontoKeyAnnuale = getMassimoScontoAnnuoApplicabile();
}

//===========================================================================

const double Dlc::prezzoFissoDlcPerUno = 6.99;

const double Dlc::prezzoFissoDlcPerDue = 3.99;

Dlc::Dlc ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, std::string piattaformaRiscattoC, std::string codiceAlfanum, std::string descrizioneDigi, std::string nomeD, unsigned int scontoDlc ):
    Digital (titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma, piattaformaRiscattoC, codiceAlfanum, descrizioneDigi), nomeDlc(nomeD), scontoDlcAnnuale(scontoDlc) {}

/*bool Dlc::operator==(const Videogame& vg) const {
    const Dlc* dl = dynamic_cast<const Dlc*>(&vg);
    return dl && Digital::operator==(vg) && nomeDlc == dl->nomeDlc && scontoDlcAnnuale == dl->scontoDlcAnnuale;
}*/

bool Dlc::operator==(const Videogame& vg) const {
    const Dlc* dl = dynamic_cast<const Dlc*>(&vg);
    return dl && Digital::operator==(vg);
}

bool Dlc::operator!=(const Videogame & vg) const {
    const Dlc* dl = dynamic_cast<const Dlc*>(&vg);
    return !dl || Digital::operator!=(vg);
}

std::string Dlc::getInfoOggetto() const {
    std::string ogg = Digital::getInfoOggetto();
    return ogg.append("\nNome dlc: " + getNomeDlc())
            .append("\nSconto dlc annuale: " + std::to_string(getScontoDlc())).append("%");
}

//Dlc* Dlc::clone() const { return new Dlc(*this); }

double Dlc::prezzoVisualizzatoDopoScontoAnnuo() const {
    //if(!getDisponibile()) return 0;
    if(!getDisponibile()) {
        if(getPrezzoBase() == 0) return 0;
    }
    if(getApplicaSconto() && scontoDlcAnnuale != 0) {
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoDlcPerDue;
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoDlcPerUno;
        double sconto = (::AnnoCorrente() - getAnnoPubblicazione()) * scontoDlcAnnuale;
        return (getPrezzoBase() - ((getPrezzoBase()*sconto)/100));
    }
    return getPrezzoBase();
}

//void Dlc::modificaScontoAnnuo() { setScontoDlcAnnuale(); }

std::string Dlc::ottieniScontoTotale() const {
    std::string ritorno = "";
    if(!getDisponibile()) ritorno = "non disponibile nel catalogo ";
    if(getApplicaSconto()) {
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 3.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 6.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        return ritorno + "sconto del " + std::to_string((::AnnoCorrente() - getAnnoPubblicazione()) * scontoDlcAnnuale) + "%";
    } else {
        if(ritorno != "") return ritorno + "non applico sconto";
        else ritorno = "non applico sconto";
    }
    return ritorno;
}

bool Dlc::ricercaPerStringa(std::string confronto) const {
    return Digital::ricercaPerStringa(confronto) || confronto == nomeDlc || confronto == std::to_string(scontoDlcAnnuale);
}

std::string Dlc::getTipologiaProdotto() const { return "Dlc"; }

std::string Dlc::getNomeDlc() const { return nomeDlc; }

unsigned int Dlc::getScontoDlc() const { return scontoDlcAnnuale; }

double Dlc::getPrezzoFissoDlcPerUno() const { return prezzoFissoDlcPerUno; }

double Dlc::getPrezzoFissoDlcPerDue() const { return prezzoFissoDlcPerDue; }

void Dlc::setNomeDlc(std::string nome) { nomeDlc = nome; }

void Dlc::setScontoDlcAnnuale(unsigned int sconto) {
    scontoDlcAnnuale = sconto;
    if(scontoDlcAnnuale > getMassimoScontoAnnuoApplicabile()) scontoDlcAnnuale = getMassimoScontoAnnuoApplicabile();
}

//===========================================================================

const double CollectorEdition::prezzoFissoCollectorEditionFigurePerUno = 59.99;

const double CollectorEdition::prezzoFissoCollectorEditionFigurePerDue = 39.99;

const double CollectorEdition::prezzoFissoCollectorEditionPerUno = 49.99;

const double CollectorEdition::prezzoFissoCollectorEditionPerDue = 29.99;

CollectorEdition::CollectorEdition ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, unsigned int barCod, std::string descrizioneE, bool actionF, unsigned int sovraPrezzoActionFig, unsigned int scontoCollectorEditionAnn ):
    Physical (titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma, barCod, descrizioneE), actionFigure(actionF), sovraPrezzoActionFigure(sovraPrezzoActionFig), scontoCollectorEditionAnnuale(scontoCollectorEditionAnn) {}

/*bool CollectorEdition::operator==(const Videogame& vg) const {
    const CollectorEdition* ce = dynamic_cast<const CollectorEdition*>(&vg);
    return ce && Physical::operator==(vg) && actionFigure == ce->actionFigure && sovraPrezzoActionFigure == ce->sovraPrezzoActionFigure && scontoCollectorEditionAnnuale == ce->scontoCollectorEditionAnnuale;
}*/

bool CollectorEdition::operator==(const Videogame& vg) const {
    const CollectorEdition* ce = dynamic_cast<const CollectorEdition*>(&vg);
    return ce && Physical::operator==(vg);
}

bool CollectorEdition::operator!=(const Videogame & vg) const {
    const CollectorEdition* ce = dynamic_cast<const CollectorEdition*>(&vg);
    return !ce || Physical::operator!=(vg);
}

std::string CollectorEdition::getInfoOggetto() const {
    std::string ogg = Physical::getInfoOggetto();
    return ogg.append("\nAction figure: ").append(getActionFigure() ? "Si" : "No")
            .append("\nSovrapprezzo action figure: " + std::to_string(getSovraPrezzoActionFigure())).append("€")
            .append("\nSconto collector's edition: " + std::to_string(getScontoCollectorEditionAnnuale())).append("%");

}

//CollectorEdition* CollectorEdition::clone() const { return new CollectorEdition(*this); }

double CollectorEdition::prezzoVisualizzatoDopoScontoAnnuo() const {
    //if(!getDisponibile()) return 0;
    if(!getDisponibile()) {
        if(getPrezzoBase() == 0) return 0;
    }
    if(getApplicaSconto() && scontoCollectorEditionAnnuale != 0) {
        //int anno = 0;
        if(actionFigure) {
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoCollectorEditionFigurePerDue;
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoCollectorEditionFigurePerUno;
        }
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoCollectorEditionPerDue;
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoCollectorEditionPerUno;
        double sconto = (::AnnoCorrente() - getAnnoPubblicazione()) * scontoCollectorEditionAnnuale;
        return (actionFigure != 0 ? (getPrezzoBase() + sovraPrezzoActionFigure - (((getPrezzoBase() + sovraPrezzoActionFigure)*sconto)/100)) : (getPrezzoBase() - ((getPrezzoBase()*sconto)/100)));
    }
    return (actionFigure != 0 ? (getPrezzoBase() + sovraPrezzoActionFigure) : getPrezzoBase());
}

//void CollectorEdition::modificaScontoAnnuo() { setScontoCollectorEditionAnnuale(); }

std::string CollectorEdition::ottieniScontoTotale() const {
    std::string ritorno = "";
    if(!getDisponibile()) ritorno = "non disponibile nel catalogo ";
    if(getApplicaSconto()) {
        if(actionFigure) {
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 39.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 59.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        }
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 29.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 49.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        return ritorno + "sconto del " + std::to_string((::AnnoCorrente() - getAnnoPubblicazione()) * scontoCollectorEditionAnnuale) + "%";
    } else {
        if(ritorno != "") return ritorno + "non applico sconto";
        else ritorno = "non applico sconto";
    }
    return ritorno;
}

bool CollectorEdition::ricercaPerStringa(std::string confronto) const {
    return Physical::ricercaPerStringa(confronto) || confronto == std::to_string(sovraPrezzoActionFigure) || confronto == std::to_string(scontoCollectorEditionAnnuale);
}

std::string CollectorEdition::getTipologiaProdotto() const { return "CollectorEdition"; }

bool CollectorEdition::getActionFigure() const{ return actionFigure; }

unsigned int CollectorEdition::getSovraPrezzoActionFigure() const { return sovraPrezzoActionFigure; }

unsigned int CollectorEdition::getScontoCollectorEditionAnnuale() const { return scontoCollectorEditionAnnuale; }

double CollectorEdition::getPrezzoFissoCollectorEditionFigurePerUno() const { return prezzoFissoCollectorEditionFigurePerUno; }

double CollectorEdition::getPrezzoFissoCollectorEditionFigurePerDue() const { return prezzoFissoCollectorEditionFigurePerDue; }

double CollectorEdition::getPrezzoFissoCollectorEditionPerUno() const { return prezzoFissoCollectorEditionPerUno; }

double CollectorEdition::getPrezzoFIssoCollectorEditionPerDue() const { return prezzoFissoCollectorEditionPerDue; }

void CollectorEdition::setActionFigure(bool action) {
    actionFigure = action;
    //if(actionFigure) actionFigure = false;
    //else actionFigure = true;
}

void CollectorEdition::setSovraPrezzoActionFigure(unsigned int aumento) { sovraPrezzoActionFigure = aumento; }

void CollectorEdition::setScontoCollectorEditionAnnuale(unsigned int sconto) {
    scontoCollectorEditionAnnuale = sconto;
    if(scontoCollectorEditionAnnuale > getMassimoScontoAnnuoApplicabile()) scontoCollectorEditionAnnuale = getMassimoScontoAnnuoApplicabile();
}

//===========================================================================

const double Game::prezzoFissoGameLimitataPerUno = 49.99;

const double Game::prezzoFissoGameLimitataPerDue = 34.99;

const double Game::prezzoFissoGamePerUno = 29.99;

const double Game::prezzoFissoGamePerDue = 14.99;

Game::Game ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, unsigned int barCod, std::string descrizioneE, bool edizioneLim, unsigned int sovraPrezzoEdizioneLim, unsigned int scontoGame ):
    Physical (titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma, barCod, descrizioneE), edizioneLimitata(edizioneLim), sovraPrezzoEdizioneLimitata(sovraPrezzoEdizioneLim), scontoGameAnnuale(scontoGame) {}

/*bool Game::operator==(const Videogame& vg) const {
    const Game* gm = dynamic_cast<const Game*>(&vg);
    return gm && Physical::operator==(vg) && edizioneLimitata == gm->edizioneLimitata && sovraPrezzoEdizioneLimitata == gm->edizioneLimitata && scontoGameAnnuale == gm->scontoGameAnnuale;
}*/

bool Game::operator==(const Videogame& vg) const {
    const Game* gm = dynamic_cast<const Game*>(&vg);
    return gm && Physical::operator==(vg);
}

bool Game::operator!=(const Videogame & vg) const {
    const Game* gm = dynamic_cast<const Game*>(&vg);
    return !gm || Physical::operator!=(vg);
}

std::string Game::getInfoOggetto() const {
    std::string ogg = Physical::getInfoOggetto();
    return ogg.append("\nEdzione limitata: ").append(getEdizioneLimitata() ? "Si" : "No")
            .append("\nSovrapprezzo edizione limitata: " + std::to_string(getSovraPrezzoEdizioneLimitata())).append("€")
            .append("\nSconto game anuuale: " + std::to_string(getScontoGameAnnuale())).append("%");
}

//Game* Game::clone() const { return new Game(*this); }

double Game::prezzoVisualizzatoDopoScontoAnnuo() const {
    //if(!getDisponibile()) return 0;
    if(!getDisponibile()) {
        if(getPrezzoBase() == 0) return 0;
    }
    if(getApplicaSconto() && scontoGameAnnuale != 0) {
        if(edizioneLimitata) {
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoGameLimitataPerDue;
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoGameLimitataPerUno;
        }
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoGamePerDue;
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoGamePerUno;
        double sconto = (::AnnoCorrente() - getAnnoPubblicazione()) * scontoGameAnnuale;
        return (edizioneLimitata != 0 ? (getPrezzoBase() + sovraPrezzoEdizioneLimitata - (((getPrezzoBase() + sovraPrezzoEdizioneLimitata)*sconto)/100)) : (getPrezzoBase() - ((getPrezzoBase()*sconto)/100)));
    }
    return (edizioneLimitata != 0 ? (getPrezzoBase() + sovraPrezzoEdizioneLimitata) : getPrezzoBase());
}

//void Game::modificaScontoAnnuo() { setScontoGameAnnuale(); }

std::string Game::ottieniScontoTotale() const {
    std::string ritorno = "";
    if(!getDisponibile()) ritorno = "non disponibile nel catalogo ";
    if(getApplicaSconto()) {
        if(edizioneLimitata) {
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 34.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 49.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        }
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 14.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 29.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        return ritorno + "sconto del " + std::to_string((::AnnoCorrente() - getAnnoPubblicazione()) * scontoGameAnnuale) + "%";
    } else {
        if(ritorno != "") return ritorno + "non applico sconto";
        else ritorno = "non applico sconto";
    }
    return ritorno;
}

bool Game::ricercaPerStringa(std::string confronto) const {
    return Physical::ricercaPerStringa(confronto) || confronto == std::to_string(sovraPrezzoEdizioneLimitata) || confronto == std::to_string(scontoGameAnnuale);
}

std::string Game::getTipologiaProdotto() const { return "GiocoNuovo"; }

bool Game::getEdizioneLimitata() const { return edizioneLimitata; }

unsigned int Game::getSovraPrezzoEdizioneLimitata() const { return sovraPrezzoEdizioneLimitata; }

unsigned int Game::getScontoGameAnnuale() const { return scontoGameAnnuale; }

double Game::getPrezzoFissoGameLimitataPerUno() const { return prezzoFissoGameLimitataPerUno; }

double Game::getPrezzoFissoGameLimitataPerDue() const { return prezzoFissoGameLimitataPerDue; }

double Game::getPrezzoFissoGamePerUno() const { return prezzoFissoGamePerUno; }

double Game::getPrezzoFissoGamePerDue() const { return prezzoFissoGamePerDue; }

void Game::setEdizioneLimitata(bool limitata) {
    edizioneLimitata = limitata;
    //if(edizioneLimitata) edizioneLimitata = false;
    //else edizioneLimitata = true;
}

void Game::setSovraPrezzoEdizioneLimitata(unsigned int aumento) { sovraPrezzoEdizioneLimitata = aumento; }

void Game::setScontoGameAnnuale(unsigned int sconto) {
    scontoGameAnnuale = sconto;
    if(scontoGameAnnuale > getMassimoScontoAnnuoApplicabile()) scontoGameAnnuale = getMassimoScontoAnnuoApplicabile();
}

//===========================================================================

const double SecondHand::prezzoFissoSecondHandScatolaPerUno = 19.99;

const double SecondHand::prezzoFissoSecondHandScatolaPerDue = 13.99;

const double SecondHand::prezzoFissoSecondHandPerUno = 15.99;

const double SecondHand::prezzoFissoSecondHandPerDue = 9.99;

SecondHand::SecondHand ( std::string titoloV, bool disponibil, double prezzoBas, unsigned int quantitaInSt, std::string casaP, unsigned int annoPubl, unsigned int peg, std::string genereG, std::string tipoPiattafor, bool applicaSc, std::string percorsoImma, unsigned int barCod, std::string descrizioneE, bool scatolaInte, unsigned int sovraPrezzoScatola, unsigned int scontoSecondHandAnnuo ):
    Physical (titoloV, disponibil, prezzoBas, quantitaInSt, casaP, annoPubl, peg, genereG, tipoPiattafor, applicaSc, percorsoImma, barCod, descrizioneE), scatolaIntegra(scatolaInte), sovraPrezzoScatolaIntegra(sovraPrezzoScatola), scontoSecondHandAnnuale(scontoSecondHandAnnuo) {}

/*bool SecondHand::operator==(const Videogame& vg) const {
    const SecondHand* sh = dynamic_cast<const SecondHand*>(&vg);
    return sh && Physical::operator==(vg) && scatolaIntegra == sh->scatolaIntegra && sovraPrezzoScatolaIntegra == sh->sovraPrezzoScatolaIntegra && scontoSecondHandAnnuale == sh->scontoSecondHandAnnuale;
}*/

bool SecondHand::operator==(const Videogame& vg) const {
    const SecondHand* sh = dynamic_cast<const SecondHand*>(&vg);
    return sh && Physical::operator==(vg);
}

bool SecondHand::operator!=(const Videogame & vg) const {
    const SecondHand* sh = dynamic_cast<const SecondHand*>(&vg);
    return !sh || Physical::operator!=(vg);
}

std::string SecondHand::getInfoOggetto() const {
    std::string ogg = Physical::getInfoOggetto();
    return ogg.append("\nScatola integra: ").append(getScatolaIntegra() ? "Si" : "No")
            .append("\nSovrapprezzo scatola integra: " + std::to_string(getSovraPrezzoSCatolaIntegra())).append("€")
            .append("\nSconto gioco usato annuale: " + std::to_string(getScontoSecondHandAnnuale())).append("%");
}

//SecondHand* SecondHand::clone() const { return new SecondHand(*this); }

double SecondHand::prezzoVisualizzatoDopoScontoAnnuo() const {
    //if(!getDisponibile()) return 0;
    if(!getDisponibile()) {
        if(getPrezzoBase() == 0) return 0;
    }
    if(getApplicaSconto() && scontoSecondHandAnnuale != 0) {
        if(scatolaIntegra) {
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoSecondHandScatolaPerDue;
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoSecondHandScatolaPerUno;
        }
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return prezzoFissoSecondHandPerDue;
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return prezzoFissoSecondHandPerUno;
        double sconto = (::AnnoCorrente() - getAnnoPubblicazione()) * scontoSecondHandAnnuale;
        return (scatolaIntegra != 0 ? (getPrezzoBase() + sovraPrezzoScatolaIntegra - (((getPrezzoBase() + sovraPrezzoScatolaIntegra)*sconto)/100)) : (getPrezzoBase() - ((getPrezzoBase()*sconto)/100)));
    }
    return (scatolaIntegra != 0 ? (getPrezzoBase() + sovraPrezzoScatolaIntegra) : getPrezzoBase());
}

//void SecondHand::modificaScontoAnnuo() { setScontoSecondHandAnnuale(); }

std::string SecondHand::ottieniScontoTotale() const {
    std::string ritorno = "";
    if(!getDisponibile()) ritorno = "non disponibile nel catalogo ";
    if(getApplicaSconto()) {
        if(scatolaIntegra) {
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 13.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
            if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 19.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        }
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoDue()) return ritorno + "prezzo fisso di 9.99€ dopo " + std::to_string(getAnniPerPrezzoFissoDue()) + " anni";
        if((::AnnoCorrente() - getAnnoPubblicazione()) > getAnniPerPrezzoFissoUno()) return ritorno + "prezzo fisso di 15.99€ dopo " + std::to_string(getAnniPerPrezzoFissoUno()) + " anni";
        return ritorno + "sconto del " + std::to_string((::AnnoCorrente() - getAnnoPubblicazione()) * scontoSecondHandAnnuale) + "%";
    } else {
        if(ritorno != "") return ritorno + "non applico sconto";
        else ritorno = "non applico sconto";
    }
    return ritorno;
}

bool SecondHand::ricercaPerStringa(std::string confronto) const {
    return Physical::ricercaPerStringa(confronto) || confronto == std::to_string(sovraPrezzoScatolaIntegra) || confronto == std::to_string(scontoSecondHandAnnuale);
}

std::string SecondHand::getTipologiaProdotto() const { return "GiocoUsato"; }

bool SecondHand::getScatolaIntegra() const { return scatolaIntegra; }

unsigned int SecondHand::getSovraPrezzoSCatolaIntegra() const { return sovraPrezzoScatolaIntegra; }

unsigned int SecondHand::getScontoSecondHandAnnuale() const { return scontoSecondHandAnnuale; }

double SecondHand::getPrezzoFissoSecondHandScatolaPerUno() const { return prezzoFissoSecondHandScatolaPerUno; }

double SecondHand::getPrezzoFissoSecondHandScatolaPerDue() const { return prezzoFissoSecondHandScatolaPerDue; }

double SecondHand::getPrezzoFissoSecondHandPerUno() const { return prezzoFissoSecondHandPerUno; }

double SecondHand::getPrezzoFissoSecondHandPerDue() const { return prezzoFissoSecondHandPerDue; }

void SecondHand::setScatolaIntegra(bool scatola) {
    scatolaIntegra = scatola;
    //if(scatolaIntegra) scatolaIntegra = false;
    //else scatolaIntegra = true;
}

void SecondHand::setSovraPrezzoScatolaIntegra(unsigned int aumento) { sovraPrezzoScatolaIntegra = aumento; }

void SecondHand::setScontoSecondHandAnnuale(unsigned int sconto) {
    scontoSecondHandAnnuale = sconto;
    if(scontoSecondHandAnnuale > getMassimoScontoAnnuoApplicabile()) scontoSecondHandAnnuale = getMassimoScontoAnnuoApplicabile();
}

//===========================================================================

/*int ::AnnoCorrente() {
      time_t currentTime;
      time(&currentTime);
      //std::string annoC = asctime(localtime(&currentTime));
      struct tm* timeinfo = localtime(&currentTime);
      int AnnoC = (1900 + (timeinfo->tm_year));
      return AnnoC;
}*/
