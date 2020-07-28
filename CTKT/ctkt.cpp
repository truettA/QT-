#include "ctkt.h"
#include "ui_ctkt.h"
#include <QMouseEvent>
#include <QDebug>
//光标位置
//#include <QCursor>
#include <ctime>
#include <QDialog>
//#include <QLayout>
#include <QLabel>
#include <QMovie>
#include <QMessageBox>
#include "mylabel.h"
#include <QPaintEvent>
#include <QPainter>
#include <QIcon>
#include <QFont>
#include <QPalette>


CTKT::CTKT(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CTKT)
{
    //产生随机数
    //随机种子
    qsrand(time(nullptr));
/*
    //产生随机数第二种方法
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int n = qrand() % 5;    //产生5以内的随机数
*/
    ui->setupUi(this);
    //去掉关闭帮助按钮
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);


    //注册过滤器
    //ui->agreeButton->installEventFilter(this);
    ui->disagreeButton->installEventFilter(this);
    //按钮设置颜色
    //ui->disagreeButton->setStyleSheet("QPushButton{border-radius:10px;}");
    ui->disagreeButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;""color: black; background-color: pink");
    ui->agreeButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;""color: black; background-color: pink");
    //ui->disagreeButton->setStyleSheet("border:none");
    //ui->disagreeButton->setFlat(true);

    //按钮图标设置
//    QIcon icon;
//    icon.addFile(":/hart.ico");
//    ui->agreeButton->setIcon(icon);
//     QPixmap icon1(":/hart.ico");
//     ui->agreeButton->setIcon(icon1);
//     ui->agreeButton->setFixedSize(icon1.size());
   //取消按钮默认样式
   // ui->agreeButton->setFlat(true);

    //设置字号
    QFont ft;
    ft.setPointSize(15);
    ui->label->setFont(ft);
    //设置颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::blue);
    ui->label->setPalette(pa);

    qPixmap = new QPixmap;

}

CTKT::~CTKT()
{
    delete qDialog;
    delete qPixmap;
    delete ui;
}

