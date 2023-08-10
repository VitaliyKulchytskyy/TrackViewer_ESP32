#pragma once
#include "utils/global_tft.h"
#include <JPEGDecoder.h>
#include "HTTPClient.h"
#include <WiFi.h>
#include "SD.h"
#include <FS.h>

/// Path to the image on the SD
#define COVER_FILENAME "/cover.jpg"


class AlbumCover {
public:
    /**
     * Draw the jpeg-format image at the X-pos and Y-pos
     * @param x X-pos of the image
     * @param y Y-pos of the image
     */
    void drawJpegImage(int x, int y);

    /**
     * Set the jpeg-format image from a URL
     * @param url URL on an image
     * @param height Height of the image (only for images from YTPlayer)
     */
    void setJpegImage(String& url);

    /**
     * Get the height of the image
     * @return Image height
     */
    int getImageHeight() const;

    /**
     * Get the width of the image
     * @return Image width
     */
    int getImageWidth() const;

private:
    /**
     * Render the decoded jpeg-format image
     * @param x X-pos of the image
     * @param y Y-pos of the image
     */
    void jpegRender(int x, int y);

    /**
     * Decode jpeg-format image and draw it
     * @param filename Path to the image on the SD
     * @param x X-pos of the image
     * @param y Y-pos of the image
     */
    void drawSdJpeg(const char *filename, int x, int y);

    /**
     * Set the height and width of the image
     * @param filename Path to the image on the SD
     */
    void setupImageProperties(const char *filename);

public:
    /**
     * Get the pointer on the file of the image
     * @param filename Path to the image on the SD
     * @return File pointer
     */
    static File* getImageFile(const char *filename);

    /**
     * Download the image from the URL
     * @param url URL on the image
     */
    static void download(String& url);

private:
    String m_albumUrl;
    int m_imageHeight{};
    int m_imageWidth{};
};
