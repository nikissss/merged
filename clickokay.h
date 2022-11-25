#ifndef CLICKOKAY_H
#define CLICKOKAY_H

#include <QDialog>

namespace Ui {
class clickokay;
}

class clickokay : public QDialog
{
    Q_OBJECT

public:
    explicit clickokay(QWidget *parent = nullptr);
    ~clickokay();

private slots:

    void on_dialogButtonBox_accepted();

private:
    Ui::clickokay *ui;
};

#endif // CLICKOKAY_H
