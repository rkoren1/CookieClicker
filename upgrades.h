#ifndef UPGRADES_H
#define UPGRADES_H

#include <QMainWindow>

namespace Ui {
class Upgrades;
}

class Upgrades : public QMainWindow
{
    Q_OBJECT

public:
    explicit Upgrades(QWidget *parent = 0);
    ~Upgrades();

private:
    Ui::Upgrades *ui;
};

#endif // UPGRADES_H
