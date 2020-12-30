#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GUI/videogamewidgetlista.h"
#include "GUI/popupdigitalkey.h"
#include "GUI/popupdigitaldlc.h"
#include "GUI/popupcollectorsedition.h"
#include "GUI/popupgioconuovo.h"
#include "GUI/popupgiocousato.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>


class MainWindow: public QWidget {
    Q_OBJECT
private:
    QWidget* parent;
    QVBoxLayout* contieniTutto;
    QHBoxLayout* contieniButtons;
    QVBoxLayout* contieniLista;
    VideogameWidgetLista* lista;
    QPushButton* bottoneModifica;
    QPushButton* bottoneRimuovi;
    const QSize btnSize;
    //PopUpGiocoNuovo* popNuo;
public:
    MainWindow(QWidget* = nullptr);
    QVBoxLayout* getContieniTutto() const;
    QHBoxLayout* getContieniButtons() const;
    QVBoxLayout* getContieniLista() const;
    VideogameWidgetLista* getLista() const;
    QPushButton* getModifica() const;
    QPushButton* getRimuovi() const;
private slots:
    void elementoSelezionatoDallaLista() const;
    //void showPopUp() const;
};

#endif // MAINWINDOW_H
