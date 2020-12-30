#ifndef LAYOUTINSERISCICOLLECTORSEDITION_H
#define LAYOUTINSERISCICOLLECTORSEDITION_H

#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>

class LayoutInserisciCollectorsEdition: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaCollEdit;
    QComboBox* actionFig;
    QLineEdit* sovraPrezzoActionFig;
    QLineEdit* scontoCollEdit;
public:
    LayoutInserisciCollectorsEdition(QWidget* = nullptr);
    QComboBox* getActionFig() const;
    QLineEdit* getSovraPrezzoActionFig() const;
    QLineEdit* getScontoCollEdit() const;
    void clearQLineEditCollectosEdition() const;
};

#endif // LAYOUTINSERISCICOLLECTORSEDITION_H
