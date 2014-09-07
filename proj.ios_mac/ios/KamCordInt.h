#ifndef __KamCordInt_H__
#define __KamCordInt_H__

#include <stddef.h>

class KamCordInt
{
public:
    void init();
    void record();
    void stop();
    void pause();
    void resume();
    void setVideoTitle(const char *str);
    void setVideoInfo(const char *strTitle, const char *strLevelName, unsigned int iScore,
        const char *strYoutubeDescription, const char *strYoutubeTags,
        const char *strFacebookDescription );
    void showKamCordViewer();
};

#endif//__KamCordInt_H__
