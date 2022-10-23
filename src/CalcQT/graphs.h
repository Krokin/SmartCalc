#ifndef GRAPHS_H
#define GRAPHS_H

#include <QDialog>

#ifdef __cplusplus
extern "C"
{
#endif
#include "../Smart_Calc.h"
#ifdef __cpluplus
}
#endif

namespace Ui {
class Graphs;
}

class Graphs : public QDialog
{
    Q_OBJECT

public:
    explicit Graphs(QWidget *parent = nullptr);
    ~Graphs();

private:
    Ui::Graphs *ui;

private slots:
    void paint();

};
#endif // GRAPHS_H
