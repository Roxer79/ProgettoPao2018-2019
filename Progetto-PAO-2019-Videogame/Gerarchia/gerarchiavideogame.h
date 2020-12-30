#ifndef GERARCHIAVIDEOGAME_H
#define GERARCHIAVIDEOGAME_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Videogame{
private:
    std::string titoloVideogioco;
    bool disponibile; //se true disponibile, se false non disponibile
    double prezzoBase;
    unsigned int quantitaInStock;
    std::string casaProduttrice;
    unsigned int annoPubblicazione; //anno uscita del videogame
    unsigned int pegi;
    std::string genereGioco;
    std::string tipoDiPiattaforma; //ps4, xboxone, pc, ps3, xbox360 ecc...
    bool applicaSconto; //se true applico sconto se false non applico sconto
    //unsigned int sconto;
    std::string percorsoImmagine;
    static const unsigned int capienzaMassimaMagazzino;
public:
    Videogame( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0" ); //il bool va messo all'inizio perchÃ¨ se gioco non ce l'ho metto titolo e non disponibile e resto va di defult

    virtual bool operator==(const Videogame&) const;
    virtual bool operator!=(const Videogame&) const;
    virtual std::string getInfoOggetto() const;
    //virtual Videogame* clone() const = 0;
    //virtual double prezzoFinale() = 0;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const = 0;
    //virtual void modificaScontoAnnuo() = 0;
    virtual std::string ottieniScontoTotale() const = 0;
    virtual std::string getTipologiaProdotto() const = 0;
    virtual bool ricercaPerStringa(std::string = "") const;
    virtual ~Videogame () = default;

    std::string getTitoloVideogioco() const;
    bool getDisponibile() const;
    double getPrezzoBase() const;
    unsigned int getQuantitaInStock() const;
    std::string getCasaProduttrice() const;
    unsigned int getAnnoPubblicazione() const;
    unsigned int getPegi() const;
    std::string getGenereGioco() const;
    std::string getTipoDiPiattaforma() const;
    bool getApplicaSconto() const;
    //unsigned int getSconto() const;
    std::string getPercorsoImmagine() const;
    unsigned int getCapienzaMassimaMagazzino() const;
    //int getScontoDuranteFestivo() const;

    void setTitoloVideogioco(std::string = "");
    void setDisponibile (bool = false);
    void setPrezzoBase(double = 0);
    void setQuantitaInStock(unsigned int = 0);
    void setAggiungiSeEsistente(unsigned int = 0, unsigned int = 0, unsigned int = 0);
    void setCasaProduttrice(std::string = "");
    void setAnnoPubblicazione(unsigned int = 0);
    void setPegi(unsigned int = 0);
    void setGenereGioco(std::string = "");
    void setTipoDiPiattaforma(std::string = "");
    void setApplicaSconto(bool = false);
    //void setSconto(unsigned int = 0);
    //void setControlloSconto();
    void setPercorsoImmagine(std::string = "");

    //bool ricercaPerStringa(std::string) const;
};

//int Videogame::scontoDuranteFestivo = 10;

