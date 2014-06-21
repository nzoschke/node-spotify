#ifndef _SPOTIFY_H
#define _SPOTIFY_H

#include "SpotifyOptions.h"
#include "User.h"
#include "InboxPlaylist.h"

#include <libspotify/api.h>
#include <string>
#include <memory>

class Spotify {
public:
  Spotify(SpotifyOptions options);
  ~Spotify() {};
  void login(std::string user, std::string password, bool remeberedUser, bool withRemembered);
  void logout();
  std::string rememberedUser();
  std::shared_ptr<User> sessionUser();
  std::shared_ptr<Playlist> inboxPlaylist();
private:
  sp_session* session;
  sp_session* createSession(SpotifyOptions options);
};

#endif