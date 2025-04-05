# Keep Log 

KeepLog is a simple library for logging in C++ applications. With KeepLog you can log log messages of different importance, set the log file location and add timestamps.

## Features 
- Stores logs in text files 
- Provides three log levels: NORMAL, WARN, and ERROR 
- Support for timestamps - Ability to change log file location

## Installation
To use KeepLog, simply include the header file [klog.h](app/src/main/headers/klog.h) in your project.

```cpp
#include "klog.h"
```

## Usage

### Creating a Log Object
```cpp
klog::LOGKEEP logger;
```

### Saving a Log
```cpp
logger.keepLog("This is a normal message", klog::NORMAL);
logger.keepLog("This is a warning", klog::WARN);
logger. keepLog("This is an error", klog::ERROR);
```

### Set the Log File Directory
```cpp
logger.setFileDir("custom-log.txt");
```

### Enable Time Stamp
```cpp
logger.setTimeStamp(true);
```

## Log Structure
Each log will be saved in the following format:
```
2025-04-04 12:34:56 [*] This is a normal message
2025-04-04 12:34:57 [ warn ] This is a warning
2025-04-04 12:34:58 [ ERROR ] This is an error
```

## Contributions
If you would like to contribute to the development of KeepLog, please fork this repository and submit a pull request.
