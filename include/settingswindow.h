#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>


namespace Ui {
class SettingsWindow;  // Forward declaration
}

class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

private:
    Ui::SettingsWindow *ui;  
};

#endif // SETTINGSWINDOW_H