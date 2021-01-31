TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abilities.cpp \
        army.cpp \
        dice.cpp \
        main.cpp \
        mainwindow.cpp \
        weapon.cpp

HEADERS += \
    abilities.h \
    army.h \
    dice.h \
    mainwindow.h \
    weapon.h

FORMS += \
    mainwindow.ui
