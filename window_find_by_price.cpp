#include "window_find_by_price.h"

Window_find_by_price::Window_find_by_price(QWidget *parent)
    : QMainWindow{parent}
{
    file = new File(FILENAME);
    interface_settings();
    file->set_headers(Table);

    connect(exit, &QPushButton::clicked, this, &QMainWindow::close);
    connect(Slider, &QSlider::valueChanged, this, &Window_find_by_price::update);
    connect(Slider, &QSlider::valueChanged, this, [=] () {tmpLabel->setText(QString::number(Slider->value()));});
}
void    Window_find_by_price::update()
{
    Table->clearContents();
    file->set_headers(Table);
    fill_table();


    min->setText(QString::number(file->find_min_price()));
    max->setText(QString::number(file->find_max_price()));
    Slider->setMinimum(file->find_min_price());
    Slider->setMaximum(file->find_max_price());
}

void    Window_find_by_price::fill_table()
{
    Computer*   buf;
    file->open_file();

    int i = 0;
    price = Slider->value();
    QDataStream in(file);
    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
            if (buf->price.toInt() <= price)
            {
                file->fill_row(Table, i, *buf);
                i++;
            }
    }
    file->close();
}

void    Window_find_by_price::interface_settings()
{
    instructions = new QLabel("Выберите максимальную цену компьютера, прокрутив ползунок.");
    Slider = new QSlider(Qt::Horizontal);
    Table = new QTableWidget(10, 5, this);
    exit = new QPushButton("Выход", this);
    tmpLabel = new QLabel("0");
    min = new QLabel(QString::number(file->find_min_price()));
    max = new QLabel(QString::number(file->find_max_price()));

    this->setWindowTitle("Найти компьютеры, цена которых не превышает заданную.");
    this->setStyleSheet("QMainWindow { background-color :#cee2ff ; color : black; }");
    this->resize(Table->width() * 6.1, Table->height() * 15);
    Table->setColumnWidth(2, 140);
    instructions->setFont(QFont("Times", 12));
    exit->setFixedHeight(30);
    exit->setFont(QFont("Times", 12));

    Slider->setMinimum(file->find_min_price());
    Slider->setMaximum(file->find_max_price());

    QHBoxLayout* values = new QHBoxLayout;
    values->addWidget(min);
    values->addWidget(tmpLabel);
    values->addWidget(max);
    values->setSpacing(170);

    QVBoxLayout *layout1 = new QVBoxLayout;
    layout1->addWidget(instructions);
    layout1->addWidget(Slider);
    layout1->addLayout(values);
    layout1->addWidget(Table);
    layout1->addWidget(exit);

    QWidget *window = new QWidget();
    window->setLayout(layout1);
    setCentralWidget(window);
}

Window_find_by_price::~Window_find_by_price()
{
    file->close();
}
