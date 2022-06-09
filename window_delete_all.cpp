#include "window_delete_all.h"

Window_delete_all::Window_delete_all(QWidget *parent)
    : QMainWindow{parent}
{
    interface_settings();
    file = new File(FILENAME);

    connect(okay, &QPushButton::clicked, this, &Window_delete_all::delete_all);
    connect(cancel, &QPushButton::clicked, this, &Window_delete_all::close);
    okay->setDefault(true);
}


void    Window_delete_all::delete_all()
{
    file->open_file();
    file->resize(0);
    file->close();
    Table->clearContents();
    file->set_headers(Table);
    this->close();
}


void    Window_delete_all::interface_settings()
{
    warning = new QLabel("Осторожно! Вы пытаетесь удалить все данные.\nНажмите ОК для подтверждения.");
    okay = new QPushButton("OK");
    cancel = new QPushButton("Отмена");

    QHBoxLayout *buttons = new QHBoxLayout(this);
    buttons->addWidget(okay);
    buttons->addWidget(cancel);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(warning);
    layout->addLayout(buttons);

    QWidget *window = new QWidget();
    window->setLayout(layout);
    setCentralWidget(window);

    this->setWindowTitle("Удалить все данные.");
}
