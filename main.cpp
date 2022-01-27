#include "mainwindow.h"
#include <QApplication>             // handles all action related to window
#include <QDesktopWidget>
//#include <QtCharts/QPieSeries>
//#include <QtCharts/QPieSlice>
//#include <QtCharts/QChartView>
//#include <QtCharts/QBarSeries>
//#include <QtCharts/QBarSet>
//#include <QtCharts/QLegend>
//#include <QtCharts/QBarCategoryAxis>
//#include <QtCharts/QHorizontalStackedBarSeries>
//#include <QtCharts/QLineSeries>
//#include <QtCharts/QCategoryAxis>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);         //creates app objcet
    MainWindow w;                       // creates main app object
//    QDesktopWidget desktop;
//    w.resize(desktop.availableGeometry(this).size() * 0.7);
    w.resize(800,600);
    w.show();

//    QPieSeries *series = new QPieSeries();
//    series->append("Protein", .40);
//    series->append("Fats", .40);
//    series->append("Carbohydrates", 0.20);

//    QPieSlice *slice0 = series->slices().at(0);
//    slice0->setLabelVisible();
//    QPieSlice *slice1 = series->slices().at(1);
//    slice0->setLabelVisible();
//    QPieSlice *slice2 = series->slices().at(2);
//    slice0->setLabelVisible();

//    QChartView *chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);

    return a.exec();                    //loops code
}
