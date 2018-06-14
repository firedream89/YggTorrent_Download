#include "mainwindow.h"
#include "ui_mainwindow.h"

#define VERSION "1.0"
#define PKEY "2 54 86 52 2 15 32 58 62 42 1 6 85 215 364 8"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    web = new QWebEngineView;

    QDir d;
    d.mkdir("download");
    test();
    QSettings settings("Yggtorrent-download");
    ui->eFind->setText(settings.value("Find").toString());

    connect(&timer,SIGNAL(timeout()),&loop,SLOT(quit()));
    connect(web,SIGNAL(loadFinished(bool)),&loop,SLOT(quit()));
    connect(ui->bFind,SIGNAL(clicked(bool)),this,SLOT(Process_Find()));
    connect(web->page()->profile(),SIGNAL(downloadRequested(QWebEngineDownloadItem*)),this,SLOT(StartDownload(QWebEngineDownloadItem*)));
    connect(ui->actionQuitter,SIGNAL(triggered(bool)),qApp,SLOT(quit()));
    connect(ui->actionOptions,SIGNAL(triggered(bool)),this,SLOT(Show_Options()));
    connect(web->page(),SIGNAL(authenticationRequired(QUrl,QAuthenticator*)),this,SLOT(Authentication(QUrl,QAuthenticator*)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete web;
    QDir d;
    d.setPath("download/");
    d.removeRecursively();
}

void MainWindow::test()
{

}

void MainWindow::Authentication(QUrl url, QAuthenticator *auth)
{
    QSettings settings("Yggtorrent-download");
    auth->setUser(settings.value("loginrt").toString());
    auth->setPassword(settings.value("mdprt").toString());
    qDebug() << "auth required";
}

void MainWindow::Authentication(QNetworkReply *reply, QAuthenticator *auth)
{
    QSettings settings("Yggtorrent-download");
    auth->setUser(settings.value("loginrt").toString());
    auth->setPassword(settings.value("mdprt").toString());
    qDebug() << "auth required Manager" << reply->errorString();
}

void MainWindow::Process_Find()
{

    QSettings settings("Yggtorrent-download");
    settings.setValue("Find",ui->eFind->text());

    ui->bFind->setEnabled(false);
    disconnect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
    while(ui->listTorrent->rowCount() > 0)
    {
        ui->listTorrent->removeRow(0);
    }
    QString text = ui->eFind->text();
    text.replace(" ","+");
    text = text.toLower();
    int resultCount(1),page(0);
    ui->result->setText("Chargement...");

    while(page < resultCount)
    {
        qDebug() << page << resultCount;
        web->load(QUrl("https://yggtorrent.is/engine/search?name=" + text + "&do=search&order=desc&sort=publish_date&page=" + QString::number(page)));
        Wait(30);
        SaveHtml();

        QFile f("web_Temp.txt");
        if(!f.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Error","Fail to open file web_Temp.txt");
        }
        QTextStream flux(&f);
        flux.setCodec(QTextCodec::codecForName("UTF-8"));

        while(!flux.atEnd())
        {
            QString tmp = flux.readLine();
            if(tmp.contains("<h2>Résultats de recherche <font style=\"float: right\">"))
            {
                ui->result->setText(tmp.split(">").at(2).split("<").at(0));
                resultCount = ui->result->text().split(" ").first().toInt();
            }
            if(tmp.contains("<a href=\"https://ww1.yggtorrent.is/torrent/"))
            {
                qApp->processEvents();
                tmp.replace("&eacute;","é");
                tmp.replace("&agrave;","à");
                tmp.replace("&egrave;","è");

                if(tmp.split(">").count() < 3 && tmp.split("\"").count() < 4)
                {
                    qDebug() << "error tmp 1";
                    ui->bFind->setEnabled(true);
                    connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
                    return;
                }
                if(tmp.split("\"").at(3).split("/").count() < 7)
                {
                    qDebug() << "error tmp 2";
                    ui->bFind->setEnabled(true);
                    connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
                    return;
                }
                int row = ui->listTorrent->rowCount();
                ui->listTorrent->insertRow(row);
                ui->listTorrent->setItem(row,0,new QTableWidgetItem(tmp.split(">").at(2)));
                ui->listTorrent->setItem(row,1,new QTableWidgetItem(tmp.split("\"").at(3).split("/").at(5)));
                ui->listTorrent->setItem(row,5,new QTableWidgetItem(tmp.split("\"").at(3)));

                while(!flux.atEnd() && !tmp.contains("<td><div class=\"hidden\">"))
                {
                    tmp = flux.readLine();
                }
                ui->listTorrent->setItem(row,2,new QTableWidgetItem(tmp.split(">").at(5).split("<").at(0)));
                tmp = flux.readLine();
                if(tmp.split(">").count() < 2)
                {
                    qDebug() << "error tmp 3" << tmp;
                    ui->bFind->setEnabled(true);
                    connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
                    return;
                }

                ui->listTorrent->setItem(row,3,new QTableWidgetItem(tmp.split(">").at(1).split("<").at(0)));
                tmp = flux.readLine();
                if(tmp.split(">").count() < 2)
                {
                    qDebug() << "error tmp 4" << tmp;
                    ui->bFind->setEnabled(true);
                    connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
                    return;
                }

                ui->listTorrent->setItem(row,4,new QTableWidgetItem(tmp.split(">").at(1).split("<").at(0)));
            }
        }
        ui->listTorrent->resizeColumnsToContents();
        page += 50;
    }
    ui->bFind->setEnabled(true);
    connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
}

void MainWindow::Wait(int sec)
{
    timer.start(sec*1000);
    loop.exec();
}

bool MainWindow::SaveHtml()
{
    bool end(false);
    QFile fichier("web_Temp.txt");
    fichier.resize(0);
    if(fichier.open(QIODevice::WriteOnly) == false) { return false; }

    QEventLoop loop;
    QTimer timer;
    connect(&timer,SIGNAL(timeout()),&loop,SLOT(quit()));
    connect(&timer,SIGNAL(timeout()),&timer,SLOT(stop()));
    web->page()->toHtml([&fichier,&end](const QString &result){ fichier.write(result.toUtf8()); end = true; });
    while(end == false)
    {
        timer.start(500);
        loop.exec();
    }
    fichier.close();
    return true;
}

void MainWindow::SaveTorrent(int row)
{
    QString link = ui->listTorrent->item(row,5)->text();

    ui->bFind->setEnabled(false);
    disconnect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));

    web->load(QUrl(link));
    Wait(30);
    SaveHtml();
    static int lvl = 0;

    QFile f("web_Temp.txt");
    if(!f.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"erreur","Ouverture du fichier web_Temp.txt échoué");
        ui->bFind->setEnabled(true);
        connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
        return;
    }
    QTextStream flux(&f);
    while(!flux.atEnd())
    {
        QString text = flux.readLine();

        if(text.split("\"").count() >= 4 && text.contains("<td colspan=\"5\"><a"))
        {
            if(text.contains("<td colspan=\"5\"><a onclick=") && lvl == 0)
            {
                QSettings settings("Yggtorrent-download");
                InsertJavaScript("document.getElementsByName('id')[1].value = '" + settings.value("Login").toString() + "';");
                InsertJavaScript("document.getElementsByName('pass')[0].value = '" + settings.value("pwd").toString() + "';");
                InsertJavaScript("document.getElementsByClassName('ico_unlock')[0].click()");
                Wait(5);
                qDebug() << "end Connexion";
                lvl++;
                SaveTorrent(row);
                ui->bFind->setEnabled(true);
                connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
                return;
            }
            else if(text.split("\"").at(3) == "window.panelConnect();")
            {
                qDebug() << "fail connexion" << lvl;
                lvl--;
                QMessageBox::warning(this,"erreur","Identifiant de connexion incorrect");
                ui->bFind->setEnabled(true);
                connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
                return;
            }
            qDebug() << text.split("\"").at(3);
            web->load(QUrl(text.split("\"").at(3)));
            Wait(30);
        }
    }
    ui->bFind->setEnabled(true);
    connect(ui->listTorrent,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SaveTorrent(int)));
}

