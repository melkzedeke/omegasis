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
void conecta(QSqlDatabase *db){
    QString my_hostname;
    QString my_database;
    QString my_username;
    QString my_password;
    //seta as variaveis de conexao do banco de dados
    QSettings settings("/etc/config/database.ini",
    QSettings::IniFormat);
    my_hostname =settings.value("omegasis/hostname").toString ();
    my_database =settings.value("omegasis/database").toString ();
    my_username =settings.value("omegasis/username").toString ();
    my_password =settings.value("omegasis/password").toString ();
    //fim das variáveis 1
    *db = QSqlDatabase::addDatabase("QMYSQL","01");
    db->setHostName(my_hostname);
    db->setDatabaseName(my_database);
    db->setUserName(my_username);
    db->setPassword(my_password);
    db->open();
}
