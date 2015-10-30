#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T15:38:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageReconstruction
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    ImageHandler.cpp \
    ImageReconstruction.cpp \
    Main3.cpp \
    Osztalyozo.cpp \
    PatternRecognizer.cpp \
    ProjectionHandler.cpp \
    TemplateMatcher.cpp \
    WrongImageException.cpp \
    Timer.cpp \
    Feature.cpp \
    Trainer.cpp \
    AverageFeatureTrainer.cpp \
    SplittedFeature.cpp \
    VectorHelper.cpp \
    OptimizerDatas.cpp \
    SimannOptimizer.cpp

HEADERS  += mainwindow.h \
    ImageHandler.h \
    ImageReconstruction.h \
    Osztalyozo.h \
    PatternRecognizer.h \
    ProjectionHandler.h \
    TemplateMatcher.h \
    WrongImageException.h \
    Timer.h \
    Feature.h \
    Trainer.h \
    AverageFeatureTrainer.h \
    SplittedFeature.h \
    VectorHelper.h \
    OptimizerDatas.h \
    SimannOptimizer.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /usr/local/include/opencv
INCLUDEPATH += /usr/include/opencv2
INCLUDEPATH += /usr/local/include/gsl


LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
#LIBS += -lopencv_ml
#LIBS += -lopencv_video
LIBS += -lopencv_features2d
#LIBS += -lopencv_calib3d
#LIBS += -lopencv_objdetect
#LIBS += -lopencv_contrib
#LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree
LIBS += -lopencv_imgcodecs

LIBS += -lgsl
LIBS += -lgslcblas
LIBS += -lm

