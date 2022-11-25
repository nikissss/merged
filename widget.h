#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>

namespace Ui {
class widget;
}

class widget : public QDialog
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_startGameButton_clicked();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
