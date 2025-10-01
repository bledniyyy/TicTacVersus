#ifndef MainWindow_H
#define MainWindow_H
#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>  // Добавьте нужные виджеты
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtMultimedia>
#include <QDebug>
#include <QString>
#include <QFont>
#include <QList>
#include <QFile>
#include <QIcon>
#include <QPixmap>
#include <QUrl>
#include <QRandomGenerator>
#include "tictaktoe.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QMediaPlayer *backgroundMusic;
    QMediaPlayer *OXXY;
    QMediaPlayer *SLAVA;
    QMediaPlayer *WIN;
    QAudioOutput *audioOutput_phra;
    QAudioOutput *audioOutput;
    QLabel *menuText;
    QAudioOutput *audioOutput_phraSLAVA;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectingFields();
    void returnWinner(Player player, bool win);
    void resetField();
    void resetGame();
    void OXXY_1_SOUNDS(int counter);
    void OXXY_2_SOUNDS(int counter);
    void SLAVA_1_SOUNDS(int counter);
    void SLAVA_2_SOUNDS(int counter);

    
private slots:
    void startButtonSlot();
    void clickOnField();
    void returnToMenuSlot (QPushButton* returnButton, QLabel* label);
    void ToggleMusicSlot();
    
   


};
#endif // MainWindow_H
