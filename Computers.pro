QT       += core gui
QT       += core5compat
QT	 += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    file.cpp \
    main.cpp \
    mainwindow.cpp \
    window_add_data.cpp \
    window_cheapest_by_microprocessor.cpp \
    window_delete_all.cpp \
    window_delete_data.cpp \
    window_find_by_memory_and_winchester.cpp \
    window_find_by_price.cpp \
    window_show_data.cpp \
    window_show_graphic.cpp

HEADERS += \
    Computer.h \
    file.h \
    mainwindow.h \
    window_add_data.h \
    window_cheapest_by_microprocessor.h \
    window_delete_all.h \
    window_delete_data.h \
    window_find_by_memory_and_winchester.h \
    window_find_by_price.h \
    window_show_data.h \
    window_show_graphic.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
