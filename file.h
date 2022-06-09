#ifndef FILE_H
#define FILE_H
#include <QtCore/qglobal.h>
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QtWidgets/QMainWindow>
#include <QRadioButton>
#include <QTextEdit>
#include <QSlider>
#include <QHeaderView>

#include "Computer.h"
#define FILENAME "Computers.txt"

class File : public QFile
{

public:
    explicit File(QObject *parent = nullptr);
    File(QString filename);
    void        open_file();
    void        add_data(Computer *computer);
    void        fill_row(QTableWidget* Table, int i,  Computer buf);
    void        fill_table(QTableWidget *Table);
    int         find_min_price();
    int         find_max_price();
    int         average_price_by_memory(int memory);
    void        set_headers(QTableWidget *Table);
    ~File(){};
};
#endif // FILE_H



