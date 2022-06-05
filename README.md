# multy_driver
Shared library for connet with different type of sport devices
## Supported OSs:
- Android
## API:
* **std::vector<DeviceDescriptor> getDevices()**
```
  Returns list of descriptors avialable devices
```
* **int sparing(const std::string &name)**
```
  Try connect to the device devined by name, returns 0 in case of sucess
```
* **int getHR()**
```
  Returns the latest HR info from the connected device, 0 if no devices connected
```
