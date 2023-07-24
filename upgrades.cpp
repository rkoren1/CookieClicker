#include "upgrades.h"
#include "ui_upgrades.h"

Upgrades::Upgrades(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Upgrades)
{
    ui->setupUi(this);
}

Upgrades::~Upgrades()
{
    delete ui;
}
