#include "window_show_graphic.h"
#include "qchartview.h"
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>

Window_show_graphic::Window_show_graphic(QWidget *parent)
    : QMainWindow{parent}
{
    file = new File(FILENAME);

    QSplineSeries* spline = new QSplineSeries();
    spline->append(4, file->average_price_by_memory(4));
    spline->append(8, file->average_price_by_memory(8));
    spline->append(16, file->average_price_by_memory(16));
    spline->append(32, file->average_price_by_memory(32));
    spline->append(64, file->average_price_by_memory(64));
    spline->append(128, file->average_price_by_memory(128));
    spline->setName("График зависимости цены компьютера от объема оперативной памяти.");


    QChart *chart = new QChart;
    chart->addSeries(spline);

    QValueAxis *axisX = new QValueAxis;
    axisX->setTickCount(10);
    chart->addAxis(axisX, Qt::AlignBottom);
    QValueAxis *axisY = new QValueAxis;
    axisY->setLinePenColor(spline->pen().color());
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->setAnimationOptions(QChart::AllAnimations);
    spline->attachAxis(axisX);
    spline->attachAxis(axisY);
    spline->setColor(QColor("#C43BC6"));

    QChartView *chartView = new QChartView(this);
    chartView->setChart(chart);


    exit = new QPushButton("Выход");
    connect(exit, &QPushButton::clicked, this, &Window_show_graphic::close);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    layout->addWidget(exit);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

    this->resize(600, 500);
    this->setWindowTitle("График");


    exit->setFixedHeight(30);
    exit->setFont(QFont("Times", 12));

}
