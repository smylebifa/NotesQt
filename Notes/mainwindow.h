#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QDebug>
#include <QTextCodec>
#include <QtGui>
#include <string>
#include <fstream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QToolBar* createToolBar();
    QToolBar* createToolBar2();

private slots:
    void slotNoImpl();
    void on_save_triggered();

    void on_exit_triggered();

    void on_open_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
