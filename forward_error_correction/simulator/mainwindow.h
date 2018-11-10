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
    const QString HEADER = "1001011010001111";
    const int HEADERSZ = 16;

    enum InGenerators {
        NONE = -1, RANDOM = 0, FILE = 1, CUSTOM = 2
    };
    enum Units {
        BYTES, KB, MB, GB
    };

    Ui::MainWindow *ui;
    Data toSend;
    Data toReceive;
    InGenerators currentGenerator;

    QString getRandomInput();
    QString getFileInput();
    QString getCustomInput();
    double transform(int bits, Units toUnit) const;
    QString formatNumber(double number, int decimals = 3) const;
    void escapeSecuence(QString& data, const QString& secuence) const;

private slots:
    void setInputGenerator(int index);
    void buildInput();
    void sendData();
};

#endif // MAINWINDOW_H
