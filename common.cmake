SET (INTERFACE_DIR ${MEDIAMANAGER_SOURCE_DIR}/interfaces/src-gen/)

FIND_PACKAGE (PkgConfig)

pkg_check_modules (PC_GIO           REQUIRED gio-2.0)
pkg_check_modules (PC_COMMONAPI     REQUIRED CommonAPI)
pkg_check_modules (PC_COMMONAPIDBUS REQUIRED CommonAPI-DBus)
pkg_check_modules (PC_GIO_UNIX      REQUIRED gio-unix-2.0)
pkg_check_modules (PC_JANSSON       REQUIRED jansson)

INCLUDE_DIRECTORIES (${PC_GIO_INCLUDE_DIRS}
                     ${PC_COMMONAPI_INCLUDE_DIRS}
                     ${PC_COMMONAPIDBUS_INCLUDE_DIRS}
                     ${PC_GIO_UNIX_INCLUDE_DIRS}
                     ${PC_JANSSON_INCLUDE_DIRS})

INCLUDE_DIRECTORIES (${INTERFACE_DIR}
                     ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/)

LINK_DIRECTORIES (${PC_COMMONAPIDBUS_LIBRARY_DIRS})

ADD_DEFINITIONS (${PC_COMMONAPIDBUS_CFLAGS} ${PC_GIO_UNIX_CFLAGS})

ADD_DEFINITIONS ("-std=c++11")

ADD_CUSTOM_COMMAND (OUTPUT ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-generated.c
                           ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-generated.h
                    COMMAND mkdir -p ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/ &&
                            gdbus-codegen --generate-c-code ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-generated
                                          --c-namespace dleynaServer
                                          --interface-prefix dleyna
                                          --interface-prefix org.gnome.UPnP
                                          ${MEDIAMANAGER_SOURCE_DIR}/src/interfaces/dleyna.xml)

ADD_CUSTOM_COMMAND (OUTPUT ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-renderer-generated.c
                           ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-renderer-generated.h
                    COMMAND mkdir -p ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/ &&
                            gdbus-codegen --generate-c-code ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-renderer-generated
                                          --c-namespace dleynaRenderer
                                          --interface-prefix dleyna
                                          --interface-prefix org.mpris
                                          ${MEDIAMANAGER_SOURCE_DIR}/src/interfaces/dleyna-renderer.xml)

SET (GENERATED_SOURCES_CAPI
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/Browser.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserTypes.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserDBusProxy.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserDBusStubAdapter.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserStubDefault.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/Indexer.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerDBusProxy.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerDBusStubAdapter.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerStubDefault.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/Player.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerDBusProxy.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerDBusStubAdapter.cpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerStubDefault.cpp
)

SET (GENERATED_HEADERS_CAPI
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserDBusProxy.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserDBusStubAdapter.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/Browser.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserTypes.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserProxyBase.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserProxy.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserStubDefault.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/BrowserStub.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerDBusProxy.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerDBusStubAdapter.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/Indexer.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerProxyBase.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerProxy.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerStubDefault.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/IndexerStub.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerDBusProxy.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerDBusStubAdapter.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/Player.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerTypes.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerProxyBase.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerProxy.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerStubDefault.hpp
    ${INTERFACE_DIR}/v1_0/org/genivi/mediamanager/PlayerStub.hpp
)

SET (GENERATED_SOURCES_DBUS
    ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-generated.c
    ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-generated.h
    ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-renderer-generated.c
    ${MEDIAMANAGER_BINARY_DIR}/generated/dleyna/dleyna-renderer-generated.h
    )
