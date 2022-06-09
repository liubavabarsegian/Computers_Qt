#include "window_show_data.h"
#include "file.h"
#include "window_delete_data.h"
#include <QVBoxLayout>

Window_show_data::Window_show_data(QWidget *parent)
    : QMainWindow{parent}
{

    file = new File(FILENAME);
    Interface_settings();
    file->set_headers(Table);

    connect(exit, &QPushButton::clicked, this, &QWidget::close);
    connect(delete_row, &QPushButton::clicked, this, &Window_show_data::delete_element);
    connect(delete_all, &QPushButton::clicked, this, &Window_show_data::delete_everything);

    file->fill_table(Table);
}

void    Window_show_data::Interface_settings()
{
    Table = new QTableWidget(15, 5, this);
    delete_row = new QPushButton("Удалить данные по номеру строки", this);
    delete_all = new QPushButton("Удалить все данные", this);
    exit = new QPushButton("Выход",this);

    this->setWindowTitle("Посмотреть все данные.");
    this->setStyleSheet("QMainWindow { background-color :#cee2ff ; color : black; }");
    this->resize(Table->width() * 5.7, Table->height() * 10);
    file->set_headers(Table);

    delete_row->setFixedHeight(30);
    delete_row->setFont(QFont("Times", 12));
    delete_all->setFixedHeight(30);
    delete_all->setFont(QFont("Times", 12));
    exit->setFixedHeight(30);
    exit->setFont(QFont("Times", 12));

    QHBoxLayout * buttons = new QHBoxLayout;
    buttons->addWidget(delete_row);
    buttons->addWidget(delete_all);
    buttons->addWidget(exit);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(Table);
    layout->addLayout(buttons);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);
}

void    Window_show_data::delete_element()
{
    W_delete_data = new Window_delete_data(this);
    W_delete_data->Table = Table;
    W_delete_data->show();
}

void    Window_show_data::delete_everything()
{
    W_delete_all = new Window_delete_all(this);
    W_delete_all->Table = Table;
    W_delete_all->show();
}


Window_show_data::~Window_show_data()
{
    file->close();
}
