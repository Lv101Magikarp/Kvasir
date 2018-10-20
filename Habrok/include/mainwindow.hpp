#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtCore>
#include <QWidget>
#include <QMainWindow>
#include <QMenu>

#include <opencv2/opencv.hpp>

#include "imageprocessingsettings.hpp"
#include "habrokconstants.h"
#include <iostream>
#include <cmath>

#include <smmclib.hpp>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    ImageProcessingSettings image_processing_settings;

    QMenu image_type_menu;
    QMenu color_menu;
    Color active_color = UNCOLORED;

    QAction *image_type_action[N_IMAGE_TYPES];
    QAction *color_action[N_COLORS];

public:
    explicit MainWindow(QWidget *parent = 0, ImageProcessingSettings *ips = nullptr);
    ~MainWindow();

signals:

private slots:
    void on_h_min_slider_valueChanged(void);
    void on_h_max_slider_valueChanged(void);
    void on_s_min_slider_valueChanged(void);
    void on_s_max_slider_valueChanged(void);
    void on_v_min_slider_valueChanged(void);
    void on_v_max_slider_valueChanged(void);
    void changeColor(QAction *action);

};

#endif // MAINWINDOW_HPP
