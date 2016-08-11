#ifndef COLORFILTERDIALOG_H
#define COLORFILTERDIALOG_H

#include <QDialog>
#include "Image.h"

namespace Ui {
class ColorFilterDialog;
}

class ColorFilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ColorFilterDialog(QWidget *parent = 0);
    ~ColorFilterDialog();

    void GetColorDialogData(component_t &, component_t &, component_t &);

private slots:

private:
    Ui::ColorFilterDialog *ui;
};

#endif // COLORFILTERDIALOG_H
