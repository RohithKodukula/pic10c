/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QComboBox *course;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *hw1slide;
    QSpinBox *hw1spin;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *hw2slide;
    QSpinBox *hw2spin;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *hw3slide;
    QSpinBox *hw3spin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *hw4slide;
    QSpinBox *hw4spin;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *hw5slide;
    QSpinBox *hw5spin;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSlider *hw6slide;
    QSpinBox *hw6spin;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSlider *hw7slide;
    QSpinBox *hw7spin;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSlider *hw8slide;
    QSpinBox *hw8spin;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_9;
    QSlider *mid1slide;
    QSpinBox *mid1spin;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_11;
    QSlider *mid2slide;
    QSpinBox *mid2spin;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_10;
    QSlider *finalslide;
    QSpinBox *finalspin;
    QSpacerItem *verticalSpacer_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_12;
    QMenuBar *menubar;
    QMenu *menuGrade_Calculator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(505, 560);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 10, 481, 501));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(verticalLayoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_10->addWidget(label_13);

        course = new QComboBox(verticalLayoutWidget_3);
        course->setObjectName(QStringLiteral("course"));
        course->setMinimumSize(QSize(235, 0));

        horizontalLayout_10->addWidget(course);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        hw1slide = new QSlider(verticalLayoutWidget_3);
        hw1slide->setObjectName(QStringLiteral("hw1slide"));
        hw1slide->setMaximum(100);
        hw1slide->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hw1slide);

        hw1spin = new QSpinBox(verticalLayoutWidget_3);
        hw1spin->setObjectName(QStringLiteral("hw1spin"));
        hw1spin->setMaximum(100);

        horizontalLayout->addWidget(hw1spin);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        hw2slide = new QSlider(verticalLayoutWidget_3);
        hw2slide->setObjectName(QStringLiteral("hw2slide"));
        hw2slide->setMaximum(100);
        hw2slide->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(hw2slide);

        hw2spin = new QSpinBox(verticalLayoutWidget_3);
        hw2spin->setObjectName(QStringLiteral("hw2spin"));
        hw2spin->setMaximum(100);

        horizontalLayout_2->addWidget(hw2spin);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        hw3slide = new QSlider(verticalLayoutWidget_3);
        hw3slide->setObjectName(QStringLiteral("hw3slide"));
        hw3slide->setMaximum(100);
        hw3slide->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hw3slide);

        hw3spin = new QSpinBox(verticalLayoutWidget_3);
        hw3spin->setObjectName(QStringLiteral("hw3spin"));
        hw3spin->setMaximum(100);

        horizontalLayout_3->addWidget(hw3spin);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        hw4slide = new QSlider(verticalLayoutWidget_3);
        hw4slide->setObjectName(QStringLiteral("hw4slide"));
        hw4slide->setMaximum(100);
        hw4slide->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hw4slide);

        hw4spin = new QSpinBox(verticalLayoutWidget_3);
        hw4spin->setObjectName(QStringLiteral("hw4spin"));
        hw4spin->setMaximum(100);

        horizontalLayout_4->addWidget(hw4spin);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        hw5slide = new QSlider(verticalLayoutWidget_3);
        hw5slide->setObjectName(QStringLiteral("hw5slide"));
        hw5slide->setMaximum(100);
        hw5slide->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(hw5slide);

        hw5spin = new QSpinBox(verticalLayoutWidget_3);
        hw5spin->setObjectName(QStringLiteral("hw5spin"));
        hw5spin->setMaximum(100);

        horizontalLayout_5->addWidget(hw5spin);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        hw6slide = new QSlider(verticalLayoutWidget_3);
        hw6slide->setObjectName(QStringLiteral("hw6slide"));
        hw6slide->setMaximum(100);
        hw6slide->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(hw6slide);

        hw6spin = new QSpinBox(verticalLayoutWidget_3);
        hw6spin->setObjectName(QStringLiteral("hw6spin"));
        hw6spin->setMaximum(100);

        horizontalLayout_6->addWidget(hw6spin);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        hw7slide = new QSlider(verticalLayoutWidget_3);
        hw7slide->setObjectName(QStringLiteral("hw7slide"));
        hw7slide->setMaximum(100);
        hw7slide->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(hw7slide);

        hw7spin = new QSpinBox(verticalLayoutWidget_3);
        hw7spin->setObjectName(QStringLiteral("hw7spin"));
        hw7spin->setMaximum(100);

        horizontalLayout_7->addWidget(hw7spin);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_8->addWidget(label_8);

        hw8slide = new QSlider(verticalLayoutWidget_3);
        hw8slide->setObjectName(QStringLiteral("hw8slide"));
        hw8slide->setMaximum(100);
        hw8slide->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(hw8slide);

        hw8spin = new QSpinBox(verticalLayoutWidget_3);
        hw8spin->setObjectName(QStringLiteral("hw8spin"));
        hw8spin->setMaximum(100);

        horizontalLayout_8->addWidget(hw8spin);


        verticalLayout->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_2->addWidget(label_9);

        mid1slide = new QSlider(verticalLayoutWidget_3);
        mid1slide->setObjectName(QStringLiteral("mid1slide"));
        mid1slide->setMaximum(100);
        mid1slide->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(mid1slide);

        mid1spin = new QSpinBox(verticalLayoutWidget_3);
        mid1spin->setObjectName(QStringLiteral("mid1spin"));
        mid1spin->setMaximum(100);

        verticalLayout_2->addWidget(mid1spin);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        mid2slide = new QSlider(verticalLayoutWidget_3);
        mid2slide->setObjectName(QStringLiteral("mid2slide"));
        mid2slide->setMaximum(100);
        mid2slide->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(mid2slide);

        mid2spin = new QSpinBox(verticalLayoutWidget_3);
        mid2spin->setObjectName(QStringLiteral("mid2spin"));
        mid2spin->setMaximum(100);

        verticalLayout_2->addWidget(mid2spin);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        finalslide = new QSlider(verticalLayoutWidget_3);
        finalslide->setObjectName(QStringLiteral("finalslide"));
        finalslide->setMaximum(100);
        finalslide->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(finalslide);

        finalspin = new QSpinBox(verticalLayoutWidget_3);
        finalspin->setObjectName(QStringLiteral("finalspin"));
        finalspin->setMaximum(100);

        verticalLayout_2->addWidget(finalspin);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        radioButton = new QRadioButton(verticalLayoutWidget_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(verticalLayoutWidget_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        label_12 = new QLabel(verticalLayoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);


        horizontalLayout_9->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_9);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 505, 21));
        menuGrade_Calculator = new QMenu(menubar);
        menuGrade_Calculator->setObjectName(QStringLiteral("menuGrade_Calculator"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGrade_Calculator->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(hw1spin, SIGNAL(valueChanged(int)), hw1slide, SLOT(setValue(int)));
        QObject::connect(hw2spin, SIGNAL(valueChanged(int)), hw2slide, SLOT(setValue(int)));
        QObject::connect(hw3spin, SIGNAL(valueChanged(int)), hw3slide, SLOT(setValue(int)));
        QObject::connect(hw4spin, SIGNAL(valueChanged(int)), hw4slide, SLOT(setValue(int)));
        QObject::connect(hw5spin, SIGNAL(valueChanged(int)), hw5slide, SLOT(setValue(int)));
        QObject::connect(hw6spin, SIGNAL(valueChanged(int)), hw6slide, SLOT(setValue(int)));
        QObject::connect(hw7spin, SIGNAL(valueChanged(int)), hw7slide, SLOT(setValue(int)));
        QObject::connect(hw8spin, SIGNAL(valueChanged(int)), hw8slide, SLOT(setValue(int)));
        QObject::connect(hw1slide, SIGNAL(sliderMoved(int)), hw1spin, SLOT(setValue(int)));
        QObject::connect(hw2slide, SIGNAL(sliderMoved(int)), hw2spin, SLOT(setValue(int)));
        QObject::connect(hw3slide, SIGNAL(sliderMoved(int)), hw3spin, SLOT(setValue(int)));
        QObject::connect(hw4slide, SIGNAL(sliderMoved(int)), hw4spin, SLOT(setValue(int)));
        QObject::connect(hw5slide, SIGNAL(sliderMoved(int)), hw5spin, SLOT(setValue(int)));
        QObject::connect(hw6slide, SIGNAL(sliderMoved(int)), hw6spin, SLOT(setValue(int)));
        QObject::connect(hw7slide, SIGNAL(sliderMoved(int)), hw7spin, SLOT(setValue(int)));
        QObject::connect(hw8slide, SIGNAL(sliderMoved(int)), hw8spin, SLOT(setValue(int)));
        QObject::connect(mid1spin, SIGNAL(valueChanged(int)), mid1slide, SLOT(setValue(int)));
        QObject::connect(mid1slide, SIGNAL(sliderMoved(int)), mid1spin, SLOT(setValue(int)));
        QObject::connect(mid2spin, SIGNAL(valueChanged(int)), mid2slide, SLOT(setValue(int)));
        QObject::connect(mid2slide, SIGNAL(sliderMoved(int)), mid2spin, SLOT(setValue(int)));
        QObject::connect(finalspin, SIGNAL(valueChanged(int)), finalslide, SLOT(setValue(int)));
        QObject::connect(finalslide, SIGNAL(sliderMoved(int)), finalspin, SLOT(setValue(int)));
        QObject::connect(finalspin, SIGNAL(valueChanged(int)), finalslide, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Course:", Q_NULLPTR));
        course->clear();
        course->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Pic 10B. Intermediate Programming", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Pic 10C. Advanced Programming", Q_NULLPTR)
        );
        label->setText(QApplication::translate("MainWindow", "Hw 1", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Hw 2", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Hw 3", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Hw 4", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Hw 5", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Hw 6", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Hw 7", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Hw 8", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Midterm 1", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Midterm 2", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Final Exam", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "Schema A", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "Schema B", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Overall Score:", Q_NULLPTR));
        menuGrade_Calculator->setTitle(QApplication::translate("MainWindow", "Grade Calculator", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
