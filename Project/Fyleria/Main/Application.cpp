// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

// External includes
#include <QtWidgets/QApplication>
#include <QtWebEngineWidgets/QWebEngineView>

// Internal includes
#include "Config/ConfigManager.h"

namespace Gecko
{

int StartApplication(int argc, char** argv)
{
    // Set attributes
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Create application
    QApplication app(argc, argv);

    // Create view
    QWebEngineView view;
    view.setUrl(QUrl(ConfigManager::GetInstance()->GetRestUrl().c_str()));
    view.resize(ConfigManager::GetInstance()->GetScreenWidth(), ConfigManager::GetInstance()->GetScreenHeight());
    view.show();

    // Enter application main loop
    return app.exec();
}

};
