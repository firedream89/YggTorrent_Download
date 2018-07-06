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
    bool SaveText(QWebEngineView *view);
    QVariant InsertJavaScript(QWebEngineView *view, QString script);
    QString Encrypt(QString text);
    QString Decrypt(QString text);

private:
    Ui::MainWindow *ui;
    QWebEngineView *web;
    QWebEngineView *rt;
    QEventLoop loop;
    QTimer timer;
    QTimer timer2;
    QString m_Filename, darkStyle;

private slots:
    void Process_Find(QString link = 0);
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
    void Top400();

    void LightStyle(){
        this->setStyleSheet("");
        QSettings s("Yggtorrent-download");
        s.setValue("style",1);
    }
    void DarkStyle(){
        this->setStyleSheet(darkStyle);
        QSettings s("Yggtorrent-download");
        s.setValue("style",0);
    }

signals:
    void finished();

};

#endif // MAINWINDOW_H
