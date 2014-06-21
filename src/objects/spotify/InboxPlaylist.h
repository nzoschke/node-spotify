#ifndef _INBOX_PLAYLIST_H
#define _INBOX_PLAYLIST_H

#include "Playlist.h"

class InboxPlaylist : public Playlist {
public:
  InboxPlaylist(sp_playlist* _playlist) : Playlist(_playlist) {};
  std::string name() { return "Inbox"; }
};

#endif