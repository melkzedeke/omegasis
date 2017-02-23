#include "frmcontaspagar.h"
#include "ui_frmcontaspagar.h"

FrmContasPagar::FrmContasPagar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmContasPagar)
{
    ui->setupUi(this);
}

FrmContasPagar::~FrmContasPagar()
{
    delete ui;
}
