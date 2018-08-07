#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->rnoiseCheckbox, &QCheckBox::stateChanged, [=](int state) {
                                                          ui->rnoisePercent->setEnabled(state == Qt::Checked); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
