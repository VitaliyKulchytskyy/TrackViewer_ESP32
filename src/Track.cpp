#include "Track.h"


Track* Track::fromJson(const String& jsonString) {
    JSONVar parsedRequest = JSON.parse(jsonString);

    if (JSON.typeof(parsedRequest) == "object") {
        auto pAlbumCover = new AlbumCover();
        String albumUrl = parsedRequest["thumb_url"];
        String albumUrlNewHeight = changeUrlImgHeight(albumUrl, 220);
        pAlbumCover->setJpegImage(albumUrlNewHeight);

        return new Track{parsedRequest["artist"],
                         parsedRequest["track_name"],
                         parsedRequest["album_name"],
                         pAlbumCover};
    } else {
        return nullptr;
    }
}

String Track::changeUrlImgHeight(String url, int height = 60) {
    if(height == 60)
        return url;

    String output = url;
    output.replace("60", std::to_string(height).c_str());
    return output;
}
