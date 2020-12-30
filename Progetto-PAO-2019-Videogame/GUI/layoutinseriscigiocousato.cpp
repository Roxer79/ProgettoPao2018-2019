#include "GUI/layoutinseriscigiocousato.h"

LayoutInserisciGiocoUsato::LayoutInserisciGiocoUsato(QWidget* p): parent(p),
    tabellaGiocoUsato(new QFormLayout(this)),
    scatolaInteg(new QComboBox(this)),
    sovraPrezzoScatolaInt(new QLineEdit(this)),
    scontoAnnualSH(new QLineEdit(this)) {

    //tabellaGiocoUsato->setLabelAlignment(Qt::AlignTop);;

    tabellaGiocoUsato->addRow("Scatola integra: ", scatolaInteg);
    scatolaInteg->addItem("No");
    scatolaInteg->addItem("Si");
    tabellaGiocoUsato->addRow("Sovrapprezzo sca-int: ", sovraPrezzoScatolaInt);
    sovraPrezzoScatolaInt->setPlaceholderText("Inserire sovrapprezzo scatola integra");
    sovraPrezzoScatolaInt->setValidator(new QIntValidator(1, 10, this));
    sovraPrezzoScatolaInt->setMaxLength(2);
    tabellaGiocoUsato->addRow("Sconto annuale GU: ", scontoAnnualSH);
    scontoAnnualSH->setPlaceholderText("Inserire sconto annuale gioco usato");
    scontoAnnualSH->setValidator(new QIntValidator(0, 50, this));
    scontoAnnualSH->setMaxLength(2);
}

QComboBox* LayoutInserisciGiocoUsato::getScatolaInteg() const { return scatolaInteg; }

QLineEdit* LayoutInserisciGiocoUsato::getSovraPrezzoScatolaInt() const { return sovraPrezzoScatolaInt; }

QLineEdit* LayoutInserisciGiocoUsato::getScontoAnnualSH() const { return scontoAnnualSH; }

void LayoutInserisciGiocoUsato::clearQLineEditGiocoUsato() const {
    scatolaInteg->setCurrentIndex(0);
    sovraPrezzoScatolaInt->deselect();
    sovraPrezzoScatolaInt->clear();
    scontoAnnualSH->deselect();
    scontoAnnualSH->clear();
}
