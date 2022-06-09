#ifndef WINDOW_CHEAPEST_BY_MICROPROCESSOR_H
#define WINDOW_CHEAPEST_BY_MICROPROCESSOR_H

#include "Computer.h"
#include "file.h"

class Window_cheapest_by_microprocessor : public QMainWindow
{
    Q_OBJECT
private:
    int     micro_type;
    bool    found;
protected:
    QRadioButton*   micro_2;
    QRadioButton*   micro_4;
    QRadioButton*   micro_6;
    QRadioButton*   micro_8;
    QRadioButton*   micro_16;
    QRadioButton*   micro_32;
    QRadioButton*   micro_64;

    QLabel*         instructions;
    QTextEdit*      Result;
    QPushButton*    search;
    QPushButton*    exit;
    File*           file;

    QVBoxLayout*    layout;
    QWidget*        window;
public:
    explicit Window_cheapest_by_microprocessor(QWidget *parent = nullptr);
    void        Choose();
    Computer    Search();
    void        Print_Result();
    void        interface_settings();
};

#endif // WINDOW_CHEAPEST_BY_MICROPROCESSOR_H
