#pragma once

#define BRANCH "@MAJOR_VERSION@.@MINOR_VERSION@"
#define VERSION "@FULL_VERSION@"
#define REVISION "release"
#define SYSTEM "@CMAKE_SYSTEM@"
#define INSPIRCD_SOCKETENGINE_NAME "select"

#define CONFIG_PATH "@CONF_PATH@"
#define MOD_PATH "@MODULE_PATH@"
#define DATA_PATH "@DATA_PATH@"
#define LOG_PATH "@LOG_PATH@"

#include "inspircd_win32wrapper.h"
#include "threadengines/threadengine_win32.h"
