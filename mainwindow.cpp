#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QWidget>
#include <QPaintEvent>
#include <QMessageBox>
#include <QString>
#include <QTextCodec>
#include <QFileDialog>
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->blur->hide();
    //设置窗体固定大小
    this->setFixedSize(this->geometry().width(),geometry().height());
    ui->lines_color_green->setChecked(true);
    ui->lines->setChecked(true);

    ui->Max_canny_spinBox->setMinimum(1);
    ui->Max_canny_spinBox->setMaximum(1500);
    ui->Max_canny_spinBox->setValue(Max_canny_value);
    ui->Max_canny_spinBox->setSingleStep(1);
    connect(ui->Max_canny_spinBox,SIGNAL(valueChanged(int)),this,SLOT(set_Max_canny_value(int)));

    ui->line_lenth_Slider->setMinimum(1);
    ui->line_lenth_Slider->setMaximum(800);
    ui->line_lenth_Slider->setValue(120);
    ui->line_lenth_Slider->setSingleStep(1);
    ui->line_lenth_spinBox->setMinimum(1);
    ui->line_lenth_spinBox->setMaximum(800);
    ui->line_lenth_spinBox->setValue(120);
    ui->line_lenth_spinBox->setSingleStep(1);

    connect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),ui->line_lenth_spinBox,SLOT(setValue(int)));
    connect(ui->line_lenth_spinBox,SIGNAL(valueChanged(int)),ui->line_lenth_Slider,SLOT(setValue(int)));

    ui->canny_Slider_th1->setMinimum(1);
    ui->canny_Slider_th1->setMaximum(Max_canny_value);
    ui->canny_Slider_th1->setValue(100);
    ui->canny_Slider_th1->setSingleStep(1);

    ui->canny_spinBox_th1->setMinimum(1);
    ui->canny_spinBox_th1->setMaximum(Max_canny_value);
    ui->canny_spinBox_th1->setValue(100);
    ui->canny_spinBox_th1->setSingleStep(1);

    ui->canny_Slider_th2->setMinimum(1);
    ui->canny_Slider_th2->setMaximum(Max_canny_value);
    ui->canny_Slider_th2->setValue(Max_canny_value/2);
    ui->canny_Slider_th2->setSingleStep(1);

    ui->canny_spinBox_th2->setMinimum(1);
    ui->canny_spinBox_th2->setMaximum(Max_canny_value);
    ui->canny_spinBox_th2->setValue(Max_canny_value/2);
    ui->canny_spinBox_th2->setSingleStep(1);

    connect(ui->canny_Slider_th1,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
    connect(ui->canny_Slider_th2,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
    connect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_hough_img()));
    connect(ui->actionopen,SIGNAL(triggered()),this,SLOT(fun_open_file()));
    connect(ui->actionabot,SIGNAL(triggered()),this,SLOT(on_test_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_file_clicked()
{
    fun_open_file();
}

void MainWindow::fun_open_file()
{
    ui->canny_checkBox->setChecked(false);
    ui->hough_checkBox->setChecked(false);
    hough_flag = false;
    canny_flag = false;
    QString filename = QFileDialog::getOpenFileName(this,tr("Open Image"),"",tr("Image File(*.bmp *.jpg *.jpeg *.png)"));
    QTextCodec *code = QTextCodec::codecForName("gb18030");
    std::string name = code->fromUnicode(filename).data();
    input_file = cv::imread(name);
    if(!input_file.data)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Image data is null!"));
        msgBox.exec();
    }
    else
    {
        select_mode(input_file);
    }
}

void MainWindow::select_mode(cv::Mat &input_file)
{
    auto_size(input_file);
    show_open_img(input_file);
    canny_th1 = ui->canny_Slider_th1->value();
    canny_th2 = ui->canny_Slider_th2->value();
    if(lines_flag)
    {
        int t = ui->line_lenth_Slider->value();
        cv::Canny(input_file,canny_img,canny_th1,canny_th2);
        canny_lines_img = canny_img.clone();
        hough_lines(canny_lines_img,t,canny_th1,canny_th2,color);
        input_file_lines_img = input_file.clone();
        hough_lines(input_file_lines_img,t,canny_th1,canny_th2,color);
    }
    else
    {
        distance = ui->line_lenth_Slider->value();
        blur_img = input_file.clone();
        hough_circles_img = hough_circles(blur_img,color,canny_th1,canny_th2,distance);
        show_open_img(hough_circles_img);
    }
}

void MainWindow::show_open_img(cv::Mat &input_img)
{
    QImage image = Mat2QImage(input_img);
    ui->show_img->setScaledContents(false);
    ui->show_img->setAlignment(Qt::AlignCenter);
    ui->show_img->clear();
    ui->show_img->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::reload_canny_img()
{
    if(input_file.data)
    {
        canny_th1 = ui->canny_Slider_th1->value();
        canny_th2 = ui->canny_Slider_th2->value();
        if(canny_flag)
        {
            cv::Canny(input_file,canny_img,canny_th1,canny_th2);
            show_open_img(canny_img);
        }
        if(canny_flag || hough_flag)
        {
            cv::Canny(input_file,canny_img,canny_th1,canny_th2);
            reload_hough_img();
        }
    }
}

void MainWindow::reload_circles_img()
{
    if(input_file.data)
    {
        distance = ui->line_lenth_Slider->value();
        hough_circles_img = hough_circles(blur_img,color,canny_th1,canny_th2,distance);
        show_open_img(hough_circles_img);
    }
}

void MainWindow::reload_hough_img()
{
    if(input_file.data)
    {
        canny_th1 = ui->canny_Slider_th1->value();
        canny_th2 = ui->canny_Slider_th2->value();
        if(hough_flag)
        {
            canny_lines_img = canny_img;
            int t = ui->line_lenth_Slider->value();
            if(canny_flag)
            {
                canny_lines_img = canny_img.clone();
                hough_lines(canny_lines_img,t,canny_th1,canny_th2,color);
                show_open_img(canny_lines_img);

            }
            else
            {
                input_file_lines_img = input_file.clone();
                hough_lines(input_file_lines_img,t,canny_th1,canny_th2,color);
                show_open_img(input_file_lines_img);
            }
        }
    }
}

void MainWindow::on_canny_checkBox_clicked(bool checked)
{
    if(checked)
    {
        canny_flag = true;
        if(hough_flag)
        {
            reload_hough_img();
        }
        else
        {
            reload_canny_img();
        }
    }
    else
    {
        canny_flag = false;
        if(hough_flag)
        {
            reload_hough_img();
        }
        else
        {
            show_open_img(input_file);
        }
    }
}


void MainWindow::on_hough_checkBox_clicked(bool checked)
{
    if(checked)
    {
        hough_flag = true;
        if(canny_flag)
        {
            canny_lines_img = canny_img.clone();
            reload_hough_img();
        }
        else
        {
            input_file_lines_img = input_file.clone();
            reload_hough_img();
        }
    }
    else
    {
        hough_flag = false;
        if(canny_flag)
        {
            reload_canny_img();
        }
        else
        {
            show_open_img(input_file);
        }
    }
}


void MainWindow::set_Max_canny_value(int value)
{
    Max_canny_value = value;
    ui->canny_Slider_th1->setMaximum(Max_canny_value);
    ui->canny_Slider_th2->setMaximum(Max_canny_value);
    ui->canny_spinBox_th1->setMaximum(Max_canny_value);
    ui->canny_spinBox_th2->setMaximum(Max_canny_value);
}

void MainWindow::on_lines_color_green_clicked()
{
    color = cv::Scalar(0,255,0);
    if(circles_flag)
        reload_canny_img();
    else
        reload_hough_img();
}

void MainWindow::on_lines_color_blue_clicked()
{
    color = cv::Scalar(255,0,0);
    if(circles_flag)
        reload_canny_img();
    else
        reload_hough_img();
}

void MainWindow::on_lines_color_red_clicked()
{
    color = cv::Scalar(0,0,255);
    if(circles_flag)
        reload_canny_img();
    else
        reload_hough_img();
}

void MainWindow::on_lines_color_white_clicked()
{
    color = cv::Scalar(255,255,255);
    if(circles_flag)
        reload_canny_img();
    else
        reload_hough_img();
}

void MainWindow::on_lines_color_black_clicked()
{
    color = cv::Scalar(0,0,0);
    if(circles_flag)
        reload_canny_img();
    else
        reload_hough_img();
}


void MainWindow::on_lines_clicked()
{
    ui->blur->hide();
    lines_flag = true;
    circles_flag = false;
    ui->canny->setTitle("Canny");
    ui->label->setText("Hough阈值");
    ui->label_2->setText("th1");
    ui->label_3->setText("th2");
    ui->canny_checkBox->show();
    ui->hough_checkBox->show();
    connect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_hough_img()));
    disconnect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_circles_img()));

}

