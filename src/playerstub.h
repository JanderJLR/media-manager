/*
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

#include <CommonAPI/CommonAPI.hpp>

#include "../interfaces/src-gen/v1_0/org/genivi/mediamanager/PlayerStubDefault.hpp"

#include "playerprovider.h"

namespace MM = v1_0::org::genivi::mediamanager;

/**
 * \brief Conversion layer between CommonAPI and internal API
 *
 * This class is undocumented, since it only provides a conversion
 * layer
 * between the auto-generated Franca functions (documented in the Player.fidl
 * file) and the Media Manager internal API, which is documented in the
 * PlayerProvider class
 *
 * @see PlayerProvider
 */
class PlayerStubImpl: public v1_0::org::genivi::mediamanager::PlayerStubDefault {

public:
    PlayerStubImpl (PlayerProvider *browser);

    void initializeDefaultValues();

    virtual void stop(MM::PlayerTypes::PlayerError& e);

    virtual void next(const std::shared_ptr<CommonAPI::ClientId> _client, nextReply_t _reply);
    virtual void openUri(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _uri, openUriReply_t _reply);
    virtual void enqueueUri(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _uri, enqueueUriReply_t _reply);
    virtual void dequeueIndex(const std::shared_ptr<CommonAPI::ClientId> _client, uint64_t _pos, dequeueIndexReply_t _reply);
    virtual void getCurrentPlayQueue(const std::shared_ptr<CommonAPI::ClientId> _client, getCurrentPlayQueueReply_t _reply);
    virtual void dequeueAll(const std::shared_ptr<CommonAPI::ClientId> _client, dequeueAllReply_t _reply);
    virtual void openPlaylist(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _uri, openPlaylistReply_t _reply);
    virtual void pause(const std::shared_ptr<CommonAPI::ClientId> _client, pauseReply_t _reply);
    virtual void play(const std::shared_ptr<CommonAPI::ClientId> _client, playReply_t _reply);
    virtual void playPause(const std::shared_ptr<CommonAPI::ClientId> _client, playPauseReply_t _reply);
    virtual void previous(const std::shared_ptr<CommonAPI::ClientId> _client, previousReply_t _reply);
    virtual void seek(const std::shared_ptr<CommonAPI::ClientId> _client, int64_t _pos, seekReply_t _reply);
    virtual void setPosition(const std::shared_ptr<CommonAPI::ClientId> _client, uint64_t _pos, setPositionReply_t _reply);

    virtual const uint64_t& getPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> _client);
    virtual const uint64_t& getDurationAttribute(const std::shared_ptr<CommonAPI::ClientId> _client);

    virtual void onRemoteRateAttributeChanged();
    virtual void onRemoteRepeatAttributeChanged();
    virtual void onRemoteShuffleAttributeChanged();

private:
    PlayerProvider *m_player;
    uint64_t pos;
    uint64_t duration;
    std::vector<std::string> m_generalFilter;
};

#endif /* PLAYERSTUB_H */
