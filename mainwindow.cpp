#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <cmath>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Nadgradi_piskotek_klik_enable=0;
    denar=0;
    denarPerClick=1;
    st_babic=0;
    st_kurzorjev=0;
    mouse_efficiency=1;
    cursor_efficiency=1;
    st_farm=0;
    cursorBaseCPS=1;
    st_posiljk=0;
    st_tovarn=0;
    st_rudnikov=0;
    st_portalov=0;
    st_laboratorijev=0;
    st_cas_strojev=0;
    st_anti=0;
    st_prizm=0;
    upgrade_krema_kanal=0;
    nalovdi();
    ui->piskotek->setIcon(QIcon("PerfectCookie.png"));
    ui->piskotek->setIconSize(QSize(256,256));
    ui->cena_prizme->setText("Cena prizme: "+QString::number((unsigned long long)(75000000000*pow(1.15,st_prizm)))+" piskotkov");
    ui->cena_anti->setText("Cena antimaterijskega kondenzatorja: "+QString::number((unsigned long long)(3999999999*pow(1.15,st_anti)))+" piskotkov");
    ui->cena_cas_stroja->setText("Cena časovnega stroja: "+QString::number((unsigned long long)(123456789*pow(1.15,st_cas_strojev)))+" piskotkov");
    ui->cena_portala->setText("Cena portala: "+QString::number((unsigned long long)(16666666*pow(1.15,st_portalov)))+" piskotkov");
    ui->cena_laboratorija->setText("Cena laboratorija: "+QString::number((unsigned long long)(200000*pow(1.15,st_laboratorijev)))+" piskotkov");
    ui->cena_posiljke->setText("Cena posiljke: "+QString::number((unsigned long long)(40000*pow(1.15,st_posiljk)))+" piskotkov");
    ui->cena_rudnika->setText("Cena rudnika: "+QString::number((unsigned long long)(10000*pow(1.15,st_rudnikov)))+" piskotkov");
    ui->cena_farme->setText("Cena farme: "+QString::number((unsigned long long)(500*pow(1.15,st_farm)))+" piskotkov");
    ui->cena_tovarne->setText("Cena tovarne: "+QString::number((unsigned long long)(3000*pow(1.15,st_tovarn)))+" piskotkov");
    ui->cena_babice->setText("Cena babice: "+QString::number((unsigned long long)(100*pow(1.15,st_babic)))+" piskotkov");
    ui->cena_kurzorja->setText("Cena kurzorja: "+QString::number((unsigned long long)(15*pow(1.15,st_kurzorjev)))+" piskotkov");
    ui->zaslon_dnar->setText(QString::number(denar)+" piskotkov");
    ui->Nadgradi_piskotek_klik->setDisabled(Nadgradi_piskotek_klik_enable);
    ui->Nadgradi_kremo_kanal->setDisabled(upgrade_krema_kanal);
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updejti()));
    timer->start(1000);
    timer1= new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(updejti1()));
    timer1->start(10000);
    timer2= new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(updejti2()));
    timer2->start(2000);

}

MainWindow::~MainWindow()
{
    sejvi();
    delete ui;
    delete timer;
    delete timer1;
    delete timer2;
}
void MainWindow::updejti()
{
    denar+=st_prizm*10000000;
    denar+= st_anti*999999;
    denar+=st_cas_strojev*98765;
    denar+=st_portalov*6666;
    denar+=st_laboratorijev*400;
    denar+=st_posiljk*100;
    denar+=st_rudnikov*40;
    denar+= st_tovarn*10;
    denar+=st_farm*4;
    ui->zaslon_dnar->setText(QString::number(denar)+" piskotkov");
}
void MainWindow::updejti1()
{
    denar+=st_kurzorjev*cursorBaseCPS*cursor_efficiency;
    ui->zaslon_dnar->setText(QString::number(denar)+" piskotkov");
}
void MainWindow::updejti2()
{
    denar+=st_babic;
    ui->zaslon_dnar->setText(QString::number(denar)+" piskotkov");
}

void MainWindow::on_piskotek_clicked()
{
    denar+=denarPerClick*mouse_efficiency;
    ui->zaslon_dnar->setText(QString::number(denar)+" piskotkov");
}
void MainWindow::sejvi()
{
    QFile file("save_game.txt");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"error while writting";
    }
    QTextStream out(&file);
    out<<denar<<endl<<st_kurzorjev<<endl<<denarPerClick<<endl<<st_babic<<endl<<st_farm<<endl<<st_tovarn<<endl<<st_rudnikov<<endl<<st_posiljk<<endl<<
         st_laboratorijev<<endl<<st_portalov<<endl<<st_cas_strojev<<endl<<st_anti<<endl<<st_prizm<<endl
      <<Nadgradi_piskotek_klik_enable<<endl<<cursorBaseCPS<<endl<<mouse_efficiency<<endl<<cursor_efficiency
     <<endl<<upgrade_krema_kanal;
    file.close();

}
void MainWindow::nalovdi()
{
    QFile file("save_game.txt");
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"error while reading";
    }
    else
    {
        in>>denar>>st_kurzorjev>>denarPerClick>>st_babic>>st_farm>>st_tovarn>>st_rudnikov>>
                st_posiljk>>st_laboratorijev>>st_portalov>>st_cas_strojev>>st_anti>>st_prizm
                >>Nadgradi_piskotek_klik_enable>>cursorBaseCPS>>mouse_efficiency>>cursor_efficiency
                >>upgrade_krema_kanal;
    }

    file.close();
}

