#pragma once
#include "AlbumCover.h"
#include <Arduino_JSON.h>


struct Track {
public:
    ~Track() {
        delete AlbumCoverImg;
    }

public:
    /**
     * Convert json to the Track object
     * @param jsonString raw json
     * @return Track pointer
     */
    static Track* fromJson(const String& jsonString);

private:
    /**
     * Change height ONLY of the YTPlayer album cover.
     * Bad implementation. Never use this shit in other projects
     * @param url URL on the image
     * @param height Set new height
     * @return URL with new height
     */
    static String changeUrlImgHeight(String url, int height);

public:
    String ArtistName;
    String TrackName;
    String AlbumName;
    AlbumCover* AlbumCoverImg;
};
