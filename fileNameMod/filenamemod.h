#ifndef FILENAMEMOD_H
#define FILENAMEMOD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class FileNameMod; }
QT_END_NAMESPACE

class FileNameMod : public QWidget
{
    Q_OBJECT

public:
    FileNameMod(QWidget *parent = nullptr);
    ~FileNameMod();

private slots:
    void on_openFile_clicked();

    void on_enterMod_clicked();

private:
    Ui::FileNameMod *ui;
};
#endif // FILENAMEMOD_H
