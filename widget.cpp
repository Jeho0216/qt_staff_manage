#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    if ( (fp = fopen("a.bin", "rb+")) == NULL)
    {
            if ( (fp = fopen("a.bin", "wb+")) == NULL)
            {
                qDebug() << "can't Open file wb+ : a.bin" << endl;
                exit(1);
            }
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    char buff[20];
    student s;

    QString name = ui->lineEdit->text();

    if (name == "")
        return;

    qsnprintf(s.name, sizeof(s.name), "%s", name.toUtf8().constData());
    s.grade = ui->lineEdit_2->text().toDouble();
    s.english = ui->lineEdit_3->text().toInt();
    fwrite(&s, sizeof(student), 1,  fp);

    sprintf(buff, "%s %4.1f %d", s.name, s.grade, s.english);
    ui->textEdit->append(buff);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void Widget::on_pushButton_3_clicked()
{
    fclose(fp);
    this->close();
}

void Widget::display_data(char *name, double score, int english)
{
    char buff[20];

    sprintf(buff, "%s %4.1f %d", name, score, english);
    ui->textEdit->append(buff);
}

void Widget::on_pushButton_2_clicked()
{
    student s;

    ui->textEdit->clear();
    rewind(fp);

    while(fread(&s, sizeof(student), 1, fp) != NULL)
    {
            if ( s.grade >= 4.0 && s.english >= 900 )
            {
                    display_data(s.name, s.grade, s.english);
            }
    }
    return;
}

void Widget::on_pushButton_4_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->textEdit->clear();
}

void Widget::on_pushButton_5_clicked()
{
    student s;

    ui->textEdit->clear();
    rewind(fp);

    while(fread(&s, sizeof(student), 1, fp) != NULL)
    {
         display_data(s.name, s.grade, s.english);
    }
    return;
}
