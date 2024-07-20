#include <sys/stat.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

bool file_exists (char *filename)
{
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
};
void openfile(char* pathname)
{
  int fd;
  fd = open(pathname, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
  if (fd < 0)
  {
    /* failure */
    if (errno == EEXIST) {
      /* the file already existed
      ... */
    };
  }
  else
  {
    /* now you can use the file */
  };
};