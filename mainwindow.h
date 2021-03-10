#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent*e);

private slots:
    void showTrayMenu(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;

    QMenu* menu;
};
#endif // MAINWINDOW_H
