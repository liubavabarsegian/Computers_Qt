#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Create_Buttons();
    interface_settings();

    connect(exit, &QPushButton::clicked, this, &MainWindow::close);
    connect(find_by_price, &QPushButton::clicked, this, &MainWindow::Clicked_find_by_price);
    connect(add_data, &QPushButton::clicked, this, &MainWindow::Clicked_add_data);
    connect(cheapest_by_microprocessor, &QPushButton::clicked, this, &MainWindow::Clicked_cheapest_by_microprocessor);
    connect(find_by_memory_and_winchester, &QPushButton::clicked, this, &MainWindow::Clicked_find_by_memory_and_winchester);
    connect(show_data, &QPushButton::clicked, this, &MainWindow::Clicked_show_data);
    connect(show_graphic, &QPushButton::clicked, this, &MainWindow::Clicked_show_graphic);
}

MainWindow::~MainWindow()
{

}

void MainWindow::interface_settings()
{
    this->setWindowTitle("Подберите компьютер!");
    this->setStyleSheet("QMainWindow { background-color :#cee2ff ; color : black; }");
    photo = new QLabel(this);
    photo->setPixmap(QPixmap(QString::fromUtf8("D:/lyuba/bamonka/oop/practice/Computers/srcs/boy.png")));
    photo->setScaledContents(true);
    photo->setFixedSize(300, 200);

    label = new QLabel("Подберите компьютер!");
    label->setFont(QFont("Times", 20));
    label->setStyleSheet("QLabel {color : #4A1795; }");
    label->setAlignment(Qt::AlignmentFlag(Qt::AlignHCenter));

    layout1 = new QVBoxLayout;
    layout1->addWidget(find_by_price);
    layout1->addWidget(cheapest_by_microprocessor);
    layout1->addWidget(find_by_memory_and_winchester);
    layout1->addWidget(show_graphic);

    layout2 = new QHBoxLayout;
    layout2->addWidget(show_data);
    layout2->addWidget(add_data);
    layout2->addWidget(exit);

    layout3 = new QHBoxLayout;
    layout3->addWidget(photo);
    layout3->addLayout(layout1);

    layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addLayout(layout3);
    layout->addLayout(layout2);
    layout->setSpacing(30);
    layout->setContentsMargins(20, 50, 20, 50);

    window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);
}

void MainWindow::Create_Buttons()
{
    find_by_price = new QPushButton("Найти компьютеры по цене", this);
    cheapest_by_microprocessor = new QPushButton("Найти самый дешевый компьютер по типу микропроцессора", this);
    exit = new QPushButton("Выход", this);
    find_by_memory_and_winchester = new QPushButton("Найти компьютеры по типу памяти и винчестера", this);
    show_graphic = new QPushButton("Посмотреть график", this);
    show_data = new QPushButton("Вывести все данные", this);
    add_data = new QPushButton("Добавить данные", this);

    find_by_price->adjustSize();
    cheapest_by_microprocessor->adjustSize();
    exit->adjustSize();
    find_by_memory_and_winchester->adjustSize();
    show_graphic->adjustSize();
    show_data->adjustSize();
    add_data->adjustSize();

    find_by_price->setFixedHeight(40);
    cheapest_by_microprocessor->setFixedHeight(40);
    exit->setFixedHeight(40);
    find_by_memory_and_winchester->setFixedHeight(40);
    show_graphic->setFixedHeight(40);
    show_data->setFixedHeight(40);
    add_data->setFixedHeight(40);

    find_by_price->setFont(QFont("Times", 12));
    cheapest_by_microprocessor->setFont(QFont("Times", 12));
    exit->setFont(QFont("Times", 12));
    find_by_memory_and_winchester->setFont(QFont("Times", 12));
    show_graphic->setFont(QFont("Times", 12));
    show_data->setFont(QFont("Times", 12));
    add_data->setFont(QFont("Times", 12));
}

void    MainWindow::Clicked_find_by_memory_and_winchester()
{
    W_find_by_memory_and_winchester = new Window_find_by_memory_and_winchester(this);
    W_find_by_memory_and_winchester->show();
}

void    MainWindow::Clicked_find_by_price()
{
    W_find_by_price = new Window_find_by_price(this);
    W_find_by_price->show();

}

void   MainWindow::Clicked_add_data()
 {
     W_add_data = new Window_add_data(this);
     W_add_data->show();
 }

void    MainWindow::Clicked_cheapest_by_microprocessor()
 {
     W_cheapest_by_microprocessor = new Window_cheapest_by_microprocessor(this);
     W_cheapest_by_microprocessor->show();
 }

void   MainWindow::Clicked_show_data()
 {
     W_show_data = new Window_show_data(this);
     W_show_data->show();
 }

void    MainWindow::Clicked_show_graphic()
 {
     W_show_graphic = new Window_show_graphic(this);
     W_show_graphic->show();
 }
