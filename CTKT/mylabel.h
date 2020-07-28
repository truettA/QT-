#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>

class MyLabel : public QLabel
{
  Q_OBJECT
public:
    MyLabel(QWidget * parent = nullptr);
    ~MyLabel();
    //override保留字，说明重写了基类函数
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
//signals:
      //void clicked();

};

#endif // MYLABEL_H
