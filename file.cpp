#include "file.h"

File::File(QString filename):QFile(filename){}

void    File::open_file()
{
 this->open(QFile::ReadWrite);
 if (!this->isOpen())
     {
         QMessageBox msg(QMessageBox::Critical,"File not found", "Please, don't cry", QMessageBox::Ok,0);
         msg.exec();
     }
}

void    File::add_data(Computer *computer)
{
     this->open_file();
     this->seek(this->size());
     QDataStream out(this);
     out
         << computer->comp_name
         << computer->memory
         << computer->microprocessor
         << computer->winchester
         << computer->price;
     this->close();
}

void    File::fill_row(QTableWidget* Table, int i, Computer buf)
{
    Table->insertRow(i);
    QTableWidgetItem *item;
    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(buf.comp_name);
    Table->setItem(i, 0, item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(buf.microprocessor);
    Table->setItem(i, 1, item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(buf.memory);
    Table->setItem(i, 2, item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(buf.winchester);
    Table->setItem(i, 3, item);

    item = new QTableWidgetItem();
    item->setFlags(Qt::NoItemFlags);
    item->setText(buf.price);
    Table->setItem(i, 4, item);
}

void    File::fill_table(QTableWidget* Table)
{
     Computer*   buf;
     QDataStream in(this);

     int i = 0;
     this->open_file();
     while (!in.atEnd())
     {
         buf = new Computer;
         in  >> buf->comp_name
             >> buf->memory
             >> buf->microprocessor
             >> buf->winchester
             >> buf->price;

            this->fill_row(Table, i, *buf);
            i++;
     }
     this->close();
}

int File::find_min_price()
{
    this->open_file();
    Computer*   buf;
    QDataStream in(this);

    bool first = true;
    int min = 0;
    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
        if (first)
        {
            min = buf->price.toInt();
            first = false;
        }
        else
        {
            if (min > buf->price.toInt())
                min = buf->price.toInt();
        }
    }
    this->close();
    return min;
}

int     File::find_max_price()
{
    this->open_file();
    Computer*   buf;
    QDataStream in(this);

    bool first = true;
    int max = 0;
    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
        if (first)
        {
            max = buf->price.toInt();
            first = false;
        }
        else
        {
            if (max < buf->price.toInt())
                max = buf->price.toInt();
        }
    }
    this->close();
    return max;
}
int        File::average_price_by_memory(int memory)
{
    this->open_file();
    Computer*   buf;
    QDataStream in(this);

    int average = 0;
    int sum = 0;
    int num = 0;
    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
        if (buf->memory.toInt() == memory)
        {
            sum += buf->price.toInt();
            num += 1;
        }
    }
    if (num)
        average = sum / num;
    this->close();
    return average;
}


void        File::set_headers(QTableWidget *Table)
{
    QStringList headers;
        headers << "Название компьютера"
                << "Объем оперативной памяти"
                << "Тип микропроцессора (разрядность)"
                << "Объем жесткого диска"
                << "Цена";
    Table->setHorizontalHeaderLabels(headers);
    Table->setWordWrap(true);
    Table->columnWidth(600);
    Table->horizontalHeader()->setDefaultAlignment((Qt::Alignment)Qt::TextWordWrap);
    Table->horizontalHeader()->setFixedHeight(70);
}