class Physical: public Videogame{
private:
    unsigned int barCode;
    std::string descrizioneEtichetta;//descrizione scatola oppure template da vedere e modificare
    static const unsigned int anniPerPrezzoFissoUno;
    static const unsigned int anniPerPrezzoFissoDue;
    static const unsigned int massimoScontoAnnuoApplicabile;
public:
    Physical( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", unsigned int = 0, std::string = "0" );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual Physical* clone() const override = 0;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override = 0;
    //virtual void modificaScontoAnnuo() override = 0;
    virtual std::string ottieniScontoTotale() const override = 0;
    virtual std::string getTipologiaProdotto() const override = 0;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~Physical() override = default;

    unsigned int getBarCode() const;
    std::string getDescrizioneEtichetta() const;
    unsigned int getAnniPerPrezzoFissoUno() const;
    unsigned int getAnniPerPrezzoFissoDue() const;
    unsigned int getMassimoScontoAnnuoApplicabile() const;

    void setBarCode(unsigned int = 0);
    void setDescrizioneEtichetta(std::string = "");
};

class Digital: public Videogame{
private:
    std::string piattaformaRiscattoCodice;
    std::string codiceAlfanumerico;
    std::string descrizioneDigital;
    static const unsigned int anniPerPrezzoFissoUno;
    static const unsigned int anniPerPrezzoFissoDue;
    static const unsigned int massimoScontoAnnuoApplicabile;
    //bool controlloRiscattoKey; //se true non usata se false key usata
public:
    Digital( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", std::string = "0", std::string = "0", std::string = "0" );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual Digital* clone() const override = 0;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override = 0;
    //virtual void modificaScontoAnnuo() override = 0;
    virtual std::string ottieniScontoTotale() const override = 0;
    virtual std::string getTipologiaProdotto() const override = 0;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~Digital() override = default;

    std::string getPiattaformaRiscattoCodice() const;
    std::string getCodiceAlfanumerico() const;
    std::string getDescrizioneDigital() const;
    unsigned int getAnniPerPrezzoFissoUno() const;
    unsigned int getAnniPerPrezzoFissoDue() const;
    unsigned int getMassimoScontoAnnuoApplicabile() const;

    void setPiattaformaRiscattoCodice(std::string = "");
    void setCodiceAlfanumerico(std::string = "");
    void setDescrizioneDigital(std::string = "");
    //bool getControlloRiscattoKey() const; //controllo se key usata o meno, se true non usata se false usata
    //void setControlloRiscattoKey(); se vendo la key dovrei settarla a false e/o fare si che se si usa la key si setta a false il parametro
    //ma appunto Ã¨ la piattaforma dove riscatto il codice che dovrÃ  settarmi a false la key in modo che non possa piÃ¹ essere utilizzata
};

class Key: public Digital{
private:
     unsigned int scontoKeyAnnuale;
     static const double prezzoFissoKeyPerUno;
     static const double prezzoFissoKeyPerDue;
public:
    Key( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", std::string = "0", std::string = "0", std::string = "0", unsigned int = 0 );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual Key* clone() const override;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override;
    //virtual void modificaScontoAnnuo() override;
    virtual std::string ottieniScontoTotale() const override;
    virtual std::string getTipologiaProdotto() const override;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~Key() override = default;

    unsigned int getScontoKeyAnnuale() const;
    double getPrezzoFissoKeyPerUno() const;
    double getPrezzoFissoKeyPerDue() const;

    void setScontoKeyAnnuale(unsigned int = 0);
};

class Dlc: public Digital{
private:
    std::string nomeDlc;
    unsigned int scontoDlcAnnuale;
    static const double prezzoFissoDlcPerUno;
    static const double prezzoFissoDlcPerDue;
public:
    Dlc( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", std::string = "0", std::string = "0", std::string = "0", std::string = "0", unsigned int = 0 );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual Dlc* clone() const override;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override;
    //virtual void modificaScontoAnnuo() override;
    virtual std::string ottieniScontoTotale() const override;
    virtual std::string getTipologiaProdotto() const override;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~Dlc() override = default;

    std::string getNomeDlc() const;
    unsigned int getScontoDlc() const;
    double getPrezzoFissoDlcPerUno() const;
    double getPrezzoFissoDlcPerDue() const;

    void setNomeDlc(std::string = "");
    void setScontoDlcAnnuale(unsigned int = 0);
};

class CollectorEdition: public Physical{
private:
    bool actionFigure; //se true c'Ã¨ statuina, se false non c'Ã¨
    unsigned int sovraPrezzoActionFigure;
    unsigned int scontoCollectorEditionAnnuale;
    static const double prezzoFissoCollectorEditionFigurePerUno;
    static const double prezzoFissoCollectorEditionFigurePerDue;
    static const double prezzoFissoCollectorEditionPerUno;
    static const double prezzoFissoCollectorEditionPerDue;
public:
    CollectorEdition( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", unsigned int = 0, std::string = "0", bool = false, unsigned int = 0, unsigned int = 0 );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual CollectorEdition* clone() const override;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override;
    //virtual void modificaScontoAnnuo() override;
    virtual std::string ottieniScontoTotale() const override;
    virtual std::string getTipologiaProdotto() const override;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~CollectorEdition() override = default;

    bool getActionFigure() const;
    unsigned int getSovraPrezzoActionFigure() const;
    unsigned int getScontoCollectorEditionAnnuale() const;
    double getPrezzoFissoCollectorEditionFigurePerUno() const;
    double getPrezzoFissoCollectorEditionFigurePerDue() const;
    double getPrezzoFissoCollectorEditionPerUno() const;
    double getPrezzoFIssoCollectorEditionPerDue() const;

    void setActionFigure(bool = false);
    void setSovraPrezzoActionFigure(unsigned int = 0);
    void setScontoCollectorEditionAnnuale(unsigned int = 0);
};

class Game: public Physical{
private:
    bool edizioneLimitata; //se true edizione limitata, se false gioco normale
    unsigned int sovraPrezzoEdizioneLimitata;
    unsigned int scontoGameAnnuale;
    static const double prezzoFissoGameLimitataPerUno;
    static const double prezzoFissoGameLimitataPerDue;
    static const double prezzoFissoGamePerUno;
    static const double prezzoFissoGamePerDue;
public:
    Game( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", unsigned int = 0, std::string = "0", bool = false, unsigned int = 0, unsigned int = 0 );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual Game* clone() const override;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override;
    //virtual void modificaScontoAnnuo() override;
    virtual std::string ottieniScontoTotale() const override;
    virtual std::string getTipologiaProdotto() const override;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~Game() override = default;

    bool getEdizioneLimitata() const;
    unsigned int getSovraPrezzoEdizioneLimitata() const;
    unsigned int getScontoGameAnnuale() const;
    double getPrezzoFissoGameLimitataPerUno() const;
    double getPrezzoFissoGameLimitataPerDue() const;
    double getPrezzoFissoGamePerUno() const;
    double getPrezzoFissoGamePerDue() const;

    void setEdizioneLimitata(bool = false);
    void setSovraPrezzoEdizioneLimitata(unsigned int = 0);
    void setScontoGameAnnuale(unsigned int = 0);
};

class SecondHand: public Physical{
private:
    bool scatolaIntegra; //true scatola integra, false scatola non integra o non presente
    unsigned int sovraPrezzoScatolaIntegra;
    unsigned int scontoSecondHandAnnuale;
    static const double prezzoFissoSecondHandScatolaPerUno;
    static const double prezzoFissoSecondHandScatolaPerDue;
    static const double prezzoFissoSecondHandPerUno;
    static const double prezzoFissoSecondHandPerDue;
public:
    SecondHand( std::string = "0", bool = false, double = 0, unsigned int = 0, std::string = "0", unsigned int = 0, unsigned int = 0, std::string = "0", std::string = "0", bool = false, std::string = "0", unsigned int = 0, std::string = "0", bool = true, unsigned int = 0, unsigned int = 0 );

    virtual bool operator==(const Videogame&) const override;
    virtual bool operator!=(const Videogame&) const override;
    virtual std::string getInfoOggetto() const override;
    //virtual SecondHand* clone() const final;
    virtual double prezzoVisualizzatoDopoScontoAnnuo() const override;
    //virtual void modificaScontoAnnuo() override;
    virtual std::string ottieniScontoTotale() const override;
    virtual std::string getTipologiaProdotto() const override;
    virtual bool ricercaPerStringa(std::string = "") const override;
    virtual ~SecondHand() override = default;

    bool getScatolaIntegra() const;
    unsigned int getSovraPrezzoSCatolaIntegra() const;
    unsigned int getScontoSecondHandAnnuale() const;
    double getPrezzoFissoSecondHandScatolaPerUno() const;
    double getPrezzoFissoSecondHandScatolaPerDue() const;
    double getPrezzoFissoSecondHandPerUno() const;
    double getPrezzoFissoSecondHandPerDue() const;

    void setScatolaIntegra(bool = false);
    void setSovraPrezzoScatolaIntegra(unsigned int = 0);
    void setScontoSecondHandAnnuale(unsigned int = 0);
};

#endif // GERARCHIAVIDEOGAME_H
