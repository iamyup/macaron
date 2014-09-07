#include "KamCordInt.h"
#include "KamCord-objc.h"

KamCordIntObjC *g_pKamCordIntObjC=NULL;

void KamCordInt::init()
{
    if( g_pKamCordIntObjC )
        return;
    
    g_pKamCordIntObjC = [KamCordIntObjC alloc];
    [g_pKamCordIntObjC Init];
}

void KamCordInt::record()
{
    if( g_pKamCordIntObjC )
        [g_pKamCordIntObjC record];
}
void KamCordInt::stop()
{
    if( g_pKamCordIntObjC )
        [g_pKamCordIntObjC stop];
}
void KamCordInt::pause()
{
    if( g_pKamCordIntObjC )
        [g_pKamCordIntObjC pause];
}

void KamCordInt::resume()
{
    if( g_pKamCordIntObjC )
        [g_pKamCordIntObjC resume];
}

void KamCordInt::setVideoTitle(const char *str)
{
    NSString *nss = [NSString stringWithUTF8String:str];
    if( g_pKamCordIntObjC )
        [g_pKamCordIntObjC setVideoTitle:nss];
}

void KamCordInt::setVideoInfo(const char *strTitle, const char *strLevelName, unsigned int iScore,
    const char *strYoutubeDescription, const char *strYoutubeTags,
    const char *strFacebookDescription )
{
    setVideoTitle(strTitle);
    if( g_pKamCordIntObjC )
    {
        NSString *nssVideoName = [NSString stringWithUTF8String:strLevelName];
        NSString *nssYTD = [NSString stringWithUTF8String:strYoutubeDescription];
        NSString *nssYTT = [NSString stringWithUTF8String:strYoutubeTags];
        NSString *nssFBD = [NSString stringWithUTF8String:strFacebookDescription];
        
        [g_pKamCordIntObjC setVideoInfo:nssVideoName score:iScore
                youtubeDesc:nssYTD youtubeTags:nssYTT
                facebookDesc:nssFBD];
    }
}

void KamCordInt::showKamCordViewer()
{
    if( g_pKamCordIntObjC )
        [g_pKamCordIntObjC showKamCordViewer];
}
