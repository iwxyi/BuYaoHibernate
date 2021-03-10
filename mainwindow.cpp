#include <QMenu>
#include <QAction>
#include <QCloseEvent>
#include <windows.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ::SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);

    QSystemTrayIcon* tray = new QSystemTrayIcon(this);
    tray->setIcon(QIcon(":/icons/hibernate"));
    QObject::connect(tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(showTrayMenu(QSystemTrayIcon::ActivationReason)));
    tray->setToolTip("不要休眠：关闭本程序前保持设备不会休眠");
    tray->show();

    menu = new QMenu(this);
    QAction* quitAction = new QAction("退出", this);
    menu->addAction(quitAction);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    tray->setContextMenu(menu);

    tray->showMessage("不要休眠", "在关闭本程序前，电脑不会自动休眠", QIcon(":/icons/hibernate"), 3000);

    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    hide();
    e->ignore();
}

void MainWindow::showTrayMenu(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
    {
        if (this->isHidden())
            this->showNormal();
        else
            this->hide();
    }
}

