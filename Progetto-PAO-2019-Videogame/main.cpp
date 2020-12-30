#include "modello.h"
#include <QApplication>

#include "GUI/controller.h"
#include "modello.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller w(new Modello());
    w.show();

    return a.exec();
}
