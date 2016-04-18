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

#ifndef INDEXERSTUB_H
#define INDEXERSTUB_H

#include <CommonAPI/CommonAPI.hpp>

#include "../interfaces/src-gen/v1_0/org/genivi/mediamanager/IndexerStubDefault.hpp"

#include "lms.h"

namespace MM = v1_0::org::genivi::mediamanager;

/**
 * \brief Conversion layer between CommonAPI and internal API
 *
 * This class is undocumented, since it only provides a conversion
 * layer
 * between the auto-generated Franca functions (documented in the Indexer.fidl
 * file) and the Media Manager internal API, which is documented in the
 * LMSProvider class
 *
 * @see LMSProvider
 */
class IndexerStubImpl: public v1_0::org::genivi::mediamanager::IndexerStubDefault {

public:
    IndexerStubImpl (LMSProvider *lms);

    virtual void getDatabasePath(const std::shared_ptr<CommonAPI::ClientId> _client, getDatabasePathReply_t _reply);
    virtual void stopIndexing(const std::shared_ptr<CommonAPI::ClientId> _client, stopIndexingReply_t _reply);
    virtual void startIndexing(const std::shared_ptr<CommonAPI::ClientId> _client, startIndexingReply_t _reply);

    virtual const MM::Indexer::IndexerStatus& getIndexerStatusAttribute(const std::shared_ptr<CommonAPI::ClientId> _client);

private:
    LMSProvider *m_lms;
};

#endif /* INDEXERSTUB_H */
