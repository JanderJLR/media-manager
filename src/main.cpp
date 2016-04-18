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

#include <unistd.h>
#include <stdlib.h>
#include <iostream>

#include <gio/gio.h>
#include <CommonAPI/CommonAPI.hpp>

#include "lms.h"
#include "browserprovider.h"
#include "playerprovider.h"
#include "indexerstub.h"
#include "browserstub.h"
#include "playerstub.h"

int main (int argc, char *argv[]) {
    guint watcher_id;
    GMainLoop *loop;
    LMSProvider lms;
    BrowserProvider browser;
    PlayerProvider player;

    CommonAPI::Runtime::LoadState loadState;
    auto runtime = CommonAPI::Runtime::load(loadState);
    if (loadState != CommonAPI::Runtime::LoadState::SUCCESS) {
        std::cerr << "Error: Unable to load runtime!\n";
        return -1;
    }

    lms.connect([&](MmError *e) {
        registerService<IndexerStubImpl, LMSProvider> (runtime,
                                          &lms,
                                          "local:org.genivi.mediamanager.Indexer:"
                                          "org.genivi.mediamanager.Indexer",
                                          "Indexer",
                                          e);
    });

    browser.connect([&](MmError *e) {
        registerService<BrowserStubImpl, BrowserProvider> (runtime,
                                          &browser,
                                          "local:org.genivi.mediamanager.Browser:"
                                          "org.genivi.mediamanager.Browser",
                                          "Browser",
                                          e);
    });

    player.connect([&](MmError *e) {
        registerService<PlayerStubImpl, PlayerProvider> (runtime,
                                          &player,
                                          "local:org.genivi.mediamanager.Player:"
                                          "org.genivi.mediamanager.Player",
                                          "Player",
                                          e);
    });

    loop = g_main_loop_new (NULL, FALSE);
    g_main_loop_run (loop);

}
