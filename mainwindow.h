#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPaintEvent>
#include <QMainWindow>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <opencv/cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "dialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void fun_open_file();
private slots:
    void reload_canny_img();
    void reload_hough_img();
    void blur_process();
    void reload_circles_img();
    void show_open_img(cv::Mat &input_img);
    void on_open_file_clicked();
    void select_mode(cv::Mat &input_file);
    void on_canny_checkBox_clicked(bool checked);
    void on_hough_checkBox_clicked(bool checked);
    void set_Max_canny_value(int value);
    void on_lines_color_green_clicked();
    void on_lines_color_blue_clicked();
    void on_lines_color_red_clicked();
    void on_lines_color_white_clicked();
    void on_lines_color_black_clicked();
    void on_lines_clicked();
    void on_circles_clicked();
    void on_blur_clicked(bool checked);
    void on_test_clicked();


private:
    Ui::MainWindow *ui;
    int canny_th1;
    int canny_th2;
    int distance;
    int Max_canny_value = 510;
    cv::Mat input_file;
    cv::Mat blur_img;
    cv::Mat canny_img;
    cv::Mat input_file_lines_img;
    cv::Mat canny_lines_img;
    cv::Mat hough_circles_img;
    bool canny_flag = false;
    bool blur_flag = false;
    bool hough_flag = false;
    bool lines_flag = true;
    bool circles_flag = false;
    cv::Scalar color = cv::Scalar(0,255,0);


};

QImage Mat2QImage(cv::Mat mat);
void auto_size(cv::Mat &src);
void hough_lines(cv::Mat &src, int t, int th1, int th2, cv::Scalar color);
cv::Mat hough_circles(cv::Mat &src, cv::Scalar color, int th1, int th2, int distance);
void blur_img_process(cv::Mat &src, cv::Mat &blur_img,int size, int sigmaX, int sigmaY );
#endif // MAINWINDOW_H
