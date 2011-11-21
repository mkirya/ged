#ifndef GED_H
#define GED_H

#include <QMainWindow>

namespace Ui {
    class ged;
}

class ged : public QMainWindow
{
    Q_OBJECT

public:
    explicit ged(QWidget *parent = 0);
    ~ged();

private:
    Ui::ged *ui;
};

#endif // GED_H
