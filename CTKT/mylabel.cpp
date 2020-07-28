#include "mylabel.h"
#include <QDebug>
#include <QEvent>
#include <QApplication>


MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

MyLabel::~MyLabel()
{

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    //emit clicked();QEvent::MouseButtonPress
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "单机";
        QApplication::exit(0);
    }
}

//不知道为什么写了后会报错
//void MyLabel::clicked()
//{
//    qDebug() << "点击图片" <<endl;
//}
