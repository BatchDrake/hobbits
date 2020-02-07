#ifndef HEXSTRINGIMPORTER_H
#define HEXSTRINGIMPORTER_H

#include "bitcontainer.h"
#include <QDialog>

namespace Ui
{
class HexStringImporter;
}

class HexStringImporter : public QDialog
{
    Q_OBJECT

public:
    explicit HexStringImporter(QWidget *parent = nullptr);

    ~HexStringImporter();

    QSharedPointer<BitContainer> getContainer() const;

private slots:
    void on_te_hexString_textChanged();
    void on_pb_selectFile_pressed();
    void on_pb_submitInput_pressed();

private:
    Ui::HexStringImporter *ui;

    QSharedPointer<BitContainer> m_container;
};

#endif // HEXSTRINGIMPORTER_H
