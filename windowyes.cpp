#include <QGuiApplication>
#include <QDesktopServices>
#include <QMessageBox>
#include "mainwindow.h"
#include "windowyes.h"
#include "ui_windowyes.h"

windowYes::windowYes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowYes)
{
    ui->setupUi(this);
    ui->NetworkingBox->hide();

}

windowYes::~windowYes()
{
    delete ui;
}

void windowYes::on_CodeGirls_clicked()
{

}

void windowYes::on_Button_Networking_clicked()
{
    ui->next1Button->setText("Next");
    ui->info1->setText("\nHere you can find links to groups for women on popular social media platforms.");
    ui->NetworkingBox->show();
}

void windowYes::on_Button_Scholarships_clicked()
{
    ui->NetworkingBox->hide();
    ui->info1->setText("\nHere you will find the link to the website with scholarships focused explicitly on women in tech.");
    ui->next1Button->setText("See scholarships");
    connect(ui->next1Button, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://www.nitrocollege.com/blog/ultimate-guide-stem-scholarships"));
    });
}

void windowYes::on_Button_Motivation_clicked()
{
    ui->NetworkingBox->hide();
    ui->info1->setText("\nHere you can find a great video from TEDx conference \"Inspiring the next generation of female engineers\".");
    ui->next1Button->setText("Go to YouTube");
    connect(ui->next1Button, &QPushButton::clicked, this, [](){
        QDesktopServices::openUrl(QUrl("https://www.youtube.com/watch?v=FEeTLopLkEo"));
    });
}

void windowYes::on_NetworkingBox_activated(int index)
{
    if(index==0)
    {
        ui->next1Button->setText("Go to Instagram");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.instagram.com/womenwhocode/"));
        });
    }
    else if (index==1)
    {
        ui->next1Button->setText("Go to Instagram");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.instagram.com/girlswhocode/"));
        });
    }
    else if (index==2)
    {
        ui->next1Button->setText("Go to Instagram");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.thetalko.com/10-women-in-tech-to-follow-on-instagram/"));
        });
    }
    else if (index==3)
    {
        ui->next1Button->setText("Go to LinkedIn");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.linkedin.com/company/women-who-code/"));
        });
    }
    else if (index==4)
    {
        ui->next1Button->setText("Go to LinkedIn");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.linkedin.com/groups/8566662/"));
        });
    }
    else if (index==5)
    {
        ui->next1Button->setText("Go to LinkedIn");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.linkedin.com/groups/13789428/"));
        });
    }
    else if (index==6)
    {
        ui->next1Button->setText("Go to Facebook");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.facebook.com/groups/1659712421002371/"));
        });
    }
    else if (index==7)
    {
        ui->next1Button->setText("Go to Facebook");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.facebook.com/groups/223806115941297/"));
        });
    }
    else if (index==8)
    {
        ui->next1Button->setText("Go to Twitter");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://twitter.com/WomenTechNet"));
        });
    }
    else if (index==9)
    {
        ui->next1Button->setText("Go to Twitter");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://twitter.com/WomenWhoCode"));
        });
    }
    else if (index==10)
    {
        ui->next1Button->setText("Go to Twitter");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://twitter.com/GirlsinTech"));
        });
    }
    else if (index==11)
    {
        ui->next1Button->setText("Go to Twitter");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("AnitaB.org"));
        });
    }
    else if (index==12)
    {
        ui->next1Button->setText("More");
        connect(ui->next1Button, &QPushButton::clicked, this, [](){
            QDesktopServices::openUrl(QUrl("https://www.cio.com/article/215709/16-organizations-for-women-in-tech.html"));
        });
    }
}

