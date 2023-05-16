#include <QGuiApplication>
#include <QDesktopServices>
#include <QMessageBox>
#include "windowno.h"
#include "ui_windowno.h"
#include <QPixmap>
#include <QLabel>


windowNo::windowNo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowNo)
{
    ui->setupUi(this);
    ui->TryIt->hide();
    ui->picture1->show();
}

windowNo::~windowNo()
{
    delete ui;
}

void windowNo::on_Button_Helping_clicked()
{

    ui->info2->setText("Did you know that programmers can help people in various ways, from developing life-saving software to creating educational apps? Programmers have developed applications that assist in medical research, monitor and control critical infrastructure, create assistive technologies for people with disabilities, and facilitate online learning for millions of students around the world. For example, you can check in 3 min if any of your family members have symptoms of dementia using a simple code.\nGive it a try now.");
    ui->next2Button->hide();
    ui->TryIt->show();
}

void windowNo::on_Button_earnings_clicked()
{
    ui->TryIt->hide();
    ui->info2->setText("Computer science and tech careers offer <b>high earning</b>.\n <b>Interns</b> at big tech companies like Google, Facebook, and Microsoft can earn salaries ranging from <b>$6,000</b> to <b>$8,000</b> per month. \nExperienced software engineers, data scientists, and other tech professionals can earn six-figure salaries.\nThe average salary for <b>a senior software engineer</b> at Google is <b>over $200,000</b> per year. \nThe constantly evolving nature of the tech industry also presents opportunities for career growth and the potential to earn even higher salaries over time.");
    ui->next2Button->setText("See earnings");
    connect(ui->next2Button, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://www.levels.fyi/?compare=Apple,Goldman%20Sachs,Bloomberg,JPMorgan%20Chase&track=Software%20Engineer#"));

    });

}

void windowNo::on_Button_hours_clicked()
{
    ui->TryIt->hide();
    ui->info2->setText("According to a survey conducted by Stack Overflow, a prominent online community for programmers, more than 50% of respondents reported having the ability to set their own working hours or enjoy flexible schedules in computer science-related professions. This indicates a strong trend towards accommodating flexible working arrangements in the industry. These options contribute to improved work-life balance and the ability to tailor working hours to personal needs.");
    ui->next2Button->setText("See more");
    connect(ui->next2Button, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://insights.stackoverflow.com/survey/2020#work-hours-per-week"));
    });

}


//void windowNo::on_pushButton_2_clicked()
//{
//    ui->TryIt->hide();
//    ui->info2->setText("A career in tech can help with self-development due to the constantly changing environment of the industry. Professionals in tech are required to adapt to new technologies and processes frequently, which can improve their problem-solving skills and ability to learn quickly. The fast-paced nature of the industry encourages us to be proactive, think critically, and work collaboratively to achieve goals. These skills can be applied to personal growth. Try to write your first \"Hello world\" program with me ");
//    ui->next2Button->show();
//    ui->next2Button->setText("Try it");
//}


void windowNo::on_TryIt_clicked()
{
    mem = new DementiaTest(this);
    mem->show();
}

void windowNo::on_next2Button_clicked()
{

}

