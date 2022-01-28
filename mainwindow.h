#ifndef MAINWINDOW_H
#define MAINWINDOW_H        // headers file loaded just once

#include <QMainWindow>
#include <QDesktopWidget>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
namespace Ui {
class MainWindow;
}

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPieSeries *series;
    QChart *chart;
    QChartView *chartView ;

public:
    explicit MainWindow(QWidget *parent = 0);   //declare a constr, widget has
    ~MainWindow();                              // no parent, dsctr

private slots:

    void PrintTotals();

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
