#include "GuiUpdater.h"

#include <QtGuiSettings.h>

GuiUpdater *GuiUpdater::instance = NULL;

GuiUpdater::GuiUpdater(QObject *parent) {
    startSpecificTimer();
}

void GuiUpdater::Destroy() {
    if (instance != NULL)
        delete instance;
    instance = NULL;
}

GuiUpdater *GuiUpdater::Instance() {
    if (instance == NULL) {
        instance = new GuiUpdater();
    }
    
    return instance;
}

void GuiUpdater::startSpecificTimer(int newTimerTick) {
    if (newTimerTick == -1) {
        int value = SETTINGS->getRefreshRate();
        startTimer(1000 / value);
    } else {
        startTimer(newTimerTick);
    }
    killTimerAtNextTick = false;
}


void GuiUpdater::resetTimer(int newTimerTick) {
    killTimerAtNextTick = true;
    timerTick = 1000 / newTimerTick;
}

void GuiUpdater::timerEvent(QTimerEvent *event) {
    if (killTimerAtNextTick) {
        killTimer(event->timerId());
        startSpecificTimer(timerTick);
    }
    newPlayingState = DBAPI->get_output()->state();
    if (newPlayingState != oldPlayingState)
    {
        if (newPlayingState == OUTPUT_STATE_STOPPED)
            emit GuiUpdater::Instance()->isPlaying(false);
        else
            emit GuiUpdater::Instance()->isPlaying(true);
    }
    oldPlayingState = newPlayingState;
    emit GuiUpdater::Instance()->frameUpdate();
}
