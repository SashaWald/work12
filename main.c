#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    DIR *d;
    struct stat sb;
    struct dirent *entry;
    d = opendir(".");
    entry = readdir(d);
    
    int size = 0;
    while (entry){
        if(entry->d_type == DT_REG){
            stat(entry->d_name, &sb);
            size+=sb.st_size;
        }
        entry=readdir(d);
    }
    printf("Total Directory Size: %d Bytes\n",size);
    rewinddir(d);
    entry=readdir(d);
    printf("Directories:\n");
    while(entry){
        if (entry->d_type == DT_DIR){
            printf("\t%s\n",entry->d_name);
        }
        entry=readdir(d);
    }
    rewinddir(d);
    entry=readdir(d);
    
    printf("Regular Files:");
    while(entry){
        if(entry->d_type == DT_REG){
            printf("\t%s\n",entry->d_name);
        }
        entry=readdir(d);
    }
    closedir(d);
    return(0);
}