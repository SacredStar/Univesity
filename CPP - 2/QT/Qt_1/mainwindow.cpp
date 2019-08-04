#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow()
{   
    //Акшины
    openAction   =   new QAction(tr("&Open"),this);
    saveAction   =   new QAction(tr("&Save"),this);
    //bin action
 /* open_binAction = new QAction(tr("&Open_bin"),this);
    save_binAction = new QAction(tr("&Save_bin"),this);*/
    //del/add Action
    addStringAction    =   new QAction(tr("&Add") ,this);
    deleteStringAction =   new QAction (tr("&Delete"),this);


    //Связи
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
    //bin файлы
 /* connect(open_binAction, SIGNAL(triggered()), this, SLOT(open_bin()));
    connect(save_binAction, SIGNAL(triggered()), this, SLOT(save_bin()));*/

    setCentralWidget(textEdit);
    // Удаление/добавление строки
    connect(addStringAction, SIGNAL(triggered()), this, SLOT(addString()));
    connect(deleteStringAction, SIGNAL(triggered()), this, SLOT(deleteString()));

    //Контекстное меню Файл
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();

    //бинарные файлы в контекстном меню
 /* fileMenu->addAction(open_binAction);
    fileMenu->addAction(save_binAction);*/

    //Контекстное меню String
    stringMenu = menuBar()->addMenu(tr("Strings"));
    stringMenu->addAction(addStringAction);
    stringMenu->addAction(deleteStringAction);

    //Текстовый эдитор
    textEdit = new QTextEdit;
    setWindowTitle(tr("Notepad"));
}
//Открытие файлов и вывод в текст едит
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("CSV Files (*.csv);;Text Files (*.txt)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
}
//Сохранение из текст эдит в файл
void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                                                    tr("CSV Files (*.csv);;Text Files (*.txt)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            // error message
        } else {
            QTextStream stream(&file);
            stream << textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}
//Добавление строки, без проверки формата ввода
void MainWindow::addString()
{
    bool ok;
    QString stringname = QInputDialog::getText(this,
                                               QString::fromUtf8("Введите строку базы данных:"),
                                               QString::fromUtf8("Введите строку базы данных в формате:\"Фамилия\";\"Имя\""),
                                               QLineEdit::Normal,
                                               "",&ok);
    if (ok == true && !stringname.isEmpty())
    {
        textEdit->append(stringname);
    }
}
//Удаление строки из списка
void MainWindow::deleteString()
{
    QStringList id_line = textEdit->toPlainText().split('\n');
    bool ok;
    QString str_to_del = QInputDialog::getItem(this,
                                          QString::fromUtf8("Удаление"),
                                          QString::fromUtf8("Выберите строку для удаления: "),
                                          id_line,0,false,&ok);
    if(!textEdit->toPlainText().isEmpty() && ok ==true)
    {
         for (auto str :id_line)
         {
             if (str ==str_to_del)
             {
                 id_line.removeOne(str);
             }
         }
         textEdit->setText("");
         for (auto line:id_line)
         {
             textEdit->append(line);
         }
    }
}


