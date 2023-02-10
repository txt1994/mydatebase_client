#ifndef TRAYICON_HPP
#define TRAYICON_HPP

#include <QMenu>
#include <QSystemTrayIcon>
class TrayIcon : public QSystemTrayIcon {
    Q_OBJECT
public:
    explicit TrayIcon(QObject* parent = nullptr);
    QMenu menu;
private slots:
    void exitActionTriggered(); // 退出函数
    void trayIconActivated(ActivationReason reason);
};

#endif // TRAYICON_HPP
