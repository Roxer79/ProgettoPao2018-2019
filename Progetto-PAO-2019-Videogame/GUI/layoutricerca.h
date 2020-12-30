#ifndef LAYOUTRICERCA_H
#define LAYOUTRICERCA_H

#include "GUI/videogamewidgetlista.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
//#include <QCheckBox>
#include <QComboBox>

class LayoutRicerca: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QVBoxLayout* conTutto;
    QFormLayout* contieniRicerca;
    QHBoxLayout* conButRicerca;
    QHBoxLayout* conButRimMod;
    QLineEdit* barraRicerca;
    QPushButton* bottoneModifica;
    QPushButton* botRimuovi;
    QPushButton* bottoneRicerca;
    QPushButton* bottoneAnnullaRicerca;
    VideogameWidgetLista* casellaLista;
    const QSize sizeBtn;
public:
    LayoutRicerca(QWidget* = nullptr);
    QLineEdit* getBarraRicerca() const;
    QPushButton* getBottoneModifica() const;
    QPushButton* getBotRimuovi() const;
    QPushButton* getBottoneRicerca() const;
    QPushButton* getBottoneAnnullaRicerca() const;
    VideogameWidgetLista* getCasellaLista() const;
    void disabilitaTutto() const;
    void abilitaTutto() const;
private slots:
    void elementoSelezionatoDallaLista() const;
    //void attivaDopoAverInseritoTesto() const;
    //void rimuoviDallaRicerca() const;
public slots:
    void annullaRicerca() const;
};

#endif // LAYOUTRICERCA_H
