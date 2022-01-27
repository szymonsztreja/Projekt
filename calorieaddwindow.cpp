#include "calorieaddwindow.h"
#include "ui_calorieaddwindow.h"
//#include <macros.cpp>
#include <QMessageBox>
#include "macros.h"
CalorieAddWindow::CalorieAddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalorieAddWindow)
{
    ui->setupUi(this);

    ui->doubleSpinBox->setSingleStep(5);
    ui->doubleSpinBox->setRange(0,1000);

    std::vector<Macros> Products;

    ui->comboBox->addItem("Chicken") ;
    ui->comboBox->addItem("Egg") ;
    ui->comboBox->addItem("Rice") ;
    ui->comboBox->addItem("Tomato") ;
    ui->comboBox->addItem("Paprika") ;
    ui->comboBox->addItem("Potato") ;
    ui->comboBox->addItem("Pasta") ;
    ui->comboBox->addItem("Bread") ;
    ui->comboBox->addItem("Oatmeal") ;
    ui->comboBox->addItem("Milk") ;
    ui->comboBox->addItem("Beef") ;

}

CalorieAddWindow::~CalorieAddWindow()
{
    delete ui;
}

void CalorieAddWindow::on_pushButton_clicked()
{
    auto Chicken = Macros(31, 0, 3.6);
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
    double a;
    auto Weigh = ui->doubleSpinBox->value();

    switch( ui->comboBox->currentIndex() )
    {
    case 0 :
        a = CalorieIntake(Weigh, Chicken);
        break;
    case 1 :
        a = CalorieIntake(Weigh, Egg);
        break;
    case 2 :
        a = CalorieIntake(Weigh, Rice);
        break;
    case 3 :
        a = CalorieIntake(Weigh, Tomato);
        break;
    case 4 :
        a = CalorieIntake(Weigh, Paprika);
        break;
    case 5 :
        a = CalorieIntake(Weigh, Potato);
        break;
    case 6 :
        a = CalorieIntake(Weigh, Pasta);
        break;
    case 7 :
        a = CalorieIntake(Weigh, Bread);
        break;
    case 8 :
        a = CalorieIntake(Weigh, Oatmeal);
        break;
    case 9 :
        a = CalorieIntake(Weigh, Milk);
        break;
    case 10 :
        a = CalorieIntake(Weigh, Beef);
        break;
    }

    QMessageBox::information(this, "title", QString::number(a) );
}
