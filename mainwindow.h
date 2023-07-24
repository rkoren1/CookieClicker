#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "upgrades.h"
#include <QFile>
#include <QTextStream>
#include <QMainWindow>
#include <QDebug>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void sejvi();
    void nalovdi();


private slots:
    void updejti2();
    void updejti1();
    void on_piskotek_clicked();

    void on_kurzorjipp_clicked();
    void updejti();

    void on_babicapp_clicked();

    void on_farmapp_clicked();

    void on_tovarnapp_clicked();

    void on_rudnikpp_clicked();

    void on_posiljkapp_clicked();

    void on_laboratorijpp_clicked();

    void on_portalpp_clicked();

    void on_cas_strojpp_clicked();

    void on_antipp_clicked();

    void on_prizmapp_clicked();

    void on_Nadgradi_piskotek_klik_clicked();

    void on_Nadgradi_kremo_kanal_clicked();

private:
    short mouse_efficiency,cursor_efficiency;
    short Nadgradi_piskotek_klik_enable,upgrade_krema_kanal;
    unsigned int cursorBaseCPS;
    Ui::MainWindow *ui;
    unsigned long long denar;
    unsigned long denarPerClick;
    unsigned long st_kurzorjev,st_babic,st_farm,st_tovarn,st_rudnikov,st_posiljk,st_laboratorijev,st_portalov,st_cas_strojev,st_anti,st_prizm;
    QTimer *timer,*timer1,*timer2;
};


#endif // MAINWINDOW_H
