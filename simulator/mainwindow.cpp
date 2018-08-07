#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , package()
{
    ui->setupUi(this);

    connect(ui->randomButton, &QPushButton::clicked, this, &MainWindow::generateRandomInput);
    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendData);
    connect(ui->rnoiseCheckbox, &QCheckBox::stateChanged, [=](int state) {
                                                          ui->rnoisePercent->setEnabled(state == Qt::Checked); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendData()
{
    QString packageStr = ui->headerEdit->text() + ui->CRCEdit->text() + ui->dataEdit->text();
    package.fromString(packageStr);
    if (ui->rnoiseCheckbox->isChecked()) {
        package.addNoise(ui->rnoisePercent->value());
    }
    ui->receivedData->setText(package.toString());
    updateValues();
}

void MainWindow::generateRandomInput()
{
    int length = ui->randomSize->value();
    double ones = ui->randomOnesPercent->value();
    QString randomized = "";

    randomized.reserve(length);
    for (int i = 0; i < length; ++i) {
        randomized.push_back((randomNormal() < ones) ? '1' : '0');
    }
    ui->dataEdit->setText(randomized);
}

void MainWindow::updateValues() const
{
    int crcSize = ui->CRCEdit->text().size();
    int payloadSize = ui->dataEdit->text().size();
    int totalSize = payloadSize + ui->headerEdit->text().size() + crcSize;
    double onesPercent = package.onesPercent();

    qDebug() << crcSize << payloadSize << totalSize << onesPercent;
    ui->totalSizeLabel->setText(QString::number(totalSize / 8));
    ui->payloadSizeLabel->setText(QString::number(payloadSize / 8));
    ui->crcSizeLabel->setText(QString::number(crcSize));
    ui->onesPercentLabel->setText(QString::number(onesPercent));
}
