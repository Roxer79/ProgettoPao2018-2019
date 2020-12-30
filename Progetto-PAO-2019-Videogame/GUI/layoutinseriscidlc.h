#ifndef LAYOUTINSERISCIDLC_H
#define LAYOUTINSERISCIDLC_H

#include <QFormLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QWidget>

class LayoutInserisciDlc: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaDlc;
    QLineEdit* nomDlc;
    QLineEdit* scontoDlcAnnual; 
public:
    LayoutInserisciDlc(QWidget* = nullptr);
    QLineEdit* getNomDlc() const;
    QLineEdit* getScontoDlcAnnual() const;
    void clearQLineEditDlc() const;
};

#endif // LAYOUTINSERISCIDLC_H
