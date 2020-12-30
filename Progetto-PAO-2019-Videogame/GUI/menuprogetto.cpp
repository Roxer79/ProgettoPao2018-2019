#include "GUI/menuprogetto.h"

MenuProgetto::MenuProgetto(QWidget* p): parent(p),
    file(new QMenu("File", this)), salva(new QAction("Salva", file)), caricaDati(new QAction("Carica dati", file)), salvaEdEsci(new QAction("Salva ed esci", file)), esci(new QAction("Esci", file)),
    negozio(new QAction("Negozio", p)),
    inserisci(new QAction("Inserisci nel catalogo", p)),
    ricerca(new QMenu("Ricerca", this)), ricercaNelCatalogoPerOggetto(new QAction("Ricerca specifica", ricerca)), ricercaGenericaStringa(new QAction("Ricerca generica", ricerca)),
    funzionalitaGestore(new QMenu("Funzionalità", this)), numElementiNegozio(new QAction("Elementi in negozio", funzionalitaGestore)),
    help(new QMenu("Aiuto", this)), informazioni(new QAction("Informazioni", help)), reportBug(new QAction("Riporta bug", help)) {

    addMenu(file);
    file->addAction(salva);
    file->addAction(caricaDati);
    file->addAction(salvaEdEsci);
    file->addAction(esci);

    addAction(negozio);

    addAction(inserisci);

    addMenu(ricerca);
    ricerca->addAction(ricercaNelCatalogoPerOggetto);
    ricerca->addAction(ricercaGenericaStringa);
    addMenu(funzionalitaGestore);
    funzionalitaGestore->addAction(numElementiNegozio);

    addMenu(help);
    help->addAction(informazioni);
    help->addAction(reportBug);

    //aggiungere SIGNAL e SLOT
    connect(caricaDati, SIGNAL(triggered()), parent, SLOT(caricaDatiXML()));
    connect(salva, SIGNAL(triggered()), parent, SLOT(salvaDatiXML()));
    //connect(salva, SIGNAL(triggered()), parent, SLOT());
    connect(salvaEdEsci, SIGNAL(triggered()), parent, SLOT(salvaDatiXML()));
    connect(salvaEdEsci, SIGNAL(triggered()), parent, SLOT(close()));
    connect(esci, SIGNAL(triggered()), parent, SLOT(close()));

    connect(negozio, SIGNAL(triggered()), parent, SLOT(metMainWindow()));

    connect(inserisci, SIGNAL(triggered()), parent, SLOT(metLayoutInserisci()));

    connect(ricercaNelCatalogoPerOggetto, SIGNAL(triggered()), parent, SLOT(metLayoutRicercaPerOggetti()));
    connect(ricercaGenericaStringa, SIGNAL(triggered()), parent, SLOT(metLayoutRicerca()));

    connect(numElementiNegozio, SIGNAL(triggered()), parent, SLOT(controlloNumeroElementiListaMessageBox()));

    connect(informazioni, SIGNAL(triggered()), parent, SLOT(informazioniQMessage()));
    connect(reportBug, SIGNAL(triggered()), parent, SLOT(riportaBugQmessage()));
}

QMenu* MenuProgetto::getFile() const { return file; }

QAction* MenuProgetto::getSalva() const { return salva; }

QAction* MenuProgetto::getCaricaDati() const { return caricaDati; }

QAction* MenuProgetto::getSalvaEdEsci() const { return  salvaEdEsci; }

QAction* MenuProgetto::getEsci() const { return esci; }

/*QMenu* MenuProgetto::getNegozio() const { return negozio; }*/

QAction* MenuProgetto::getNegozio() const { return negozio; }

/*QAction* MenuProgetto::getElementiNegozio() const { return elementiNegozio; }*/

QAction* MenuProgetto::getInserisci() const { return inserisci; }

QMenu* MenuProgetto::getRicerca() const { return ricerca; }

QAction* MenuProgetto::getRicercaNelCatalogoPerOggetto() const { return ricercaNelCatalogoPerOggetto; }

QAction* MenuProgetto::getRicercaPerStringa() const { return ricercaGenericaStringa; }

QMenu* MenuProgetto::getFunzionalitaGestore() const { return funzionalitaGestore; }

QAction* MenuProgetto::getNumElementiNegozio() const { return numElementiNegozio; }

QMenu* MenuProgetto::getHelp() const { return help; }

QAction* MenuProgetto::getInformazioni() const { return informazioni; }

QAction* MenuProgetto::getReportBug() const { return reportBug; }
