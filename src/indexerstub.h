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

#include <CommonAPI/CommonAPI.h>

#include "../src-gen/org/genivi/MediaManager/IndexerStubDefault.h"

#include "lms.h"

class IndexerStubImpl: public org::genivi::MediaManager::IndexerStubDefault {

public:
    IndexerStubImpl (LMSProvider *lms);
    virtual void getDatabasePath(std::string& output);
    virtual void startIndexing();
    virtual void stopIndexing();
    virtual const org::genivi::MediaManager::Indexer::IndexerStatus& getIndexerStatusAttribute ();

private:
    LMSProvider *m_lms;
};
