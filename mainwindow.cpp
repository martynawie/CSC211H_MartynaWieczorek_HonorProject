#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonYes_clicked()
{
    hide();
    WindowYes = new windowYes(this);
    WindowYes->show();
}

void MainWindow::on_ButtonNo_clicked()
{
    hide();
    WindowNo = new windowNo(this);
    WindowNo->show();
}

void MainWindow::showMainWindow()
{
    show();
    WindowYes->hide();
    WindowNo->hide();
}
