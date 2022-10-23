#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QValidator>
#include <QScrollBar>
#include <iostream>
#include <QtGui>
#include "graphs.h"
#include "deposit.h"
#include "credit.h"
#include <QVector>

#ifdef __cplusplus
extern "C"
{
#endif
#include "../Smart_Calc.h"
#ifdef __cpluplus
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_actionDeposit_calculator_triggered();
    void on_actionCredit_Calculator_triggered();
    void on_actionGraphs_triggered();
};

#endif // MAINWINDOW_H
