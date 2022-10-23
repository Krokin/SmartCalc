#include "graphs.h"
#include "ui_graphs.h"

Graphs::Graphs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphs)
{
    ui->setupUi(this);
    ui->widget->xAxis->setRange(-10,10);
    ui->widget->yAxis->setRange(-10,10);
    connect(ui->pushButtonPaint,SIGNAL(clicked()),this,SLOT(paint()));

}

Graphs::~Graphs()
{
    delete ui;
}


void Graphs:: paint() {
    ui->widget->clearGraphs();
    double xBegin, xEnd, h, X;
    QVector<double> x,y;
    h = 0.1;
    xBegin = ui->xBegin->value();
    xEnd = ui->xEnd->value();
    double buf_X;
    QString buf_strx;
    int err = 0;
    char str[1024] = {0};
    for (X = xBegin; X <= xEnd;) {
        x.push_back(X);
        QByteArray barr = ui->func->text().toLatin1();
        strlcpy(str, barr, ui->func->text().length() + 1);
        buf_strx = QString::number(X);
        QByteArray strx = buf_strx.toLocal8Bit();
        char *strx1 = strx.data();
        err = Smart_Calc(str,strx1,&buf_X);
        y.push_back(buf_X);
        if (X + h > -0.0001 && X + h < 0) {
            X = 0;
        } else {
            X += h;
        }
    }
    if (err != -1) {
        ui->err->setText("");
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x,y);
        ui->widget->replot();
    } else {
        ui->err->setText("Ошибка ввода");
    }
}
