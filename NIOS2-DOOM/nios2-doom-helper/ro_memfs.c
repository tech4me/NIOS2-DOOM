#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>

#include "alt_types.h"

#include "ro_memfs.h"

int ro_memfs_open(alt_fd *fd, const char *name, int flags, int mode)
{
    int ret_code = -EROFS;
    ro_memfs_dev *dev = (ro_memfs_dev *)fd->dev;
    if (flags == O_RDONLY)
    {
        name += strlen(dev->fs_dev.name) + 1;
        if (strncmp(&_binary_doom_wad_name_start, name, (int)&_binary_doom_wad_name_size))
        {
            printf("File with the name: %s does not exist in ro_memfs\n", name);
        }
        else
        {
            fd->priv = (alt_u8 *)&_binary_doom_wad_start;
            ret_code = 0;
        }
    }
    return ret_code;
}

int ro_memfs_read(alt_fd *fd, char *ptr, int len)
{
    int file_len = (int)&_binary_doom_wad_size;
    alt_u8 *current = fd->priv, *start = (alt_u8 *)&_binary_doom_wad_start;
    int amount_to_copy = MIN(len, file_len - (current - start));
    memcpy(ptr, current, amount_to_copy);
    fd->priv += amount_to_copy;
    return amount_to_copy;
}

int ro_memfs_seek(alt_fd *fd, int ptr, int dir)
{
    int ret_code;
    int len = (int)&_binary_doom_wad_size;
    alt_u8 *start = (alt_u8 *)&_binary_doom_wad_start;
    switch (dir)
    {
        case SEEK_CUR: // From Current
        {
            if ((fd->priv + ptr) > (start + len))
            {
                ret_code = -EINVAL;
                printf("Invalid fseek: seek pass eof\n");
                goto exit;
            }
            fd->priv += ptr;
            break;
        }
        case SEEK_SET: // From Begin
        {
            if (ptr > len)
            {
                ret_code = -EINVAL;
                printf("Invalid fseek: seek pass eof\n");
                goto exit;
            }
            fd->priv = start + ptr;
            break;
        }
        case SEEK_END: // From End
        {
            if (ptr > 0)
            {
                ret_code = -EINVAL;
                printf("Invalid fseek: seek pass eof\n");
                goto exit;
            }
            fd->priv = start + ptr + len;
            break;
        }
    }
    ret_code = (int)(fd->priv - start);
exit:
    return ret_code;
}

int ro_memfs_fstat(alt_fd *fd, struct stat *buf)
{
    int len = (int)&_binary_doom_wad_size;
    buf->st_mode = S_IFREG;
    buf->st_size = (off_t)len;
    return 0;
}
