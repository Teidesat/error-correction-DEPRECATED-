#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include "datastream.h"
#include "utils.h"

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
    Ui::MainWindow *ui;
    DataStream package;

private slots:
    void sendData();
    void generateRandomInput();
    void updateValues() const;
};

#endif // MAINWINDOW_H
