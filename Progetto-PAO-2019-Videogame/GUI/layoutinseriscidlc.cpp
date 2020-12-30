#include "GUI/layoutinseriscidlc.h"

LayoutInserisciDlc::LayoutInserisciDlc(QWidget* p): parent(p),
    tabellaDlc(new QFormLayout(this)),
    nomDlc(new QLineEdit(this)),
    scontoDlcAnnual(new QLineEdit(this)) {

    //tabellaDlc->setLabelAlignment(Qt::AlignTop);

    tabellaDlc->addRow("Nome dlc: ", nomDlc);
    nomDlc->setPlaceholderText("Inserire nome dlc");
    nomDlc->setMaxLength(50);
    tabellaDlc->addRow("Sconto annuale dlc: ", scontoDlcAnnual);
    scontoDlcAnnual->setPlaceholderText("Inserire sconto annuale dlc");
    scontoDlcAnnual->setValidator(new QIntValidator(0, 50, this));
    scontoDlcAnnual->setMaxLength(2);
}

QLineEdit* LayoutInserisciDlc::getNomDlc() const { return nomDlc; }

QLineEdit* LayoutInserisciDlc::getScontoDlcAnnual() const { return scontoDlcAnnual; }

void LayoutInserisciDlc::clearQLineEditDlc() const {
    nomDlc->deselect();
    nomDlc->clear();
    scontoDlcAnnual->deselect();
    scontoDlcAnnual->clear();
}
