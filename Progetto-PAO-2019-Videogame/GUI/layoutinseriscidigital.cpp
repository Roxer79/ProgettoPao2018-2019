#include "GUI/layoutinseriscidigital.h"

LayoutInserisciDigital::LayoutInserisciDigital(QWidget* p): parent(p),
    tabellaDigital(new QFormLayout(this)),
    piattaRiscattoCodice(new QLineEdit(this)),
    codiceAlfaNum(new QLineEdit(this)),
    descrizioneDigi(new QLineEdit(this)) {

    //tabellaDigital->setLabelAlignment(Qt::AlignTop);

    tabellaDigital->addRow("Piattaforma riscatto: ", piattaRiscattoCodice);
    piattaRiscattoCodice->setPlaceholderText("Inserire piattaforma riscatto codice");
    piattaRiscattoCodice->setMaxLength(30);
    tabellaDigital->addRow("Codice alfanum: ", codiceAlfaNum);
    codiceAlfaNum->setPlaceholderText("Inserire codice alfanumerico");
    codiceAlfaNum->setMaxLength(20);
    tabellaDigital->addRow("Descrizione prodotto: ", descrizioneDigi);
    descrizioneDigi->setPlaceholderText("Inserire descrizione prodotto");
    descrizioneDigi->setMaxLength(80);
}

QLineEdit* LayoutInserisciDigital::getPiattaRiscattoCodice() const { return piattaRiscattoCodice; }

QLineEdit* LayoutInserisciDigital::getCodiceAlfaNum() const { return codiceAlfaNum; }

QLineEdit* LayoutInserisciDigital::getDescrizioneDigi() const { return descrizioneDigi; }

void LayoutInserisciDigital::clearQLineEditDigital() const {
    piattaRiscattoCodice->deselect();
    piattaRiscattoCodice->clear();
    codiceAlfaNum->deselect();
    codiceAlfaNum->clear();
    descrizioneDigi->deselect();
    descrizioneDigi->clear();
}

