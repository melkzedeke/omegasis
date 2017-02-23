#ifndef FRMLOCALIZAR_H
#define FRMLOCALIZAR_H

#include <QDialog>
#include <QString>
namespace Ui {
class FrmLocalizar;
}

class FrmLocalizar : public QDialog
{
    Q_OBJECT

public:
    explicit FrmLocalizar(QWidget *parent = 0);
    QString id;
    ~FrmLocalizar();

private slots:
    void on_btn_localizar_clicked();

    void on_grd_localizar_cellClicked(int row, int column);

    void on_pushButton_2_clicked();

private:
    Ui::FrmLocalizar *ui;
};

#endif // FRMLOCALIZAR_H
