#ifndef GUIMEDIATOR_H
#define GUIMEDIATOR_H

#include <QObject>
#include <QMessageBox>

#include "mainwindow.h"


class GuiMediator : public QObject
{
    Q_OBJECT
public:
    explicit GuiMediator(MainWindow* gui, QObject *parent = nullptr);
    ~GuiMediator();
signals:
    
private:
    QMessageBox* m_box;
};

#endif // GUIMEDIATOR_H
