#ifndef POPUPGENERICO_H
#define POPUPGENERICO_H

//#include "modello.h"
//#include "controller.h"
#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinserisciphysical.h"
#include "GUI/layoutinseriscidigital.h"
#include "GUI/layoutinseriscikey.h"
#include "GUI/layoutinseriscidlc.h"
#include "GUI/layoutinseriscicollectorsedition.h"
#include "GUI/layoutinseriscigioconuovo.h"
#include "GUI/layoutinseriscigiocousato.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>

class PopUpGenerico: public QDialog {
    Q_OBJECT
private:
    QWidget* parent;
    QVBoxLayout* contenitorePopUp;
    QLabel* avvisoCampiObbligatori;
    LayoutInserisciVideogame* popUpVid;
    LayoutInserisciPhysical* popUpPhy;
    LayoutInserisciDigital* popUpDig;
    LayoutInserisciKey* popUpKey;
    LayoutInserisciDlc* popUpDlc;
    LayoutInserisciCollectorsEdition* popUpCol;
    LayoutInserisciGiocoNuovo* popUpNuo;
    LayoutInserisciGiocoUsato* popUpUsa;
    QHBoxLayout* contieniLabelEBottone;
    QLabel* aggiungiDescrizione;
    QPushButton* bottoneModificaFoto;
    QHBoxLayout* contieniBottoniSmAm;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* bottoneAnnullaModifiche;
    Videogame* oggettoPassato;
    QString icona;
public:
    PopUpGenerico(QWidget* = nullptr/*, Videogame* = nullptr, Modello* = nullptr*/);
    QVBoxLayout* getContenitorePopUp() const;
    LayoutInserisciVideogame* getPopUpVid() const;
    LayoutInserisciPhysical* getPopUpPhy() const;
    LayoutInserisciDigital* getPopUpDig() const;
    LayoutInserisciKey* getPopUpKey() const;
    LayoutInserisciDlc* getPopUpDlc() const;
    LayoutInserisciCollectorsEdition* getPopUpCol() const;
    LayoutInserisciGiocoNuovo* getPopUpNuo() const;
    LayoutInserisciGiocoUsato* getPopUpUsa() const;
    QPushButton* getBottoneModificaFoto() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getBottoneAnnullaModifiche() const;
    QString getIcona() const;
    void setNuovaIcona(std::string);
    bool lanciaErroriInserimento() const;
    //void setLayoutHideAndClear() const;
private slots:
    void reject();
    void cambiaIcona();
public slots:
    void setLayoutHideAndClear() const;
};

#endif // POPUPGENERICO_H
