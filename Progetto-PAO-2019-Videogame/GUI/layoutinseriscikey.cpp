#include "GUI/layoutinseriscikey.h"

LayoutInserisciKey::LayoutInserisciKey(QWidget* p): parent(p),
    tabellaKey(new QFormLayout(this)),
    scontoKeyAnnual(new QLineEdit(this)) {

    //tabellaKey->setLabelAlignment(Qt::AlignTop);

    tabellaKey->addRow("Sconto annuale key: ", scontoKeyAnnual);
    scontoKeyAnnual->setPlaceholderText("Inserire sconto annuale key");
    scontoKeyAnnual->setValidator(new QIntValidator(0, 50, this));
    scontoKeyAnnual->setMaxLength(2);
}

QLineEdit* LayoutInserisciKey::getScontoKeyAnnual() const { return scontoKeyAnnual; }

void LayoutInserisciKey::clearQLineEditKey() const {
    scontoKeyAnnual->deselect();
    scontoKeyAnnual->clear();
}
