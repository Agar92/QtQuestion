#ifndef BOOKWINDOW_H
#define BOOKWINDOW_H

#include <QtWidgets>
#include <QtSql>

#include "ui_bookwindow.h"

#include "tablemodel.h"


class BookWindow: public QMainWindow
{
    Q_OBJECT
public:
    BookWindow();

private slots:
    void about();

private:
    void showError(const QSqlError &err);
    Ui::BookWindow ui;
    //QSqlRelationalTableModel *model;
    TableModel * model;

    int authorIdx, genreIdx;

    void createMenuBar();
};

#endif
