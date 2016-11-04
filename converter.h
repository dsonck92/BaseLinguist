#ifndef CONVERTER_H
#define CONVERTER_H

#include <QDialog>

namespace Ui {
class Converter;
}

class Converter : public QDialog
{
    Q_OBJECT

    QStringList Hexits;
    QStringList Opers;

public:
    explicit Converter(QWidget *parent = 0);
    ~Converter();

public slots:
    void reconvert(int input);

private:
    Ui::Converter *ui;
};

#endif // CONVERTER_H
