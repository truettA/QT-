#ifndef CTKT_H
#define CTKT_H

#include <QWidget>
#include <QEvent>
#include <QObject>
#include <QPixmap>
#include <QString>

//随机图片显示
typedef enum {PICTURE_ONE,PICTURE_TWO,PICTURE_THREE,PICTURE_FORE}pictureNum;


QT_BEGIN_NAMESPACE
namespace Ui { class CTKT; }
QT_END_NAMESPACE


class CTKT : public QWidget
{
    Q_OBJECT

public:
    CTKT(QWidget *parent = nullptr);
    ~CTKT();

private slots:
    void on_agreeButton_clicked();
    bool eventFilter(QObject *watched, QEvent *event);

    void on_disagreeButton_clicked();
    //MyLabel槽函数
    //void handlelabelclicked();
    //关闭事件
    void closeEvent(QCloseEvent *event);
    //
    void paintEvent(QPaintEvent *);
public:
    //要用到的临时坐标
    int x = 0,y = 0;
    //按钮跳动计数
    int nums = 3;
    //画笔
    QPixmap *qPixmap;
    //图片路径
    QString pictureFilePath;
    //同意新窗口
    QDialog *qDialog;

private:
    Ui::CTKT *ui;
};
#endif // CTKT_H
