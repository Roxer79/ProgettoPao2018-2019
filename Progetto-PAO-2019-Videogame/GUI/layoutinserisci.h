#ifndef LAYOUTINSERISCI_H
#define LAYOUTINSERISCI_H

#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinserisciphysical.h"
#include "GUI/layoutinseriscidigital.h"
#include "GUI/layoutinseriscikey.h"
#include "GUI/layoutinseriscidlc.h"
#include "GUI/layoutinseriscicollectorsedition.h"
#include "GUI/layoutinseriscigioconuovo.h"
#include "GUI/layoutinseriscigiocousato.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>

class LayoutInserisci: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QVBoxLayout* contieniTut;
    QLabel* avvisoCampiObbligatori;
    QVBoxLayout* contieniLayout;
    QHBoxLayout* contieniVideogame;
    QHBoxLayout* contieniDigitalPhysical;
    QHBoxLayout* contieniKeDlCeGnGu;
    QHBoxLayout* contientiAggCan;
    QComboBox* boxSceltaDerivateInserisci;
    LayoutInserisciVideogame* layInsVid;
    LayoutInserisciPhysical* layInsPhy;
    LayoutInserisciDigital* layInsDig;
    LayoutInserisciKey* layInsKey;
    LayoutInserisciDlc* layInsDlc;
    LayoutInserisciCollectorsEdition* layInsCse;
    LayoutInserisciGiocoNuovo* layInsNuo;
    LayoutInserisciGiocoUsato* layInsUsa;
    QHBoxLayout* contieniLabelBottone;
    QLabel* scrittaLabel; //provvisorio da cambiare con altro
    QPushButton* bottoneAggiungiImmagine;
    QPushButton* bottoneAggiungi;
    QPushButton* bottoneCancellaTutto;
    QString icona;
    const QSize sizBtn;
public:
    LayoutInserisci(QWidget* = nullptr);
    QComboBox* getSceltaDerivate() const;
    LayoutInserisciVideogame* getLayoutInserisciVideogame() const;
    LayoutInserisciPhysical* getLayoutInserisciPhysical() const;
    LayoutInserisciDigital* getLayoutInserisciDigital() const;
    LayoutInserisciKey* getLayoutInserisciKey() const;
    LayoutInserisciDlc* getLayoutInserisciDlc() const;
    LayoutInserisciCollectorsEdition* getLayoutInserisciCollectorsEdition() const;
    LayoutInserisciGiocoNuovo* getLayoutInserisciGiocoNuovo() const;
    LayoutInserisciGiocoUsato* getLayoutInserisciGiocoUsato() const;
    QPushButton* getBottoneAggiungiImmagine() const;
    QPushButton* getBottoneAggiungi() const;
    QPushButton* getBottoneCancellaTutto() const;
    QString getIcona() const;
    //void seNuovaIcona();
    void changeIndexBoxScelteDerivateInserisci() const;
    //void clearTutteQLineEdit() const;
public slots:
    void clearTutteQLineEdit() const;
    void metLayoutInserisciVideogame(int) const;
    void cambiaIconaInserisci();
};

#endif // LAYOUTINSERISCI_H
