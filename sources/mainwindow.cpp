#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_layout = dynamic_cast<QGridLayout*>(LayoutInit());
    setLayout(m_layout);
    InternalConnections();    
}

MainWindow::MainWindow(const QString& defaultText, QWidget *parent) : MainWindow()
{
    qDebug() << "Default tetx:" << defaultText;
    m_leftDataPanel->setText(defaultText);    
}

MainWindow::MainWindow(QFile& file, QWidget *parent) : MainWindow()
{
    qDebug() << "Default filename: " << file.fileName();
    if (file.exists())
    {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qWarning() << "Cannot open specified file!";
            return;        
        }
        QTextStream in(&file);
        QString text = in.readAll();
        m_leftDataPanel->setText(text);
        file.close();
    }
    else
    {
        qWarning() << "Specified file is not readable!";
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::ReceiveRightPanelText(const QString& text)
{
    m_rightDataPanel->setText(text);
}

QLayout *MainWindow::LayoutInit()
{
    m_leftDataPanel = new QTextEdit();
    m_rightDataPanel = new QTextEdit();
    m_leftButton = new QPushButton("SendLeftPanelText");
    m_rightButton = new QPushButton("UserAction");
    QGridLayout* l = new QGridLayout();
    l->addWidget(m_leftDataPanel, 0, 0, 2, 2);
    l->addWidget(m_rightDataPanel, 0, 2, 2, 2);
    l->addWidget(m_leftButton, 2, 0, 1, 1);
    l->addWidget(m_rightButton, 2, 3, 1, 1);
    
    return l;
}

void MainWindow::InternalConnections()
{
    connect(m_leftButton, &QPushButton::clicked, this, [=](){SendLeftPanelText(m_leftDataPanel->toPlainText());});
    connect(m_rightButton, SIGNAL(clicked(bool)), this, SIGNAL(UserAction()));
}

