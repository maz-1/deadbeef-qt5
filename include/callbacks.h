#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "config.h"
#include "DBApiWrapper.h"
#include <QIcon>

#ifdef ARTWORK_ENABLED

#include <QImage>
typedef void (*DB_coverart_t)(const char *fname, const char *artist, const char *album, void *user_data);
#define CALLBACK(x) ((DB_coverart_t)(x))

extern QImage *scale(const char *fname);
extern void cover_avail_callback(const char *fname, const char *artist, const char *album, void *user_data);

#endif

void conf_get_str(const char *key, char *value, int len, const char *def);
void dsp_conf_get_str(const char *key, char *value, int len, const char *def);

QIcon getStockIcon(QWidget *widget, const QString &freedesktop_name, int fallback);

void loadPlaylist(const QString &fname);
void loadAudioCD();

#endif //CALLBACKS_H
