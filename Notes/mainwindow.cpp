#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->addToolBar(Qt::TopToolBarArea, createToolBar());
    this->addToolBar(Qt::TopToolBarArea, createToolBar2());

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QToolBar* MainWindow::createToolBar()
{
    QToolBar* ptb = new QToolBar("Linker ToolBar");
    ptb->setMovable(true);

    ptb->addAction("Untitled");

    return ptb;
}

QToolBar* MainWindow::createToolBar2()
{
    QToolBar* ptb = new QToolBar("Linker ToolBar2");
    ptb->setMovable(false);

    ptb->addAction("+", this, SLOT(slotNoImpl()));

    return ptb;
}


void MainWindow::slotNoImpl()
{
    this->addToolBar(Qt::TopToolBarArea, createToolBar());
}

void MainWindow::on_save_triggered()
{
    char * FILE_NAME = "test.txt";

    ofstream out;
    out.open(FILE_NAME);

    string text_field = ui->text_field->toPlainText().toStdString();

    if (out.is_open())
    {
        out << text_field;
    }

}

void MainWindow::on_exit_triggered()
{
    this->close();
}

void MainWindow::on_open_triggered()
{

}
