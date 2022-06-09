#ifndef WINDOW_SHOW_GRAPHIC_H
#define WINDOW_SHOW_GRAPHIC_H

#include "file.h"
#include <QSplineSeries>
#include <QLineSeries>

class Window_show_graphic : public QMainWindow
{
    Q_OBJECT
private:
    File*           file;
    QPushButton*    exit;
public:
    explicit Window_show_graphic(QWidget *parent = nullptr);

signals:

};

#endif // WINDOW_SHOW_GRAPHIC_H
