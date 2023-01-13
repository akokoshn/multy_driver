//
// Created by akokoshn on 10/01/2023.
//

#ifndef QT_BLUETOOTH_SERVER_H
#define QT_BLUETOOTH_SERVER_H

#include "internal_types.h"

#include <QtBluetooth/qbluetoothdevicediscoveryagent.h>
#include <QtCore/QObject>

class QtBluetoothServer : public QObject
{
    Q_OBJECT
public:
    QtBluetoothServer();
    virtual ~QtBluetoothServer();
    void startSearching(std::vector<DeviceDescriptor>* deviceDescriptors);
    void stopSearching();
private:
    QBluetoothDeviceDiscoveryAgent* discoveryAgent;
    std::vector<DeviceDescriptor>* devices;
private slots:
    // QBluetoothDeviceDiscoveryAgent related
    void addDevice(const QBluetoothDeviceInfo&);
};

#endif //QT_BLUETOOTH_SERVER_H
