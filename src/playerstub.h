/**
  * Copyright (C) 2014, Jaguar Land Rover
  *
  * Author: Jonatan Palsson <jonatan.palsson@pelagicore.com>
  *
  * This file is part of the GENIVI Media Manager Proof-of-Concept
  * For further information, see http://genivi.org/
  *
  * This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/.
  */

#ifndef PLAYERSTUB_H
#define PLAYERSTUB_H

#include <CommonAPI/CommonAPI.h>

#include "../src-gen/org/genivi/MediaManager/PlayerStubDefault.h"

#include "playerprovider.h"

namespace MM = org::genivi::MediaManager;

class PlayerStubImpl: public org::genivi::MediaManager::PlayerStubDefault {

public:
    PlayerStubImpl (PlayerProvider *browser);

    void initializeDefaultValues();

    virtual void next(MM::Player::PlayerError& e);
    virtual void openUri(std::string uri, MM::Player::PlayerError& e);
    virtual void openPlaylist(std::string uri, MM::Player::PlayerError& e);
    virtual void pause(MM::Player::PlayerError& e);
    virtual void play(MM::Player::PlayerError& e);
    virtual void playPause(MM::Player::PlayerError& e);
    virtual void previous(MM::Player::PlayerError& e);
    virtual void seek(int64_t pos, MM::Player::PlayerError& e);
    virtual void setPosition(uint64_t pos, MM::Player::PlayerError& e);
    virtual void stop(MM::Player::PlayerError& e);

    virtual void enqueueUri(std::string uri, MM::Player::PlayerError& e);
    virtual void dequeueIndex(uint64_t pos, MM::Player::PlayerError& e);
    virtual void dequeueAll(MM::Player::PlayerError& e);
    virtual void getCurrentPlayQueue(std::string& playQueue, MM::Player::PlayerError& e);

    const uint64_t& getPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> clientId);

    virtual void onRemoteRateAttributeChanged();
    virtual void onRemoteRepeatAttributeChanged();
    virtual void onRemoteShuffleAttributeChanged();

private:
    PlayerProvider *m_player;
    uint64_t pos;
};

#endif /* PLAYERSTUB_H */
