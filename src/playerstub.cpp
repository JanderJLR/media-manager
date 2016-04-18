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

#include "playerstub.h"

namespace MM = v1_0::org::genivi::mediamanager;

PlayerStubImpl::PlayerStubImpl (PlayerProvider *player) {
    m_player = player;
    m_player->stub = this;

    initializeDefaultValues();

    m_generalFilter.push_back("Path");
    m_generalFilter.push_back("Parent");
    m_generalFilter.push_back("Type");
    m_generalFilter.push_back("TypeEx");
    m_generalFilter.push_back("DisplayName");
    m_generalFilter.push_back("ChildCount");
    m_generalFilter.push_back("Artists");
    m_generalFilter.push_back("Artist");
    m_generalFilter.push_back("Searchable");
    m_generalFilter.push_back("MIMEType");
    m_generalFilter.push_back("Album");
    m_generalFilter.push_back("URI");
    m_generalFilter.push_back("Genre");
    m_generalFilter.push_back("Size");
    m_generalFilter.push_back("TrackNumber");
    m_generalFilter.push_back("Bitrate");
    m_generalFilter.push_back("SampleRate");
    m_generalFilter.push_back("Duration");
    m_generalFilter.push_back("AlbumArtURL");
}

void PlayerStubImpl::initializeDefaultValues() {
    /* Mute */
    if (m_player->m_muted)
        trySetMuteAttribute (MM::PlayerTypes::MuteStatus::MUTED);
    else
        trySetMuteAttribute (MM::PlayerTypes::MuteStatus::UNMUTED);

    /* Shuffle */
    if (m_player->m_shuffle)
        trySetShuffleAttribute(MM::PlayerTypes::ShuffleStatus::SHUFFLE);
    else
       trySetShuffleAttribute(MM::PlayerTypes::ShuffleStatus::UNSHUFFLE);

    /* Repeat */
    trySetRepeatAttribute (m_player->m_repeat);

    /* Rate */
    trySetRateAttribute(m_player->m_playrate);

    /* Volume */
    trySetVolumeAttribute (m_player->m_volume);

    /* Go next */
    trySetCanGoNextAttribute(false);

    /* Go previous */
    trySetCanGoPreviousAttribute(false);

    /* Can Pause */
    trySetCanPauseAttribute (false);

    /* Can Play */
    trySetCanPlayAttribute (false);

    /* Can Seek */
    trySetCanSeekAttribute (false);

    /* Current track */
    trySetCurrentTrackAttribute (m_player->playQueuePosition);

    /* Playback status */
    if (m_player->isPlaying)
        trySetPlaybackStatusAttribute (MM::PlayerTypes::PlaybackStatus::PLAYING);
    else
        trySetPlaybackStatusAttribute (MM::PlayerTypes::PlaybackStatus::PAUSED);

    /* Play position */
    trySetPositionAttribute (UINT64_MAX - 1);
}

void PlayerStubImpl::next(const std::shared_ptr<CommonAPI::ClientId> _client, nextReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->next(&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::openUri(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _uri, openUriReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->openURI(_uri, &error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::openPlaylist(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _uri, openPlaylistReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->openPlaylist(_uri, &error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::pause(const std::shared_ptr<CommonAPI::ClientId> _client, pauseReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->pause(&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::play(const std::shared_ptr<CommonAPI::ClientId> _client, playReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->play(&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::playPause(const std::shared_ptr<CommonAPI::ClientId> _client, playPauseReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->playPause(&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::previous(const std::shared_ptr<CommonAPI::ClientId> _client, previousReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->previous(&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::seek(const std::shared_ptr<CommonAPI::ClientId> _client, int64_t _pos, seekReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->seek(_pos, &error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::setPosition(const std::shared_ptr<CommonAPI::ClientId> _client, uint64_t _pos, setPositionReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->setPosition(_pos, &error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::stop(MM::PlayerTypes::PlayerError& e){
    MmError *error = new MmError("");
    m_player->stop(&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }
}

void PlayerStubImpl::enqueueUri(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _uri, enqueueUriReply_t _reply) {

    MmError *error = new MmError();
    MM::PlayerTypes::PlayerError e;

    m_player->enqueueUri (_uri, &error);


    if (error) {
        std::cout << "Error in " << __FUNCTION__ << " " << error->message << std::endl;
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::dequeueIndex(const std::shared_ptr<CommonAPI::ClientId> _client, uint64_t _pos, dequeueIndexReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->dequeueIndex (_pos, &error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::dequeueAll(const std::shared_ptr<CommonAPI::ClientId> _client, dequeueAllReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    m_player->dequeueAll (&error);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(e);
}

void PlayerStubImpl::getCurrentPlayQueue(const std::shared_ptr<CommonAPI::ClientId> _client, getCurrentPlayQueueReply_t _reply) {

    MmError *error = new MmError("");
    MM::PlayerTypes::PlayerError e;

    json_t* queue;
    m_player->getCurrentPlayQueue (&queue, &error);

    MM::MediaTypes::ResultMapList playQueue;
    Common::resultMapListToCAPIResultMapList(queue, playQueue, m_generalFilter);

    if (error) {
        e = MM::PlayerTypes::PlayerError::BACKEND_UNREACHABLE;
        free (error);
    }

    _reply(playQueue, e);
}

const uint64_t& PlayerStubImpl::getPositionAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
    pos = m_player->getPosition(NULL);
    return pos;
}

const uint64_t& PlayerStubImpl::getDurationAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
    duration = m_player->getDuration(NULL);
    return duration;
}

void PlayerStubImpl::onRemoteRateAttributeChanged() {
    std::cout << "Remote has updated Rate attribute" << std::endl;
    double rate = getRateAttribute();

    if (rate < -16 || rate > 16) {
        std::cout << "Bad rate selected" << std::endl;
    }

    m_player->setRate (rate, NULL);
}

void PlayerStubImpl::onRemoteRepeatAttributeChanged() {
    std::cout << "Remote has updated repeat attribute" << std::endl;
    m_player->setRepeat(getRepeatAttribute());
}
void PlayerStubImpl::onRemoteShuffleAttributeChanged() {
    std::cout << "Remote has updated shuffle attribute" << std::endl;

    if (getShuffleAttribute() == MM::PlayerTypes::ShuffleStatus::SHUFFLE)
        m_player->setShuffle(true);
    else
        m_player->setShuffle(false);
}
