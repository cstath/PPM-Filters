#include <QtGui>
#include <QFileDialog>
#include <QString>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

//    QString message = tr("A context menu is available by right-clicking");
//    statusBar()->showMessage(message);

    // Create and position the buttons
    buttonGray = new QPushButton("Gray", this);
    buttonGray->setGeometry(0, 50, 80, 30);
    buttonGray->setToolTip("Apply Gray Filter");

    buttonBlur = new QPushButton("Blur", this);
    buttonBlur->setGeometry(0, 80, 80, 30);
    buttonBlur->setToolTip("Apply Blur Filter");

    buttonDiff = new QPushButton("Diff", this);
    buttonDiff->setGeometry(0, 110, 80, 30);
    buttonDiff->setToolTip("Apply Diff Filter");

    connect(buttonGray, SIGNAL (clicked()), this, SLOT (slotGrayButtonClicked()));
    connect(buttonBlur, SIGNAL (clicked()), this, SLOT (slotBlurButtonClicked()));
    connect(buttonDiff, SIGNAL (clicked()), this, SLOT (slotDiffButtonClicked()));

    setWindowTitle(tr("Filters"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

void MainWindow::open()
{
    QString inputFileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/chris", tr("Image Files (*.ppm)"));
    infoLabel->setText(inputFileName);

    if (inputFileName != NULL){

        inputImage = new Image((unsigned int)0, (unsigned int)0);

        (*inputImage) << inputFileName.toStdString().c_str();
        outputImage = inputImage;
    }
//    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::save()
{
    QString outputFileName = QFileDialog::getSaveFileName(this,
        tr("Save Image"), "/home/chris", tr("Image Files (*.ppm)"));
    infoLabel->setText(outputFileName);

    if (outputFileName != NULL){
        (*outputImage) >> outputFileName.toStdString().c_str();
    }
//    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
//    fileMenu->addSeparator();
//    fileMenu->addAction(exitAct);

//    helpMenu = menuBar()->addMenu(tr("&Help"));
//    helpMenu->addAction(aboutAct);
}

void MainWindow::slotGrayButtonClicked()
{
    if (outputImage == NULL){
        infoLabel->setText("No loaded image!");
    }
    else{
        infoLabel->setText("Applied Gray filter");
        GrayFilter grayfilter;
        (*outputImage) = grayfilter << (*outputImage);
    }

}

void MainWindow::slotBlurButtonClicked()
{
    if (outputImage == NULL){
        infoLabel->setText("No loaded image!");
    }
    else{
        infoLabel->setText("Applied Blur filter");
        BlurFilter blurfilter;
        (*outputImage) = blurfilter << (*outputImage);
    }
}

void MainWindow::slotDiffButtonClicked()
{
    if (outputImage == NULL){
        infoLabel->setText("No loaded image!");
    }
    else {
        infoLabel->setText("Applied Diff filter");
        DiffFilter difffilter;
        (*outputImage) = difffilter << (*outputImage);
    }
}
