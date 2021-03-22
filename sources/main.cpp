#include "mainwindow.h"
#include "guimediator.h"

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QCommandLineParser>
#include <QCommandLineOption>

#define ARG_KEY_TEXT "t"
#define ARG_KEY_FILE "f"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w;
    
    // Set argument parser options
    QScopedPointer<QCommandLineParser> parser(new QCommandLineParser());
    parser->setApplicationDescription("");
    parser->addHelpOption();
    QCommandLineOption defaultLeftPanelText(ARG_KEY_TEXT, QObject::tr("Specify default text for left panel."), "defaultLeftPanelText");
    parser->addOption(defaultLeftPanelText);
    QCommandLineOption defaultLeftPanelTextFile(ARG_KEY_FILE, QObject::tr("Specify file with default text for left panel."), "defaultLeftPanelTextFile");
    parser->addOption(defaultLeftPanelTextFile);
    
    // Parse arguments
    parser->process(a.arguments());
    if (parser->isSet(ARG_KEY_TEXT))
    {
        w = new MainWindow(parser->value(defaultLeftPanelText));
    }
    else if (parser->isSet(ARG_KEY_FILE))
    {
        QFile f(parser->value(defaultLeftPanelTextFile));
        w = new MainWindow(f);
    }
    else
    {
        w = new MainWindow();
    }
    
    GuiMediator mediator(w);
    w->show();
    return a.exec();
}
