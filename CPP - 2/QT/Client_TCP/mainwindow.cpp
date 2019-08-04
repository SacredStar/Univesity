#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //lay = new QGridLayout(this);
    button = new QPushButton("&Open");
    Qprog = new QProgressBar();
    timer = new QTimer();
    timer->setInterval(1000);


   // lay = new QVBoxLayout();

    Qprog->setMinimum(0);
    Qprog->setMaximum(10);
    connect(button, SIGNAL(clicked()), SLOT(slotSendToServer()));
    setCentralWidget(button);

}

MainWindow::~MainWindow()
{

}

void MainWindow::slotSendToServer()
{

     mTcpSocket = new QTcpSocket(this);
     mTcpSocket->connectToHost("localhost",6000);
     /*QString fileName = QFileDialog::getOpenFileName(this,
                                                     tr("Open File"),
                                                     "",
                                                     tr("MSI Files (*.msi)")
                                                     );*/

     QFile file("cmake.msi");
     file.open(QIODevice::ReadOnly);
     QByteArray arrBlock;
     QDataStream out(&arrBlock,QIODevice::WriteOnly);

     out << file.readAll();
     out.device()->seek(0);
     out << quint16(arrBlock.size());
     mTcpSocket->write(arrBlock);
     Qprog->show();

}
