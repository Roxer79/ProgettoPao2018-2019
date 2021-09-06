#ifndef LAYOUTINSERISCIVIDEOGAME_H
#define LAYOUTINSERISCIVIDEOGAME_H

#include "Gerarchia/gerarchiavideogame.h"

#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>
#include <QLabel>

class LayoutInserisciVideogame: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    //QLabel* avvisoCampiObbligatori;
    QFormLayout* tabellaVideogame;
    QLineEdit* titVideogioco;
    QComboBox* disponibil;
    QLineEdit* prezBase;
    QDoubleValidator* prezMinMax;
    QLineEdit* quantInStock;
    QLineEdit* casProduttice;
    QLineEdit* annoPubbl;
    QLineEdit* peg;
    QLineEdit* genGioco;
    QLineEdit* tipoDiPiatta;
    QComboBox* appliSconto;
public:
    LayoutInserisciVideogame(QWidget* = nullptr);
    QLineEdit* getTitVideogioco() const;
    QComboBox* getDisponibil() const;
    QLineEdit* getPrezBase() const;
    QLineEdit* getQuantInStock() const;
    QLineEdit* getCasProduttice() const;
    QLineEdit* getAnnoPubl() const;
    QLineEdit* getPeg() const;
    QLineEdit* getGenGioco() const;
    QLineEdit* getTipoDiPiatta() const;
    QComboBox* getAppliSconto() const;
    void clearQLineEditVideogame() const;
};

//qmessagebox da fare if else che mi ritrona un bool così posso unire i vari layout

#endif // LAYOUTINSERISCIVIDEOGAME_H
