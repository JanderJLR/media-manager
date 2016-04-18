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

#ifndef BROWSERSTUB_H
#define BROWSERSTUB_H

#include <CommonAPI/CommonAPI.hpp>

#include "../interfaces/src-gen/v1_0/org/genivi/mediamanager/BrowserStubDefault.hpp"

#include "browserprovider.h"

namespace MM = v1_0::org::genivi::mediamanager;

/**
 * \brief Conversion layer between CommonAPI and internal API
 *
 * This class is undocumented, since it only provides a conversion
 * layer
 * between the auto-generated Franca functions (documented in the Browser.fidl
 * file) and the Media Manager internal API, which is documented in the
 * BrowserProvider class
 *
 * @see BrowserProvider
 */
class BrowserStubImpl: public v1_0::org::genivi::mediamanager::BrowserStubDefault {

public:

    BrowserStubImpl (BrowserProvider *browser);

    virtual void discoverMediaManagers(const std::shared_ptr<CommonAPI::ClientId> _client, discoverMediaManagersReply_t _reply);
    virtual void listContainers(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, listContainersReply_t _reply);
    virtual void listContainersEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listContainersExReply_t _reply);
    virtual void listChildren(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, listChildrenReply_t _reply);
    virtual void listChildrenEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listChildrenExReply_t _reply);
    virtual void listItems(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, listItemsReply_t _reply);
    virtual void listItemsEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, listItemsExReply_t _reply);
    virtual void createReference(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _objectPath, createReferenceReply_t _reply);
    virtual void createContainer(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _displayName, std::vector<std::string> _childTypes, createContainerReply_t _reply);

    virtual void searchObjects(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _query, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, searchObjectsReply_t _reply);
    virtual void searchObjectsEx(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _path, std::string _query, uint64_t _offset, uint64_t _count, std::vector<std::string> _filter, ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey, searchObjectsExReply_t _reply);


private:
    BrowserProvider *m_browser;
    std::vector<std::string> m_generalFilter;

    void browserMapToCAPIBrowserMap(Common::ResultMapList* from,
                               MM::MediaTypes::ResultMapList& to,
                               std::vector<std::string> filter);
};

#endif /* BROWSERSTUB_H */
