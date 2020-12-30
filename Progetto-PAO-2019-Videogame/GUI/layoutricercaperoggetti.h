#ifndef LAYOUTRICERCAPEROGGETTI_H
#define LAYOUTRICERCAPEROGGETTI_H

#include "GUI/videogamewidgetlista.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QMessageBox>

class LayoutRicercaPerOggetti: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QVBoxLayout* contieTutto;
    QFormLayout* contieniCampiRicerca;
    QHBoxLayout* contieniAnnullaCerca;
    QHBoxLayout* contieniModCanc;
    QComboBox* sceltaDerivateRic;
    QLineEdit* lineTitoloVideogioco;
    QLineEdit* lineCasaProduttrice;
    QLineEdit* lineAnnoPubblicazione;
    QLineEdit* lineGenereGioco;
    QPushButton* bottonAnnullaRic;
    QPushButton* bottoneCercaOgg;
    VideogameWidgetLista* listaRicOgg;
    QPushButton* bottoneModificaOggRic;
    QPushButton* bottoneEliminaOggRic;
    const QSize sizeconstBtn;
public:
    LayoutRicercaPerOggetti(QWidget* = nullptr);
    QComboBox* getSceltaDerivateRic() const;
    QLineEdit* getLineTitoloVideogioco() const;
    QLineEdit* getLineCasaProduttrice() const;
    QLineEdit* getLineAnnoPubblicazione() const;
    QLineEdit* getLineGenereGioco() const;
    QPushButton* getBottonAnnullaRic() const;
    QPushButton* getBottoneCercaOgg() const;
    QPushButton* getBottoneModificaOggRic() const;
    QPushButton* getBottoneEliminaOggRic() const;
    VideogameWidgetLista* getListaRicOgg() const;
    void abilitaQLineEdit() const;
private slots:
    void disabilitaInBaseAlComboBox(int) const;
    void elementoSelezionatoDallaLista() const;
public slots:
    void disabilitaQLineEdit() const;
};

#endif // LAYOUTRICERCAPEROGGETTI_H
