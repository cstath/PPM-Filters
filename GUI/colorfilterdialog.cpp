#include "colorfilterdialog.h"
#include "ui_colorfilterdialog.h"

ColorFilterDialog::ColorFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ColorFilterDialog)
{
    ui->setupUi(this);
}

ColorFilterDialog::~ColorFilterDialog()
{
    delete ui;
}

void ColorFilterDialog::GetColorDialogData(component_t &r, component_t &g, component_t &b){

    r = (component_t) ui->lineEdit_r->text().toDouble();
    g = (component_t) ui->lineEdit_g->text().toDouble();
    b = (component_t) ui->lineEdit_b->text().toDouble();

}
