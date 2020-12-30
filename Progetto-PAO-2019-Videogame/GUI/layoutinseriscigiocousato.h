#ifndef LAYOUTINSERISCIGIOCOUSATO_H
#define LAYOUTINSERISCIGIOCOUSATO_H

#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>

class LayoutInserisciGiocoUsato: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaGiocoUsato;
    QComboBox* scatolaInteg;
    QLineEdit* sovraPrezzoScatolaInt;
    QLineEdit* scontoAnnualSH;
public:
    LayoutInserisciGiocoUsato(QWidget* = nullptr);
    QComboBox* getScatolaInteg() const;
    QLineEdit* getSovraPrezzoScatolaInt() const;
    QLineEdit* getScontoAnnualSH() const;
    void clearQLineEditGiocoUsato() const;
};

#endif // LAYOUTINSERISCIGIOCOUSATO_H
