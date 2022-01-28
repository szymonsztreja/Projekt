#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>
#include "bmi_window.h"
#include <calorieaddwindow.h>
#include <macros.cpp>

#include <QList>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    series = new QPieSeries();
    series->append("Protein", macros_summary.Protein);
    series->append("Fats", macros_summary.Fats);
    series->append("Carbs", macros_summary.Carbs);

    QFont lablesFont;
    lablesFont.setPixelSize(13);
//    lablesFont.bold();

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setExploded();
    slice0->setLabelColor(QColor("#ffcc00"));
    slice0->setLabelFont(lablesFont);
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::black, 1));
    slice0->setColor(QColor("#4dc3ff"));
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelColor(QColor("#ffcc00"));
//    slice1->setLabelFont(QFont("ubuntu bold"));
    slice1->setLabelFont(lablesFont);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::black, 1));
    slice1->setColor(QColor("#ffdb4d"));
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelColor(QColor("#ffcc00"));
//    slice2->setLabelFont(QFont("ubuntu bold"));
    slice2->setLabelFont(lablesFont);
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::black, 1));
    slice2->setColor(QColor("#ff9933"));

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Macronutrients");
    chart->setTitleBrush(QBrush(QColor("#ffcc00")));
    chart->legend()->hide();
    chart->setBackgroundBrush(QBrush(QColor("transparent")));

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setParent(ui->frame);
    chartView->setMinimumSize(ui->frame->size() );

    QStringList food = { "Chicken", "Egg", "Rice", "Tomato",
                         "Paprika" , "Potato", "Pasta",
                         "Bread" , "Oatmeal", "Milk", "Beef"};
    ui->comboBox->addItems(food);
    ui->comboBox_2->addItems(food);
    ui->comboBox_3->addItems(food);
    ui->comboBox_4->addItems(food);
    ui->comboBox_5->addItems(food);

    ui->spinBox->setSingleStep(5);
    ui->spinBox->setRange(0,1000);
    ui->spinBox_2->setSingleStep(5);
    ui->spinBox_2->setRange(0,1000);
    ui->spinBox_3->setSingleStep(5);
    ui->spinBox_3->setRange(0,1000);
    ui->spinBox_4->setSingleStep(5);
    ui->spinBox_4->setRange(0,1000);
    ui->spinBox_5->setSingleStep(5);
    ui->spinBox_5->setRange(0,1000);

    ui->label_protein->setText(QString::number(macros_summary.Protein));
    ui->label_carbs->setText(QString::number(macros_summary.Carbs));
    ui->label_fats->setText(QString::number(macros_summary.Fats));
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
    auto weight = ui->spinBox->value();
    Switch_function( ui->comboBox->currentIndex(), weight);
    PrintTotals();
    Draw_Graph();
}


void MainWindow::on_pushButton_2_clicked()
{
    auto weight = ui->spinBox_2->value();
    Switch_function( ui->comboBox_2->currentIndex(), weight);;
    PrintTotals();
    Draw_Graph();
}

void MainWindow::on_pushButton_3_clicked()
{
    auto weight = ui->spinBox_3->value();
    Switch_function( ui->comboBox_3->currentIndex(), weight);
    PrintTotals();
    Draw_Graph();
}

void MainWindow::on_pushButton_4_clicked()
{
    auto weight = ui->spinBox_4->value();
    Switch_function( ui->comboBox_4->currentIndex(), weight);
    PrintTotals();
    Draw_Graph();
}

void MainWindow::on_pushButton_5_clicked()
{
    auto weight = ui->spinBox_5->value();
    Switch_function( ui->comboBox_5->currentIndex(), weight);
    PrintTotals();
    Draw_Graph();
}


void MainWindow::Draw_Graph()
{
    chart->removeSeries(series);

    series = new QPieSeries();
    series->append("Protein", macros_summary.Protein);
    series->append("Fats", macros_summary.Fats);
    series->append("Carbs", macros_summary.Carbs);

    chart->addSeries(series);

    QFont lablesFont;
    lablesFont.setPixelSize(13);
    lablesFont.bold();

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setExploded();
    slice0->setLabelColor(QColor("#ffcc00"));
    slice0->setLabelFont(lablesFont);
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::black, 1));
    slice0->setColor(QColor("#4dc3ff"));
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setLabelColor(QColor("#ffcc00"));
//    slice1->setLabelFont(QFont("ubuntu bold"));
    slice1->setLabelFont(lablesFont);
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::black, 1));
    slice1->setColor(QColor("#ffdb4d"));
    QPieSlice *slice2 = series->slices().at(2);
    slice2->setLabelColor(QColor("#ffcc00"));
//    slice2->setLabelFont(QFont("ubuntu bold"));
    slice2->setLabelFont(lablesFont);
    slice2->setLabelVisible();
    slice2->setPen(QPen(Qt::black, 1));
    slice2->setColor(QColor("#ff9933"));
}

void MainWindow::Switch_function(int index, double w)
{
    auto Chicken = Macros(21, 0, 3.6);
    auto Egg = Macros(13, 0.7, 9.5);
    auto Rice = Macros(6, 79, 1);
    auto Tomato = Macros(0.9, 3.9, 0.2);
    auto Paprika = Macros(0, 6, 1);
    auto Beef =  Macros(18, 0, 18);
    auto Potato = Macros(2, 18, 0);
    auto Pasta = Macros(15, 58, 3);
    auto Bread = Macros(6, 51, 2);
    auto Oatmeal = Macros( 17, 66, 7);
    auto Milk = Macros(3, 5, 3.2);


    switch( index )
    {
    case 0 :
       macros_summary.CalorieIntake(w, Chicken);
        break;
    case 1 :
        macros_summary.CalorieIntake(w, Egg);
        break;
    case 2 :
        macros_summary.CalorieIntake(w, Rice);
        break;
    case 3 :
        macros_summary.CalorieIntake(w, Tomato);
        break;
    case 4 :
        macros_summary.CalorieIntake(w, Paprika);
        break;
    case 5 :
        macros_summary.CalorieIntake(w, Potato);
        break;
    case 6 :
        macros_summary.CalorieIntake(w, Pasta);
        break;
    case 7 :
        macros_summary.CalorieIntake(w, Bread);
        break;
    case 8 :
        macros_summary.CalorieIntake(w, Oatmeal);
        break;
    case 9 :
        macros_summary.CalorieIntake(w, Milk);
        break;
    case 10 :
        macros_summary.CalorieIntake(w, Beef);
        break;
    }
}

void MainWindow::PrintTotals()
{
    ui->label_protein->setText(QString::number(macros_summary.Protein));
    ui->label_carbs->setText(QString::number(macros_summary.Carbs));
    ui->label_fats->setText(QString::number(macros_summary.Fats));
    ui->label_total->setText(QString::number(macros_summary.CaloriesTotal));
}
