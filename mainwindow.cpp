#include <iostream>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::startButtonSlot);
    ui->gameFieldBox->hide();
    MainWindow::connectingFields();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startButtonSlot() {
    ui->StartButton->hide();
    ui->OffMusic->hide();
    ui->gameFieldBox->show();
    qDebug() << "hello" << "\n"; 
}

void MainWindow::clickOnField() {
    QToolButton *button = qobject_cast<QToolButton*>(sender());
    if (button) {
        qDebug() << "Нажата кнопка:" << button->objectName();
        
        // Можно также получить координаты из имени
        QString name = button->objectName();
        if (name.startsWith("cell_")) {
            QStringList parts = name.split('_');
            if (parts.size() == 3) {
                int row = parts[1].toInt();
                int col = parts[2].toInt();
                qDebug() << "Координаты: строка" << row << "столбец" << col;
            }
        }
    }
}

void MainWindow::connectingFields() {
    connect(ui->cell_0_0, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_1_0, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_2_0, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_0_1, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_1_1, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_2_1, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_0_2, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_1_2, &QToolButton::clicked, this, &MainWindow::clickOnField);
    connect(ui->cell_2_2, &QToolButton::clicked, this, &MainWindow::clickOnField);
}