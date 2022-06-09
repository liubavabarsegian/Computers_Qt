#ifndef WINDOW_ADD_DATA_H
#define WINDOW_ADD_DATA_H
#include "Computer.h"
#include "file.h"

#include <QMainWindow>
class Window_add_data : public QMainWindow
{
    Q_OBJECT
protected:
    QLineEdit*  input_comp_name;
    QLineEdit*  input_winchester;
    QLineEdit*  input_microprocessor;
    QLineEdit*  input_memory;
    QLineEdit*  input_price;

    QLabel*     label_comp_name;
    QLabel*     label_winchester;
    QLabel*     label_microprocessor;
    QLabel*     label_memory;
    QLabel*     label_price;

    QPushButton*    save;
    QPushButton*    exit;

    File*      file;
    Computer*   computer;

    QVBoxLayout *layout1;
    QWidget *window;

public:
    explicit Window_add_data(QWidget *parent = nullptr);
    ~Window_add_data();
    void    Interface_settings();
    void    Save_data();
};

#endif // WINDOW_ADD_DATA_H
