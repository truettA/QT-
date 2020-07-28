#include "filenamemod.h"
#include "ui_filenamemod.h"
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QTextDocument>
#include <QTextBlock>
#include <QMessageBox>

FileNameMod::FileNameMod(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileNameMod)
{
    ui->setupUi(this);
    //设置软件图标
    setWindowIcon(QIcon(":/Image/applicationIco.ico"));
}

FileNameMod::~FileNameMod()
{
    delete ui;
}


void FileNameMod::on_openFile_clicked()
{
    ui ->viewFile->clear();
    qDebug() <<"open file" << endl;
    QFileDialog *fileDialog = new QFileDialog(this);
    //设置对话框标题
    fileDialog -> setWindowTitle("选中文件");
    //设置文件过滤器
    //可以用;;分隔
    QStringList filters;
    filters <<"Any file(*)"
            <<"Images(*.png *.jpg *.jpeg *.bmp)"
            <<"Iext file(*.txt)"
            <<"办公文档(*.doc *.docx *.xls *.pptx)";
    fileDialog->setNameFilters(filters);
    //fileDialog->setNameFilter("Images(*.png *.jpg *.jpeg *.bmp)");


    //设置选择多个文件   默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog -> setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog -> setViewMode(QFileDialog::Detail);

    //获取选中文件夹
    QString fileNamePath;
    fileNamePath = fileDialog->getExistingDirectory();
    ui->viewFilePath->setText(fileNamePath);
    //设置默认文件路径
    fileDialog -> setDirectory(fileNamePath);
    //获取文件路径长度
    int size = fileNamePath.length();

    //打印所有选择的文件的路径
      QStringList fileNames;
      //exe()阻塞 fileDialog窗口
      if (fileDialog->exec())
      {
        fileNames = fileDialog->selectedFiles();
        //fileNamePaths = fileDialog->
      }
      for (QString tmp : fileNames)
      {
        //qDebug() << tmp << endl;
        //tmp =tmp - fileNamePath;
        tmp.remove(0,size+1);
        ui->viewFile->append(tmp);
      }
      // 释放对象
      delete fileDialog;
}

void FileNameMod::on_enterMod_clicked()
{
    //将viewFile里面内容转为文本内容
    QTextDocument* doc = ui->viewFile->document();
    //回车符是一个block
    //获取多少行count
    int num1, num2;
    if(ui->fileName1->text().isEmpty())
    {
           num1 = -1;
    }
    else
    {
        num1 = ui->fileName1->text().toInt();
    }
    num2 = ui->fileName3->text().toInt();
    int count = doc->blockCount();
    //储存新的文件名然后打印到lineedit
    QStringList LFileName;
    for(int i = 0; i < count; i++)
    {
        //获取文本中的一段（即一行)
        //一个 document 有多个 TextBlock，从 document 中读取出的一个文本块类型为 QTextBlock，通过 QTextBlock::text() 函数可以获取其纯文本文字。
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString oldFileName = textLine.text();
        oldFileName = ui->viewFilePath->text() + "/" +oldFileName;
        //修改文件名拼接
        QString newFileName = ui->viewFilePath->text()+"/";
        if(num1 >=0 )
        {
          qDebug() << "有效" << endl;
          newFileName.append(QString::number(num1,10));
        }
        newFileName.append(ui->fileName2->text());
        newFileName.append(QString::number(num2,10));
        qDebug() << num1 << endl;
        qDebug() << num2 << endl;
        qDebug() << ui->fileName2->text() << endl;
        newFileName.append(".");
        newFileName.append(ui->fileName4->text());
        qDebug() << oldFileName << endl;
        qDebug() << newFileName << endl;
        //修改文件名
       bool result = QFile::rename(oldFileName,newFileName);
       if(result)
       {
           qDebug() << "更改文件名成功" << endl;
       }
       else
       {
           qDebug() << "更改文件名失败！" << endl;
       }
        LFileName.append(newFileName);
        //另外一个种
        //LFileName << QStringLiteral(newFileName)
        num2++;
        if(num1 >=0)
        {
            num1++;
        }

    }
    ui->viewFile->clear();

    int size = ui->viewFilePath->text().length();
    for(auto tmp : LFileName)
    {
        tmp.remove(0,size+1);
        ui->viewFile->append(tmp);
    }
    //消息对话框
    QString dlgTitle = QStringLiteral("提示消息");
    QString strInfo = QStringLiteral("文件名修改成功");
    QMessageBox::information(this,dlgTitle,strInfo,QMessageBox::Ok);

}
