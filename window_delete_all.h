#ifndef WINDOW_DELETE_ALL_H
#define WINDOW_DELETE_ALL_H

#include "file.h"

class Window_delete_all : public QMainWindow
{
protected:
    QLabel*         warning;
    QPushButton*    okay;
    QPushButton*    cancel;
    File*           file;
public:
    QTableWidget*     Table;

    explicit Window_delete_all(QWidget *parent = nullptr);
    void    interface_settings();
    void    delete_all();
signals:

};

#endif // WINDOW_DELETE_ALL_H
