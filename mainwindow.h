#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windowno.h"
#include "windowyes.h"

#include "dementiatest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ButtonYes_clicked();
    void on_ButtonNo_clicked();


public slots:
     void showMainWindow();
private:
    Ui::MainWindow *ui;
    windowNo *WindowNo;
    windowYes *WindowYes;

};
#endif // MAINWINDOW_H
