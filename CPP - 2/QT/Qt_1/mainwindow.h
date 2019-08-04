#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();

public  slots:
     void open();
     void save();
     //бин
  /* void save_bin();
     void open_bin(); */
     void addString();
     void deleteString();

private:
    QTextEdit *textEdit;
    QAction *saveAction;
    QAction *openAction;
    //bin action
/*  QAction *save_binAction;
    QAction *open_binAction; */
    QAction *addStringAction;
    QAction *deleteStringAction;

    QMenu *fileMenu;
    QMenu *stringMenu;
};

#endif // MAINWINDOW_H
