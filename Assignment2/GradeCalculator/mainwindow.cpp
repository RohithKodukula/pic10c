#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioButton->setChecked(true);
    ui->radioButton_2->setChecked(false);

    QObject::connect(ui->hw1spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw2spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw3spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw4spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw5spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw6spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw7spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->hw8spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));

    QObject::connect(ui->mid1spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->mid2spin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));
    QObject::connect(ui->finalspin, SIGNAL( valueChanged(int) ),this, SLOT(update_label()));

    QObject::connect(ui->radioButton, SIGNAL( toggle() ),this, SLOT(update_label()));
    QObject::connect(ui->radioButton_2, SIGNAL( toggle() ),this, SLOT(update_label()));

}

void MainWindow::update_label() const
{
    double hw1 = ui->hw1spin->value();
    double hw2 = ui->hw2spin->value();
    double hw3 = ui->hw3spin->value();
    double hw4 = ui->hw4spin->value();
    double hw5 = ui->hw5spin->value();
    double hw6 = ui->hw6spin->value();
    double hw7 = ui->hw7spin->value();
    double hw8 = ui->hw8spin->value();

    double mid1 = ui->mid1spin->value();
    double mid2 = ui->mid2spin->value();
    double final = ui->finalspin->value();

    if(ui->radioButton->isChecked())
    {
        double grade = (hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)*(.25/8)+(mid1+mid2)*(.4/2)+final*.35;
        QString text("Overal Score: " + QString::number(grade,'f',2));
        ui->label_12->setText(text);
    }
    else if(ui->radioButton_2->isChecked())
    {
        double grade = (hw1+hw2+hw3+hw4+hw5+hw6+hw7+hw8)*(.25/8)+(fmax(mid1, mid2))*(.3)+final*.44;
        QString text("Overal Score: " + QString::number(grade,'f',2));
        ui->label_12->setText(text);
    }
    else {}
}



MainWindow::~MainWindow()
{
    delete ui;
}
