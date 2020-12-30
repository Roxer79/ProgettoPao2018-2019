#ifndef LAYOUTINSERISCIPHYSICAL_H
#define LAYOUTINSERISCIPHYSICAL_H

#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>
#include <QIntValidator>

class LayoutInserisciPhysical: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QFormLayout* tabellaPhysical;
    QLineEdit* barCod;
    QLineEdit* descrizioneEti;
public:
    LayoutInserisciPhysical(QWidget* = nullptr);
    QLineEdit* getBarCod() const;
    QLineEdit* getDescrizioneEti() const;
    void clearQLineEditPhysical() const;
};


#endif // LAYOUTINSERISCIPHYSICAL_H
