#ifndef POPUPGIOCONUOVO_H
#define POPUPGIOCONUOVO_H

#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinserisciphysical.h"
#include "GUI/layoutinseriscigioconuovo.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class PopUpGiocoNuovo: public QDialog {
private:
    QVBoxLayout* contenitoreGioNuo;
    LayoutInserisciVideogame* popUpVidNuo;
    LayoutInserisciPhysical* popUpPhyNuo;
    LayoutInserisciGiocoNuovo* popUpGinNuo;
    QHBoxLayout* contieniLabelEBottone;
    QLabel* aggiungiImmagine;
    QIcon icona;
    QPushButton* bottoneModificaFoto;
    QHBoxLayout* contieniBottoniSmAm;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* bottoneAnnullaModifiche;
public:
    PopUpGiocoNuovo(QWidget* = nullptr, Game* = nullptr);
    QPushButton* getBottoneModificaFoto() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getBottoneAnnullaModifiche() const;
};

#endif // POPUPGIOCONUOVO_H
