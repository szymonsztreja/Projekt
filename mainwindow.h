#ifndef MAINWINDOW_H
#define MAINWINDOW_H        // headers file loaded just once

#include <QMainWindow>
#include <QDesktopWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);   //declare a constr, widget has
    ~MainWindow();                              // no parent, dsctr

private slots:

    void Switch_function(int index, double w);

    void Draw_Graph();

    void on_actionBMI_Calculator_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;                         // handles window
};

#endif // MAINWINDOW_H
