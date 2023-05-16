#include "dementiatest.h"
#include "ui_dementiatest.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

DementiaTest::DementiaTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DementiaTest)
{
    ui->setupUi(this);
    readWordsFromFile("/Users/martyna/build-code-Qt_6_5_0_for_macOS-Debug/fruits.txt", set1);
    readWordsFromFile("/Users/martyna/build-code-Qt_6_5_0_for_macOS-Debug/animals.txt", set2);
    readWordsFromFile("/Users/martyna/build-code-Qt_6_5_0_for_macOS-Debug/colors.txt", set3);
    setRandomObjects();
    printObjects();
    ui->RandomQuestions->hide();
    ui->AnswerBox->hide();
}

DementiaTest::~DementiaTest()
{
    delete ui;

}

//Tamplet as well as file input (read from the file) and Exception Handling,
template<typename T>
void DementiaTest::readWordsFromFile(const string& filename, T arr[])
{
    try
    {
        ifstream file(filename);
        //input validation
        if (file.is_open())
        {
            for (int i = 0; i < 3; i++)
            {
                getline(file, arr[i]);
            }
            file.close();
        }
        else
        {
            throw runtime_error("Error: Failed to open the file." );
        }
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

void DementiaTest::setRandomObjects()
{
    srand(time(NULL));
    objects[0] = set1[rand() % 3];
    objects[1] = set2[rand() % 3];
    objects[2] = set3[rand() % 3];
}

void DementiaTest::printObjects()
{
    ui->textEdit->append("I will give you 3 words, you need to memorize them.\n");
    ui->textEdit->append("The 3 objects are:");

    for (int i = 0; i < 3; i++)
    {
        string object = objects[i];
        QString objectStr = QString::fromStdString(object);
        ui->textEdit->append(QString::number(i + 1) + "- " + objectStr);
    }

    ui->textEdit->append("\nRepeat them once out loud and click the \"Next\" button");
}

void DementiaTest::on_Next_clicked()
{
    ui->textEdit->clear();
    ui->textEdit->append("\nI will ask you some other questions about you. \nWhen you will filed the questions click \"Next\"");
    ui->RandomQuestions->show();
    ui->Next->hide();
}

void DementiaTest::on_Next2_clicked()
{
    this->name = ui->lineEdit1->text().toStdString();
    QString age = ui->lineEdit2->text();
    QString number = ui->lineEdit3->text();
    QString animal = ui->lineEdit4->text();
    QString drink = ui->lineEdit5->text();
    QString color = ui->lineEdit6->text();
    QString day = ui->lineEdit7->text();

    ui->lineEdit1->setText("");
    ui->lineEdit2->setText("");
    ui->lineEdit3->setText("");
    ui->lineEdit4->setText("");
    ui->lineEdit5->setText("");
    ui->lineEdit6->setText("");
    ui->lineEdit7->setText("");

    ui->textEdit->clear();
    ui->textEdit->append("Your name is: " + QString::fromStdString(name));
    ui->textEdit->append("Your age is: " + age);
    ui->textEdit->append("Your phone number is: " + number);
    ui->textEdit->append("Your favorite animal is: " + animal);
    ui->textEdit->append("Your favorite drink is: " + drink);
    ui->textEdit->append("Your favorite color is: " + color);
    ui->textEdit->append("Your favorite day of the week is: " + day);

    ui->RandomQuestions->hide();

    ui->textEdit->append("\n How many object do you remember out of the 3 objects? Put them in the 3 blank spots. After youre done click \"submit\"");

    ui->AnswerBox->show();
}

void DementiaTest::on_Submit_clicked()
{
    ui->textEdit->clear();
    QString obj1 = ui->lineEdit8->text();
    QString obj2 = ui->lineEdit9->text();
    QString obj3 = ui->lineEdit10->text();
    string arr[3];
    arr[0] = obj1.toStdString();
    arr[1] = obj2.toStdString();
    arr[2] = obj3.toStdString();

    comparre(arr);

    ui->lineEdit8->setText("");
    ui->lineEdit9->setText("");
    ui->lineEdit10->setText("");
    ui->AnswerBox->hide();


    int score = correct_guesses;
    writeScoreToFile(this->name, score);
}

void DementiaTest::comparre(string arr[])
{
    correct_guesses = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <3; j++)
        {
            if(objects[i] == arr[j])
            {
                correct_guesses++;
                break;
            }
        }
    }
    ui->textEdit->append("You remembered " + QString::number(correct_guesses) + " out of 3 objects.");

}

//file output (writing to the file) user name + score
void DementiaTest::writeScoreToFile(const string& username, int score)
{
    ofstream file("/Users/martyna/build-code-Qt_6_5_0_for_macOS-Debug/score2.txt", ios::app);
    if (file.is_open())
    {
        ui->textEdit->append("Name: " + QString::fromStdString(username) + ", Score: " + QString::number(score));
        file << "Name: " << username << ", Score: " << score << endl;
        file.close();
    }
    else
    {
        cout << "Error: Failed to open the file." << endl;
    }
}
