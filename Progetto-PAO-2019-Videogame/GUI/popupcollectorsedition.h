#ifndef POPUPCOLLECTORSEDITION_H
#define POPUPCOLLECTORSEDITION_H

#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinserisciphysical.h"
#include "GUI/layoutinseriscicollectorsedition.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class PopUpCollEdition: public QDialog {
private:
    QVBoxLayout* contenitoreColEdit;
    LayoutInserisciVideogame* popUpVidCol;
    LayoutInserisciPhysical* popUpPhyCol;
    LayoutInserisciCollectorsEdition* popUpColCol;
    QHBoxLayout* contieniLabelEBottone;
    QLabel* aggiungiImmagine;
    QIcon icona;
    QPushButton* bottoneModificaFoto;
    QHBoxLayout* contieniBottoniSmAm;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* bottoneAnnullaModifiche;
public:
    PopUpCollEdition(QWidget* = nullptr, CollectorEdition* = nullptr);
    QPushButton* getBottoneModificaFoto() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getBottoneAnnullaModifiche() const;
};

#endif // POPUPCOLLECTORSEDITION_H
