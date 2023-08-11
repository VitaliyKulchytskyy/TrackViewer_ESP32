#include "View/View.h"


void View::printHeader(ViewCallback &callback) {
    if(callback.isNewMessage()) {
        String getTime = callback.getMessage();
        const bool isSDInserted = callback.getPeriphery().IsSDInserted;
        lbHeader.setLabelText(getTime + (isSDInserted ? "" : " [SD]"));
    }

    scHeader.centerMessage();
}

void View::printTrackData(ViewCallback &callback) {
    if(callback.isNewMessage()) {
        String message = callback.getMessage();
        Track* trackData = Track::fromJson(message);
        String thisAlbumUrl = trackData->AlbumCoverImg->getJpegUrlOnImage();

        if(prevAlbumUrl != thisAlbumUrl) {
            const uint16_t center = (tft.width() >> 1) - (trackData->AlbumCoverImg->getImageWidth() >> 1);
            trackData->AlbumCoverImg->drawJpegImage(center, 30);
        }
        prevAlbumUrl = thisAlbumUrl;

        lbSongName.setLabelText(trackData->TrackName);
        lbArtistName.setLabelText(trackData->ArtistName);

        delete trackData;
    }

    scSongName.autoScroll();
    scArtistName.autoScroll();
}

void setupTFT() {
    tft.init();
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(2);
    tft.setSwapBytes(true);
    tft.setFreeFont(&FreeSansBold12pt7b);
}

void setupSprites() {
    /* ----- [A track name settings] ----- */
    spSongName.setFreeFont(&FreeSansBold12pt7b);
    spSongName.setColorDepth(8);
    spSongName.setTextColor(TFT_WHITE, TFT_BLACK);

    lbSongName.setPosition(tft.width(), 2);
    spLbSongName.setPosition(0, 265);
    spLbSongName.setSize(tft.width(), tft.fontHeight());
    scSongName.setMessageScrollDelay(40)
            .setSpaceBetweenRepeats(90);

//    lbSongName.setLabelText("To see the current track on the YTMusic type \"trackViewer.exe -r\" in a terminal");

    /* ----- [An artist name settings] ----- */
    spArtistName.setFreeFont(&FreeSansBold9pt7b);
    spArtistName.setColorDepth(8);
    spArtistName.setTextColor(TFT_WHITE, TFT_BLACK);

    lbArtistName.setPosition(tft.width(), 2);
    spLbArtistName.setPosition(0, 295);
    spLbArtistName.setSize(tft.width(), tft.fontHeight());
    scArtistName.setMessageScrollDelay(50)
                .setSpaceBetweenRepeats(90);

//    lbArtistName.setLabelText("By Karlenko");

    /* ----- [The header label settings] ----- */
    spHeader.setFreeFont();
    spHeader.setColorDepth(8);
    spHeader.setTextColor(TFT_WHITE, TFT_BLACK);

    lbHeader.setPosition(tft.width(), 2);
    spLbHeader.setPosition(0, 6);
    spLbHeader.setSize(tft.width(), 9);
    scHeader.setMessageScrollDelay(50)
            .setSpaceBetweenRepeats(90);
}

void View::setupView() {
    setupTFT();
    setupSprites();
}