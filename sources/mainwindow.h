#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDebug>

#include <QString>
#include <QFile>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QPushButton>
#include <QTextStream>

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(const QString& defaultText, QWidget *parent = nullptr);
    explicit MainWindow(QFile& defaultTextFile, QWidget *parent = nullptr);
    
    ~MainWindow();

signals:
    void SendLeftPanelText(const QString&);
    void UserAction();
    
public slots:
    void ReceiveRightPanelText(const QString&);
    
private:
    QLayout* LayoutInit();
    void InternalConnections();
    
    QTextEdit* m_leftDataPanel;
    QTextEdit* m_rightDataPanel;
    QPushButton* m_leftButton;
    QPushButton* m_rightButton;
    QGridLayout* m_layout;
    
};
#endif // MAINWINDOW_H