void MainWindow::on_kurzorjipp_clicked()
{
    unsigned long long cena =15*pow(1.15,st_kurzorjev);
    if(denar>=cena)
    {
        denar-=cena;
        st_kurzorjev+=1;
        cena =15*pow(1.15,st_kurzorjev);
        ui->cena_kurzorja->setText("Cena kurzorja: "+QString::number(cena)+ " piskotkov");
    }


}

void MainWindow::on_babicapp_clicked()
{
    unsigned long long cena =100*pow(1.15,st_babic);
    if(denar>=cena)
    {
        denar-=cena;
        st_babic+=1;
        cena =100*pow(1.15,st_babic);
        ui->cena_babice->setText("Cena babice: "+QString::number(cena)+ " piskotkov");
    }
}

void MainWindow::on_farmapp_clicked()
{
    unsigned long long cena =500*pow(1.15,st_farm);
    if(denar>=cena)
    {
        denar-=cena;
        st_farm+=1;
        cena =500*pow(1.15,st_farm);
        ui->cena_farme->setText("Cena farme: "+QString::number(cena)+ " piskotkov");
    }
}

void MainWindow::on_tovarnapp_clicked()
{
    unsigned long long cena =3000*pow(1.15,st_tovarn);
    if(denar>=cena)
    {
        denar-=cena;
        st_tovarn+=1;
        cena =3000*pow(1.15,st_tovarn);
        ui->cena_tovarne->setText("Cena tovarne: "+QString::number(cena)+ " piskotkov");
    }

}

void MainWindow::on_rudnikpp_clicked()
{
    unsigned long long cena =10000*pow(1.15,st_rudnikov);
    if(denar>=cena)
    {
        denar-=cena;
        st_rudnikov+=1;
        cena =10000*pow(1.15,st_rudnikov);
        ui->cena_rudnika->setText("Cena rudnika: "+QString::number(cena)+ " piskotkov");
    }
}

void MainWindow::on_posiljkapp_clicked()
{
    unsigned long long cena =40000*pow(1.15,st_posiljk);
    if(denar>=cena)
    {
        denar-=cena;
        st_posiljk+=1;
        cena =40000*pow(1.15,st_posiljk);
        ui->cena_posiljke->setText("Cena posiljke: "+QString::number(cena)+ " piskotkov");
    }
}

void MainWindow::on_laboratorijpp_clicked()
{
    unsigned long long cena =2000000*pow(1.15,st_laboratorijev);
    if(denar>=cena)
    {
        denar-=cena;
        st_laboratorijev+=1;
        cena =200000*pow(1.15,st_laboratorijev);
        ui->cena_laboratorija->setText("Cena laboratorija: "+QString::number(cena)+ " piskotkov");
    }

}

void MainWindow::on_portalpp_clicked()
{
    unsigned long long cena =1666666*pow(1.15,st_portalov);
    if(denar>=cena)
    {
        denar-=cena;
        st_portalov+=1;
        cena =16666666*pow(1.15,st_portalov);
        ui->cena_portala->setText("Cena portala: "+QString::number(cena)+ " piskotkov");
    }

}

void MainWindow::on_cas_strojpp_clicked()
{
    unsigned long long cena =123456789*pow(1.15,st_cas_strojev);
    if(denar>=cena)
    {
        denar-=cena;
        st_cas_strojev+=1;
        cena =123456789*pow(1.15,st_cas_strojev);
        ui->cena_cas_stroja->setText("Cena časovnega stroja: "+QString::number(cena)+ " piskotkov");
    }

}

void MainWindow::on_antipp_clicked()
{
    unsigned long long cena =3999999999*pow(1.15,st_anti);
    if(denar>=cena)
    {
        denar-=cena;
        st_anti+=1;
        cena =3999999999*pow(1.15,st_anti);
        ui->cena_anti->setText("Cena antimaterijskega kondenzatorja: "+QString::number(cena)+ " piskotkov");
    }
}

void MainWindow::on_prizmapp_clicked()
{
    unsigned long long cena =75000000000*pow(1.15,st_prizm);
    if(denar>=cena)
    {
        denar-=cena;
        st_prizm+=1;
        cena =75000000000*pow(1.15,st_prizm);
        ui->cena_prizme->setText("Cena prizme: "+QString::number(cena)+ " piskotkov");
    }
}


void MainWindow::on_Nadgradi_piskotek_klik_clicked()
{
    if(denar>=100)
    {
        denar-=100;
        denarPerClick+=1;
        cursorBaseCPS+=1;
        Nadgradi_piskotek_klik_enable=1;
        ui->Nadgradi_piskotek_klik->setDisabled(Nadgradi_piskotek_klik_enable);

    }

}

void MainWindow::on_Nadgradi_kremo_kanal_clicked()
{
    if(denar>=400)
    {
        denar-=400;
        mouse_efficiency+=1;
        cursor_efficiency+=1;
        upgrade_krema_kanal=1;
        ui->Nadgradi_kremo_kanal->setDisabled(upgrade_krema_kanal);
    }
}
