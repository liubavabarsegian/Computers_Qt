#include "window_add_data.h"
#include "file.h"
#include "qpushbutton.h"
#include <QGroupBox>

Window_add_data::Window_add_data(QWidget *parent)
    : QMainWindow{parent}
{

    Interface_settings();
    connect(exit, &QPushButton::clicked, this, &QWidget::close);
    connect(save, &QPushButton::clicked, this, &Window_add_data::Save_data);

    file = new File(FILENAME);
}

void Window_add_data::Save_data()
{
    computer = new Computer;
    computer->comp_name = input_comp_name->text();
    computer->memory = input_memory->text();
    computer->microprocessor = input_microprocessor->text();
    computer->winchester = input_winchester->text();
    computer->price = input_price->text();

    file->add_data(computer);

    input_comp_name->clear();
    input_memory->clear();
    input_microprocessor->clear();
    input_winchester->clear();
    input_price->clear();
}

void    Window_add_data::Interface_settings()
{
    this->setWindowTitle("Добавить данные");
    this->setStyleSheet("QMainWindow { background-color :#cee2ff ; color : black; }");

    input_comp_name = new QLineEdit;
    input_winchester = new QLineEdit;
    input_microprocessor = new QLineEdit;
    input_memory = new QLineEdit;
    input_price = new QLineEdit;

    label_comp_name = new QLabel;
    label_winchester = new QLabel;
    label_microprocessor = new QLabel;
    label_memory = new QLabel;
    label_price = new QLabel;

    save = new QPushButton("Сохранить данные", this);
    exit = new QPushButton("Выход", this);

    label_comp_name->setText("Название компьютера:");
    label_winchester->setText("Объем винчестера:");
    label_microprocessor->setText("Тип микропроцессора:");
    label_memory->setText("Объем оперативной памяти:");
    label_price->setText("Цена");

    this->setStyleSheet("QLabel{font-size: 12pt;}");
    input_comp_name->setFixedHeight(30);
    input_winchester->setFixedHeight(30);
    input_microprocessor->setFixedHeight(30);
    input_memory->setFixedHeight(30);
    input_price->setFixedHeight(30);

    save->setFont(QFont("Times", 12));
    exit->setFont(QFont("Times", 12));
    save->setFixedHeight(30);
    exit->setFixedHeight(30);

    layout1 = new QVBoxLayout;
    layout1->addWidget(label_comp_name);
    layout1->addWidget(input_comp_name);
    layout1->addWidget(label_price);
    layout1->addWidget(input_price);
    layout1->addWidget(label_winchester);
    layout1->addWidget(input_winchester);
    layout1->addWidget(label_microprocessor);
    layout1->addWidget(input_microprocessor);
    layout1->addWidget(label_memory);
    layout1->addWidget(input_memory);
    layout1->addWidget(label_price);
    layout1->addWidget(input_price);
    layout1->addWidget(save);
    layout1->addWidget(exit);
    layout1->setContentsMargins(10, 10, 10, 10);

    window = new QWidget();
    window->setLayout(layout1);
    setCentralWidget(window);

    this->setFixedWidth(300);

}

Window_add_data::~Window_add_data()
{
    //file->close();
};
