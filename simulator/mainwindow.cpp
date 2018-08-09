#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , toSend()
    , currentGenerator(InGenerators::NONE)
{
    ui->setupUi(this);

    setInputGenerator(InGenerators::RANDOM);
    connect(ui->inputGeneratorCBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setInputGenerator(int)));
    connect(ui->updateBtn, SIGNAL(clicked()), this, SLOT(buildInput()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getRandomInput()
{
    double ones = ui->rdataOnes->value();
    int length = ui->rdataLength->value();
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
    QString header = ui->headerData->text();
    QString crc = ui->CRCData->text();
    QString payload;

    switch (currentGenerator) {
    case InGenerators::RANDOM:  payload = getRandomInput(); break;
    case InGenerators::FILE:    payload = getFileInput();   break;
    case InGenerators::CUSTOM:  payload = getCustomInput(); break;
    default: break;
    }
    toSend.fromString(header);
    toSend.appendFromString(crc);
    toSend.appendFromString(payload);
    ui->sentData->setText(toSend.toString());
}
