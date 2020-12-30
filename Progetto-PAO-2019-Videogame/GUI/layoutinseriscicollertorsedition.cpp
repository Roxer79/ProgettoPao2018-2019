#include "GUI/layoutinseriscicollectorsedition.h"

LayoutInserisciCollectorsEdition::LayoutInserisciCollectorsEdition(QWidget* p): parent(p),
    tabellaCollEdit(new QFormLayout(this)),
    actionFig(new QComboBox(this)),
    sovraPrezzoActionFig(new QLineEdit(this)),
    scontoCollEdit(new QLineEdit(this)) {

    //tabellaCollEdit->setLabelAlignment(Qt::AlignTop);

    tabellaCollEdit->addRow("Action Figure: ", actionFig);
    //addRow("Action Figure: ", actionFig);
    actionFig->addItem("No");
    actionFig->addItem("Si");
    tabellaCollEdit->addRow("Sovrapprezzo act-fig: ", sovraPrezzoActionFig);
    //addRow("Sovrapprezzo actfig: ", sovraPrezzoActionFig);
    sovraPrezzoActionFig->setPlaceholderText("Inserire sovrapprezzo action figure");
    sovraPrezzoActionFig->setValidator(new QIntValidator(0, 150, this));
    sovraPrezzoActionFig->setMaxLength(3);
    tabellaCollEdit->addRow("Sconto annuale CE: ", scontoCollEdit);
    //addRow("Sconto annuale: ", scontoCollEdit);
    scontoCollEdit->setPlaceholderText("Inserire sconto annuale collector's edition");
    scontoCollEdit->setValidator(new QIntValidator(0, 50, this));
    scontoCollEdit->setMaxLength(2);
}

QComboBox* LayoutInserisciCollectorsEdition::getActionFig() const { return actionFig; }

QLineEdit* LayoutInserisciCollectorsEdition::getSovraPrezzoActionFig() const { return sovraPrezzoActionFig; }

QLineEdit* LayoutInserisciCollectorsEdition::getScontoCollEdit() const { return scontoCollEdit; }

void LayoutInserisciCollectorsEdition::clearQLineEditCollectosEdition() const {
    actionFig->setCurrentIndex(0);
    sovraPrezzoActionFig->deselect();
    sovraPrezzoActionFig->clear();
    scontoCollEdit->deselect();
    scontoCollEdit->clear();
}
