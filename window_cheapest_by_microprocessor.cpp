#include "window_cheapest_by_microprocessor.h"

#include <QVBoxLayout>

Window_cheapest_by_microprocessor::Window_cheapest_by_microprocessor(QWidget *parent)
    : QMainWindow{parent}
{
    micro_type = -1;
    interface_settings();
    connect(exit, &QPushButton::clicked, this, &QMainWindow::close);
    connect(search, &QPushButton::clicked, this, &Window_cheapest_by_microprocessor::Print_Result);

    file = new File(FILENAME);
    found = false;
}

void        Window_cheapest_by_microprocessor::Choose()
{
    if (micro_2->isChecked())
        micro_type = 2;
    if (micro_4->isChecked())
        micro_type = 4;
    if (micro_6->isChecked())
        micro_type = 6;
    if (micro_8->isChecked())
        micro_type = 8;
    if (micro_16->isChecked())
        micro_type = 16;
    if (micro_32->isChecked())
        micro_type = 32;
    if (micro_64->isChecked())
        micro_type = 64;
}

void    Window_cheapest_by_microprocessor::interface_settings()
{
    this->setWindowTitle("Найти компьютер по типу микропроцессора.");
    this->setStyleSheet("QMainWindow { background-color :#cee2ff ; color : black; }");
    this->setFixedWidth(430);

    micro_2 = new QRadioButton("2-разрядный микропроцессор");
    micro_4 = new QRadioButton("4-разрядный микропроцессор");
    micro_6 = new QRadioButton("6-разрядный микропроцессор");
    micro_8 = new QRadioButton("8-разрядный микропроцессор");
    micro_16 = new QRadioButton("16-разрядный микропроцессор");
    micro_32 = new QRadioButton("32-разрядный микропроцессор");
    micro_64 = new QRadioButton("64-разрядный микропроцессор");

    instructions = new QLabel("Выберите тип микропроцессора, а мы подберем самый бюджетный компьютер с указанным типом!", this);
    Result = new QTextEdit;
    search = new QPushButton("Поиск", this);
    search->setFixedHeight(30);
    exit = new QPushButton("Выход", this);
    exit->setFixedHeight(30);

    instructions->setFont(QFont("Times", 12));
    instructions->setWordWrap(true);
    micro_2->setFont(QFont("Times", 10));
    micro_4->setFont(QFont("Times", 10));
    micro_6->setFont(QFont("Times", 10));
    micro_8->setFont(QFont("Times", 10));
    micro_16->setFont(QFont("Times", 10));
    micro_32->setFont(QFont("Times", 10));
    micro_64->setFont(QFont("Times", 10));
    exit->setFont(QFont("Times, 20"));
    search->setFont(QFont("Times, 20"));

    layout = new QVBoxLayout(this);
    layout->addWidget(instructions);
    layout->addWidget(micro_2);
    layout->addWidget(micro_4);
    layout->addWidget(micro_6);
    layout->addWidget(micro_8);
    layout->addWidget(micro_16);
    layout->addWidget(micro_32);
    layout->addWidget(micro_64);
    layout->addWidget(search);
    layout->addWidget(Result);
    layout->addWidget(exit);

    window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

}

Computer    Window_cheapest_by_microprocessor::Search()
{
    Choose();

    Computer*   buf;
    file->open_file();
    QDataStream in(file);

    int min = 0;
    Computer    result;
    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
        if (buf->microprocessor.toInt() == micro_type)
        {
            found = true;
            if (min == 0)
            {
                min = buf->price.toInt();
                result = *buf;
            }
            else
            {
                if (buf->price.toInt() < min)
                {
                    min = buf->price.toInt();
                    result = *buf;
                }
            }
        }
    }
    return result;
}

void        Window_cheapest_by_microprocessor::Print_Result()
{
    Computer comp_result = Search();
    Result->clear();
    if (micro_type == -1)
    {
        QMessageBox msg(QMessageBox::Critical, "Внимание!", "Вы ничего не выбрали. Выберите что-нибудь, пж....", QMessageBox::Ok,0);
        msg.exec();
    }
    else if (found)
    {
        Result->append("Компьютер с выбранным микропроцессором найден!\nСамый бюджетный вариант: \n");
        Result->append("Название компьютера: " + comp_result.comp_name);
        Result->append("Объем оперативной памяти в ГБ:" + comp_result.memory);
        Result->append("Тип микропроцессора (разрядность): " + comp_result.microprocessor);
        Result->append("Объем жесткого диска: " + comp_result.winchester);
        Result->append("Цена: " + comp_result.price);
    }
    else
    {
        QMessageBox msg(QMessageBox::Critical, "Упс", "Извините, в наличии нет подходящих компьютеров.", QMessageBox::Ok,0);
        msg.exec();
    }
    file->close();
}
