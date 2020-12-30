#ifndef LAYOUTINSERISCIKEY_H
#define LAYOUTINSERISCIKEY_H

#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>
#include <QPushButton>

class LayoutInserisciKey: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaKey;
    QLineEdit* scontoKeyAnnual;
public:
    LayoutInserisciKey(QWidget* = nullptr);
    QLineEdit* getScontoKeyAnnual() const;
    void clearQLineEditKey() const;
};

#endif // LAYOUTINSERISCIKEY_H
