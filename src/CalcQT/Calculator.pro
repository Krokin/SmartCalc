QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    deposit.cpp \
    graphs.cpp \
    main.cpp \
    mainwindow.cpp \
    ../Smart_Calc.c \
    ../Credit_Calc.c \
    ../Deposit_Calc.c \
    qcustomplot.cpp

HEADERS += \
    credit.h \
    credit.h \
    deposit.h \
    graphs.h \
    mainwindow.h \
    ../Smart_Calc.h \
    qcustomplot.h

FORMS += \
    credit.ui \
    deposit.ui \
    graphs.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    SmartCalc.pro.user
