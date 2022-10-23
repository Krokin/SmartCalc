#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_point,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_res,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_multi,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_un_minus,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_reset,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_X,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_pow,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_c_bracket,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_log,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_o_bracket,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(digits_numbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_res = "";
    if (button->text() == "+/-") {
        new_res = (ui->result_show->text() + ("-"));
    } else if (button->text() == "X") {
        new_res = (ui->result_show->text() + ("x"));
    } else if (button->text() == "x^") {
        new_res = (ui->result_show->text() + ("^"));
    } else if (button->text() == "log10") {
        new_res = (ui->result_show->text() + ("log"));
    } else if (button->text() == "√x") {
        new_res = (ui->result_show->text() + ("sqrt"));
    } else if (button->text() == "AC") {
    } else if (button->text() == "=") {
        double res = 0;
        char str[1024] = {0};
        char strx[1024] = {0};
        QByteArray barr = ui->result_show->text().toLatin1();
        strlcpy(str, barr, ui->result_show->text().length() + 1);
        QByteArray barr1 = ui->strx->text().toLatin1();
        strlcpy(strx, barr1, ui->strx->text().length() + 1);
        int err = Smart_Calc(str,strx,&res);
        if (err == 0) {
            new_res = QString::number(res, 'g', 15);
            ui->statusBar->showMessage("Ожидание ввода");
        } else {
            ui->statusBar->showMessage("Ошибка ввода. Ожидание ввода");
        }
    } else {
        new_res = (ui->result_show->text() + button->text());
    }
    ui->result_show->setText(new_res);
}

void MainWindow::on_actionDeposit_calculator_triggered()
{
    deposit window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_actionCredit_Calculator_triggered()
{
    credit window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_actionGraphs_triggered()
{
    Graphs window;
    window.setModal(true);
    window.exec();
}

