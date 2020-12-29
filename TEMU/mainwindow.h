#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ChangeUI.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mainloop();

private slots:
    void on_Btn_ni_clicked();

    void on_btn_help_clicked();

    void on_btn_c_clicked();

    void on_lineEdit_returnPressed();

    void on_btn_w_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
