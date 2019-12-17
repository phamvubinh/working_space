#include <stdio.h>
#include <sys/stat.h>  /* Header for mkdir function */
#include <sys/types.h> /* Header for file mode */

#include <sys/types.h>
#include <dirent.h>

#define TEST_FOLDER   "./Testfolder"
#define TEST1_FOLDER  TEST_FOLDER"/Test1"
#define TEST2_FOLDER  TEST1_FOLDER"/abc"
#define TEST3_FOLDER  TEST_FOLDER"/egf"

typedef	struct
{
	char name[50];
	mode_t mode; 
}Struct_Folder;


#if 0
/* This is option of mode_t in <sys/stat.h> */
#define S_IRWXU 0000700    /* RWX mask for owner */
#define S_IRUSR 0000400    /* R for owner */
#define S_IWUSR 0000200    /* W for owner */
#define S_IXUSR 0000100    /* X for owner */

#define S_IRWXG 0000070    /* RWX mask for group */
#define S_IRGRP 0000040    /* R for group */
#define S_IWGRP 0000020    /* W for group */
#define S_IXGRP 0000010    /* X for group */

#define S_IRWXO 0000007    /* RWX mask for other */
#define S_IROTH 0000004    /* R for other */
#define S_IWOTH 0000002    /* W for other */
#define S_IXOTH 0000001    /* X for other */

#define S_ISUID 0004000    /* set user id on execution */
#define S_ISGID 0002000    /* set group id on execution */
#define S_ISVTX 0001000    /* save swapped text even after use */

struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t  st_blocks;  /* number of blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
#endif

/* Note that folder need execute mode to access and save data */
Struct_Folder folderArray[4] = {
	{TEST_FOLDER,  S_IRWXU | S_IRWXG | S_IROTH },
	{TEST1_FOLDER, S_IRWXU | S_IRWXG | S_IWOTH },
	{TEST2_FOLDER, S_IRWXU | S_IRWXG | S_IXOTH },
	{TEST3_FOLDER, S_IRWXU | S_IRWXG | S_IRWXO },
};

#define FOLDERNUM sizeof(folderArray)/sizeof(folderArray[0])

int	main(int argc, char const *argv[])
{
	int result = 0;
	int i = 0;

	/* Struct to save status of file or folder */
	struct stat st = {0};

	/* Check foler status and remove if existed */
	result = stat(TEST_FOLDER, &st);
	if(result == 0)
	{
		printf("Checking status of folder\n");
		/* Check if buffer is the folder or file by using st.st_mode content */
		if (S_ISDIR(st.st_mode))
        {
        	/* Remove if it is empty folder */
			result = rmdir(TEST_FOLDER);
			if(result)
			{
				printf("Cannot remove folder: %s - %d\n", TEST_FOLDER, result);
			}
			/* Need to implement more for recusive remove folder content */
        }
        else
        {
        	/* Unlink if it is a file  */
			result = remove(TEST_FOLDER);
			if(result)
			{
				printf("Cannot remove file: %s\n", TEST_FOLDER);
			}
        }
	}

	/* Create folder and set 0777 permission */
	for (i = 0; i < 4; ++i)
	{
		result = mkdir(folderArray[i].name, S_IRWXU | S_IRWXG | S_IRWXO);
		if(result != 0)
		{
			printf("Failed to create folder: %s\n", folderArray[i].name);
		}
	}

	/* Change mode to what we expect */
	/* We need this step because the non execute mode folder cannot be accessed */
	for (i = 3; i >= 0; i--)
	{
		result = chmod(folderArray[i].name, folderArray[i].mode);
		if(result != 0)
		{
			printf("Failed to change mode folder: %s\n", folderArray[i].name);
		}
	}

	/* Read the directory mode and display information */
	for (i = 0; i < 4; ++i)
	{
		result = stat(folderArray[i].name, &st);
		if(result == 0)
		{
			/* Check if folder mode has read for other user */
			if(st.st_mode & S_IROTH == S_IROTH)
			{
				printf("%s folder has read mode for other user\n", folderArray[i].name);
			}
		}
	}
	return result;
}