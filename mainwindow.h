#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineProfile>
#include <QTimer>
#include <QEventLoop>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#include <QWebEngineDownloadItem>
#include <QDir>
#include <QFormLayout>
#include <QLineEdit>
#include <QSettings>
#include <QAuthenticator>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QNetworkReply>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Wait(int sec);
    bool SaveHtml();
    QVariant InsertJavaScript(QWebEngineView *view, QString script);
    QString Encrypt(QString text);
    QString Decrypt(QString text);

private slots:
    void Process_Find();
    void SaveTorrent(int row);
    void StartDownload(QWebEngineDownloadItem *down);
    void Show_Options();
    void Save_Options();
    void Authentication(QUrl url,QAuthenticator *auth);
    void Authentication(QNetworkReply *reply,QAuthenticator *auth);
    void SendRequestToruTorrent(QString filename = 0);
    void Import();
    void Export();
    void UpdateDownCount();
    void About();
    void Load(int progress);

signals:
    void finished();

private:
    Ui::MainWindow *ui;
    QWebEngineView *web;
    QWebEngineView *rt;
    QEventLoop loop;
    QTimer timer;
    QTimer timer2;
    QString m_Filename;
};

#endif // MAINWINDOW_H
