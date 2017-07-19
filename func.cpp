#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QString>
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

QImage Mat2QImage(cv::Mat mat)
{
    //单通道
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);

        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    //3通道
    else if(mat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    //4通道
    else if(mat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}

void auto_size(cv::Mat &src)
{
    int w;
    int h;
    if(src.cols > 640)
    {
        h = round(double(src.rows)/double(src.cols)*double(640.0));
        cv::resize(src,src,cv::Size(640,h),3);
    }
    if(src.rows > 480)
    {
        w = round(double(src.cols)/double(src.rows)*double(480.0));
        cv::resize(src,src,cv::Size(w,480),3);
    }
    if(src.cols < 640 || src.rows < 480)
    {
        if(src.cols < src.rows)
        {
            w = round(double(src.cols)/double(src.rows)*double(480.0));
            cv::resize(src,src,cv::Size(w,480),3);
        }
        else
        {
            h = round(double(src.rows)/double(src.cols)*double(640.0));
            cv::resize(src,src,cv::Size(640,h),3);
        }
    }
}

void hough_lines(cv::Mat &src, int t, int th1, int th2, cv::Scalar color)
{
    std::vector<cv::Vec2f> lines;
    //图像,线,距离精度,角度精度,阈值
    cv::Mat temp;
    if(src.channels() == 1)
    {
        cv::HoughLines(src,lines,1.0,CV_PI/180,t,0,0,0);
    }
    else
    {
        cv::Canny(src,temp,th1,th2);
        cv::HoughLines(temp,lines,1.0,CV_PI/180,t,0,0,0);
    }
    //画线
    if(src.channels() == 1)
        cv::cvtColor(src,src,CV_GRAY2BGR);
    for(size_t i = 0; i < lines.size(); i++)
    {
        float rho = lines[i][0], theta = lines[i][1];
        cv::Point pt1, pt2;
        double a = cos(theta), b = sin(theta);
        double x0 = a*rho, y0 = b*rho;
        pt1.x = cvRound(x0 + 1000*(-b));
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        cv::line(src,pt1,pt2,color,1,cv::LINE_AA);
    }
}

cv::Mat hough_circles(cv::Mat &src ,cv::Scalar color, int th1, int th2, int distance)
{
    std::vector<cv::Vec3f> circles;
    cv::Mat temp;
    //复制图像用于画圆
    cv::Mat output = src.clone();
    if(src.channels() != 1)
    {
        cv::cvtColor(src,temp,CV_BGR2GRAY);
        cv::HoughCircles(temp,circles,cv::HOUGH_GRADIENT,1.5,distance,th1,th2,0,0);
    }
    else
    {
        cv::HoughCircles(src,circles,cv::HOUGH_GRADIENT,1.5,distance,th1,th2,0,0);
    }
    if(src.channels() == 1)
        cv::cvtColor(output,output,CV_GRAY2BGR);
    for(size_t i = 0; i < circles.size(); i++)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        cv::circle(output,center,1,color,1,8,0);
        cv::circle(output,center,radius,color,1,8,0);
    }
    return output;
}

void blur_img_process(cv::Mat &src, cv::Mat &blur_img,int size, int sigmaX, int sigmaY )
{
    cv::GaussianBlur(src,blur_img,cv::Size(size,size),sigmaX,sigmaY);
}
