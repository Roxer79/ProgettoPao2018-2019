#ifndef POPUPGIOCOUSATO_H
#define POPUPGIOCOUSATO_H

#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinserisciphysical.h"
#include "GUI/layoutinseriscigiocousato.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class PopUpGiocoUsato: public QDialog {
    //Q_OBJECT
private:
    QVBoxLayout* contenitoreGioUsa;
    LayoutInserisciVideogame* popUpVidUsa;
    LayoutInserisciPhysical* popUpPhyUsa;
    LayoutInserisciGiocoUsato* popUpUsaUsa;
    QHBoxLayout* contieniLabelEBottone;
    QLabel* aggiungiImmagine;
    QIcon icona;
    QPushButton* bottoneModificaFoto;
    QHBoxLayout* contieniBottoniSmAm;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* bottoneAnnuallaModiche;
public:
    PopUpGiocoUsato(QWidget* = nullptr, SecondHand* = nullptr);
    QPushButton* getBottoneModificaFoto() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getBottoneAnnullaModifiche() const;
//private slots:
    //void salvaModificheDatoXML();
};

#endif // POPUPGIOCOUSATO_H
