#include "frmos.h"
#include "ui_frmos.h"

frmOs::frmOs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::frmOs)
{
    ui->setupUi(this);
}

frmOs::~frmOs()
{
    delete ui;
}

void frmOs::on_frmOs_accepted()
{

}
