#include "GUI/layoutinseriscivideogame.h"

LayoutInserisciVideogame::LayoutInserisciVideogame(QWidget* p): parent(p),
    //avvisoCampiObbligatori(new QLabel(this)),
    tabellaVideogame(new QFormLayout(this)),
    titVideogioco(new QLineEdit(this)),
    disponibil(new QComboBox(this)),
    prezBase(new QLineEdit(this)),
    prezMinMax(new QDoubleValidator(1.99, 999.99, 2, prezBase)),
    quantInStock(new QLineEdit(this)),
    casProduttice(new QLineEdit(this)),
    annoPubbl(new QLineEdit(this)),
    peg(new QLineEdit(this)),
    genGioco(new QLineEdit(this)),
    tipoDiPiatta(new QLineEdit(this)),
    appliSconto(new QComboBox(this)) {

    //tabellaVideogame->SetMaximumSize;
    //tabellaVideogame->setLabelAlignment(Qt::AlignTop);
    //avvisoCampiObbligatori->setText(QString("I campi con il '*' sono obbligatori"));

    tabellaVideogame->addRow("*Titolo videogame: ", titVideogioco);
    titVideogioco->setPlaceholderText("Inserire titolo videogioco");
    titVideogioco->setMaxLength(60);
    tabellaVideogame->addRow("Disponibile", disponibil);
    disponibil->addItem("No");
    disponibil->addItem("Si");
    tabellaVideogame->addRow("Prezzo: ", prezBase);
    prezBase->setPlaceholderText("Inserire prezzo base");
    prezBase->setValidator(prezMinMax);
    //prezMinMax->decimals();
    //prezMinMax->setDecimals(2);
    //prezMinMax->setNotation(QDoubleValidator::StandardNotation);
    prezBase->setMaxLength(6); //deccidere il da fars in base ad esigenze o metto prezzi minori di 5 cifre ad esempio xx,xx o boh
    prezMinMax->setNotation(QDoubleValidator::ScientificNotation);
    tabellaVideogame->addRow("Quantità in stock: ", quantInStock);
    quantInStock->setPlaceholderText("Inserire o aggiornare quantità in stock");
    quantInStock->setValidator(new QIntValidator(1, 9999, quantInStock));
    quantInStock->setMaxLength(4);
    tabellaVideogame->addRow("*Casa produttrice: ", casProduttice);
    casProduttice->setPlaceholderText("Inserire casa produttrice");
    casProduttice->setMaxLength(30);
    tabellaVideogame->addRow("*Anno di pubblicazione: ", annoPubbl);
    annoPubbl->setPlaceholderText("Inserire anno di pubblicazione");
    annoPubbl->setValidator(new QIntValidator(1958, 9999, annoPubbl));
    annoPubbl->setMaxLength(4);
    tabellaVideogame->addRow("Pegi: ", peg);
    peg->setPlaceholderText("Inserire pegi");
    peg->setValidator(new QIntValidator(0, 18, peg));
    peg->setMaxLength(2);
    tabellaVideogame->addRow("*Genere gioco: ", genGioco);
    genGioco->setPlaceholderText("Inserire genere gioco");
    genGioco->setMaxLength(50);
    tabellaVideogame->addRow("Piattaforma di gioco: ", tipoDiPiatta);
    tipoDiPiatta->setPlaceholderText("Inserire tipo di piattaforma del gioco");
    tipoDiPiatta->setMaxLength(20);
    tabellaVideogame->addRow("Applica sconto: ", appliSconto);
    appliSconto->addItem("No");
    appliSconto->addItem("Si");
}

QLineEdit* LayoutInserisciVideogame::getTitVideogioco() const { return titVideogioco; }

QComboBox* LayoutInserisciVideogame::getDisponibil() const { return disponibil; }

QLineEdit* LayoutInserisciVideogame::getPrezBase() const { return prezBase; }

QLineEdit* LayoutInserisciVideogame::getQuantInStock() const { return quantInStock; }

QLineEdit* LayoutInserisciVideogame::getCasProduttice() const { return casProduttice; }

QLineEdit* LayoutInserisciVideogame::getAnnoPubl() const { return annoPubbl; }

QLineEdit* LayoutInserisciVideogame::getPeg() const { return peg; }

QLineEdit* LayoutInserisciVideogame::getGenGioco() const { return genGioco; }

QLineEdit* LayoutInserisciVideogame::getTipoDiPiatta() const { return tipoDiPiatta; }

QComboBox* LayoutInserisciVideogame::getAppliSconto() const { return appliSconto; }

void LayoutInserisciVideogame::clearQLineEditVideogame() const {
    titVideogioco->deselect();
    titVideogioco->clear();
    disponibil->setCurrentIndex(0);
    prezBase->deselect();
    prezBase->clear();
    quantInStock->deselect();
    quantInStock->clear();
    casProduttice->deselect();
    casProduttice->clear();
    annoPubbl->deselect();
    annoPubbl->clear();
    peg->deselect();
    peg->clear();
    genGioco->deselect();
    genGioco->clear();
    tipoDiPiatta->deselect();
    tipoDiPiatta->clear();
    appliSconto->setCurrentIndex(0);
}
