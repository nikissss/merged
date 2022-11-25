#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <QDialog>
#include<Qtsql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class playgame;
}

class playgame : public QDialog
{
    Q_OBJECT

public:
    explicit playgame(QWidget *parent = nullptr);
    ~playgame();

private:
    Ui::playgame *ui;
};

#endif // PLAYGAME_H
