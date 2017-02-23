#include "frmrelatorio.h"
#include "ui_frmrelatorio.h"
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
#include "conexao.h"
#include <QPrinter>
#include <QPrintDialog>
extern QString sql_relat ;
extern QString cab_relat ;
extern QString linha_relat;
extern QString table_relat;

FrmRelatorio::FrmRelatorio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmRelatorio)
{
    ui->setupUi(this);
    ui->edt_relatorio->setStyleSheet("QTextEdit {margin-left:5px; margin-right:5px}");
    relatorio();

}

FrmRelatorio::~FrmRelatorio()
{
    delete ui;
}


void FrmRelatorio::on_FrmRelatorio_accepted()
{

}

void FrmRelatorio::relatorio()
{

    QFont fixed("Courier New", 8);
    ui->edt_relatorio ->setFont(fixed);
    ui->edt_relatorio ->insertPlainText("============================================================================================= \n");
    ui->edt_relatorio ->insertPlainText("Omega Sistemas With Qt & C++                                          # Relatório de Clientes  \n");
    ui->edt_relatorio ->insertPlainText("============================================================================================= \n");
    ui->edt_relatorio ->insertPlainText("\n");
    ui->edt_relatorio ->insertPlainText("\n");
    ui->edt_relatorio ->insertPlainText("============================================================================================= \n");
    ui->edt_relatorio ->insertPlainText(cab_relat+"\n");
    ui->edt_relatorio ->insertPlainText("============================================================================================= \n");

    {
        QSqlDatabase db ;
        conecta(&db);
        QSqlQuery query(db);
        query.exec("select "+sql_relat+" from "+table_relat);
        QSqlRecord rec = query.record();
        int qtd_row=rec.count();
        QString campo;
        QString nome;
        QString linha;
        QString regua;
        QString texto;
        int tamanho;
        int contador =0;
        int verificador =0;
            while (query.next())
            {
                while(contador!=qtd_row)
                {
                    campo = query.value(contador).toString();
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
                    campo = campo.leftJustified(tamanho, ' ');

                    regua.clear();
                    regua.append(linha);
                    regua.append(campo);

                    if(regua.count()<= 94)
                    {
                        linha.append(campo);
                    }
                    else
                    {
                        linha = linha.leftJustified(94, ' ');
                        linha.append("\n");
                        texto.append(linha);
                        linha.clear();
                        linha.append(campo);
                    }

                    verificador++;
                    contador++;
                }
                linha.append("\n");
                texto.append(linha);
                linha.clear();
                contador = 0;
            }
        ui->edt_relatorio ->insertPlainText(texto);
        db.close();
        sql_relat="";
        cab_relat="";
        linha_relat="";
    }
    QSqlDatabase::removeDatabase("01"); // correct
}

void FrmRelatorio::on_btn_imprimir_clicked()
{
    QPrinter printer;
    printer.setPrinterName("");

    QPrintDialog printDialog(&printer, this);
    if (printDialog.exec() == QDialog::Accepted) {
        ui->edt_relatorio->print(&printer);
        // print ...
    }

}
