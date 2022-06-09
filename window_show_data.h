#ifndef WINDOW_SHOW_DATA_H
#define WINDOW_SHOW_DATA_H

#include <QtCore/qglobal.h>
#include <QtWidgets/QMainWindow>

#include <QTableWidget>
#include <QPushButton>
#include "file.h"
#include "window_delete_all.h"
#include "window_delete_data.h"

class Window_show_data : public QMainWindow
{
    Q_OBJECT
protected:
    QTableWidget*       Table;
    QPushButton*        exit;
    File*               file;
    QPushButton*        delete_row;
    QPushButton*        delete_all;
    Window_delete_data* W_delete_data;
    Window_delete_all*  W_delete_all;

    int *row;
public:
    explicit Window_show_data(QWidget *parent = nullptr);
    void    Interface_settings();
    void    fill_table(QTableWidget* Table);
    void    delete_element();
    void    delete_everything();
    void    update();
    ~Window_show_data();
signals:

};

#endif // WINDOW_SHOW_DATA_H
