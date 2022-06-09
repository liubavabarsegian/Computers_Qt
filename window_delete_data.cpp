#include "window_delete_data.h"
#include "qlineedit.h"
#include <QVBoxLayout>

Window_delete_data::Window_delete_data(QWidget *parent)
    : QMainWindow{parent}
{
    interface_settings();
    connect(okay, &QPushButton::clicked, this, &Window_delete_data::delete_by_row);
    connect(cancel, &QPushButton::clicked, this, &QMainWindow::close);
    okay->setDefault(true);
    file = new File(FILENAME);
}

void    Window_delete_data::delete_by_row()
{
    row = (input->text().toInt()) - 1;
    move_to_file();
    copy_file();
    Table->clearContents();
    file->fill_table(Table);
    file->set_headers(Table);
    this->close();
}

void    Window_delete_data::interface_settings()
{
    this->setWindowTitle("Делето");
    this->setStyleSheet("QMainWindow { background-color :#cee2ff ; color : black; }");

    instruction = new QLabel("Выберите номер строки, которую необходимо удалить.");
    input = new QLineEdit(this);
    okay = new QPushButton("OK");
    cancel = new QPushButton("Отмена");
    Table = new QTableWidget;

    QHBoxLayout *buttons = new QHBoxLayout;
    buttons->addWidget(okay);
    buttons->addWidget(cancel);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(instruction);
    layout->addWidget(input);
    layout->addLayout(buttons);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

}

void    Window_delete_data::move_to_file()
{
    Computer*   buf;
    file->open_file();

    File* g = new File("TempFile.txt");
    g->open_file();

    int i = 0;

    QDataStream in(file);
    QDataStream out(g);

    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
        if (i != row)
        {
            out
                << buf->comp_name
                << buf->memory
                << buf->microprocessor
                << buf->winchester
                << buf->price;
        }
           i++;
    }
    file->close();
    g->close();
    file->resize(0);
}

void    Window_delete_data::copy_file()
{
    Computer*   buf;
    File* g = new File("TempFile.txt");
    file->open_file();
    g->open_file();
    QDataStream out(file);
    QDataStream in(g);

    while (!in.atEnd())
    {
        buf = new Computer;
        in  >> buf->comp_name
            >> buf->memory
            >> buf->microprocessor
            >> buf->winchester
            >> buf->price;
        out
            << buf->comp_name
            << buf->memory
            << buf->microprocessor
            << buf->winchester
            << buf->price;
    }

    g->close();
    g->remove();
    file->close();
}
