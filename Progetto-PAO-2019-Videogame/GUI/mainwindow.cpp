#include "GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* p): parent(p),
    contieniTutto(new QVBoxLayout(this)),
    contieniButtons(new QHBoxLayout),
    contieniLista(new QVBoxLayout),
    lista(new VideogameWidgetLista(this)),
    bottoneModifica(new QPushButton("Modifica", this)),
    bottoneRimuovi(new QPushButton("Rimuovi", this)),
    btnSize(QSize(300, 40))
    /*popNuo(new PopUpGiocoNuovo)*/ {

    //contieniTutto->addWidget(lista);

    contieniTutto->addLayout(contieniLista);
    contieniLista->addWidget(lista);
    lista->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    lista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    contieniTutto->addLayout(contieniButtons);
    contieniButtons->addWidget(bottoneModifica);
    bottoneModifica->setEnabled(false);
    bottoneModifica->setFixedSize(btnSize);
    bottoneModifica->setStyleSheet("font: bold; font-size: 20px;");
    contieniButtons->addWidget(bottoneRimuovi);
    bottoneRimuovi->setEnabled(false);
    bottoneRimuovi->setFixedSize(btnSize);
    bottoneRimuovi->setStyleSheet("font: bold; font-size: 20px;");

    //popNuo->hide();
    //signal e slot

    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(elementoSelezionatoDallaLista()));
    //connect(lista, SIGNAL())
};

/*QVBoxLayout* MainWindow::getContieniTutto() const { return contieniTutto; }

QHBoxLayout* MainWindow::getContieniButtons() const { return contieniButtons; }

QVBoxLayout* MainWindow::getContieniLista() const { return contieniLista; }*/

VideogameWidgetLista* MainWindow::getLista() const { return lista; }

QPushButton* MainWindow::getModifica() const { return bottoneModifica; }

QPushButton* MainWindow::getRimuovi() const { return bottoneRimuovi; }

void MainWindow::elementoSelezionatoDallaLista() const {
    bottoneModifica->setEnabled(true);
    bottoneRimuovi->setEnabled(true);
}
