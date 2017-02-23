#ifndef FRMOPSRELATORIO_H
#define FRMOPSRELATORIO_H

#include <QDialog>

namespace Ui {
class FrmOpsRelatorio;
}

class FrmOpsRelatorio : public QDialog
{
    Q_OBJECT

public:
    explicit FrmOpsRelatorio(QWidget *parent = 0);
    ~FrmOpsRelatorio();

private slots:
    void on_lst_ops_doubleClicked();
    //sintax original
    //void on_lst_select_doubleClicked(const QModelIndex &index);
    void on_lst_select_doubleClicked();


    void on_btn_GeraRelatorio_clicked();

private:
    Ui::FrmOpsRelatorio *ui;
};

#endif // FRMOPSRELATORIO_H
