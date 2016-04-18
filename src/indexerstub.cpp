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

#include <iostream>

#include "indexerstub.h"
#include "common.h"

namespace MM = v1_0::org::genivi::mediamanager;

IndexerStubImpl::IndexerStubImpl (LMSProvider *lms) {
    m_lms = lms;
}

void IndexerStubImpl::getDatabasePath(const std::shared_ptr<CommonAPI::ClientId> _client, getDatabasePathReply_t _reply) {

    MmError *error = NULL;
    MM::Indexer::IndexerError e;

    std::cout << "Call to " << __FUNCTION__ << std::endl;

    std::string output;
    m_lms->getDatabasePath(output, &error);

    if (error) {
        std::cout << "Setting error to BACKEND_UNREACHABLE" << std::endl;
        e = MM::Indexer::IndexerError::BACKEND_UNREACHABLE;
    }

    _reply(output, e);
}

void IndexerStubImpl::startIndexing(const std::shared_ptr<CommonAPI::ClientId> _client, startIndexingReply_t _reply) {
    MmError *error = NULL;
    MM::Indexer::IndexerError e;

    std::cout << "Call to " << __FUNCTION__ << std::endl;
    m_lms->startIndexing(&error);

    if (error) {
        std::cout << "Setting error to BACKEND_UNREACHABLE" << std::endl;
        e = MM::Indexer::IndexerError::BACKEND_UNREACHABLE;
    }
    _reply(e);
}

void IndexerStubImpl::stopIndexing(const std::shared_ptr<CommonAPI::ClientId> _client, stopIndexingReply_t _reply) {
    MmError *error = NULL;
    MM::Indexer::IndexerError e;

    std::cout << "Call to " << __FUNCTION__ << std::endl;
    m_lms->stopIndexing(&error);

    if (error) {
        std::cout << "Setting error to BACKEND_UNREACHABLE" << std::endl;
        e = MM::Indexer::IndexerError::BACKEND_UNREACHABLE;
    }
    _reply(e);
}

const MM::Indexer::IndexerStatus& IndexerStubImpl::getIndexerStatusAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) {
    std::cout << "Not implemented: Call to " << __FUNCTION__ << std::endl;
    return MM::Indexer::IndexerStatus::RUNNING;
}
