#ifndef MENUPROGETTO_H
#define MENUPROGETTO_H

#include <QMenuBar>
#include <QWidget>

class MenuProgetto: public QMenuBar {
    Q_OBJECT
private:
    QWidget* parent;
    QMenu* file;
    QAction* salva;
    QAction* caricaDati;
    QAction* salvaEdEsci;
    QAction* esci;
    /*QMenu* negozio;*/
    QAction* negozio; //homepage
    /*QAction* elementiNegozio;*/
    QAction* inserisci;
    QMenu* ricerca;
    QAction* ricercaNelCatalogoPerOggetto;
    QAction* ricercaGenericaStringa;
    QMenu* funzionalitaGestore;
    QAction* numElementiNegozio;
    QMenu* help;
    QAction* informazioni;
    QAction* reportBug;
public:
    MenuProgetto(QWidget *parent = nullptr);
    QMenu* getFile() const;
    QAction* getSalva() const;
    QAction* getCaricaDati() const;
    QAction* getSalvaEdEsci() const;
    QAction* getEsci() const;
    /*QMenu* getNegozio() const;*/
    QAction* getNegozio() const;
    /*QAction* getElementiNegozio() const;*/
    QAction* getInserisci() const;
    QMenu* getRicerca() const;
    QAction* getRicercaNelCatalogoPerOggetto() const;
    QAction* getRicercaPerStringa() const;
    QMenu* getFunzionalitaGestore() const;
    QAction* getNumElementiNegozio() const;
    QMenu* getHelp() const;
    QAction* getInformazioni() const;
    QAction* getReportBug() const;
};

#endif // MENUPROGETTO_H
