#ifndef FRMRELATORIO_H
#define FRMRELATORIO_H

#include <QDialog>

namespace Ui {
class FrmRelatorio;
}

class FrmRelatorio : public QDialog
{
    Q_OBJECT

public:
    explicit FrmRelatorio(QWidget *parent = 0);
    ~FrmRelatorio();
private slots:
    void on_FrmRelatorio_accepted();
    void relatorio();

    void on_btn_imprimir_clicked();

private:
    Ui::FrmRelatorio *ui;
};

#endif // FRMRELATORIO_H
