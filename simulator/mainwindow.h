#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>
#include "utils.h"
#include "data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    enum InGenerators {
        NONE = -1, RANDOM = 0, FILE = 1, CUSTOM = 2
    };

    Ui::MainWindow *ui;
    Data toSend;
    InGenerators currentGenerator;

    QString getRandomInput();
    QString getFileInput();
    QString getCustomInput();

private slots:
    void setInputGenerator(int index);
    void buildInput();
};

#endif // MAINWINDOW_H
