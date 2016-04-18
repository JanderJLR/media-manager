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

#include "browserstub.h"
#include "common.h"

namespace MM = v1_0::org::genivi::mediamanager;

BrowserStubImpl::BrowserStubImpl (BrowserProvider *browser) {
    m_browser = browser;

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

std::string sortKeyToString (MM::BrowserTypes::SortKey sk) {
    std::string keyStr;
    if (sk.getOrder() == MM::BrowserTypes::SortOrder::ASCENDING)
        keyStr += "+";
    else
        keyStr += "-";

    keyStr += sk.getKeyName();

    return keyStr;
}

void BrowserStubImpl::discoverMediaManagers(const std::shared_ptr<CommonAPI::ClientId> _client, discoverMediaManagersReply_t _reply) {
    std::vector<std::string> idents = Common::discoverDLNABackends("servers", NULL);
    _reply(idents, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::listContainers(const std::shared_ptr<CommonAPI::ClientId> _client,
                            std::string _path,
                            uint64_t _offset,
                            uint64_t _count,
                            std::vector<std::string> _filter,
                            listContainersReply_t _reply) {
    Common::ResultMapList* bml = json_array();
    m_browser->listContainers(_path,
                              _offset,
                              _count,
                              _filter,
                              &bml,
                              NULL);

    MM::MediaTypes::ResultMapList containers;
    Common::resultMapListToCAPIResultMapList(bml, containers, m_generalFilter);
    _reply(containers, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::listContainersEx(const std::shared_ptr<CommonAPI::ClientId> _client,
                            std::string _path,
                            uint64_t _offset,
                            uint64_t _count,
                            std::vector<std::string> _filter,
                            ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey,
                            listContainersExReply_t _reply) {

    Common::ResultMapList* bml = json_array();

    m_browser->listContainersEx(_path,
                                _offset,
                                _count,
                                _filter,
                                sortKeyToString(_sortKey),
                                &bml,
                                NULL);

    MM::MediaTypes::ResultMapList containers;
    Common::resultMapListToCAPIResultMapList(bml, containers, m_generalFilter);
    _reply(containers, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::listChildrenEx(const std::shared_ptr<CommonAPI::ClientId> _client,
                          std::string _path,
                          uint64_t _offset,
                          uint64_t _count,
                          std::vector<std::string> _filter,
                          ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey,
                          listChildrenExReply_t _reply) {
    Common::ResultMapList* bml = json_array();

    m_browser->listChildrenEx(_path,
                              _offset,
                              _count,
                              _filter,
                              sortKeyToString(_sortKey),
                              &bml,
                              NULL);

    MM::MediaTypes::ResultMapList children;
    Common::resultMapListToCAPIResultMapList(bml, children, m_generalFilter);
    _reply(children, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::listChildren(const std::shared_ptr<CommonAPI::ClientId> _client,
                                   std::string _path,
                                   uint64_t _offset,
                                   uint64_t _count,
                                   std::vector<std::string> _filter,
                                   listChildrenReply_t _reply) {

    Common::ResultMapList* bml = json_array();

    m_browser->listChildren(_path,
                            _offset,
                            _count,
                            _filter,
                            &bml,
                            NULL);

    MM::MediaTypes::ResultMapList children;
    Common::resultMapListToCAPIResultMapList(bml, children, m_generalFilter);
    _reply(children, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::listItems(const std::shared_ptr<CommonAPI::ClientId> _client,
                     std::string _path,
                     uint64_t _offset,
                     uint64_t _count,
                     std::vector<std::string> _filter,
                     listItemsReply_t _reply) {

    Common::ResultMapList* bml = json_array();

    m_browser->listItems(_path,
                         _offset,
                         _count,
                         _filter,
                         &bml,
                         NULL);

    MM::MediaTypes::ResultMapList items;
    Common::resultMapListToCAPIResultMapList(bml, items, m_generalFilter);
    _reply(items, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::listItemsEx(const std::shared_ptr<CommonAPI::ClientId> _client,
                       std::string _path,
                       uint64_t _offset,
                       uint64_t _count,
                       std::vector<std::string> _filter,
                       ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey,
                       listItemsExReply_t _reply) {

    Common::ResultMapList* bml = json_array();

    m_browser->listItemsEx(_path,
                           _offset,
                           _count,
                           _filter,
                           sortKeyToString(_sortKey),
                           &bml,
                           NULL);

    MM::MediaTypes::ResultMapList items;
    Common::resultMapListToCAPIResultMapList(bml, items, m_generalFilter);
    _reply(items, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);

}

void BrowserStubImpl::createReference(const std::shared_ptr<CommonAPI::ClientId> _client,
                                            std::string _path,
                                            std::string _objectPath,
                                            createReferenceReply_t _reply) {

    std::string result;
    m_browser->createReference(_path,
                               _objectPath,
                               result,
                               NULL);
    _reply(result, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::createContainer(const std::shared_ptr<CommonAPI::ClientId> _client,
                                            std::string _path,
                                            std::string _displayName,
                                            std::vector<std::string> _childTypes,
                                            createContainerReply_t _reply) {

    std::string result;
    m_browser->createContainer (_path,
                                _displayName,
                                _childTypes,
                                result,
                                NULL);
    _reply(result, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::searchObjects(const std::shared_ptr<CommonAPI::ClientId> _client,
                                          std::string _path,
                                          std::string _query,
                                          uint64_t _offset,
                                          uint64_t _count,
                                          std::vector<std::string> _filter,
                                          searchObjectsReply_t _reply) {

    Common::ResultMapList* bml = json_array();

    m_browser->searchObjects (_path,
                              _query,
                              _offset,
                              _count,
                              _filter,
                              &bml,
                              NULL);

    MM::MediaTypes::ResultMapList items;
    Common::resultMapListToCAPIResultMapList(bml, items, m_generalFilter);
    _reply(items, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}

void BrowserStubImpl::searchObjectsEx(const std::shared_ptr<CommonAPI::ClientId> _client,
                           std::string _path,
                           std::string _query,
                           uint64_t _offset,
                           uint64_t _count,
                           std::vector<std::string> _filter,
                           ::v1_0::org::genivi::mediamanager::BrowserTypes::SortKey _sortKey,
                           searchObjectsExReply_t _reply) {

    Common::ResultMapList* bml = json_array();

    m_browser->searchObjectsEx (_path,
                                _query,
                                _offset,
                                _count,
                                _filter,
                                sortKeyToString(_sortKey),
                                &bml,
                                NULL);

    MM::MediaTypes::ResultMapList items;
    Common::resultMapListToCAPIResultMapList(bml, items, m_generalFilter);
    _reply(items, ::v1_0::org::genivi::mediamanager::BrowserTypes::BrowserError::NO_ERROR);
}
