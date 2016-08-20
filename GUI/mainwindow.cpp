#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorfilterdialog.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inputImage = NULL;
    outputImage = NULL;
    pixmapitem = NULL;

    scene = new QGraphicsScene(this);   // create a scene
    ui->graphicsView->setScene(scene);  // show the scene on graphicsView

    setWindowTitle("PPM-filters");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString inputFileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/chris", tr("Image Files (*.ppm)"));

    ui->statusBar->showMessage("Opened " + inputFileName);

    if (inputFileName != NULL){

        inputImage = new imaging::Image((unsigned int)0, (unsigned int)0);

        (*inputImage) << inputFileName.toStdString().c_str();
        outputImage = inputImage;
        imageHistory.push_back(outputImage);

        // create and show the pixmap
        showOnQGraphicsView(outputImage);

    }
}

void MainWindow::on_actionSave_triggered()
{
    QString outputFileName = QFileDialog::getSaveFileName(this,
        tr("Save Image"), "/home/chris", tr("Image Files (*.ppm)"));

    ui->statusBar->showMessage("Saved " + outputFileName);

    if (outputFileName != NULL && outputImage != NULL){
        (*outputImage) >> outputFileName.toStdString().c_str();
    }
}

void MainWindow::showOnQGraphicsView(imaging::Image *anImage){

    scene->clear();

    unsigned int width, height;
    width = anImage->getWidth();
    height = anImage->getHeight();
    pixmap = new QPixmap((int) width, (int) height);

    QPainter *painter = new QPainter(pixmap);

    for(unsigned int y=0; y<height; y++){
        for(unsigned int x=0; x<width; x++){
            math::Vec3<component_t> color;
            color = (*anImage)(x,y);

            QColor qcol( (int) (color.r * 255),
                         (int) (color.g * 255),
                         (int) (color.b * 255));

            painter->setPen(qcol);
            painter->drawPoint((int) x, (int) y);
        }
    }

    pixmapitem = scene->addPixmap(*pixmap);
    scene->setSceneRect(0, 0, pixmap->width(), pixmap->height());
}

void MainWindow::on_pushButton_Median_clicked()
{
    if (outputImage == NULL){
        ui->statusBar->showMessage("No loaded image!");
    }
    else{
        imaging::MedianFilter medianfilter;
        apply_filter(dynamic_cast<imaging::Filter*>(&medianfilter));
    }
}

void MainWindow::on_pushButton_Gray_clicked()
{
    if (outputImage == NULL){
        ui->statusBar->showMessage("No loaded image!");
    }
    else{
        imaging::GrayFilter grayfilter;
        apply_filter(dynamic_cast<imaging::Filter*>(&grayfilter));
    }
}

void MainWindow::on_pushButton_Blur_clicked()
{
    if (outputImage == NULL){
        ui->statusBar->showMessage("No loaded image!");
    }
    else{
        imaging::BlurFilter blurfilter;
        apply_filter(dynamic_cast<imaging::Filter*>(&blurfilter));
    }
}

void MainWindow::on_pushButton_Diff_clicked()
{
    if (outputImage == NULL){
        ui->statusBar->showMessage("No loaded image!");
    }
    else{
        imaging::DiffFilter difffilter;
        apply_filter(dynamic_cast<imaging::Filter*>(&difffilter));
    }
}


void MainWindow::on_pushButton_Color_clicked()
{
    if (outputImage == NULL){
        ui->statusBar->showMessage("No loaded image!");
    }
    else{
        ColorFilterDialog colorDialog;
        colorDialog.setModal(true);

        if (colorDialog.exec()){
            component_t r, g, b;
            colorDialog.GetColorDialogData(r, g, b);

            imaging::ColorFilter colorfilter;
            colorfilter.setColorFactors(r,g,b);
            apply_filter(dynamic_cast<imaging::Filter*>(&colorfilter));
        }
    }
}

void MainWindow::apply_filter(imaging::Filter *filter)
{
    ui->statusBar->showMessage("Applying" + QString::fromStdString(filter->getFilterName()) + "filter...");

    imaging::Image * newImage = new imaging::Image((unsigned int)0, (unsigned int)0);
    (*newImage) = (*filter) << (*outputImage);
    imageHistory.push_back(newImage);
    outputImage = newImage;

    showOnQGraphicsView(outputImage);
    ui->statusBar->showMessage( QString::fromStdString(filter->getFilterName()) + " filter applied!");
}

void MainWindow::on_actionUndo_triggered()
{
    if ( imageHistory.size() > 1 )
    {
        imaging::Image * delImage = imageHistory.back();
        imageHistory.pop_back();

        outputImage = imageHistory.back();
        showOnQGraphicsView(outputImage);

        delete delImage;
    }
}
