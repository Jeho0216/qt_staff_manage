#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QDebug>

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public: 
    explicit Widget(QWidget *parent = nullptr);
    FILE *fp;
    void display_data(char *name, double score, int english);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H


class student
{
public:
        char    name[20];
        double  grade;
        int     english;
};
