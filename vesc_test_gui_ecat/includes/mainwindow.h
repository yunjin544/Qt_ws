#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

extern char share_init;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void ExecuteProgram();
    ~MainWindow();

private slots:
    void on_Send_btn_clicked();

    void on_Stop_btn_clicked();

private:
    Ui::MainWindow *ui;
    QProcess *textMsgProcess;
};
#endif // MAINWINDOW_H
