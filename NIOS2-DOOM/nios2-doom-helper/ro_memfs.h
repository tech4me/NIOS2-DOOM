#ifndef __RO_MEMFS_H__
#define __RO_MEMFS_H__

#include <stddef.h>
#include "sys/alt_dev.h"
#include "sys/alt_llist.h"

// Linker symbols for doom wad file
__attribute__ ((section ("rodata"))) extern const char _binary_doom_wad_name_start;
__attribute__ ((section ("rodata"))) extern const char _binary_doom_wad_name_end;
__attribute__ ((section ("rodata"))) extern const int _binary_doom_wad_name_size;

__attribute__ ((section ("rodata"))) extern const char _binary_doom_wad_start;
__attribute__ ((section ("rodata"))) extern const char _binary_doom_wad_end;
__attribute__ ((section ("rodata"))) extern const int _binary_doom_wad_size;

typedef struct ro_memfs ro_memfs_dev;

extern int ro_memfs_open(alt_fd* fd, const char * name, int flags, int mode);
extern int ro_memfs_close(alt_fd* fd);
extern int ro_memfs_read(alt_fd* fd, char * ptr, int len);
extern int ro_memfs_seek(alt_fd* fd, int ptr, int dir);
extern int ro_memfs_fstat(alt_fd* fd, struct stat* buf);

#define RO_MEMFS_NAME "/mnt/memfs"

struct ro_memfs
{
    alt_dev  fs_dev;
};


#define RO_MEMFS_INSTANCE(name, dev) static ro_memfs_dev dev = \
{                                                                         \
    {                                                                     \
        ALT_LLIST_ENTRY,                                                  \
        name##_NAME,                                                      \
        ro_memfs_open,                                                    \
        NULL, /* close */                                                 \
        ro_memfs_read,                                                    \
        NULL, /* write */                                                 \
        ro_memfs_seek,                                                    \
        ro_memfs_fstat,                                                   \
        NULL, /* ioctl */                                                 \
    },                                                                    \
}    


/*
* Mount the filesystem
*/
#define RO_MEMFS_INIT(name, dev) \
    alt_fs_reg (&dev.fs_dev)

#endif
