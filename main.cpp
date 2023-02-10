#include "mainwindow.hpp"

#include "trayicon.hpp"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QTranslator>
QString readfromjson();
QTranslator* translator = nullptr; // 设置全局变量为了热切换功能

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    // 设置组织名和域名
    a.setOrganizationName("database_gui");
    a.setOrganizationDomain("https://github.com/txt1994/mydatebase_client");
    a.setApplicationName("DataBase_GUI");
    a.setApplicationVersion("0.1");
    a.setQuitOnLastWindowClosed(false);

    // 国际化
    translator = new QTranslator;
    translator->load(readfromjson(), ":/locales", "", ".qm");
    a.installTranslator(translator);

    // 设置系统托盘图标
    try {
        if (!QSystemTrayIcon::isSystemTrayAvailable()) // 判断系统托管图标是否可用
            throw std::runtime_error(a.translate("Main", "Your system needs to support tray icon.")
                                         .toUtf8()
                                         .toStdString());
        TrayIcon t(this);
        t.show();

        MainWindow w;
        w.show();
        return a.exec();
    } catch (const std::exception& e) {
        QMessageBox::critical(nullptr, QApplication::applicationName(), e.what());
        return 1;
    }
}

QString readfromjson() {

    QFile file(":/locales/settings.json");
    QJsonParseError err;
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开json文件!";
        return {};
    } else {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &err);
        if (err.error != QJsonParseError::NoError) {
            qDebug() << "json 格式错误";
            return {};
        }
        QJsonObject obj = doc.object();
        return obj.value("language").toString();
    }
    file.close();
}
