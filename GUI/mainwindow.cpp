#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString inputFileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/chris", tr("Image Files (*.ppm)"));

    ui->infoLabel->setText(inputFileName);

    if (inputFileName != NULL){

        inputImage = new imaging::Image((unsigned int)0, (unsigned int)0);

        (*inputImage) << inputFileName.toStdString().c_str();
        outputImage = inputImage;

        // create and show the pixmap
        showOnQGraphicsView(outputImage);

    }
}

void MainWindow::on_actionSave_triggered()
{
    QString outputFileName = QFileDialog::getSaveFileName(this,
        tr("Save Image"), "/home/chris", tr("Image Files (*.ppm)"));

    ui->infoLabel->setText(outputFileName);

    if (outputFileName != NULL && outputImage != NULL){
        (*outputImage) >> outputFileName.toStdString().c_str();
    }
}

void MainWindow::on_pushButton_Gray_clicked()
{
    if (outputImage == NULL){
        ui->infoLabel->setText("No loaded image!");
    }
    else{
        ui->infoLabel->setText("Applying Gray filter...");
        imaging::GrayFilter grayfilter;
        (*outputImage) = grayfilter << (*outputImage);
        showOnQGraphicsView(outputImage);
        ui->infoLabel->setText("Applied Gray filter");
    }
}

void MainWindow::on_pushButton_Blur_clicked()
{
    if (outputImage == NULL){
        ui->infoLabel->setText("No loaded image!");
    }
    else{
        ui->infoLabel->setText("Applying Blur filter...");
        imaging::BlurFilter blurfilter;
        (*outputImage) = blurfilter << (*outputImage);
        showOnQGraphicsView(outputImage);
        ui->infoLabel->setText("Applied Blur filter");
    }
}

void MainWindow::on_pushButton_Diff_clicked()
{
    if (outputImage == NULL){
        ui->infoLabel->setText("No loaded image!");
    }
    else{
        ui->infoLabel->setText("Applying Diff filter...");
        imaging::DiffFilter difffilter;
        (*outputImage) = difffilter << (*outputImage);
        showOnQGraphicsView(outputImage);
        ui->infoLabel->setText("Applied Diff filter");
    }
}

void MainWindow::showOnQGraphicsView(imaging::Image *anImage){

//    if( pixmapitem!=NULL )
//        delete pixmapitem;
//        scene->removeItem(pixmapitem);

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
}
