#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conexao.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Clientes_triggered();

    void on_action_Os_triggered();

    void on_action_ContasP_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
