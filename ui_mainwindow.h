/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionexit;
    QAction *actionabot;
    QWidget *centralWidget;
    QLabel *show_img;
    QGroupBox *canny;
    QGridLayout *gridLayout;
    QSpinBox *canny_spinBox_th1;
    QSpinBox *canny_spinBox_th2;
    QSpinBox *Max_canny_spinBox;
    QSlider *canny_Slider_th1;
    QLabel *label_3;
    QSlider *canny_Slider_th2;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_5;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_4;
    QPushButton *open_file;
    QCheckBox *hough_checkBox;
    QRadioButton *circles;
    QRadioButton *lines;
    QCheckBox *canny_checkBox;
    QCheckBox *blur;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QGroupBox *lines_color;
    QGridLayout *gridLayout_3;
    QRadioButton *lines_color_blue;
    QRadioButton *lines_color_green;
    QRadioButton *lines_color_white;
    QRadioButton *lines_color_black;
    QRadioButton *lines_color_red;
    QFrame *hough;
    QGridLayout *gridLayout_2;
    QSpinBox *line_lenth_spinBox;
    QLabel *label;
    QSlider *line_lenth_Slider;
    QPushButton *test;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(803, 608);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        actionabot = new QAction(MainWindow);
        actionabot->setObjectName(QStringLiteral("actionabot"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        show_img = new QLabel(centralWidget);
        show_img->setObjectName(QStringLiteral("show_img"));
        show_img->setGeometry(QRect(10, 10, 640, 480));
        show_img->setMinimumSize(QSize(640, 480));
        show_img->setMaximumSize(QSize(640, 480));
        show_img->setFrameShape(QFrame::Panel);
        canny = new QGroupBox(centralWidget);
        canny->setObjectName(QStringLiteral("canny"));
        canny->setGeometry(QRect(655, 90, 131, 401));
        canny->setAutoFillBackground(false);
        canny->setAlignment(Qt::AlignCenter);
        canny->setCheckable(false);
        gridLayout = new QGridLayout(canny);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        canny_spinBox_th1 = new QSpinBox(canny);
        canny_spinBox_th1->setObjectName(QStringLiteral("canny_spinBox_th1"));

        gridLayout->addWidget(canny_spinBox_th1, 3, 0, 1, 1);

        canny_spinBox_th2 = new QSpinBox(canny);
        canny_spinBox_th2->setObjectName(QStringLiteral("canny_spinBox_th2"));

        gridLayout->addWidget(canny_spinBox_th2, 3, 1, 1, 1);

        Max_canny_spinBox = new QSpinBox(canny);
        Max_canny_spinBox->setObjectName(QStringLiteral("Max_canny_spinBox"));

        gridLayout->addWidget(Max_canny_spinBox, 1, 0, 1, 2);

        canny_Slider_th1 = new QSlider(canny);
        canny_Slider_th1->setObjectName(QStringLiteral("canny_Slider_th1"));
        canny_Slider_th1->setOrientation(Qt::Vertical);

        gridLayout->addWidget(canny_Slider_th1, 2, 0, 1, 1);

        label_3 = new QLabel(canny);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        canny_Slider_th2 = new QSlider(canny);
        canny_Slider_th2->setObjectName(QStringLiteral("canny_Slider_th2"));
        canny_Slider_th2->setOrientation(Qt::Vertical);

        gridLayout->addWidget(canny_Slider_th2, 2, 1, 1, 1);

        label_4 = new QLabel(canny);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 2);

        label_2 = new QLabel(canny);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(700, 510, 81, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(660, 0, 121, 81));
        gridLayout_4 = new QGridLayout(layoutWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        open_file = new QPushButton(layoutWidget);
        open_file->setObjectName(QStringLiteral("open_file"));

        gridLayout_4->addWidget(open_file, 0, 0, 1, 1);

        hough_checkBox = new QCheckBox(layoutWidget);
        hough_checkBox->setObjectName(QStringLiteral("hough_checkBox"));

        gridLayout_4->addWidget(hough_checkBox, 2, 0, 1, 1);

        circles = new QRadioButton(layoutWidget);
        circles->setObjectName(QStringLiteral("circles"));

        gridLayout_4->addWidget(circles, 2, 1, 1, 1);

        lines = new QRadioButton(layoutWidget);
        lines->setObjectName(QStringLiteral("lines"));

        gridLayout_4->addWidget(lines, 1, 1, 1, 1);

        canny_checkBox = new QCheckBox(layoutWidget);
        canny_checkBox->setObjectName(QStringLiteral("canny_checkBox"));

        gridLayout_4->addWidget(canny_checkBox, 1, 0, 1, 1);

        blur = new QCheckBox(centralWidget);
        blur->setObjectName(QStringLiteral("blur"));
        blur->setGeometry(QRect(660, 50, 71, 20));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 501, 681, 50));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lines_color = new QGroupBox(layoutWidget1);
        lines_color->setObjectName(QStringLiteral("lines_color"));
        lines_color->setAlignment(Qt::AlignCenter);
        lines_color->setFlat(false);
        gridLayout_3 = new QGridLayout(lines_color);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lines_color_blue = new QRadioButton(lines_color);
        lines_color_blue->setObjectName(QStringLiteral("lines_color_blue"));

        gridLayout_3->addWidget(lines_color_blue, 0, 1, 1, 1);

        lines_color_green = new QRadioButton(lines_color);
        lines_color_green->setObjectName(QStringLiteral("lines_color_green"));

        gridLayout_3->addWidget(lines_color_green, 0, 0, 1, 1);

        lines_color_white = new QRadioButton(lines_color);
        lines_color_white->setObjectName(QStringLiteral("lines_color_white"));

        gridLayout_3->addWidget(lines_color_white, 0, 3, 1, 1);

        lines_color_black = new QRadioButton(lines_color);
        lines_color_black->setObjectName(QStringLiteral("lines_color_black"));

        gridLayout_3->addWidget(lines_color_black, 0, 4, 1, 1);

        lines_color_red = new QRadioButton(lines_color);
        lines_color_red->setObjectName(QStringLiteral("lines_color_red"));

        gridLayout_3->addWidget(lines_color_red, 0, 2, 1, 1);


        horizontalLayout->addWidget(lines_color);

        hough = new QFrame(layoutWidget1);
        hough->setObjectName(QStringLiteral("hough"));
        hough->setFrameShape(QFrame::Panel);
        gridLayout_2 = new QGridLayout(hough);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        line_lenth_spinBox = new QSpinBox(hough);
        line_lenth_spinBox->setObjectName(QStringLiteral("line_lenth_spinBox"));

        gridLayout_2->addWidget(line_lenth_spinBox, 0, 1, 1, 1);

        label = new QLabel(hough);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        line_lenth_Slider = new QSlider(hough);
        line_lenth_Slider->setObjectName(QStringLiteral("line_lenth_Slider"));
        line_lenth_Slider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(line_lenth_Slider, 0, 0, 1, 1);


        horizontalLayout->addWidget(hough);

        test = new QPushButton(centralWidget);
        test->setObjectName(QStringLiteral("test"));
        test->setGeometry(QRect(700, 530, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        show_img->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        canny->raise();
        label_5->raise();
        blur->raise();
        test->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 803, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionopen);
        menuFile->addAction(actionexit);
        menuHelp->addAction(actionabot);

        retranslateUi(MainWindow);
        QObject::connect(canny_Slider_th1, SIGNAL(valueChanged(int)), canny_spinBox_th1, SLOT(setValue(int)));
        QObject::connect(canny_Slider_th2, SIGNAL(valueChanged(int)), canny_spinBox_th2, SLOT(setValue(int)));
        QObject::connect(canny_spinBox_th2, SIGNAL(valueChanged(int)), canny_Slider_th2, SLOT(setValue(int)));
        QObject::connect(canny_spinBox_th1, SIGNAL(valueChanged(int)), canny_Slider_th1, SLOT(setValue(int)));
        QObject::connect(actionexit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hough\345\217\230\346\215\242", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        actionexit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        actionabot->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", Q_NULLPTR));
        show_img->setText(QString());
        canny->setTitle(QApplication::translate("MainWindow", "Canny", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "th2", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Max Value", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "th1", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "WangHongshuo", Q_NULLPTR));
        open_file->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        hough_checkBox->setText(QApplication::translate("MainWindow", "Hough", Q_NULLPTR));
        circles->setText(QApplication::translate("MainWindow", "\345\234\206", Q_NULLPTR));
        lines->setText(QApplication::translate("MainWindow", "\347\272\277", Q_NULLPTR));
        canny_checkBox->setText(QApplication::translate("MainWindow", "Canny", Q_NULLPTR));
        blur->setText(QApplication::translate("MainWindow", "\351\253\230\346\226\257\346\250\241\347\263\212", Q_NULLPTR));
        lines_color->setTitle(QApplication::translate("MainWindow", "\347\272\277\350\211\262", Q_NULLPTR));
        lines_color_blue->setText(QApplication::translate("MainWindow", "\350\223\235\350\211\262", Q_NULLPTR));
        lines_color_green->setText(QApplication::translate("MainWindow", "\347\273\277\350\211\262", Q_NULLPTR));
        lines_color_white->setText(QApplication::translate("MainWindow", "\347\231\275\350\211\262", Q_NULLPTR));
        lines_color_black->setText(QApplication::translate("MainWindow", "\351\273\221\350\211\262", Q_NULLPTR));
        lines_color_red->setText(QApplication::translate("MainWindow", "\347\272\242\350\211\262", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Hough\351\230\210\345\200\274", Q_NULLPTR));
        test->setText(QApplication::translate("MainWindow", "test", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
