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
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#ifdef KPM_DISABLED_PROFILES
char kpm_disabled_profiles[100] = KPM_DISABLED_PROFILES;
#else
char kpm_disabled_profiles[] = "none";
#endif

char kpm_final_gov[20];

int kpm_profile = -1;
module_param_named(kpm_profile, kpm_profile, int, 0644);

static int kpm_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "1\n");
	return 0;
}

static int kpm_name_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "%s\n", KPM_NAME);
	return 0;
}

static int kpm_not_tuned_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "%s\n", KPM_NOT_TUNED_GOVERNOR);
	return 0;
}

static int kpm_final_proc_show(struct seq_file *m, void *v) {
	switch(kpm_profile) {
#ifdef KPM_BALANCE_GOVERNOR
		case balance:
			strcpy(kpm_final_gov, KPM_BALANCE_GOVERNOR);
			break;
#endif
#ifdef KPM_PERFORMANCE_GOVERNOR
		case performance:
			strcpy(kpm_final_gov, KPM_PERFORMANCE_GOVERNOR);
			break;
#endif
#ifdef KPM_BATTERY_GOVERNOR
		case battery:
			strcpy(kpm_final_gov, KPM_BATTERY_GOVERNOR);
			break;
#endif
#ifdef KPM_GAMING_GOVERNOR
		case gaming:
			strcpy(kpm_final_gov, KPM_GAMING_GOVERNOR);
			break;
#endif
		default:
			strcpy(kpm_final_gov, "Oops, looks like you haven't set this up correctly");
	}
	seq_printf(m, "%s\n", kpm_final_gov);
	return 0;
}

static int kpm_disabled_profiles_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "%s\n", kpm_disabled_profiles);
	return 0;
}

static int kpm_proc_open(struct inode *inode, struct file *file) {
	return single_open(file, kpm_proc_show, NULL);
}

static int kpm_name_proc_open(struct inode *inode, struct file *file) {
	return single_open(file, kpm_name_proc_show, NULL);
}

static int kpm_not_tuned_proc_open(struct inode *inode, struct file *file) {
	return single_open(file, kpm_not_tuned_proc_show, NULL);
}

static int kpm_final_proc_open(struct inode *inode, struct file *file) {
	return single_open(file, kpm_final_proc_show, NULL);
}

static int kpm_disabled_profiles_proc_open(struct inode *inode, struct file *file) {
	return single_open(file, kpm_disabled_profiles_proc_show, NULL);
}

static const struct file_operations kpm_proc_fops = {
	.open		= kpm_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static const struct file_operations kpm_name_proc_fops = {
	.open		= kpm_name_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static const struct file_operations kpm_not_tuned_proc_fops = {
	.open		= kpm_not_tuned_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static const struct file_operations kpm_final_proc_fops = {
	.open		= kpm_final_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static const struct file_operations kpm_disabled_profiles_proc_fops = {
	.open		= kpm_disabled_profiles_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_kpm_init(void) {
	proc_create("kpm_supported", 0, NULL, &kpm_proc_fops);
	proc_create("kpm_name", 0, NULL, &kpm_name_proc_fops);
	proc_create("kpm_not_tuned", 0, NULL, &kpm_not_tuned_proc_fops);
	proc_create("kpm_final", 0, NULL, &kpm_final_proc_fops);
	if(strcmp(kpm_disabled_profiles, "none") != 0){
		proc_create("kpm_disabled_profiles", 0, NULL, &kpm_disabled_profiles_proc_fops);
	}

	return 0;
}

fs_initcall(proc_kpm_init);
