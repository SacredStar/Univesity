#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>

class table : public MainWindow
{
    Q_OBJECT
public:
    explicit table(QWidget *parent = nullptr);
    QStandardItemModel *model;
    QStandardItem *item;
    QStringList V_header;
    QStringList H_header;

signals:

public slots:
};

#endif // TABLE_H
