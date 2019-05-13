// Fyleria Engine
// Copyright © 2016 Go Go Gecko Productions

// External includes
#include <QtWidgets/QApplication>
#include <QtWebEngineWidgets/QWebEngineView>

namespace Gecko
{

int StartApplication(int argc, char** argv, const char* sUrl, const char* sTitle, int iWidth, int iHeight)
{
    // Set attributes
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // Create application
    QApplication app(argc, argv);

    // Create view
    QWebEngineView view;
    view.setUrl(QUrl(sUrl));
    view.resize(iWidth, iHeight);
    view.show();

    // Enter application main loop
    return app.exec();
}

};
