#import <UIKit/UIKit.h>

@interface KamCordIntObjC: NSObject
{
}

- (void) Init;
- (void) record;
- (void) stop;
- (void) pause;
- (void) resume;
- (void) show;
- (void) showWatchView;         // browse other peoples videos
- (void) setVideoTitle:(NSString *)title;
- (void) setVideoInfo:(NSString *)LevelName score:(unsigned int)iScore
        youtubeDesc:(NSString *)YTd youtubeTags:(NSString *)YTt
        facebookDesc:(NSString *)FBd;
- (void) showKamCordViewer;

@end


