#include "trayicon.hpp"

#include <QApplication>
extern MainWindow* w;
TrayIcon::TrayIcon(QObject* parent) : QSystemTrayIcon(parent) {

    QIcon exitIcon(":/images/images/exit.bmp");
    QIcon appicon(":/icons/database.png");
    QIcon appmaskicon(":/icons/database2.png");
    appmaskicon.setIsMask(true);

    // 系统判断，设置托盘
    if (QSysInfo::productType() == "osx" || QSysInfo::productType() == "macos")
        setIcon(appicon);
    else
        setIcon(appmaskicon);

    QAction* action = menu.addAction(exitIcon, tr("Exit")); // 添加退出动作

    connect(action, &QAction::triggered, this, &TrayIcon::exitActionTriggered);
    setContextMenu(&menu); // 设置菜单系统托盘图标的上下文菜单
    setToolTip(QApplication::applicationName());

    connect(this, &QSystemTrayIcon::activated, this, &TrayIcon::trayIconActivated);
}

void TrayIcon::exitActionTriggered() {
    QApplication::exit();
}

void TrayIcon::trayIconActivated(QSystemTrayIcon::ActivationReason reason) {
    if (reason == DoubleClick) {
        w->show();
    }
}
