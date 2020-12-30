#ifndef POPUPDIGITALKEY_H
#define POPUPDIGITALKEY_H

#include "GUI/layoutinseriscivideogame.h"
#include "GUI/layoutinseriscidigital.h"
#include "GUI/layoutinseriscikey.h"


#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

class PopUpDigitalKey: public QDialog {
private:
    QWidget* parent;
    QVBoxLayout* contenitoreDigKey;
    LayoutInserisciVideogame* popUpVidKey;
    LayoutInserisciDigital* popUpDigKey;
    LayoutInserisciKey* popUpKeyKey;
    QHBoxLayout* contieniLabelEBottone;
    QLabel* aggiungiImmagine;
    QPushButton* bottoneModificaFoto;
    QHBoxLayout* contieniBottoniSmAm;
    QPushButton* bottoneSalvaModifiche;
    QPushButton* bottoneAnnullaModifiche;
public:
    PopUpDigitalKey(QWidget* = nullptr);
    LayoutInserisciVideogame* getLayoutInserisciVideogame() const;
    QPushButton* getBottoneModificaFoto() const;
    QPushButton* getBottoneSalvaModifiche() const;
    QPushButton* getBottoneAnnullaModifiche() const;
};

#endif // POPUPDIGITALKEY_H
