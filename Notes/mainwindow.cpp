#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->removeTab(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_save_triggered()
{
   QString filePath = QFileDialog::getSaveFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));

    if (filePath != "")
    {
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this,tr("Error"),tr("Could not save file"));
            return;
        }
        else
        {
            QTextStream stream(&file);
            stream << ui->text_field->toPlainText();
            stream.flush();
            file.close();
        }

        QFileInfo fileinfo(filePath);
        QString fileName = fileinfo.fileName();

        ui->tabWidget->setTabText(0, fileName);
    }

}

void MainWindow::on_exit_triggered()
{
    this->close();
}

void MainWindow::on_open_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));

    if (filePath != "")
    {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,tr("Error"),tr("Could not open file"));
            return;
        }

        QTextStream in(&file);
        ui->text_field->setText(in.readAll());
        file.close();

        QFileInfo fileinfo(filePath);
        QString fileName = fileinfo.fileName();

        ui->tabWidget->setTabText(0, fileName);
    }


}
