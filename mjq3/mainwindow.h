#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    enum Song{DHT, MJQ};
    int choice;

private slots:
    void on_pushButton_clicked();


protected:
      bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
