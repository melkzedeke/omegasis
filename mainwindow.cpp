#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "frmclientes.h"
#include "frmos.h"
#include "frmcontaspagar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/omega/projetos/OmegaSis/OmegaSis/logo.jpg");
    ui->lbl_pic->setPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_Clientes_triggered()
{
    //seta o formulario de cliente
    FrmClientes * newFrmCliente = new FrmClientes;
    //atribui valor de modal
    newFrmCliente->setModal(true);
    //mostra o formulario
    newFrmCliente->show();
}


void MainWindow::on_action_Os_triggered()
{
    //seta o formulario de cliente
    frmOs * newFrmOs = new frmOs;
    //atribui valor de modal
    newFrmOs->setModal(true);
    //mostra o formulario
    newFrmOs->show();
}

void MainWindow::on_action_ContasP_triggered()
{
    //seta o formulario de cliente
    FrmContasPagar * newFrmContasPagar = new FrmContasPagar;
    //atribui valor de modal
    newFrmContasPagar->setModal(true);
    //mostra o formulario
    newFrmContasPagar->show();
}
