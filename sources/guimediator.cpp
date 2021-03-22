#include "guimediator.h"
#include <QString>


GuiMediator::GuiMediator(MainWindow *gui, QObject *parent) : m_box(nullptr)
{
    /* INSERT YOUR CLASS CONNECTIION CODE HERE*/
	QObject::connect(gui, &MainWindow::SendLeftPanelText, gui, &MainWindow::ReceiveRightPanelText);
    QObject::connect(gui, &MainWindow::UserAction, gui, [=](){m_box = new QMessageBox(QMessageBox::Icon::Information, "Message", "User Action Handler"); m_box->show();});
}

GuiMediator::~GuiMediator()
{
    delete m_box;
}
