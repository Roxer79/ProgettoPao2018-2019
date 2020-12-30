#include "GUI/layoutinseriscigioconuovo.h"

LayoutInserisciGiocoNuovo::LayoutInserisciGiocoNuovo(QWidget* p): parent(p),
    tabellaGiocoNuovo(new QFormLayout(this)),
    edizioneLim(new QComboBox(this)),
    sovraPrezzoEdizioneLim(new QLineEdit(this)),
    scontoAnnualGam(new QLineEdit(this)) {

    //tabellaGiocoNuovo->setLabelAlignment(Qt::AlignTop);

    tabellaGiocoNuovo->addRow("Edizione limitata: ", edizioneLim);
    edizioneLim->addItem("No");
    edizioneLim->addItem("Si");
    tabellaGiocoNuovo->addRow("Sovrapprezzo edi-lim: ", sovraPrezzoEdizioneLim);
    sovraPrezzoEdizioneLim->setPlaceholderText("Inserire sovrapprezzo edizione limitata");
    sovraPrezzoEdizioneLim->setValidator(new QIntValidator(1, 100, this));
    sovraPrezzoEdizioneLim->setMaxLength(2);
    tabellaGiocoNuovo->addRow("Sconto annuale GN: ", scontoAnnualGam);
    scontoAnnualGam->setPlaceholderText("Inserire sconto annuale gioco nuovo");
    scontoAnnualGam->setValidator(new QIntValidator(0, 50, this));
    scontoAnnualGam->setMaxLength(2);
}

QComboBox* LayoutInserisciGiocoNuovo::getEdizioneLim() const { return edizioneLim; }

QLineEdit* LayoutInserisciGiocoNuovo::getSovraPrezzoEdizioneLim() const { return sovraPrezzoEdizioneLim; }

QLineEdit* LayoutInserisciGiocoNuovo::getScontoAnnualGam() const { return scontoAnnualGam; }

void LayoutInserisciGiocoNuovo::clearQLineEditGiocoNuovo() const {
    edizioneLim->setCurrentIndex(0);
    sovraPrezzoEdizioneLim->deselect();
    sovraPrezzoEdizioneLim->clear();
    scontoAnnualGam->deselect();
    scontoAnnualGam->clear();
}
