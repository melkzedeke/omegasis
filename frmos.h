#ifndef FRMOS_H
#define FRMOS_H

#include <QDialog>

namespace Ui {
class frmOs;
}

class frmOs : public QDialog
{
    Q_OBJECT

public:
    explicit frmOs(QWidget *parent = 0);
    ~frmOs();

private slots:
    void on_frmOs_accepted();

private:
    Ui::frmOs *ui;
};

#endif // FRMOS_H
