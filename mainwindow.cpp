#include <iostream>
#include "mainwindow.h" 
#include "./ui_mainwindow.h"

// Глобальные переменные (лучше сделать членами класса)
Tiktaktoe game;
Player player = Player::X;
bool win = false;
bool NewGame = true;
int counterOXXY = 1;
int counterSLAVA = 1;
int packOXXY;
int packSLAVA;


// Добавь эту функцию если её нет
QString stringToPlayer(Player player) {
    switch(player) {
        case Player::X: return "OXXY";
        case Player::Y: return "SLAVA KPSS";
        default: return "Unknown";
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // Инициализация в списке инициализации
    , OXXY(new QMediaPlayer(this))
    , SLAVA(new QMediaPlayer(this))
    , audioOutput_phra(new QAudioOutput(this))
    , backgroundMusic(new QMediaPlayer(this))
    , audioOutput(new QAudioOutput(this))
    , menuText (new QLabel(this))
<<<<<<< HEAD
{
    ui->setupUi(this);
=======

{
    ui->setupUi(this);
    QIcon oxxyIcon(":/images/oxxy_lico.png");
    QIcon slavaIcon(":/images/slava_lico.png");
>>>>>>> cce12dd (фикс окси, иконки, стили)
    QPixmap pixmap(":/images/menuText.png");
    menuText->setPixmap(pixmap);
    menuText->setScaledContents(true);
    menuText->setGeometry(20, 30, 490, 350); // x, y, width, height
    menuText->setAttribute(Qt::WA_TransparentForMouseEvents);
    menuText->show(); //!!!!!!!!!!!!!!!!
    ui->OffMusic->setText("🔊");
    OXXY->setAudioOutput(audioOutput_phra);
    SLAVA->setAudioOutput(audioOutput_phra);
    audioOutput_phra->setVolume(0.5);
    qDebug() << "Initializing music player...";
    
    // Проверка существования ресурса
    if (QFile::exists(":/sounds/mainMenu.mp3")) {
        qDebug() << "Resource file exists";
    } else {
        qDebug() << "Resource file NOT found!";
        // Попробуй абсолютный путь для теста
        if (QFile::exists("sounds/mainMenu.mp3")) {
            qDebug() << "Local file exists";
        }
    }
    
    // Правильная инициализация музыки
    //QAudioOutput* audioOutput = new QAudioOutput;
    
    backgroundMusic->setAudioOutput(audioOutput);
    
    
       connect(backgroundMusic, &QMediaPlayer::errorOccurred, this, [](QMediaPlayer::Error error) {
        qDebug() << "MediaPlayer error:" << error;
    });
    
    connect(backgroundMusic, &QMediaPlayer::mediaStatusChanged, this, [](QMediaPlayer::MediaStatus status) {
        qDebug() << "Media status:" << status;
    });

    backgroundMusic->setSource(QUrl("qrc:/music/mainMenu.mp3"));
    qDebug() << "Exists? " << QFile::exists(":/music/mainMenu.mp3");
    audioOutput->setVolume(0.5);
    
    
    qDebug() << "Source set, attempting to play...";
    backgroundMusic->play();
    
    connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::startButtonSlot);
    connect(ui->OffMusic, &QToolButton::clicked, this, &MainWindow::ToggleMusicSlot);
    ui->gameFieldBox->hide();
    connectingFields();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startButtonSlot() {
    if (NewGame) {
        resetField();
        ui->StartButton->hide();
        ui->OffMusic->hide();
        menuText->hide();
        ui->gameFieldBox->show();
        backgroundMusic->stop();
        qDebug() << "hello" << "\n"; 
        packOXXY = QRandomGenerator::global()->bounded(1,3);
        //packSLAVA = QRandomGenerator::global()->bounded(1,3);
    }
    else {
        resetGame();
        backgroundMusic->stop();
        packOXXY = QRandomGenerator::global()->bounded(1,3);
        packSLAVA = QRandomGenerator::global()->bounded(1,3);
    }
}

void MainWindow::clickOnField() {
    int random;
    QToolButton *button = qobject_cast<QToolButton*>(sender());
    if (!button) return;
    qDebug() << "Нажата кнопка:" << button->objectName();
    QString name = button->objectName();
    if (name.startsWith("cell_")) {
        QStringList parts = name.split('_');
        if (parts.size() == 3) {
            int row = parts[1].toInt();
            int col = parts[2].toInt();
            qDebug() << "Координаты: строка" << row << "столбец" << col;
            
            game.PointToFied(row, col, static_cast<int>(player));
            qDebug() << "Точка поставлена, значение" << game.CheckPoint(row, col) << "\n";
            
            
            button->setText(player == Player::X ? "X" : "Y");
            button->setEnabled(false);
            qDebug() << packOXXY << "ЩАС БУДЕТ ИГРАТЬ ОКСИ\n";
            if (player == Player::X) {
                QIcon oxxyIcon(":/images/oxxy_lico.png");
                oxxyIcon.addPixmap(oxxyIcon.pixmap(150, QIcon::Normal), QIcon::Disabled);
                button->setIcon(oxxyIcon);
                
                button->setIconSize(QSize(200, 200));

                switch (packOXXY)
                {
                case 1: {
                            MainWindow::OXXY_1_SOUNDS(counterOXXY);
                            break;
                        }
                case 2: {
                            MainWindow::OXXY_2_SOUNDS(counterOXXY);
                            break;
                        }
                
                default:
                    break;
                }

            }
            else {
                QIcon slavaIcon(":/images/slava_lico.png");
                slavaIcon.addPixmap(slavaIcon.pixmap(150, QIcon::Normal), QIcon::Disabled);
                button->setIcon(slavaIcon);
                button->setIconSize(QSize(200, 200));

            }
            
            
            
            if (game.CheckWin(static_cast<int>(player))) {
                win = true;
                returnWinner(player, win);
                return;
            }
            
            if (game.checkAllCells()) {
                win = false;
                returnWinner(player, win);
                return;
            }
            
            player = (player == Player::X) ? Player::Y : Player::X;
            if (player == Player::X) counterOXXY++;
            else counterSLAVA++; 
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

void MainWindow::returnWinner(Player player, bool win) {
    if (win) {
    ui->gameFieldBox->hide();
    
    QLabel *winLabel = new QLabel(this);
    winLabel->move(177, 200);
    winLabel->resize(300, 100);
    winLabel->setText("WINS: " + stringToPlayer(player));
    winLabel->setStyleSheet("color: #00FFCC; font-weight: regular; font-family: PixelifySans");

    QFont font;
    font.setPointSize(25);
    font.setBold(true);
    winLabel->setFont(font);
    winLabel->show();
    
    QPushButton *returnToMenu = new QPushButton("Вернуться в меню", this);
    returnToMenu->move(150, 310);
    returnToMenu->resize(210, 50);
    returnToMenu->show();
    
    NewGame = false;
    win = false;
    
    connect(returnToMenu, &QPushButton::clicked, this, [this, returnToMenu, winLabel](){
        qDebug() << "returnToMenuSlot\n"; 
        returnToMenuSlot(returnToMenu, winLabel);
    });
    }
    else {
        ui->gameFieldBox->hide();
    
    QLabel *winLabel = new QLabel(this);
    winLabel->move(177, 200);
    winLabel->resize(300, 100);
    winLabel->setText("DRAW");
    winLabel->setStyleSheet("color: #00FFCC; font-weight: regular; font-family: PixelifySans");

    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    winLabel->setFont(font);
    winLabel->show();
    
    QPushButton *returnToMenu = new QPushButton("Вернуться в меню", this);
    returnToMenu->move(150, 310);
    returnToMenu->resize(210, 50);
    returnToMenu->show();
    
    NewGame = false;
    
    connect(returnToMenu, &QPushButton::clicked, this, [this, returnToMenu, winLabel](){
        qDebug() << "returnToMenuSlot\n"; 
        returnToMenuSlot(returnToMenu, winLabel);
    });
    }
}

void MainWindow::resetField() {
    QList<QToolButton*> buttons = {
        ui->cell_0_0, ui->cell_1_0, ui->cell_2_0,
        ui->cell_0_1, ui->cell_1_1, ui->cell_2_1,
        ui->cell_0_2, ui->cell_1_2, ui->cell_2_2
    };

    for (QToolButton *button : buttons) {
        button->setText("");
        button->setEnabled(true);
    }
}

void MainWindow::resetGame() {
    resetField();
    game = Tiktaktoe();
    player = Player::X;
    NewGame = true;
    
    ui->gameFieldBox->show();
    ui->StartButton->hide();
    ui->OffMusic->hide();
}

void MainWindow::returnToMenuSlot(QPushButton* returnButton, QLabel* label) {
    delete returnButton;
    qDebug() << "returnButton - удалено\n"; 
    delete label;
    win = false;
    counterOXXY = 1;
    counterSLAVA = 1;
    qDebug() << "label - удалено\n"; 
    ui->gameFieldBox->hide(); 
    qDebug() << "gameFieldBox - скрыто\n"; 
    ui->StartButton->show();
    qDebug() << "StartButton - показано\n"; 
    ui->OffMusic->show();
    qDebug() << "OffMusic - показано\n"; 
    NewGame = false;
    qDebug() << "NewGame - false\n"; 
    backgroundMusic->play();
    qDebug() << "NebackgroundMusicwGame - play\n";
    menuText->show();
}

void MainWindow::OXXY_1_SOUNDS(int counter) {
    OXXY->setAudioOutput(audioOutput_phra);
    switch (counter)
    {
    case 1: { 
                
                OXXY->setSource(QUrl("qrc:/sounds/opaaOXXY.mp3"));
                OXXY->play();
                break;
            }

    case 2: {
                OXXY->setSource(QUrl("qrc:/sounds/umenyaTojeEstPtichki.mp3"));
                OXXY->play();
                break;
            }

    case 3: {
                OXXY->setSource(QUrl("qrc:/sounds/mikrofoni.mp3"));
                OXXY->play();
                break;
            }
    case 4: {
                OXXY->setSource(QUrl("qrc:/sounds/yaZdesChistoPofanu.mp3"));
                OXXY->play();
                break;
            }
    case 5: {
               OXXY->setSource(QUrl("qrc:/sounds/parallelogram.mp3")); 
               OXXY->play();
               break;
            }
    
    default:
        break;
    }
}

void  MainWindow::OXXY_2_SOUNDS(int counter) {
    OXXY->setAudioOutput(audioOutput_phra);
    switch (counter)
    {
    case 1: { 
                
                OXXY->setSource(QUrl("qrc:/sounds/govno.mp3"));
                OXXY->play();
                break;
            }

    case 2: {
                OXXY->setSource(QUrl("qrc:/sounds/zalupa.mp3"));
                OXXY->play();
                break;
            }

    case 3: {
                OXXY->setSource(QUrl("qrc:/sounds/penis.mp3"));
                OXXY->play();
                break;
            }
    case 4: {
                OXXY->setSource(QUrl("qrc:/sounds/her.mp3"));
                OXXY->play();
                break;
            }
    case 5: {
               OXXY->setSource(QUrl("qrc:/sounds/mudilaETC.mp3")); 
               OXXY->play();
               break;
            }
    
    default:
        break;
    }
}

void MainWindow::ToggleMusicSlot() {
  if (audioOutput->volume() > 0.0) {
    audioOutput->setVolume(0.0);
    ui->OffMusic->setText("🔇"); // или QIcon
} else {
    audioOutput->setVolume(0.5);
    ui->OffMusic->setText("🔊");
}
}




