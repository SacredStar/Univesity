#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow()
{
    //Параметры для БД
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost"); // или, например, "my1.server.ru"
        db.setDatabaseName("test");
        db.setUserName("root");
        db.setPassword("12345678");
    //Обработка БД
        model = new QStandardItemModel;
        item = new QStandardItem;

    //Actions:
        //Акшины to connect disconnect DB
        connectAction      =   new QAction(tr("&Connect"),this);
        disconnectAction   =   new QAction(tr("&Disconnect"),this);

        //Task_action
        task2aAction =   new QAction (tr("&Task 2a"),this);
        task2bAction =   new QAction (tr("&Task 2b"),this);
        task2cAction =   new QAction (tr("&Task 2c"),this);
        task2eAction =   new QAction (tr("&Task 2e"),this);
        task2dAction =   new QAction (tr("&Task 2d"),this);

        task4Action =   new QAction (tr("&Task 4"),this);


    //Connectors :
        //DB connectors
        connect(connectAction, SIGNAL(triggered()), this, SLOT(connect_db()));
        connect(disconnectAction, SIGNAL(triggered()), this, SLOT(disconnect_db()));
        //Task connectors
       connect(task2aAction, SIGNAL(triggered()), this, SLOT(task2a()));
       connect(task2bAction, SIGNAL(triggered()), this, SLOT(task2b()));
       connect(task2cAction, SIGNAL(triggered()), this, SLOT(task2c()));
       connect(task2eAction, SIGNAL(triggered()), this, SLOT(task2e()));
       connect(task2dAction, SIGNAL(triggered()), this, SLOT(task2d()));

       connect(task4Action, SIGNAL(triggered()), this, SLOT(task4()));

    //Context menu:
        //Context DB menu:
        DB_Menu = menuBar()->addMenu(tr("&DB"));
        DB_Menu->addAction(connectAction);
        DB_Menu->addSeparator();
        DB_Menu->addAction(disconnectAction);
        //Context TASK menu:
        Task_Menu = menuBar()->addMenu(tr("Tasks"));
        Task_Menu->addAction(task2aAction);
        Task_Menu->addAction(task2bAction);
        Task_Menu->addAction(task2cAction);
        Task_Menu->addAction(task2eAction);
        Task_Menu->addAction(task2dAction);
        Task_Menu->addSeparator();
        Task_Menu->addAction(task4Action);


    //TextEdit
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);
    setWindowTitle(tr("Shmelev Kirill: Database Homework"));
}

void MainWindow::connect_db()
{

    bool connected = db.open();
    if(!connected)
    {
        QMessageBox::critical(
                    parentWidget(),
                    QObject::tr("Connect to Database was unsucsesfull"),
                    db.lastError().text()
                    );
    }
    else {
        QMessageBox::information(
                    parentWidget(),
                    "Test Database",
                    "Database connected"
                    );
    }
}
void MainWindow::disconnect_db()
{
    db.close();
    QMessageBox::information(
                    parentWidget(),
                    "Test Database",
                    "Database disconnected"
                    );
}

