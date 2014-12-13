/* Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#ifndef NL80211_INTERNAL_H_
#define NL80211_INTERNAL_H_

#include <stdint.h>

struct i802_bss;

/* nl80211_internal_iface contains function pointers to accessor methods for
 * extracting parts of the internal nl80211 context. This allows
 * driver-specific bits of code to process data from the nl80211 private
 * structures without breaking every time the nl80211 code in wpa_suppplicant
 * is updated. */
struct nl80211_internal_iface {
	/* get_bss_ifname returns the interface name stored in the BSS
	 * structure. */
	char* (*get_ifname)(struct i802_bss*);
	/* get_bss_ifindex returns the cache interface index, as returned by
	 * the if_nametoindex(2) system call. */
	int (*get_ifindex)(struct i802_bss*);
	/* get_bss_wdev_id returns the device id given by the kernel when
	 * creating the interface. */
	uint64_t (*get_wdev_id)(struct i802_bss*);
	/* get_wpa_s returns the |wpa_suppplicant| pointer stored in the
	 * nl80211 context. This is needed to pass to wpa_suppplicant functions
	 * like |wpa_suppplicant_event|. */
	void* (*get_wpa_s)(struct i802_bss*);
	/* get_ioctl_sock returns a file descriptor for use with the ioctl(2)
	 * system call. This is a global, PF_INET, SOCK_DGRAM socket. */
	int (*get_ioctl_sock)(struct i802_bss*);
};

#endif  /* NL80211_INTERNAL_H_ */
