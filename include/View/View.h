#pragma once
#include "Track.h"
#include "ViewCallback.h"
#include "utils/global_tft.h"
#include "TFTExtention/Label.h"
#include "TFTExtention/MessageSprite.h"
#include "TFTExtention/ScrollHandler.h"


namespace View {
    void printHeader(ViewCallback &);
    void printTrackData(ViewCallback &);
    void setupView();
}

/*
 * Notation:
 * sp - Sprite
 * lb - Label
 * sc - Scroll
 */
namespace {
    TFT_eSprite spSongName = TFT_eSprite(&tft);
    Label lbSongName;
    MessageSprite spLbSongName(&spSongName, &lbSongName);
    ScrollHandler scSongName(&spLbSongName);

    TFT_eSprite spArtistName = TFT_eSprite(&tft);
    Label lbArtistName;
    MessageSprite spLbArtistName(&spArtistName, &lbArtistName);
    ScrollHandler scArtistName(&spLbArtistName);

    TFT_eSprite spHeader = TFT_eSprite(&tft);
    Label lbHeader;
    MessageSprite spLbHeader(&spHeader, &lbHeader);
    ScrollHandler scHeader(&spLbHeader);;
}