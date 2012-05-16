#ifndef WINDOWTITLEREADER_H
#define WINDOWTITLEREADER_H
#include <QtCore>
#include "windowinfo.h"
#ifdef Q_WS_WIN
#include "win.h"
#endif

#ifdef Q_WS_MACX
#include "mac.h"
#endif

#ifdef Q_WS_X11
#include "linux_x11.h"
#endif

class WindowTitleReader : public QObject
{
    Q_OBJECT
public:
    WindowTitleReader();
    ~WindowTitleReader();
    QString qstrMessage;

private:
    QTimer* timer;
    QList<WindowInfo> m_activeWindows;
    int* m_pid;
    QString* m_processName;

private slots:
    void getWindowTitle();
};

#endif // WINDOWTITLEREADER_H