void MainWindow::task2a()
{
    textEdit->setText("");
    v_header.clear();
    QSqlQuery query;
    textEdit->setPlainText("");
    QString query_string =(" SELECT CASE WHEN inner_out.summ > 10000 THEN \"Богатые\" WHEN inner_out.summ > 5000 THEN \"Средний достаток\" ELSE \"Бедные\" END \"Достаток\", inner_out.id,citizens.name,inner_out.Days,inner_out.Summ FROM inner_out JOIN citizens ON inner_out.id_citiz = citizens.id");
    query.exec(query_string);
    textEdit->append("Task:Составной многотабличный запрос с параметром, включающий соединение таблиц и CASE-выражение; \n");
    textEdit->append("Query: "+ query_string +"\n\n");
    textEdit->append("Result:\n");

    while(query.next())
    {
        QString answ = query.value(0).toString();
        QString id = query.value(1).toString();
        QString name = query.value(2).toString();
        QString Days = query.value(3).toString();
        QString Summ = query.value(4).toString();
        textEdit->append(id + " " + name + " " + Days+ " " + Summ+" "+ answ + "\n");
    }
}
void MainWindow::task2b(){
        textEdit->setText("");
        v_header.clear();
        QSqlQuery query;
        textEdit->setPlainText("");
        QString query_string = "SELECT * FROM `test`.`v` ORDER BY `Summ`";
        query.exec(query_string);
        textEdit->append("Task:На основе обновляющего представления (многотабличного VIEW), в котором критерий упорядоченности задает пользователь при выполнении;; \n");
        textEdit->append("Query: "+ query_string +"\n\n");
        textEdit->append("Result:\n");

        while(query.next())
        {
            QString id = query.value(0).toString();
            QString id_citiz = query.value(1).toString();
            QString id_room = query.value(2).toString();
            QString cur_tmp = query.value(3).toString();
            QString deploy_tmp = query.value(4).toString();
            QString Days = query.value(5).toString();
            QString Summ = query.value(6).toString();
            textEdit->append(id + " " + id_citiz + " " + id_room + " " + cur_tmp + " " + deploy_tmp + " " + Days+ " " + Summ + "\n");
        }
}

void MainWindow::task2c(){
    textEdit->setText("");
    v_header.clear();
    QSqlQuery query;
    textEdit->setPlainText("");
    QString query_string ="";//TODO
    query.exec(query_string);
    textEdit->append("Task:Запрос, содержащий коррелированные и некоррелированные подзапросы в разделах SELECT, FROM и WHERE (в каждом хотя бы по одному);; \n");
    textEdit->append("Query: "+ query_string +"\n\n");
    textEdit->append("Result:\n");
    //TODO
}
void MainWindow::task2e(){
    textEdit->setText("");
    v_header.clear();
    QSqlQuery query;
    textEdit->setPlainText("");
    QString query_string ="SELECT citizens.name,COUNT(id_citiz) as \"COUNT\",SUM(summ) as SUMM FROM inner_out Join citizens On inner_out.id_citiz = citizens.id  GROUP BY inner_out.id_citiz HAVING AVG(SUMM) > 5000";
    query.exec(query_string);
    textEdit->append("Task:Многотабличный запрос, содержащий группировку записей, агрегативные функции и параметр, используемый в разделе HAVING; \n");
    textEdit->append("Query: "+ query_string +"\n\n");
    textEdit->append("Result:\n");
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString count = query.value(1).toString();
        QString summ = query.value(2).toString();
        textEdit->append(name + " " + count + " " + summ + "\n");
    }

}
void MainWindow::task2d(){
    textEdit->setText("");
    v_header.clear();
    QSqlQuery query;
    textEdit->setPlainText("");
    QString query_string ="SELECT i.id,citizens.name,COUNT(i.id_citiz) as \"TIME\"FROM inner_out i Join citizens on i.id_citiz=citizens.id WHERE citizens.name = ANY(SELECT citizens.name FROM citizens WHERE surname != \"Shmelev\" && surname != \"Nahnah\")GROUP BY citizens.name";
    query.exec(query_string);
    textEdit->append("Task:Запрос, содержащий предикат ANY(SOME)  или ALL \n");
    textEdit->append("Query: "+ query_string +"\n\n");
    textEdit->append("Result:\n");
    while(query.next())
    {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString count = query.value(2).toString();
        textEdit->append(id +" " + name + " " + count + "\n");
    }
}

void MainWindow::task4(){
    textEdit->setText("");
    v_header.clear();
    QSqlQuery query;
    textEdit->setPlainText("");
    QString query_string_show_room = "SELECT * FROM room";
    query.exec(query_string_show_room);
    QVector <int>vec;
    while(query.next())
    {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString price = query.value(2).toString();
        textEdit->append(id + " " + name + " " + price + "\n");
    }
}
