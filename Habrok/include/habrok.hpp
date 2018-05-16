#ifndef HABROK_HPP
#define HABROK_HPP

#include <QApplication>
#include <QtCore>
#include <QWidget>
#include <QMainWindow>
#include <QMenu>

#include <boost/interprocess/managed_shared_memory.hpp>

#include <string>
#include <iostream>
#include <cmath>

#include <smmclib.hpp>

#include "habrokconstants.h"
#include "mainwindow.hpp"
#include "imageprocessingsettings.hpp"
#include "imageprocessingthread.hpp"
#include "robotrecognizerthread.hpp"
#include "visionfieldhandler.hpp"

class Habrok : public QObject
{
    Q_OBJECT

private:
    boost::interprocess::managed_shared_memory *shared_memory;

    std::string write_key;
    std::string read_key;
    std::string shutdown_key;

    VisionFieldHandler vision_field_handler;

    ImageProcessingSettings image_processing_settings;

    ImageProcessingThread *image_processing_thread;
    RobotRecognizerThread *robot_recognizer_thread;

    bool write_changes;

    std::string getSharedMemoryWriteKey(void);

    std::string getSharedMemoryReadKey(void);

    std::string getSharedMemoryShutdownKey(void);

public:
    Habrok(std::string wk, std::string rk, std::string sk);
    Habrok();
    ~Habrok();

    int runHabrok(void);

    int calibrate(void);

signals:
    void stopImageProcessingThread(void);
    void stopRobotRecognizerThread(void);

private slots:
    void writeChanges(void);

};

#endif // HABROK_HPP