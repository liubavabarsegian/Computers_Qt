#include "window_find_by_memory_and_winchester.h"
#include "Computer.h"
#include "qgroupbox.h"
#include "file.h"

Window_find_by_memory_and_winchester::Window_find_by_memory_and_winchester(QWidget *parent)
    : QMainWindow{parent}
{
    inteface_settings();
    connect(exit, &QPushButton::clicked, this, &QMainWindow::close);
    connect(search, &QPushButton::clicked, this, &Window_find_by_memory_and_winchester::fill_table);
    connect(delete_choices, &QPushButton::clicked, this, &Window_find_by_memory_and_winchester::delete_all);
    file = new File(FILENAME);
    found = false;
}

void    Window_find_by_memory_and_winchester::inteface_settings()
{
    memory_4 = new QRadioButton("4 ГБ", this);
    memory_8 = new QRadioButton("8 ГБ", this);
    memory_16 = new QRadioButton("16 ГБ", this);
    memory_32 = new QRadioButton("32 ГБ", this);
    memory_64 = new QRadioButton("64 ГБ", this);
    memory_128 = new QRadioButton("128 ГБ", this);

    winchester_128 = new QRadioButton("128 ГБ", this);
    winchester_256 = new QRadioButton("256 ГБ", this);
    winchester_512 = new QRadioButton("512 ГБ", this);
    winchester_1024 = new QRadioButton("1 ТБ", this);
    winchester_2048 = new QRadioButton("2 ТБ", this);

    search = new QPushButton("Поиск", this);
    delete_choices = new QPushButton("Очистить", this);
    Table = new QTableWidget(15, 5, this);
    exit = new QPushButton("Выход", this);


    this->setWindowTitle("Найти компьютеры по объему памяти");
    this->resize(Table->width() * 6.1, Table->height() * 20);
    Table->setColumnWidth(2, 140);
    search->setFixedHeight(30);
    search->setFont(QFont("Times", 12));
    file->set_headers(Table);
    delete_choices->setFixedHeight(30);
    delete_choices->setFont(QFont("Times", 12));
    exit->setFixedHeight(30);
    exit->setFont(QFont("Times", 12));

    QVBoxLayout *memories = new QVBoxLayout(this);
    memories->addWidget(memory_4);
    memories->addWidget(memory_8);
    memories->addWidget(memory_16);
    memories->addWidget(memory_32);
    memories->addWidget(memory_64);
    memories->addWidget(memory_128);

    QVBoxLayout *winchesters = new QVBoxLayout(this);
    winchesters->addWidget(winchester_128);
    winchesters->addWidget(winchester_256);
    winchesters->addWidget(winchester_512);
    winchesters->addWidget(winchester_1024);
    winchesters->addWidget(winchester_2048);

    QGroupBox*      groupBox1 = new QGroupBox("Выберите минимальный объем оперативной памяти:");
    groupBox1->setLayout(memories);
    QGroupBox*      groupBox2 = new QGroupBox("Выберите минимальный одъем жесткого диска:");
    groupBox2->setLayout(winchesters);

    QHBoxLayout*    RadioButtons = new QHBoxLayout(this);
    RadioButtons->addWidget(groupBox1);
    RadioButtons->addWidget(groupBox2);

    QHBoxLayout *buttons = new QHBoxLayout(this);
    buttons->addWidget(search);
    buttons->addWidget(delete_choices);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addLayout(RadioButtons);
    layout->addLayout(buttons);
    layout->addWidget(Table);
    layout->addWidget(exit);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);
}

void    Window_find_by_memory_and_winchester::choose_memory()
{
    if (memory_4->isChecked())
        memory = 4;
    if (memory_8->isChecked())
        memory = 8;
    if (memory_16->isChecked())
        memory = 16;
    if (memory_32->isChecked())
        memory = 32;
    if (memory_64->isChecked())
        memory = 64;
    if (memory_128->isChecked())
        memory = 128;
}

void    Window_find_by_memory_and_winchester::choose_winchester()
{
    if (winchester_128->isChecked())
        winchester = 128;
    if (winchester_256->isChecked())
        winchester = 256;
    if (winchester_512->isChecked())
        winchester = 512;
    if (winchester_1024->isChecked())
        winchester = 1024;
    if (winchester_2048->isChecked())
        winchester = 2048;
}

void    Window_find_by_memory_and_winchester::fill_table()
{

    Table->clearContents();
    file->set_headers(Table);
    choose_memory();
    choose_winchester();

    if (memory != 0 && winchester != 0)
    {
        Computer*   buf;
        file->open_file();
        QDataStream in(file);

        int i = 0;
        while (!in.atEnd())
        {
            buf = new Computer;
            in  >> buf->comp_name
                >> buf->memory
                >> buf->microprocessor
                >> buf->winchester
                >> buf->price;
            if (buf->winchester.toInt() >= winchester && buf->memory.toInt() >= memory)
            {
                found = true;
                file->fill_row(Table, i, *buf);
                i++;
            }
        }
        file->close();
    }
    else
    {
        QMessageBox msg(QMessageBox::Critical, "Внимание!", "Вы ничего не выбрали. Выберите что-нибудь, пж....", QMessageBox::Ok,0);
        msg.exec();
    }

}

void    Window_find_by_memory_and_winchester::delete_all()
{
    Table->clearContents();

    memory_4->setAutoExclusive(false);
    memory_4->setChecked(false);
    memory_4->setAutoExclusive(true);

    memory_8->setAutoExclusive(false);
    memory_8->setChecked(false);
    memory_8->setAutoExclusive(true);

    memory_16->setAutoExclusive(false);
    memory_16->setChecked(false);
    memory_16->setAutoExclusive(true);

    memory_32->setAutoExclusive(false);
    memory_32->setChecked(false);
    memory_32->setAutoExclusive(true);

    memory_64->setAutoExclusive(false);
    memory_64->setChecked(false);
    memory_64->setAutoExclusive(true);

    winchester_128->setAutoExclusive(false);
    winchester_128->setChecked(false);
    winchester_128->setAutoExclusive(true);

    winchester_256->setAutoExclusive(false);
    winchester_256->setChecked(false);
    winchester_256->setAutoExclusive(true);

    winchester_512->setAutoExclusive(false);
    winchester_512->setChecked(false);
    winchester_512->setAutoExclusive(true);

    winchester_1024->setAutoExclusive(false);
    winchester_1024->setChecked(false);
    winchester_1024->setAutoExclusive(true);

    winchester_2048->setAutoExclusive(false);
    winchester_2048->setChecked(false);
    winchester_2048->setAutoExclusive(true);

    memory = 0;
    winchester = 0;
}