void MainWindow::on_circles_clicked()
{
    ui->blur->show();
    ui->blur->setChecked(false);
    blur_flag = false;
    circles_flag = true;
    lines_flag = false;
    ui->canny->setTitle("Hough圆检测");
    ui->label->setText("最小圆心距");
    ui->canny_checkBox->setChecked(false);
    ui->hough_checkBox->setChecked(false);
    ui->label_2->setText("canny");
    ui->label_3->setText("累加器");
    ui->canny_Slider_th1->setValue(100);
    ui->canny_Slider_th2->setValue(Max_canny_value/2);
    ui->line_lenth_Slider->setValue(120);
    ui->line_lenth_Slider->setSingleStep(1);
    hough_flag = false;
    canny_flag = false;
    ui->canny_checkBox->hide();
    ui->hough_checkBox->hide();
    disconnect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_hough_img()));
    connect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_circles_img()));
}

void MainWindow::on_blur_clicked(bool checked)
{
    if(checked)
    {
        blur_flag = true;
        ui->canny->setTitle("高斯模糊参数");
        ui->label_2->setText("sigmaX");
        ui->label_3->setText("sigmaY");
        ui->label->setText("ksize");
        ui->canny_Slider_th1->setValue(3);
        ui->canny_Slider_th2->setValue(3);
        ui->line_lenth_Slider->setValue(3);
        ui->line_lenth_Slider->setSingleStep(2);
        ui->line_lenth_spinBox->setSingleStep(2);
        disconnect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
        disconnect(ui->canny_Slider_th1,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
        disconnect(ui->canny_Slider_th2,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
        connect(ui->canny_Slider_th1,SIGNAL(valueChanged(int)),this,SLOT(blur_process()));
        connect(ui->canny_Slider_th2,SIGNAL(valueChanged(int)),this,SLOT(blur_process()));
        connect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(blur_process()));
        blur_process();
    }
    else
    {
        blur_flag = false;
        ui->canny->setTitle("Hough圆检测");
        ui->label_2->setText("canny");
        ui->label_3->setText("累加器");
        ui->label->setText("最小圆心距");
        ui->canny_Slider_th1->setValue(100);
        ui->canny_Slider_th2->setValue(Max_canny_value/2);
        ui->line_lenth_Slider->setValue(120);
        ui->line_lenth_Slider->setSingleStep(1);
        connect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
        connect(ui->canny_Slider_th1,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
        connect(ui->canny_Slider_th2,SIGNAL(valueChanged(int)),this,SLOT(reload_canny_img()));
        disconnect(ui->canny_Slider_th1,SIGNAL(valueChanged(int)),this,SLOT(blur_process()));
        disconnect(ui->canny_Slider_th2,SIGNAL(valueChanged(int)),this,SLOT(blur_process()));
        disconnect(ui->line_lenth_Slider,SIGNAL(valueChanged(int)),this,SLOT(blur_process()));

    }
}

void MainWindow::blur_process()
{
    if(blur_flag && input_file.data)
    {
        int size = ui->line_lenth_Slider->value();
        int sigmaX = ui->canny_Slider_th1->value();
        int sigmaY = ui->canny_Slider_th2->value();
        blur_img_process(input_file,blur_img,size,sigmaX,sigmaY);
        show_open_img(blur_img);
    }
}


void MainWindow::on_test_clicked()
{
    Dialog h;
    h.show();
    h.exec();
}
