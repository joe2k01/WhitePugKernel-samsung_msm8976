/*  Copyright (c) 2018 Giuseppe "joe2k01" Barillari <joe2k01dev@gmail.com>
 *
 *  This driver is used to share infos between the Kernel Profiles Manager
 *  Interface Initializer and CPU governor(s)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define KPM_NAME "YourKernelNameHere"
// THIS IS MANDATORY, YOU MUST DEFINE YOUR KERNEL NAME.

#define KPM_DISABLED_PROFILES "balance,gaming"
// If you want to include all the profiles, you can delete this line.

#define KPM_NOT_TUNED_GOVERNOR "ondemand"
// THIS IS MANDATORY, YOU MUST DEFINE A NOT TUNED GOVERNOR.

extern int kpm_profile;

enum kpm_available_profiles {
	// You should change values here according to the disabled profiles.
	performance = 1,
	battery = 2
};

/* Here you should define the governor you want to use
 * for each profile
 */
#define KPM_PERFORMANCE_GOVERNOR "interactive"
#define KPM_BATTERY_GOVERNOR "interactive"

