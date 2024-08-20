#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	DIR *dirp;
	struct dirent *dentry;

	int file_count, dir_count = 0;

	if((dirp = opendir(argv[1])) == NULL )
		exit(1);

	while((dentry = readdir(dirp)) )
	{
		if(dentry->d_ino != 0) {
			if(dentry->d_type == DT_REG) {
                file_count += 1;
            } else if(dentry->d_type == DT_DIR) {
				 dir_count += 1;
            }
		}
	}

	printf("FILE : %d\n", file_count);
	printf("DIRECTIRY : %d\n",dir_count);

	closedir(dirp);
}
