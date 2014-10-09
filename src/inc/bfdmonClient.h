#ifndef BFDMON_CLIENT_H
#define BFDMON_CLIENT_H

#include "bfd.h"

struct Session_ {
    struct Session_ *next;
    bfdSession bfd;
};
typedef struct Session_ Session;

typedef enum BfdMonLogLvl_ {
    BFDMON_LOG_DEBUG,
    BFDMON_LOG_INFO,
    BFDMON_LOG_WARN,
    BFDMON_LOG_ERR
} BfdMonLogLvl;

/* User of library must provide the bfdmonClientLog() function. */
extern void bfdmonClientLog(BfdMonLogLvl lvl, const char *file, int line,
                            const char *fmt, ...);

#define bfdmonClientDebug(fmt, args...) \
    bfdmonClientLog(BFDMON_LOG_DEBUG, __FILE__, __LINE__, fmt, ##args)

#define bfdmonClientInfo(fmt, args...) \
    bfdmonClientLog(BFDMON_LOG_INFO, __FILE__, __LINE__, fmt, ##args)

#define bfdmonClientWarn(fmt, args...) \
    bfdmonClientLog(BFDMON_LOG_WARN, __FILE__, __LINE__, fmt, ##args)

#define bfdmonClientErr(fmt, args...) \
    bfdmonClientLog(BFDMON_LOG_ERR, __FILE__, __LINE__, fmt, ##args)

extern const char *bfdmonClientLogLvlStr(BfdMonLogLvl lvl);

extern int bfdmonClient_init(const char *monitor_server);
extern void bfdmonClient_SubscribeSession(int sock, bfdSession *sn);
extern void bfdmonClient_UnsubscribeSession(int sock, bfdSession *sn);

#endif  /* BFDMON_CLIENT_H */
