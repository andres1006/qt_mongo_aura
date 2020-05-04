QT += core gui dbus sql quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


CONFIG += c++11 console
CONFIG -= app_bundle

#DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        aurajson.cpp \
        data.cpp \
        logger.cpp \
        main.cpp \
        process.cpp \
        qutils.cpp \
        utilsprocess.cpp



#LIBS += \
#    -L/usr/local/lib \
#    -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs \
#    -lmongocxx \
#    -lbsoncxx \

LIBS += \
     -L/usr/include \
     -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lmongocxx -lbsoncxx \


HEADERS += \
    aurajson.h \
    data.h \
    logger.h \
    process.h \
    qutils.h \
    utilsprocess.h
