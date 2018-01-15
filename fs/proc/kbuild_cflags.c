#include <linux/ctype.h>
#include <linux/fs.h>
#include <generated/kbuild_cflags.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int kbuild_cflags_proc_show(struct seq_file *m, void *v)
{
	char kbuild_cflags[] = USED_KBUILD_CFLAGS;
	int i;
	for(i = 0; i < strlen(kbuild_cflags); i++)
	{
		if (isspace(kbuild_cflags[i])) kbuild_cflags[i]='\n';
	}

	seq_printf(m, "The KBUILD_CFLAGS variable during the running kernel compilation had this flags enabled: %s\n", kbuild_cflags);
	return 0;
}

static int kbuild_cflags_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, kbuild_cflags_proc_show, NULL);
}

static const struct file_operations kbuild_cflags_proc_fops = {
	.open		= kbuild_cflags_proc_open,
	.read		= seq_read,
	.llseek		= seq_lseek,
	.release	= single_release,
};

static int __init proc_kbuild_cflags_init(void)
{
	proc_create("kbuild_cflags", 0, NULL, &kbuild_cflags_proc_fops);
	return 0;
}
module_init(proc_kbuild_cflags_init);
