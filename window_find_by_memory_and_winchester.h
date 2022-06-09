#ifndef WINDOW_FIND_BY_MEMORY_AND_WINCHESTER_H
#define WINDOW_FIND_BY_MEMORY_AND_WINCHESTER_H

#include "file.h"
#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class Window_find_by_memory_and_winchester : public QMainWindow
{
private:
    int memory = 0;
    int winchester = 0;
    bool    found;
protected:
    QRadioButton*   memory_4;
    QRadioButton*   memory_8;
    QRadioButton*   memory_16;
    QRadioButton*   memory_32;
    QRadioButton*   memory_64;
    QRadioButton*   memory_128;

    QRadioButton*   winchester_128;
    QRadioButton*   winchester_256;
    QRadioButton*   winchester_512;
    QRadioButton*   winchester_1024;
    QRadioButton*   winchester_2048;

    QPushButton*    search;
    QPushButton*    delete_choices;
    QTableWidget*   Table;
    QPushButton*    exit;
    File*           file;

public:
    explicit Window_find_by_memory_and_winchester(QWidget *parent = nullptr);
    void    inteface_settings();
    void    choose_memory();
    void    choose_winchester();
    void    fill_table();
    void    delete_all();
signals:

};

#endif // WINDOW_FIND_BY_MEMORY_AND_WINCHESTER_H
