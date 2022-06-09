#ifndef WINDOW_DELETE_DATA_H
#define WINDOW_DELETE_DATA_H

#include "file.h"

class Window_delete_data : public QMainWindow
{
    Q_OBJECT
protected:
    QLabel*         instruction;
    QLineEdit*      input;
    QPushButton*    okay;
    QPushButton*    cancel;
    File*           file;
    int row;
public:
    QTableWidget*     Table;

    explicit Window_delete_data(QWidget *parent = nullptr);
    void    interface_settings();
    void    move_to_file();
    void    copy_file();
    void    delete_by_row();

signals:

};

#endif // WINDOW_DELETE_DATA_H
