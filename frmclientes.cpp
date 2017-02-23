#include "frmclientes.h"
#include "funcoes.h"
#include "ui_frmclientes.h"
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
#include "frmlocalizar.h"
#include "frmopsrelatorio.h"
#include "frmopsrelatorio.h"
extern QString table_relat;
void conecta(QSqlDatabase *db);
FrmClientes::FrmClientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmClientes)
{
    ui->setupUi(this);
}

FrmClientes::~FrmClientes()
{
    delete ui;
}

void FrmClientes::on_edt_id_returnPressed()
{
Mascara("asdfaf");
TrataVirgulas("sdfads");
soma("dsfasdf","asdfasdf");
}

void FrmClientes::on_btn_salvar_clicked()
{
    {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);
        QString verify = ui->edt_id -> text();
        QString verify_nome = ui->edt_nome -> text();
        if (verify ==""){
            if(verify_nome==""){
            QMessageBox::information(this, tr("Mensagem!"),
                tr("Por Favor Preencher Pelo Menos\n"
                   "o (Nome do Cliente) Obrigado!..."));
            }else{
            QString nome = ui->edt_nome -> text();
            QString endereco = ui->edt_endereco -> text();
            QString sql = "insert into Cliente (Cod,Nome,Endereco)Values(0,'"+nome+"','"+endereco+"')";
            query.exec(sql);
            db.close();
            QMessageBox::information(this, tr("Mensagem!"),
                tr("Cliente Cadastrado com Sucesso!.\n"
                    "Obrigado Por Usar (Omega Sistemas)!"));
            }

        }else{
            QString sql2 = "select * from Cliente where Cod="+verify+"";
            query.exec(sql2);
            int nraff = query.numRowsAffected();
//			qDebug()<<query.numRowsAffected();
            if (nraff >0){

            QMessageBox::information(this, tr("Mensagem!"),
                tr("Já Existe Um Clinte Cadastrado com esse ID.\n"
                    "Por Favor, Peça (Novo) para Cadastrar!"));
            }else{
                QString id = ui->edt_id-> text();
                QString nome = ui->edt_nome -> text();
                QString endereco = ui->edt_endereco -> text();
                QString fone = ui->edt_fone -> text();
                QString sql = "insert into Cliente (Cod,Nome,Endereco,fone)Values('"+id+"','"+nome+"','"+endereco+"','"+fone+"')";
                query.exec(sql);

                db.close();
            }
        }
    }

     QSqlDatabase::removeDatabase("01"); // correct
}

void FrmClientes::on_pushButton_2_clicked()
{
    ui->edt_id->clear();
    ui->edt_nome->clear();
    ui->edt_endereco->clear();
}

void FrmClientes::on_btn_localizar_clicked()
{
    FrmLocalizar formLocalizar(this);
    formLocalizar.exec();
    pegadados(formLocalizar.id);

}

void FrmClientes::pegadados(QString x)
{
   {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);
        QString name = ui->edt_nome -> text();
        QString codx =x;
        QString sql = "SELECT * FROM `Cliente` where Cod="+x+"";
        query.exec(sql);
        //funcionou bem
        while (query.next()) {
            QString id = query.value(0).toString();
            QString name = query.value(1).toString();
            QString fone = query.value(2).toString();
            QString endereco = query.value(3).toString();

            ui->edt_id ->setText(id);
            ui->edt_nome ->setText(name);
            ui->edt_endereco ->setText(endereco);
            ui->edt_fone->setText(fone);
        };
        //fecha o banco de dados
        db.close();
   }
   //Remove a conexao
   QSqlDatabase::removeDatabase("01"); // correct
}

void FrmClientes::on_btn_relatorio_clicked()
{
    table_relat="Cliente";
    FrmOpsRelatorio formOpsRelatorio(this);
    formOpsRelatorio.exec();
}

void FrmClientes::on_btn_atualizar_clicked()
{
    {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);

        QString verify = ui->edt_id -> text();
        QString sql2 = "select * from Cliente where Cod='"+verify+"' limit 1";
        query.exec(sql2);

        int nraff = query.size();
        if (nraff <= 0){

         QMessageBox::information(this, tr("Mensagem!"),
                      tr("Este Cliente Ainda não Foi Cadastrado!.\n"
                         "Por Favor, Peça (Salvar) para Cadastrar!"));
        }else{

                QString id = ui->edt_id -> text();
                QString nome = ui->edt_nome -> text();
                QString endereco = ui->edt_endereco -> text();
                QString fone = ui->edt_fone -> text();
                QString sql = "UPDATE Cliente SET Nome = '"+nome+"',Endereco='"+endereco+"',Fone = '"+fone+"' where Cod ="+id;
                query.exec(sql);
                db.close();
                QMessageBox::information(this, tr("Mensagem!"),
                tr("Cliente Atualizado com Sucesso!.\n"
                   "Obrigado Por Usar (Omega Sistemas)!"));
        }
    }

    QSqlDatabase::removeDatabase("01"); // correct


}
