#-------------------------------------------------
#
# Project created by QtCreator 2020-12-01T04:30:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = t1
TEMPLATE = app
INCLUDEPATH += TEMU/mips_sc/src \
    TEMU/temu/include/cpu \
    TEMU/temu/include/memory \
    TEMU/temu/include \
    TEMU/temu/include/monitor \
    TEMU


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    TEMU/temu/src/cpu/exec.cpp \
    TEMU/temu/src/cpu/i-type.cpp \
    TEMU/temu/src/cpu/r-type.cpp \
    TEMU/temu/src/cpu/reg.cpp \
    TEMU/temu/src/cpu/special.cpp \
    TEMU/temu/src/memory/dram.cpp \
    TEMU/temu/src/memory/memory.cpp \
    TEMU/temu/src/monitor/cpu-exec.cpp \
    TEMU/temu/src/monitor/expr.cpp \
    TEMU/temu/src/monitor/monitor.cpp \
    TEMU/temu/src/monitor/ui.cpp \
    TEMU/temu/src/monitor/watchpoint.cpp \
    ChangeUI.cpp

HEADERS += \
        mainwindow.h \
    TEMU/temu/include/cpu/all-instr.h \
    TEMU/temu/include/cpu/helper.h \
    TEMU/temu/include/cpu/i-type.h \
    TEMU/temu/include/cpu/operand.h \
    TEMU/temu/include/cpu/r-type.h \
    TEMU/temu/include/cpu/reg.h \
    TEMU/temu/include/cpu/special.h \
    TEMU/temu/include/memory/burst.h \
    TEMU/temu/include/memory/memory.h \
    TEMU/temu/include/monitor/expr.h \
    TEMU/temu/include/monitor/monitor.h \
    TEMU/temu/include/monitor/watchpoint.h \
    TEMU/temu/include/common.h \
    TEMU/temu/include/debug.h \
    TEMU/temu/include/macro.h \
    TEMU/temu/include/misc.h \
    TEMU/temu/include/temu.h \
    ChangeUI.h \
    loop.h

FORMS += \
        mainwindow.ui

LIBS += -lreadline \
        -L/usr/lib/x86_64-linux-gnu/libreadline.so

DISTFILES += \
    TEMU/entry

