#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , toSend()
    , toReceive()
    , currentGenerator(InGenerators::NONE)
{
    ui->setupUi(this);

    setInputGenerator(InGenerators::RANDOM);
    connect(ui->inputGeneratorCBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setInputGenerator(int)));
    connect(ui->updateBtn, SIGNAL(clicked()), this, SLOT(buildInput()));
    connect(ui->sendBtn, SIGNAL(clicked()), this, SLOT(sendData()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getRandomInput()
{
    double ones = ui->rdataOnes->value();
    int length = ui->rdataLength->value() * 8;
    QString random;

    random.reserve(length);
    for (int i = 0; i < length; ++i) {
        random[i] = (randomNormal() < ones) ? '1' : '0';
    }
    return random;
}

QString MainWindow::getFileInput()
{
    return "";
}

QString MainWindow::getCustomInput()
{
    return ui->customData->text();
}

double MainWindow::transform(int bits, MainWindow::Units toUnit) const
{
    double number = 0;
    if (toUnit == Units::BYTES)   number = bits / 8.0;
    else if (toUnit == Units::KB) number = bits / (8.0 * 1024.0);
    else if (toUnit == Units::MB) number = bits / (8.0 * 1024.0 * 1024.0);
    else if (toUnit == Units::GB) number = bits / (8.0 * 1024.0 * 1024.0 * 1024.0);
    return number;
}

QString MainWindow::formatNumber(double number, int decimals) const
{
    QString format = "%." + QString::number(decimals) + "f";
    return QString::asprintf(format.toStdString().c_str(), number);
}

void MainWindow::escapeSecuence(QString &data, const QString &secuence) const
{
    ;
}

void MainWindow::setInputGenerator(int index)
{
    assert(index == InGenerators::RANDOM || index == InGenerators::CUSTOM || index == InGenerators::FILE);

    ui->randomInput->setVisible(index == InGenerators::RANDOM);
    ui->customInput->setVisible(index == InGenerators::CUSTOM);
    ui->fileInput->setVisible(index == InGenerators::FILE);
    currentGenerator = static_cast<InGenerators>(index);
}

void MainWindow::buildInput()
{
    QString crc = ui->CRCData->text();
    QString payload;

    switch (currentGenerator) {
    case InGenerators::RANDOM:  payload = getRandomInput(); break;
    case InGenerators::FILE:    payload = getFileInput();   break;
    case InGenerators::CUSTOM:  payload = getCustomInput(); break;
    default: break;
    }
    // Original payload
    ui->payloadData->setText(payload);
    // Original payload size
    ui->payloadSizeOriginalLabel->setText(formatNumber(transform(payload.size(), Units::KB)));
    // Escape payload header
    escapeSecuence(payload, HEADER);
    // Final payload size
    ui->payloadSizeFinalLabel->setText(formatNumber(transform(payload.size(), Units::KB)));
    // Build the package
    toSend.fromString(HEADER);
    toSend.appendFromString(crc);
    toSend.appendFromString(payload);
    // Data to send
    ui->sentData->setText(toSend.toString());
    // Totalpackage size
    ui->psizeLabel->setText(formatNumber(transform(toSend.size(), Units::KB)));
}

void MainWindow::sendData()
{
    toReceive = toSend;
    if (ui->rnoiseCheckbox->isChecked()) {
        toReceive.addNoise(ui->rnoiseRate->value());
    }
    double diffs = toReceive.diffs(toSend);
    qDebug() << diffs << toReceive.size();
    ui->finalNoiseLabel->setText(formatNumber(diffs * 100.0 / toReceive.size()));
    ui->receivedData->setText(toReceive.toString());
}
