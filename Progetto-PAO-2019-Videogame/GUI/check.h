#ifndef CHECK_H
#define CHECK_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QFileDialog>

#include "controller.h"

class Controller;

class Check : public QWidget {
	Q_OBJECT
private:
    Controller *controller;
	QListWidget *list;
    QLineEdit *tag; //form

public:
    Check(QWidget *parent = nullptr);
	~Check();

	QString getTag() const;
	QString selectedItem() const;

    void add();
	void remove() const;
	QString savePath();
};

#endif // WIDGET_H
