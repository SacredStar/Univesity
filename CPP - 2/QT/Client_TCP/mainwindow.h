#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QPushButton>
#include <QFile>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QByteArray>
#include <QMessageBox>
#include <QDataStream>
#include <QProgressBar>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket * mTcpSocket;
    QPushButton* mPushButton;
    QPushButton* button;
    QProgressBar* Qprog;
    QTimer* timer;
   // QMenuBar* menu;
    //QVBoxLayout* lay;
public slots:
    void slotSendToServer();

private:

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
