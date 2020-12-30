#ifndef LAYOUTINSERISCIGIOCONUOVO_H
#define LAYOUTINSERISCIGIOCONUOVO_H

#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>

class LayoutInserisciGiocoNuovo: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaGiocoNuovo;
    QComboBox* edizioneLim;
    QLineEdit* sovraPrezzoEdizioneLim;
    QLineEdit* scontoAnnualGam;
public:
    LayoutInserisciGiocoNuovo(QWidget* = nullptr);
    QComboBox* getEdizioneLim() const;
    QLineEdit* getSovraPrezzoEdizioneLim() const;
    QLineEdit* getScontoAnnualGam() const;
    void clearQLineEditGiocoNuovo() const;
};

#endif // LAYOUTINSERISCIGIOCONUOVO_H
