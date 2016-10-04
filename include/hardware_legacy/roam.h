/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __WIFI_HAL_ROAM_H__
#define __WIFI_HAL_ROAM_H__

#include "wifi_hal.h"

#define MAX_BLACKLIST_BSSID         16
#define MAX_WHITELIST_SSID          8
#define MAX_SSID_LENGTH             32

/* Get the chipset roaming capabilities. */
typedef struct {
    u32 max_blacklist_size;
    u32 max_whitelist_size;
}wifi_roaming_capabilities;

wifi_error wifi_get_roaming_capabilities(wifi_interface_handle handle,
                                         wifi_roaming_capabilities *caps);
/* Enable/disable firmware roaming */
wifi_error wifi_enable_firmware_roaming(wifi_interface_handle handle,
                                        u32 enable);
/* Pass down the blacklist BSSID and whitelist SSID to firmware. */
typedef struct {
    u32 num_blacklist_bssid;
    mac_addr blacklist_bssid[MAX_BLACKLIST_BSSID];
    u32 num_whitelist_ssid;
    char whitelist_ssid[MAX_WHITELIST_SSID][MAX_SSID_LENGTH];
}wifi_roaming_config;

wifi_error wifi_configure_roaming(wifi_interface_handle handle,
                                  wifi_roaming_config *roaming_config);

#endif /* __WIFI_HAL_ROAM_H__ */
