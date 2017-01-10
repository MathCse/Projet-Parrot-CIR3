/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SumoMain
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *_flip;
    QPushButton *_balance;
    QPushButton *_flipDown;
    QPushButton *_hijump;
    QPushButton *_longjump;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *_turn;
    QPushButton *_watchLeftRight;
    QPushButton *_tap;
    QPushButton *_swing;
    QPushButton *_turnLeftRight;
    QPushButton *_turnToBalance;
    QPushButton *_turnAndJump;
    QPushButton *_slalom;
    QPushButton *_growingCircles;
    QPushButton *_open_close;
    QSlider *_turning;
    QHBoxLayout *horizontalLayout;
    QSlider *_speed;
    QProgressBar *_batteryLevel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SumoMain)
    {
        if (SumoMain->objectName().isEmpty())
            SumoMain->setObjectName(QString::fromUtf8("SumoMain"));
        SumoMain->resize(714, 521);
        centralwidget = new QWidget(SumoMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        _flip = new QPushButton(centralwidget);
        _flip->setObjectName(QString::fromUtf8("_flip"));
        _flip->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(_flip);

        _balance = new QPushButton(centralwidget);
        _balance->setObjectName(QString::fromUtf8("_balance"));
        _balance->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(_balance);

        _flipDown = new QPushButton(centralwidget);
        _flipDown->setObjectName(QString::fromUtf8("_flipDown"));
        _flipDown->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(_flipDown);

        _hijump = new QPushButton(centralwidget);
        _hijump->setObjectName(QString::fromUtf8("_hijump"));
        _hijump->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(_hijump);

        _longjump = new QPushButton(centralwidget);
        _longjump->setObjectName(QString::fromUtf8("_longjump"));
        _longjump->setEnabled(true);
        _longjump->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_2->addWidget(_longjump);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        _turn = new QPushButton(centralwidget);
        _turn->setObjectName(QString::fromUtf8("_turn"));
        _turn->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_turn);

        _watchLeftRight = new QPushButton(centralwidget);
        _watchLeftRight->setObjectName(QString::fromUtf8("_watchLeftRight"));
        _watchLeftRight->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_watchLeftRight);

        _tap = new QPushButton(centralwidget);
        _tap->setObjectName(QString::fromUtf8("_tap"));
        _tap->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_tap);

        _swing = new QPushButton(centralwidget);
        _swing->setObjectName(QString::fromUtf8("_swing"));
        _swing->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_swing);

        _turnLeftRight = new QPushButton(centralwidget);
        _turnLeftRight->setObjectName(QString::fromUtf8("_turnLeftRight"));
        _turnLeftRight->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_turnLeftRight);

        _turnToBalance = new QPushButton(centralwidget);
        _turnToBalance->setObjectName(QString::fromUtf8("_turnToBalance"));
        _turnToBalance->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_turnToBalance);

        _turnAndJump = new QPushButton(centralwidget);
        _turnAndJump->setObjectName(QString::fromUtf8("_turnAndJump"));
        _turnAndJump->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_turnAndJump);

        _slalom = new QPushButton(centralwidget);
        _slalom->setObjectName(QString::fromUtf8("_slalom"));
        _slalom->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_slalom);

        _growingCircles = new QPushButton(centralwidget);
        _growingCircles->setObjectName(QString::fromUtf8("_growingCircles"));
        _growingCircles->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_3->addWidget(_growingCircles);


        verticalLayout->addLayout(horizontalLayout_3);

        _open_close = new QPushButton(centralwidget);
        _open_close->setObjectName(QString::fromUtf8("_open_close"));
        _open_close->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(_open_close);

        _turning = new QSlider(centralwidget);
        _turning->setObjectName(QString::fromUtf8("_turning"));
        _turning->setEnabled(true);
        _turning->setFocusPolicy(Qt::NoFocus);
        _turning->setMinimum(-64);
        _turning->setMaximum(64);
        _turning->setTracking(true);
        _turning->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(_turning);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        _speed = new QSlider(centralwidget);
        _speed->setObjectName(QString::fromUtf8("_speed"));
        _speed->setFocusPolicy(Qt::NoFocus);
        _speed->setMinimum(-127);
        _speed->setMaximum(127);
        _speed->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(_speed);


        verticalLayout->addLayout(horizontalLayout);

        _batteryLevel = new QProgressBar(centralwidget);
        _batteryLevel->setObjectName(QString::fromUtf8("_batteryLevel"));
        _batteryLevel->setFocusPolicy(Qt::NoFocus);
        _batteryLevel->setValue(0);

        verticalLayout->addWidget(_batteryLevel);

        SumoMain->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SumoMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SumoMain->setStatusBar(statusbar);

        retranslateUi(SumoMain);

        QMetaObject::connectSlotsByName(SumoMain);
    } // setupUi

    void retranslateUi(QMainWindow *SumoMain)
    {
        SumoMain->setWindowTitle(QApplication::translate("SumoMain", "QSumo", 0, QApplication::UnicodeUTF8));
        _flip->setText(QApplication::translate("SumoMain", "Up", 0, QApplication::UnicodeUTF8));
        _balance->setText(QApplication::translate("SumoMain", "Balance", 0, QApplication::UnicodeUTF8));
        _flipDown->setText(QApplication::translate("SumoMain", "Down", 0, QApplication::UnicodeUTF8));
        _hijump->setText(QApplication::translate("SumoMain", "HighJump", 0, QApplication::UnicodeUTF8));
        _longjump->setText(QApplication::translate("SumoMain", "LongJump", 0, QApplication::UnicodeUTF8));
        _turn->setText(QApplication::translate("SumoMain", "Turn", 0, QApplication::UnicodeUTF8));
        _watchLeftRight->setText(QApplication::translate("SumoMain", "Watch-L+R", 0, QApplication::UnicodeUTF8));
        _tap->setText(QApplication::translate("SumoMain", "Tap", 0, QApplication::UnicodeUTF8));
        _swing->setText(QApplication::translate("SumoMain", "Swing", 0, QApplication::UnicodeUTF8));
        _turnLeftRight->setText(QApplication::translate("SumoMain", "Turn L+R", 0, QApplication::UnicodeUTF8));
        _turnToBalance->setText(QApplication::translate("SumoMain", "Turn - Bal", 0, QApplication::UnicodeUTF8));
        _turnAndJump->setText(QApplication::translate("SumoMain", "Turn+Jump", 0, QApplication::UnicodeUTF8));
        _slalom->setText(QApplication::translate("SumoMain", "Slalom", 0, QApplication::UnicodeUTF8));
        _growingCircles->setText(QApplication::translate("SumoMain", "Grow-Circle", 0, QApplication::UnicodeUTF8));
        _open_close->setText(QApplication::translate("SumoMain", "Open", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SumoMain: public Ui_SumoMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
