#ifndef INTERFACEPREFERENCESWIDGET_H
#define INTERFACEPREFERENCESWIDGET_H

#include <QWidget>

namespace Ui {
    class InterfacePreferencesWidget;
}

class InterfacePreferencesWidget : public QWidget {
    Q_OBJECT
public:
    InterfacePreferencesWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
private:
    Ui::InterfacePreferencesWidget *ui;
    void loadSettings();
    void createConnections();
protected:
    void changeEvent(QEvent *e);
private Q_SLOTS: 
    void saveTrayIconHidden(bool);
    void saveCloseOnMinimize(bool);
    void saveTrackInfoOnSwitch(bool);
    void saveTitlePlaying();
    void saveTitleStopped();
    void saveRefreshRate(int);
    void saveTrayMessageFormat();
    void saveGuiPlugin(const QString &);
    void saveTrayIconTheme(const QString &);
    
    void saveDetectCP1251(bool);
    void saveDetectCP936(bool);
    void saveDetectShiftJIS(bool);
Q_SIGNALS:
    void setTrayIconHidden(bool);
    void setTrayIconTheme(const QString &);
    void setCloseOnMinimize(bool);
    void titlePlayingChanged();
    void titleStoppedChanged();
};

#endif // INTERFACEPREFERENCESWIDGET_H
