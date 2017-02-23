#ifndef FRMCLIENTES_H
#define FRMCLIENTES_H

#include <QDialog>

namespace Ui {
class FrmClientes;
}

class FrmClientes : public QDialog
{
    Q_OBJECT

public:
    explicit FrmClientes(QWidget *parent = 0);
    void pegadados(QString x);
    ~FrmClientes();

private slots:
    void on_edt_id_returnPressed();

    void on_btn_salvar_clicked();

    void on_pushButton_2_clicked();

    void on_btn_localizar_clicked();

    void on_btn_relatorio_clicked();

    void on_btn_atualizar_clicked();

private:
    Ui::FrmClientes *ui;
};

#endif // FRMCLIENTES_H
