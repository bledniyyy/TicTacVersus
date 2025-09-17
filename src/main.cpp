#include "mainwindow.h"
#include "settingswindow.h"
#include <QWindow>
#include <QApplication>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SettingsWindow SettingsWindow;

    QObject::connect(&w, &MainWindow::showsettings, [&]() {
        w.hide();
        SettingsWindow.show();
    });

    

    w.show();
    return a.exec();
}
