#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include "Shared_Memory.h"


char share_init;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    share_init = shmem_init();

    ui->setupUi(this);
    this->setWindowTitle("VESC TEST GUI");

    int n = *shmem[SLAVE_N];
    int i = 0;
    while(i < n)
    {
        char str[100];
        sprintf(str,"Motor %d",i+1);
        ui->motor_select->addItem(str);

        i=i+1;
    }




}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Send_btn_clicked()
{
    s_wait(semid[DUTY]);
    *shmem[DUTY] =int(ui->doubleSpinBox->value());
    s_quit(semid[DUTY]);
}


void MainWindow::on_Stop_btn_clicked()
{
    s_wait(semid[DUTY]);
    ui->doubleSpinBox->setValue(0);
    *shmem[DUTY] =int(ui->doubleSpinBox->value());
    s_quit(semid[DUTY]);

}




