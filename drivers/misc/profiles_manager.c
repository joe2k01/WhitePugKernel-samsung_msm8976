/*  Copyright (c) 2018 Giuseppe "joe2k01" Barillari <joe2k01dev@gmail.com>
 *
 *  This driver is used only to create some sysfs paths needed for the
 *  in built kernel profiles manager interface.
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

#include <linux/module.h>
#include <linux/profiles_manager.h>

// Battery profile
int battery_profile = 0;
module_param_named(battery_profile, battery_profile, int, 0664);

// Performance profile
int performance_profile = 0;
module_param_named(performance_profile, performance_profile, int, 0664);
