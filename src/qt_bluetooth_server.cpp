//
// Created by akokoshn on 12/12/2022.
//

#include "qt_bluetooth_server.h"

#include <QtAndroidExtras/QAndroidJniObject>
#include <QtCore/5.15.8/QtCore/private/qjni_p.h>
#include <QtCore/5.15.8/QtCore/private/qjnihelpers_p.h>

#include "android.h"

const QMetaObject* QtBluetoothServer::metaObject() const
{
    return QObject::metaObject();
}

void* QtBluetoothServer::qt_metacast(const char* _clname)
{
    return QObject::qt_metacast(_clname);
}

int QtBluetoothServer::qt_metacall(QMetaObject::Call call, int t, void** p)
{
    return QObject::qt_metacall(call, t, p);
}

QtBluetoothServer::QtBluetoothServer(): discoveryAgent(nullptr), devices(nullptr)
{
}

QtBluetoothServer::~QtBluetoothServer()
{
    delete discoveryAgent;
}

void QtBluetoothServer::addDevice(const QBluetoothDeviceInfo &info)
{
    DeviceDescriptor desc;
    LOGI("Find device: %s %s\n", info.address().toString().toStdString().c_str(), info.name().toStdString().c_str());
    desc.name = info.name().toStdString();
    if (devices) {
        devices->push_back(desc);
    }
}

void QtBluetoothServer::startSearching(std::vector<DeviceDescriptor>* deviceDescriptors)
{
    LOGI("QtBluetoothServer::startSearching");
    if (discoveryAgent) {
        discoveryAgent->stop();
        delete discoveryAgent;
    }
    devices = deviceDescriptors;
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    LOGI("discoveryAgent = %p", discoveryAgent);
    discoveryAgent->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        this, &QtBluetoothServer::addDevice);
    LOGI("start");
    discoveryAgent->start();
}

void QtBluetoothServer::stopSearching()
{
    if (discoveryAgent) {
        discoveryAgent->stop();
    }
}
