#ifndef WINDOW_FIND_BY_PRICE_H
#define WINDOW_FIND_BY_PRICE_H

#include "file.h"

class Window_find_by_price : public QMainWindow
{
private:
    int price;
protected:
    QLabel*         instructions;
    QSlider*        Slider;
    QTableWidget*   Table;
    QPushButton*    exit;
    File*           file;
    QLabel*         tmpLabel;
    QLabel*         min;
    QLabel*         max;
public:
    explicit Window_find_by_price(QWidget *parent = nullptr);
    void    interface_settings();
    void    fill_table();
    void    update();
    ~Window_find_by_price();
signals:

};

#endif // WINDOW_FIND_BY_PRICE_H
