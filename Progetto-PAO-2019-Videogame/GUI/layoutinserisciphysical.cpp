#include "GUI/layoutinserisciphysical.h"

LayoutInserisciPhysical::LayoutInserisciPhysical(QWidget* p): parent(p),
    tabellaPhysical(new QFormLayout(this)),
    barCod(new QLineEdit(this)),
    descrizioneEti(new QLineEdit(this)) {

    //tabellaPhysical->setLabelAlignment(Qt::AlignTop);

    tabellaPhysical->addRow("BarCode: ", barCod);
    barCod->setPlaceholderText("Inserire codice a barre");
    barCod->setValidator(new QIntValidator(0, 999999999, barCod));
    barCod->setMaxLength(9);
    tabellaPhysical->addRow("Descrizione etichetta: ", descrizioneEti);
    descrizioneEti->setPlaceholderText("Inserire descrizione etichetta");
    descrizioneEti->setMaxLength(80);
}

QLineEdit* LayoutInserisciPhysical::getBarCod() const { return barCod; }

QLineEdit* LayoutInserisciPhysical::getDescrizioneEti() const { return descrizioneEti; }

void LayoutInserisciPhysical::clearQLineEditPhysical() const {
    barCod->deselect();
    barCod->clear();
    descrizioneEti->deselect();
    descrizioneEti->clear();
}
