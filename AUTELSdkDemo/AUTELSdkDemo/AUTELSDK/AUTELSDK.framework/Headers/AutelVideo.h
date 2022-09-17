#ifndef __AUTELVIDEO_H__
#define __AUTELVIDEO_H__

typedef struct{
    int x;  //起始点设置
    int y;
    int width;  //ViewPort长宽设置
    int height;
    void (*CallbackFunc)(void *data);
} AUTEL_VIDEO_CONF;

typedef struct{
    int state;   // 0: 正常； 其他值: 错误；
    int streamState;  // 流状态：0:准备好数据 其他值:未准备好；
    void *statedata;  //错误信息
    //正常：
    //-1, -1, NULL 初始配置成功；
    //0, 0, str  成功打开流，准备好数据；
    //1, 0, NULL 成功初始化Opengl，等待渲染；
    //1, 1, NULL destroy释放完成；

    //错误：
    //2, 0, NULL 启动解码线程失败（已有一个解码线程）
    //0, 1, err  打开网络流失败；
} OGCBDATA;

int AutelGetVersion(char *version);
int AutelVideoConfig(AUTEL_VIDEO_CONF *conf);
int AutelVideoStreamPlay(char *pUrl);

typedef enum {
    RATIO_16V9 = 0,
    RATIO_4V3,
    RATIO_3V2,
} HEIGHT_WIDTH_RATIO;

int AutelVideoRendeFrame(int ratio_type);
int AutelVideoDestroy(void);

typedef enum {
    BackgroundColor_Mono   = 0,
    BackgroundColor_Normal = 1,
    BackgroundColor_GRAY   = 2,
} BackgroundColor;

int AutelVideoSetBackgroundColor(BackgroundColor color);

int AutelVideoOverExposureDetection(int over_exposure_index);
int AutelVideoSetState(int state);

typedef struct AutelRtmp AutelRtmp;

AutelRtmp *AutelRtmp_Connect(const char *src_url, const char *rtmp_url);
int AutelRtmp_Disconnect(AutelRtmp *artmp);
int AutelRtmp_Start(AutelRtmp *artmp, int (*)(int, int, int), void (*)(int));
int AutelRtmp_Stop(AutelRtmp *artmp);

int AutelRtmp_WritePcmData(AutelRtmp *artmp, char *buf, int size);

typedef struct AutelMuxer AutelMuxer;

AutelMuxer *AutelMuxer_Open(const char *src_url, const char *file_path);
int AutelMuxer_Close(AutelMuxer *muxer);

typedef struct AutelSink AutelSink;

AutelSink *AutelSink_Open(const char *url);
int AutelSink_Close(AutelSink *asink);

typedef struct {
    int keyframe;
    int64_t pts;
    uint8_t *data;
    int size;
    int decode_only;
} AutelPkt;

int AutelSink_Read(AutelSink *asink, AutelPkt *pkt, int milliseconds);

typedef struct AutelVideoDec AutelVideoDec;

AutelVideoDec *AutelVideoDec_Create(void);
int AutelVideoDec_Destroy(AutelVideoDec *dec);
int AutelVideoDec_WriteFrame(AutelVideoDec *dec, uint8_t *buf, int size, int64_t pts, int keyframe, int decode_only);

typedef struct {
    int width;
    int height;

    long opaque;
    int64_t pts;

    int keyframe;

    uint8_t *data;
    int      size;
} AutelFrame;

int AutelVideoDec_ReadFrame(AutelVideoDec *dec, float ratio, AutelFrame *frame);

int AutelUtils_H264toJpeg(void *src, int src_size, void *dst, int dst_size, float scale);

#endif
