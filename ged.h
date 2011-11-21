#ifndef GED_H
#define GED_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace Ui {
    class ged;
}

class ged : public QMainWindow
{
    Q_OBJECT

public:
    explicit ged(QWidget *parent = 0);
    ~ged();

    int eventcounter;

    int currentrow;

private:
    Ui::ged *ui;

public slots:
    void checkchange();
    void createnew();
    void deletecurrent();
    void checkout();
};

#endif // GED_H
