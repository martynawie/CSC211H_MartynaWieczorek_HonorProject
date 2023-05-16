#ifndef WINDOWNO_H
#define WINDOWNO_H

#include <QDialog>
#include "dementiatest.h"


namespace Ui {
class windowNo;
}

class windowNo : public QDialog
{
    Q_OBJECT

public:
    explicit windowNo(QWidget *parent = nullptr);
    ~windowNo();

private slots:


    void on_Button_Helping_clicked();

    void on_Button_earnings_clicked();

    void on_Button_hours_clicked();

//  void on_pushButton_2_clicked();

    void on_next2Button_clicked();

    void on_TryIt_clicked();

private:
    Ui::windowNo *ui;
    DementiaTest *mem;
};

#endif // WINDOWNO_H