void MainWindow::StartDownload(QWebEngineDownloadItem *down)
{
    m_Filename = down->path().split("/").last();
    QColor blue;
    blue.setBlue(240);
    ui->result->setText("Téléchargement démarré");
    connect(down,SIGNAL(finished()),this,SLOT(SendRequestToruTorrent()));
    down->setPath("download/"+ down->path().split("\\").last().split("/").last());
    down->accept();
    ui->result->setText("Téléchargement de " + down->path() + " terminé");
    ui->listTorrent->item(ui->listTorrent->currentRow(),0)->setBackgroundColor(blue);
}

QVariant MainWindow::InsertJavaScript(QString script)
{
    bool end(false);
    QVariant r;
    web->page()->runJavaScript(script, [&r,&end](const QVariant &result){ r = result; end = true; });
    while(end == false)
    {
        Wait(0.5);
    }
    return r;
}

void MainWindow::Show_Options()
{
    QSettings settings("Yggtorrent-download");
    QDialog *f = new QDialog(this);
    f->setObjectName("Options");
    connect(f,SIGNAL(rejected()),f,SLOT(deleteLater()));
    connect(f,SIGNAL(accepted()),f,SLOT(deleteLater()));
    QFormLayout *l = new QFormLayout(f);
    QLineEdit *login = new QLineEdit(settings.value("Login").toString());
    login->setObjectName("login");
    QLineEdit *pwd = new QLineEdit(settings.value("pwd").toString());
    pwd->setObjectName("pwd");
    pwd->setEchoMode(QLineEdit::Password);
    QLineEdit *ip = new QLineEdit(settings.value("ip").toString());
    ip->setObjectName("ip");
    QLineEdit *loginrt = new QLineEdit(settings.value("loginrt").toString());
    loginrt->setObjectName("loginrt");
    QLineEdit *mdprt = new QLineEdit(settings.value("mdprt").toString());
    mdprt->setObjectName("mdprt");
    mdprt->setEchoMode(QLineEdit::Password);
    QPushButton *b = new QPushButton;
    b->setText("Enregistré");
    connect(b,SIGNAL(clicked(bool)),this,SLOT(Save_Options()));
    QPushButton *b2 = new QPushButton;
    b2->setText("Importer");
    connect(b2,SIGNAL(clicked(bool)),this,SLOT(Import()));
    QPushButton *b3 = new QPushButton;
    b3->setText("Exporter");
    connect(b3,SIGNAL(clicked(bool)),this,SLOT(Export()));

    l->addRow("Login yggtorrent",login);
    l->addRow("Mot de passe yggtorrent",pwd);
    l->addRow("Ip rutorrent",ip);
    l->addRow("Login rutorrent",loginrt);
    l->addRow("Mot de passe rutorrent",mdprt);
    QHBoxLayout *lb = new QHBoxLayout(f);
    lb->addWidget(b);
    lb->addWidget(b2);
    lb->addWidget(b3);
    l->addRow(lb);

    f->exec();
}

