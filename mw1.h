#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include<QKeyEvent>
#include<QTimer>
#include "rpgobj.h"
#include "world.h"
#include"image_change.h"
namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
    Image_Change ic;//创建一个图片切换类作为MW1的成员变量，使MW1可以使用它
protected slots:
    void randomMove();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
};

#endif // MW1_H
