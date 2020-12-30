#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "GUI/menuprogetto.h"
#include "GUI/mainwindow.h"
#include "GUI/layoutinserisci.h"
#include "GUI/layoutricercaperoggetti.h"
#include "GUI/layoutricerca.h"
#include "GUI/popupgenerico.h"
#include "modello.h"

#include <iostream>
#include <QFileDialog>
#include <QList>
#include <QMessageBox>

#include <QDesktopWidget>
#include <QStyle>
#include <QApplication>

class Controller: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    MenuProgetto* miomenu;
    MainWindow* mainwind;
    LayoutInserisci* layIns;
    LayoutRicercaPerOggetti* layRicPerOgg;
    LayoutRicerca* layRic;
    QVBoxLayout* layoutPrincipale;
    PopUpGenerico* popGen;
    Modello* model;
    QString file;
public:
    Controller(Modello* /*= nullptr*/, QWidget* = nullptr);
    //~Controller();
    MenuProgetto* getMioMenu() const;
    //QVBoxLayout* getLayoutPrincipale() const;
    Modello* getModel() const;
    void caricaDati() const;
    void disabilitaTutto() const;
    void abilitaTutto() const;
    unsigned int controlloNumeroElementiLista() const;
    //void salvaDatiXMLAllaChiusura() const;
//private slots:
    //void closeEvent(QCloseEvent*);
public slots:
    void metMainWindow() const;
    void metLayoutInserisci() const;
    void metLayoutRicercaPerOggetti() const;
    void metLayoutRicerca() const;
    void caricaDatiXML();
    void salvaDatiXML() const;
    void salvaModificheDatoXML();
    void modificaCaricaPopUp() const;

    void aggiungiElementoAllaLista();
    void rimuoviDallaListaContainer();
    void ricercaOggetto() const;
    void ricercaOggettoPerStringa() const;

    void controlloNumeroElementiListaMessageBox() const;
    void informazioniQMessage() const;
    void riportaBugQmessage() const;
};

#endif // CONTROLLER_H
