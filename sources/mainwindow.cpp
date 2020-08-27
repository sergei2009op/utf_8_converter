#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <vector>
#include <QDebug>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString sym = ui->lineEdit->text();
    vector<int> v;

    if (sym.size() != 0)
    {
        QByteArray utf = sym.toUtf8();
        for (int i = 0; i < utf.size(); i++)
            v.push_back(utf[i]);

        if (v[0] < 0 && v[1] < 0)
        {
            ui->spinBox->setValue((v[0] + 64)*64 + (v[1] + 128));
            ui->spinBox_2->setValue(v[0] + 256);
            ui->spinBox_3->setValue(v[1] + 256);
        }
        else
        {
            ui->spinBox->setValue(v[0]);
            ui->spinBox_2->setValue(v[0]);
            ui->spinBox_3->setValue(0);
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    int sym = ui->spinBox->value();
    ui->lineEdit->setText(QString(sym));
}
