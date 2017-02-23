#include "frmlocalizar.h"
#include "ui_frmlocalizar.h"
#include "frmclientes.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlResult>
#include <QString>
#include <QSqlQueryModel>
#include <QDialog>
#include <QMessageBox>
#include "conexao.h"
FrmLocalizar::FrmLocalizar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmLocalizar)
{
    ui->setupUi(this);
    ui->grd_localizar->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
}

FrmLocalizar::~FrmLocalizar()
{
    delete ui;
}

void FrmLocalizar::on_btn_localizar_clicked()
{
    {

        QString id;
        QString name;
        QTableWidgetItem *item_id;
        QTableWidgetItem *item_name;
        QSqlDatabase db;
        conecta(&db);
        QSqlQuery query(db);
        QString sql = "SELECT * FROM `Cliente` where Nome like '"+ui->edt_localizar->text()+"%' limit 20";
        query.exec(sql);
        //funcionou bem
        int contador =0;
        while (query.next()) {
            id = query.value(0).toString();
            name = query.value(1).toString();
            item_id = new QTableWidgetItem((id));
            item_name = new QTableWidgetItem((name));
            ui->grd_localizar->setRowCount(contador+1);
            ui->grd_localizar->setItem(contador,0,item_id)	;
            ui->grd_localizar->setItem(contador,1, item_name);
            contador++;
        };

        db.close();
    }
    QSqlDatabase::removeDatabase("01");
}

void FrmLocalizar::on_grd_localizar_cellClicked(int row, int column)
{

    QTableWidgetItem *item_id;
    QTableWidgetItem *item_nome;

    if(column==0){
        item_id = ui->grd_localizar->item(row, column);
        item_nome = ui->grd_localizar->item(row, column+1);
    }else{
        item_id = ui->grd_localizar->item(row, column-1);
        item_nome = ui->grd_localizar->item(row, column);
    }

    ui->edt_id ->setText(item_id -> text());
    ui->edt_nome ->setText(item_nome -> text());

}

void FrmLocalizar::on_pushButton_2_clicked()
{
    close();
    id = ui->edt_id->text();

}
