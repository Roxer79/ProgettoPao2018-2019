#ifndef MODELLO_H
#define MODELLO_H

#include "Gerarchia/qontainer.h"
#include "Gerarchia/gerarchiavideogame.h"

#include <QMessageBox>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <iostream>

class Modello {
private:
    Container<Videogame*>* negozio;
    std::string percorsoXML;
    bool salvaSeModifica;
public:
    Modello(std::string = ":/Salvataggio_Dati_XML/dati progetto.xml"); //da fare
    ~Modello();
    std::string getPercorsoXML() const;
    bool getSalvaSeModifica() const;
    void setSalvaSeModifica(bool);

    Container<Videogame*>::iterator Begin() const;
    Container<Videogame*>::iterator End() const;
    Container<Videogame*>::constiterator cBegin() const;
    Container<Videogame*>::constiterator cEnd() const;

    //void inserisci(Videogame*, Videogame* = nullptr, Videogame* = nullptr);
    void inserisciAdInizio(Videogame*);
    void inserisciInFine(Videogame*);

    Videogame* ricercaPerPuntatori(Videogame*) const;

    void settaNuovoPercorsoFileXML(std::string = "");
    void salvataggioDatiXML();
    void caricaXML();

    void rimuoviElementoDallaLista(Videogame* = nullptr);
    unsigned int numeroElementiInNegozio() const;
    double totaleCostoProdottiInNegozio() const;
};

#endif // MODELLO_H
