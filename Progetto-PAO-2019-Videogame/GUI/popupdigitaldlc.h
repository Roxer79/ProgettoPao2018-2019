#ifndef POPUPDIGITALDLC_H
#define POPUPDIGITALDLC_H

#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinseriscidigital.h"
#include "GUI/layoutinseriscidlc.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class PopUpDigitalDlc: public QDialog {
private:
    QVBoxLayout* contenitoreDigDlc;
    LayoutInserisciVideogame* popUpVidDlc;
    LayoutInserisciDigital* popUpDigDlc;
    LayoutInserisciDlc* popUpDlcDlc;
    QHBoxLayout* contieniLabelEBottone;
    QLabel* aggiungiImmagine;
    QIcon icona;
    QPushButton* bottoneModificaFoto;
    QHBoxLayout* contieniBottoniSmAm;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* bottoneAnnullaModifiche;
public:
    PopUpDigitalDlc(QWidget* = nullptr, Dlc* ogg = nullptr);
    QPushButton* getBottoneModificaFoto() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getBottoneAnnullaModifiche() const;
};

#endif // POPUPDIGITALDLC_H
