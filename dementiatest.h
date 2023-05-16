#ifndef DEMENTIATEST_H
#define DEMENTIATEST_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <fstream>

using namespace std;

namespace Ui {
class DementiaTest;
}
//virtual class
class DementiaTestBase {
public:
    virtual ~DementiaTestBase() {}
    virtual void comparre(string arr[]) = 0;
};

class DementiaTest : public QDialog, public DementiaTestBase
{
    Q_OBJECT
private:
    Ui::DementiaTest *ui;
    string set1[3];
    string set2[3];
    string set3[3];
    string objects[3];
    int correct_guesses;
    string name;

private slots:
    void on_Next_clicked();
    void on_Next2_clicked();
    void on_Submit_clicked();


public:
    DementiaTest(QWidget *parent = nullptr);
    ~DementiaTest();
    //I will make a function to be template function that works with different types of arrays, for exampe QString or string
    template<typename T>
    void readWordsFromFile(const string& filename, T arr[]) ;
    void writeScoreToFile(const string& username, int score) ;
    void setRandomObjects() ;
    void printObjects() ;
    void comparre(string arr[]) override;

};

#endif // DEMENTIATEST_H

