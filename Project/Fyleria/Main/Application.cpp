// Fyleria Engine
// Copyright © 2019 Go Go Gecko Productions

// External includes
#include <QtWidgets/QApplication>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEngineSettings>

// Internal includes
#include "Config/ConfigManager.h"
#include "Utility/Constants.h"

namespace Gecko
{

int StartApplication(int iArgCount, char** vArgList, const char* sUrl)
{
    // Create application
    QApplication app(iArgCount, vArgList);

    // Set attributes
    QCoreApplication::setApplicationName(APPLICATION_NAME_SHORT);
    QCoreApplication::setApplicationVersion(APPLICATION_VERSION);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::AutoLoadImages, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::JavascriptCanOpenWindows, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::JavascriptCanAccessClipboard, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::XSSAuditingEnabled, false);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::ErrorPageEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::PluginsEnabled, false);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::FullScreenSupportEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::ScreenCaptureEnabled, false);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::WebGLEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::Accelerated2dCanvasEnabled, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::AllowWindowActivationFromJavaScript, true);
    QWebEngineSettings::defaultSettings()->setAttribute(QWebEngineSettings::ShowScrollBars,
        ConfigManager::GetInstance()->GetEnableScrollbars());

    // Create view
    QWebEngineView view;

    // Set context menu policy
    if(ConfigManager::GetInstance()->GetEnableContextMenu())
    {
        view.setContextMenuPolicy(Qt::DefaultContextMenu);
    }
    else
    {
        view.setContextMenuPolicy(Qt::NoContextMenu);
    }

    // Set window state
    if(ConfigManager::GetInstance()->GetStartFullscreen())
    {
        view.setWindowState(Qt::WindowFullScreen);
    }
    else if(ConfigManager::GetInstance()->GetStartMaximized())
    {
        view.setWindowState(Qt::WindowMaximized);
    }

    // Resize window
    view.resize(
        ConfigManager::GetInstance()->GetScreenWidth(),
        ConfigManager::GetInstance()->GetScreenHeight());

    // Set url
    view.setUrl(QUrl(sUrl));

    // Show window
    view.show();

    // Enter application main loop
    return app.exec();
}

};
