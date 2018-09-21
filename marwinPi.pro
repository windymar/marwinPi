#-------------------------------------------------
#
# Project created by QtCreator 2018-09-16T17:51:40
#
#-------------------------------------------------

QT       -= core gui

TARGET = marwinPi
TEMPLATE = lib
CONFIG += staticlib

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
    Diodes/MarwinPi_Diode.cpp \
    Platform/MarwinPi_Setup.cpp \
    Sensors/MarwinPi_MotionSensor.cpp \
    Sound/MarwinPi_Buzzer.cpp

HEADERS += \
    Diodes/MarwinPi_Diode.hpp \
    Diodes/MarwinPi_IDiode.hpp \
    Platform/MarwinPi_Setup.hpp \
    Sensors/MarwinPi_IMotionSensor.hpp \
    Sensors/MarwinPi_MotionSensor.hpp \
    Sound/MarwinPi_IBuzzer.hpp \
    Sound/MarwinPi_Buzzer.hpp \
    Platform/MarwinPi_Types.hpp \
    Platform/MarwinPi_IGpioPort.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}
