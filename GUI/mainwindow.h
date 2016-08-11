#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QPixmap>
#include <QColor>
#include <QPainter>
#include "Vec3.h"
#include "Image.h"
#include "GrayFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"
#include "MedianFilter.h"
#include "ColorFilter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_pushButton_Gray_clicked();

    void on_pushButton_Blur_clicked();

    void on_pushButton_Diff_clicked();

    void on_pushButton_Median_clicked();

    void on_pushButton_Color_clicked();

private:
    Ui::MainWindow *ui;

    imaging::Image *inputImage;
    imaging::Image *outputImage;
    QGraphicsScene *scene;
    QPixmap *pixmap;
    QGraphicsPixmapItem *pixmapitem;

    void showOnQGraphicsView(imaging::Image *anImage);

};

#endif // MAINWINDOW_H
