#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "window_add_data.h"
#include "window_cheapest_by_microprocessor.h"
#include "window_find_by_memory_and_winchester.h"
#include "window_find_by_price.h"
#include "window_delete_data.h"
#include "window_show_data.h"
#include "window_show_graphic.h"

class MainWindow : public QMainWindow
{
protected:
    QLabel*         label;

    QPushButton*    find_by_price;
    QPushButton*    cheapest_by_microprocessor;
    QPushButton*    exit;
    QPushButton*    find_by_memory_and_winchester;
    QPushButton*    show_graphic;
    QPushButton*    show_data;
    QPushButton*    add_data;
    QLabel*         photo;

    Window_find_by_price*                   W_find_by_price;
    Window_add_data*                        W_add_data;
    Window_cheapest_by_microprocessor*      W_cheapest_by_microprocessor;
    Window_find_by_memory_and_winchester*   W_find_by_memory_and_winchester;
    Window_show_data*                       W_show_data;
    Window_show_graphic*                    W_show_graphic;

    QVBoxLayout *layout1;
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;
    QVBoxLayout *layout;
    QWidget *window;
public:
    MainWindow(QWidget *parent = nullptr);
    void    Create_Buttons();
    void    Clicked_find_by_price();
    void    Clicked_add_data();
    void    Clicked_cheapest_by_microprocessor();
    void    Clicked_find_by_memory_and_winchester();
    void    Clicked_show_graphic();
    void    Clicked_show_data();
    void    interface_settings();
    ~MainWindow();
};
#endif // MAINWINDOW_H
