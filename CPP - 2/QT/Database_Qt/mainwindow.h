#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtGui>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QStandardItemModel>
#include <QStandardItem>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();
     //Database
    QSqlDatabase db;
    QStandardItemModel *model;
    QStandardItem *item;
    QStringList v_header;

public  slots:
     //Slots for DB
     void connect_db();
     void disconnect_db();

     //Slots for tasks
     void task2a();
     void task2b();
     void task2c();
     void task2e();
     void task2d();

     void task4();

private:
    QTextEdit *textEdit;

    //Actions DB
    QAction *connectAction;
    QAction *disconnectAction;
    //Task Actions
     QAction *task2aAction;
     QAction *task2bAction;
     QAction *task2cAction;
     QAction *task2eAction;
     QAction *task2dAction;
     QAction *task4Action;

    //Menu
    QMenu *DB_Menu;
    QMenu *Task_Menu;
};

#endif // MAINWINDOW_H
