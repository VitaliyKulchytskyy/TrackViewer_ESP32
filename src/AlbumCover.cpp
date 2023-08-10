#include "AlbumCover.h"


void AlbumCover::drawJpegImage(int x, int y) {
    drawSdJpeg(COVER_FILENAME, x, y);
}

void AlbumCover::setJpegImage(String& url) {
    m_albumUrl = url;
    this->setupImageProperties(COVER_FILENAME);
}

int AlbumCover::getImageHeight() const {
    return this->m_imageHeight;
}

int AlbumCover::getImageWidth() const {
    return this->m_imageWidth;
}

void AlbumCover::jpegRender(int x, int y) {
    uint16_t *pImg;
    uint16_t mcu_w = JpegDec.MCUWidth;
    uint16_t mcu_h = JpegDec.MCUHeight;
    uint32_t max_x = JpegDec.width;
    uint32_t max_y = JpegDec.height;

    bool swapBytes = tft.getSwapBytes();
    tft.setSwapBytes(true);

    uint32_t min_w = jpg_min(mcu_w, max_x % mcu_w);
    uint32_t min_h = jpg_min(mcu_h, max_y % mcu_h);

    uint32_t win_w = mcu_w;
    uint32_t win_h = mcu_h;

    max_x += x;
    max_y += y;

    while (JpegDec.read()) {
        pImg = JpegDec.pImage;

        int mcu_x = JpegDec.MCUx * mcu_w + x;
        int mcu_y = JpegDec.MCUy * mcu_h + y;

        if (mcu_x + mcu_w <= max_x) win_w = mcu_w;
        else win_w = min_w;

        if (mcu_y + mcu_h <= max_y) win_h = mcu_h;
        else win_h = min_h;

        if (win_w != mcu_w) {
            uint16_t *cImg;
            int p = 0;
            cImg = pImg + win_w;
            for (int h = 1; h < win_h; h++) {
                p += mcu_w;
                for (int w = 0; w < win_w; w++) {
                    *cImg = *(pImg + w + p);
                    cImg++;
                }
            }
        }

        uint32_t mcu_pixels = win_w * win_h;

        if ((mcu_x + win_w) <= tft.width() && (mcu_y + win_h) <= tft.height())
            tft.pushImage(mcu_x, mcu_y, win_w, win_h, pImg);
        else if ((mcu_y + win_h) >= tft.height())
            JpegDec.abort();
    }

    tft.setSwapBytes(swapBytes);
}

void AlbumCover::drawSdJpeg(const char *filename, int x, int y) {
    auto jpegFile =  AlbumCover::getImageFile(COVER_FILENAME);
    if(jpegFile == nullptr)
        return;

    bool decoded = JpegDec.decodeSdFile(*jpegFile);

    if (decoded)
        jpegRender(x, y);

    jpegFile->close();
    delete jpegFile;
}

void AlbumCover::setupImageProperties(const char *filename) {
    download(this->m_albumUrl);

    auto jpegFile =  AlbumCover::getImageFile(COVER_FILENAME);
    if(jpegFile == nullptr)
        return;

    JpegDec.decodeSdFile(*jpegFile);
    this->m_imageWidth = JpegDec.width;
    this->m_imageHeight = JpegDec.height;

    jpegFile->close();
    delete jpegFile;
}

File* AlbumCover::getImageFile(const char *filename) {
    File* jpegFile = new File{SD.open(filename, FILE_READ)};

    if (!(*jpegFile))
        return nullptr;

    return jpegFile;
}

void AlbumCover::download(String& url) {
    File file = SD.open(COVER_FILENAME, FILE_WRITE);

    HTTPClient urlDownloadHandler;
    urlDownloadHandler.begin(url);
    int httpCode = urlDownloadHandler.GET();
    WiFiClient* stream = urlDownloadHandler.getStreamPtr();

    size_t downloaded_data_size = 0;
    const size_t imageSize = urlDownloadHandler.getSize();
    while (downloaded_data_size < imageSize) {
        size_t available_data_size = stream->available();
        if (available_data_size > 0) {
            auto audio_data = (uint8_t*)malloc(available_data_size);
            stream->readBytes(audio_data, available_data_size);
            file.write(audio_data, available_data_size);
            downloaded_data_size += available_data_size;
            free(audio_data);
        }
    }

    file.close();
}
