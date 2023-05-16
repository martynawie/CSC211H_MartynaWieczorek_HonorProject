#ifndef WINDOWYES_H
#define WINDOWYES_H

#include <QDialog>

namespace Ui {
class windowYes;
}

class windowYes : public QDialog
{
    Q_OBJECT

public:
    explicit windowYes(QWidget *parent = nullptr);
    ~windowYes();

private slots:

    void on_Button_Networking_clicked();
    void on_Button_Scholarships_clicked();
    void on_Button_Motivation_clicked();
    void on_CodeGirls_clicked();
    void on_NetworkingBox_activated(int index);

private:
    Ui::windowYes *ui;
};

#endif // WINDOWYES_H
