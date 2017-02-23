#include "frmopsrelatorio.h"
#include "ui_frmopsrelatorio.h"
#include <QtGui>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QSqlResult>
#include <QString>
#include <QSqlQueryModel>
#include <QDialog>
#include <QMessageBox>
#include <Qt>
#include <conexao.h>
#include"frmrelatorio.h"
QString sql_relat;
QString cab_relat;
QString linha_relat;
QString table_relat;

FrmOpsRelatorio::FrmOpsRelatorio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmOpsRelatorio)
{
    ui->setupUi(this);
    {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);
        //qDebug();
        query.exec("select * from "+table_relat);
        QSqlRecord rec = query.record();
        int qtd_row=rec.count();
        QString campo;
        QString nome;
        QString linha;
        QString regua;
        QString texto;
        int contador =0;
        while(contador!=qtd_row)
        {
            nome = rec.fieldName(contador);
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setText(nome);
            ui->lst_ops->insertItem(contador, newItem);
            contador++;
        }
        contador = 0;
    }
    QSqlDatabase::removeDatabase("01"); // correct
}

FrmOpsRelatorio::~FrmOpsRelatorio()
{
    delete ui;
}
 //sintax original
//void FrmOpsRelatorio::on_lst_ops_doubleClicked(const QModelIndex &index)
void FrmOpsRelatorio::on_lst_ops_doubleClicked()
{
    {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);
        query.exec("select * from "+table_relat);
        QSqlRecord rec = query.record();
        int qtd_row=rec.count();
        QString campo;
        QString nome;
        QString regua;
        QString texto;
        int tamanho;
        int contador =0;
        //int verificador =0;
        while(contador!=qtd_row)
        {
            nome = rec.fieldName(contador);
            QSqlField field = rec.field(nome);
            QVariant tipo(QVariant::String);
            if(field.type() !=tipo)
            {
                tamanho =field.length();
            }
            else
            {
                tamanho =field.length()/3;
            }

            if(nome==ui->lst_ops->currentItem()->text())
            {

                QListWidgetItem *newItem = new QListWidgetItem;
                newItem->setText(nome);
                ui->lst_select->insertItem(contador, newItem);
                if(sql_relat.count()==0)
                {
                sql_relat.append(nome);
                }else{
                sql_relat.append(","+nome);
                }

                campo = nome;
                campo = campo.leftJustified(tamanho, ' ');
                regua.clear();
                regua.append(linha_relat);
                regua.append(campo);

                if(regua.count()<= 94)
                {
                    linha_relat.append(campo);
                    cab_relat.append(campo);
                }
                else
                {
                    cab_relat.append("\n");
                    cab_relat.append(campo);
                    linha_relat.clear();
                    linha_relat.append(campo);
                }

            }
            contador++;
        }
        contador = 0;
    }
    QSqlDatabase::removeDatabase("01"); // correct
    ui->lst_ops->takeItem(ui->lst_ops->currentRow());
}
//sintax original
//void FrmOpsRelatorio::on_lst_select_doubleClicked(const QModelIndex &index)
void FrmOpsRelatorio::on_lst_select_doubleClicked()
{
    {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);
        linha_relat.clear();
        cab_relat.clear();
        query.exec("select * from "+table_relat);
        QSqlRecord rec = query.record();
        int qtd_row=rec.count();
        QString campo;
        QString nome;
        QString regua;
        int tamanho;
        int contador =0;
        int cont =0;

        while(contador!=qtd_row)
        {

            nome = rec.fieldName(contador);
            QSqlField field = rec.field(nome);
            QVariant tipo(QVariant::String);
            if(field.type() !=tipo)
            {
                tamanho =field.length();
            }
            else
            {
                tamanho =field.length()/3;
            }

            if(nome==ui->lst_select->currentItem()->text())
            {
                QListWidgetItem *newItem = new QListWidgetItem;
                newItem->setText(nome);
                ui->lst_ops->insertItem(contador, newItem);

                if(sql_relat.indexOf(nome)==0)
                {
                    sql_relat.remove(sql_relat.indexOf(nome),nome.count()+1);
                }
                else
                {
                    sql_relat.remove(sql_relat.indexOf(nome)-1,nome.count()+1);
                }


           }
            while(cont != ui->lst_select->count()){
                if(nome== ui->lst_select->item(cont)->text())
                {
                    if(nome!=ui->lst_select->currentItem()->text())
                    {
                        campo = nome;
                        campo = campo.leftJustified(tamanho, ' ');
                        regua.clear();
                        regua.append(linha_relat);
                        regua.append(campo);

                        if(regua.count()<= 94)
                        {
                            linha_relat.append(campo);
                            cab_relat.append(campo);
                        }
                        else
                        {
                            cab_relat.append("\n");
                            cab_relat.append(campo);
                            linha_relat.clear();
                            linha_relat.append(campo);
                        }
                    }
                }
                cont++;
            }
            cont = 0;
            contador++;
        }
        contador = 0;
    }
    QSqlDatabase::removeDatabase("01"); // correct

    ui->lst_select->takeItem(ui->lst_select->currentRow());

}

void FrmOpsRelatorio::on_btn_GeraRelatorio_clicked()
{
    table_relat="Cliente";
    //seta o formulario de cliente
    FrmRelatorio * newFrmRelatorio = new FrmRelatorio;
    //atribui valor de modal
    newFrmRelatorio->setModal(true);
    //mostra o formulario
    newFrmRelatorio->show();
    this->close();

}
