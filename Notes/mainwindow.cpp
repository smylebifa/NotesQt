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

    QString filePath = QFileDialog::getSaveFileName(this, tr("Open file"), "", tr("Text files (*.txt)"), 0);

    QFileInfo fileinfo(filePath);
    QString fileName = fileinfo.fileName();

    if (!filePath.isNull())
    {
        char * FILE_NAME;
        strcpy(FILE_NAME, filePath.toStdString().c_str());

        ofstream out;
        out.open(FILE_NAME);

        string text_field = ui->text_field->toPlainText().toStdString();

        ui->tabWidget->setTabText(0, fileName);

        if (out.is_open())
        {
            out << text_field;
        }
    }

}

void MainWindow::on_exit_triggered()
{
    this->close();
}

void MainWindow::on_open_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Text files (*.txt)"));

    QFileInfo fileinfo(filePath);
    QString fileName = fileinfo.fileName();

    if (!filePath.isNull())
    {
        char * FILE_NAME;

        string textFile = "";

        strcpy(FILE_NAME, filePath.toStdString().c_str());

        string line;

        ifstream in(FILE_NAME);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                textFile += line;
            }
        }

        in.close();

        ui->tabWidget->setTabText(0, fileName);

        ui->text_field->setText(QString::fromStdString(textFile));

    }

}
