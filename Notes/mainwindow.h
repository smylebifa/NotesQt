#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include <string>

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

private slots:
    // Slots for handling menu buttons
    void on_save_triggered();
    void on_exit_triggered();
    void on_open_triggered();
    void on_saveAs_triggered();

    void on_text_field_textChanged();

private:
    Ui::MainWindow *ui;

    QString filePath_;
};

#endif // MAINWINDOW_H
