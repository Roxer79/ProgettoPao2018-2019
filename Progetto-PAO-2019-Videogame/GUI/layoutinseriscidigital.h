#ifndef LAYOUTINSERISCIDIGITAL_H
#define LAYOUTINSERISCIDIGITAL_H

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>

class LayoutInserisciDigital: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaDigital;
    QLineEdit* piattaRiscattoCodice;
    QLineEdit* codiceAlfaNum;
    QLineEdit* descrizioneDigi;
public:
    LayoutInserisciDigital(QWidget* = nullptr);
    QLineEdit* getPiattaRiscattoCodice() const;
    QLineEdit* getCodiceAlfaNum() const;
    QLineEdit* getDescrizioneDigi() const;
    void clearQLineEditDigital() const;
};

#endif // LAYOUTINSERISCIDIGITAL_H