void MainWindow::Save_Options()
{
    QDialog *f = this->findChild<QDialog*>("Options");
    if(f)
    {
        QSettings settings("Yggtorrent-download");
        settings.setValue("Login",f->findChild<QLineEdit*>("login")->text());
        settings.setValue("pwd",f->findChild<QLineEdit*>("pwd")->text());
        settings.setValue("ip",f->findChild<QLineEdit*>("ip")->text());
        settings.setValue("loginrt",f->findChild<QLineEdit*>("loginrt")->text());
        settings.setValue("mdprt",f->findChild<QLineEdit*>("mdprt")->text());

        f->close();
        f->deleteLater();
    }
}

void MainWindow::Import()
{
    QString link = QFileDialog::getOpenFileName(this,"Sélectionner le fichier à importer",qApp->applicationDirPath(),"*.yd");
    if(link.isEmpty())
        return;
    qDebug() << link;

    QFile f(link);
    if(!f.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"","Echec d'ouverture du fichier");
        return;
    }

    QTextStream flux(&f);
    QString var = Decrypt(flux.readAll());
    QSettings settings("Yggtorrent-download");
    if(var.split(";").count() != 5)
    {
        QMessageBox::warning(this,"","Echec de l'importation, le fichier est corrompu !");
        return;
    }
    settings.setValue("Login",var.split(";").at(0));
    settings.setValue("pwd",var.split(";").at(1));
    settings.setValue("ip",var.split(";").at(2));
    settings.setValue("loginrt",var.split(";").at(3));
    settings.setValue("mdprt",var.split(";").at(4));

    Show_Options();
}

