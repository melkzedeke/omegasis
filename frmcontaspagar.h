#ifndef FRMCONTASPAGAR_H
#define FRMCONTASPAGAR_H

#include <QDialog>

namespace Ui {
class FrmContasPagar;
}

class FrmContasPagar : public QDialog
{
    Q_OBJECT

public:
    explicit FrmContasPagar(QWidget *parent = 0);
    ~FrmContasPagar();

private:
    Ui::FrmContasPagar *ui;
};

#endif // FRMCONTASPAGAR_H
