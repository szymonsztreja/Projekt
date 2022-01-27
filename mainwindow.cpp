#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include "bmi_window.h"
#include <calorieaddwindow.h>
#include <macros.cpp>
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

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPieSeries *series = new QPieSeries();
    series->append("Protein", macros_summary.Protein);
    series->append("Fats", macros_summary.Fats);
    series->append("Carbohydrates", macros_summary.Carbs);

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setLabelVisible();
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelVisible();
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Dupa");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->frame);
    chartView->setFixedSize(ui->frame->size() );


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBMI_Calculator_triggered()
{
    BMI_window bmi;
    bmi.setModal(true);
    bmi.exec();
}

void MainWindow::on_pushButton_clicked()
{
    CalorieAddWindow CAW;
    CAW.setModal(true);
    CAW.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    CalorieAddWindow CAW;
    CAW.setModal(true);
    CAW.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    CalorieAddWindow CAW;
    CAW.setModal(true);
    CAW.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    CalorieAddWindow CAW;
    CAW.setModal(true);
    CAW.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    CalorieAddWindow CAW;
    CAW.setModal(true);
    CAW.exec();
}