void MainWindow::Export()
{
    QString link = QFileDialog::getSaveFileName(this,"Sélectionner l'emplacement ou exporter",qApp->applicationDirPath(),"*.yd");
    if(link.isEmpty())
        return;
    qDebug() << link;

    QFile f(link);
    f.resize(0);
    if(!f.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,"","Echec d'ouverture du fichier");
        return;
    }

    QTextStream flux(&f);

    QSettings settings("Yggtorrent-download");
    QString var = settings.value("Login").toString() + ";";
    var += settings.value("pwd").toString() + ";";
    var += settings.value("ip").toString() + ";";
    var += settings.value("loginrt").toString() + ";";
    var += settings.value("mdprt").toString();

    flux << Encrypt(var);
}

QString MainWindow::Encrypt(QString text)
{
    QString crypt;
    QStringList k = QString(PKEY).split(" ");
    int idk(0);
    for(int i = 0;i<text.count();i++)
    {
        if(idk == k.count())
        {
            idk = 0;
        }
        int t = text.at(i).unicode();
        t -= k.at(idk).toInt();
        if(t > 250)
        {
            t = t - 250;
        }
        else if(t < 0)
        {
            t = t + 250;
        }
        if(t == 34)//si '
        {
            t = 251;
        }
        else if(t == 39)//ou "
        {
            t = 252;
        }
        crypt += QChar(t).toLatin1();
        idk++;
    }
    return crypt;
}

QString MainWindow::Decrypt(QString text)
{
    QString decrypt;
    QStringList k = QString(PKEY).split(" ");
    int idk(0);
    for(int i = 0;i<text.count();i++)
    {
        if(idk == k.count())
        {
            idk = 0;
        }
        int t = text.at(i).unicode();
        if(t == 251)//retour a '
        {
            t = 34;
        }
        else if(t == 252)//retour a "
        {
            t = 39;
        }
        t += k.at(idk).toInt();
        if(t < 0)
        {
            t = t + 250;
        }
        else if(t > 250)
        {
            t = t - 250;
        }
        decrypt += QChar(t).toLatin1();
        idk++;
    }
    return decrypt;
}

void MainWindow::SendRequestToruTorrent(QString filename)
{
    QSettings settings("Yggtorrent-download");
    if(settings.value("ip").toString().isEmpty())
        return;

    if(filename.isEmpty())
        filename = m_Filename;

    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    multiPart->setBoundary("-----------------------------53711022811275");

    QHttpPart filePart;
    filePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"torrent_file[]\"; filename=\"" + filename + "\""));
    filePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/octet-stream"));

    QHttpPart textPart;
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"dir_edit\""));
    textPart.setBody("");

    QFile *file = new QFile("download/" + filename);
    file->open(QIODevice::ReadOnly);
    filePart.setBodyDevice(file);
    file->setParent(multiPart);

    multiPart->append(textPart);
    multiPart->append(filePart);

    QUrl url("http://" + settings.value("ip").toString() + "/rutorrent/php/addtorrent.php");
    QNetworkRequest request(url);

    QNetworkAccessManager *networkManager= new QNetworkAccessManager;
    connect(networkManager,SIGNAL(authenticationRequired(QNetworkReply*,QAuthenticator*)),this,SLOT(Authentication(QNetworkReply*,QAuthenticator*)));
    QNetworkReply *reply = networkManager->post(request, multiPart);
    multiPart->setParent(reply);

     connect(reply, SIGNAL(finished()),&loop,SLOT(quit()));
     loop.exec();
     if(reply->error() == QNetworkReply::NoError)
         ui->result->setText(filename + " ajouté au serveur avec succès !");
     else
        ui->result->setText(filename + " n'a pas été ajouté sur le serveur");
}