void CTKT::on_agreeButton_clicked()
{
    qDebug() <<"点击同意" << endl;
    /*
    //获取title下左顶点在桌面上面坐标
    qDebug() << this->frameGeometry().x()
             << this->frameGeometry().y();
    //获取窗口左顶点在桌面上面坐标
    qDebug() << this->pos().x() << this->pos().y();
    */
    //整个窗口的高和宽
//    qDebug() << this->frameGeometry().width()
//             << this->frameGeometry().height();
//    qDebug() << this->geometry().x()
//             << this->geometry().y();//坐标
    //获取窗口里面的高和宽
//    qDebug() << this->geometry().width()
//             << this->geometry().height();

    qDialog = new QDialog;
    //对话框标题
    qDialog->setWindowTitle("乖巧girl");
    //去掉关闭帮助按钮
    qDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    //对话框大小
    qDialog->setFixedHeight(400);
    qDialog->setFixedWidth(300);
    //Layout布局
    //QLayout qLayout(&qDialog);
    //qDialog.setLayout()
    //在同意窗口中添加label
    //添加文本label
    QLabel aLabelText(qDialog);
    aLabelText.setText("哈哈哈。不要脸的我，知道你会同意的！\n点击动图退出，我等着你的消息");
    aLabelText.setGeometry(0,0,300,100); //大小及坐标
    //设置字号
    QFont ft;
    ft.setPointSize(13);
    aLabelText.setFont(ft);
    //设置颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::blue);
    aLabelText.setPalette(pa);
    //添加文本label
    MyLabel aLabelPicture(qDialog);
    QMovie qMovie(":/20200726175935.gif");
    qMovie.start();    //用了start函数gif才会动
    aLabelPicture.setMovie(&qMovie);
    aLabelPicture.setGeometry(0,100,300,300);
   // aLabelPicture.installEventFilter(qDialog);


/*
    2.利用drawPixmap 画。（动态的图片只能显示第一桢，而且因该重写paintEvent）代码如下：


    void CourseInfoPage::paintEvent(QPaintEvent* event)

    {

    QPixmap pic(":/images/bkg.gif");//这个要到资源文件source.qrc里面,其他的没有试过能成功不

    QPainter painter(this);

    painter.drawPixmap(m_ui->frame_picture->x(),m_ui->frame_picture->y(),m_ui->frame_picture->width(),m_ui->frame_picture->height(),pic);
    ｝
*/

    qDialog->exec();

}
void CTKT::on_disagreeButton_clicked()
{
   // QMessageBox::information(this,"你再想想啦","不要这么无情",QMessageBox::Yes);
    QDialog *disagreeDialog = new QDialog;
    //对话框标题
    disagreeDialog->setWindowTitle("你再想想啦");
    //去掉关闭帮助按钮
    disagreeDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
   // 对话框大小
    disagreeDialog->setFixedHeight(300);
    disagreeDialog->setFixedWidth(400);
    //添加布局
    //disagreeDialog->setLayout()
    //添加文本label
    QLabel aLabelText(disagreeDialog);
    aLabelText.setText("不要这么快决定啦");
    aLabelText.setGeometry(230,100,200,70); //大小及坐标
    //设置字号
    QFont ft;
    ft.setPointSize(15);
    aLabelText.setFont(ft);
    //设置颜色
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::red);
    aLabelText.setPalette(pa);

    QPushButton qPushButton(disagreeDialog);
    qPushButton.setText("再想想");

    qPushButton.setGeometry(235,230,50,30);
    connect(&qPushButton,&QPushButton::clicked,[=](){
        disagreeDialog->close();
    });

    QLabel qLabel(disagreeDialog);
   //更换图片
    QPixmap pixmap;
    int i = qrand()%4;
    qDebug() << i << endl;
    if(i == 0 ||i == 3)
    {
        pixmap.load(":/doge.jpg");
    }
    else if(i == 1 || i ==2)
    {
        aLabelText.setText("我知道你\n肯定点错啦");
        pixmap.load(":/cat4.jpg");
    }
    qLabel.setPixmap(pixmap);
    qLabel.setGeometry(0,0,220,220);
    // qLabel.setStyleSheet("border-image:url(:/doge.jpg)");
    //按比例缩放
    qLabel.setScaledContents(true);

    //重置nums
    nums = 5;

    disagreeDialog->exec();

}
//重写关闭事件函数
void CTKT::closeEvent(QCloseEvent *event)
{
    qDebug() <<"程序关闭";
    QMessageBox::StandardButton button;
    QMessageBox::question(this,"不要这么快走了",QString("你还没有回答我问题呢？不准离开"),QMessageBox::Yes);
    event->ignore();
}
//背景图设置
void CTKT::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/tiangei.jpg");
    painter.drawPixmap(0, 0, width(), height(), pixmap);
}


//重写事件过滤器
bool CTKT::eventFilter(QObject *watched, QEvent *event)
{
    if(ui->disagreeButton == watched)
    {
        if(event->type() == QEvent::Enter)
        {
            //随机图片编号
            int key = qrand()%5;
            if(key == 1 || key == 0)
            {
                pictureFilePath = ":/20200726180125.jpg";
            }
            else if(key == 2)
            {
                pictureFilePath = ":/cat1.jpg";
            }
            else if(key == 3)
            {
                pictureFilePath = ":/cat2.jpg";
            }
            else if(key == 4)
            {
                pictureFilePath = ":/cat3.jpg";
            }

            //获取当前窗口大小 x y
            //qDebug() << "鼠标进入agreeButton" << endl;
            //产生随机坐标
            x = qrand()%(this->geometry().width() - ui->disagreeButton->geometry().width());
            y = qrand()%(this->geometry().height() - ui->disagreeButton->geometry().height());
            if(nums < 10)
            {
                ui->disagreeButton->move(x,y);
                nums++;
            }
            //更换图片
            qPixmap->load(pictureFilePath);
            ui->pictureMain->setPixmap(*qPixmap);
            if(nums == 9)
            {
                ui->disagreeButton->setText("不为难你了");
            }
            if(nums == 10)
            {
                ui->disagreeButton->setText("不同意，滚");
            }
        }

    }

//    if(qDialog == watched)
//    {
//        if(event->type() == QEvent::MouseButtonPress)
//        {
//            qDebug() <<"鼠标点击" <<endl;
//        }
//    }
}


