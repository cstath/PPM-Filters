#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "Array.h"
#include "Image.h"
#include "Vec3.h"
#include "Filter.h"
#include "GrayFilter.h"
#include "BlurFilter.h"
#include "DiffFilter.h"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

using namespace imaging;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();
protected:

private:
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QAction *openAct;
    QAction *saveAct;
    QLabel *infoLabel;

    QPushButton *buttonGray;
    QPushButton *buttonBlur;
    QPushButton *buttonDiff;

    Image * inputImage;
    Image * outputImage;

signals:

private slots:
    void open();
    void save();
    void slotGrayButtonClicked();
    void slotBlurButtonClicked();
    void slotDiffButtonClicked();
};

#endif // MAINWINDOW_H
