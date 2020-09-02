#include <stdio.h>
#include <windows.h>
#include <shlobj.h>  

#define MAX_NAME 256

//draw a heart
void draw(FILE *fp)
{
	float x=0.,y=0.; 
	for (y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (x = -1.5f; x < 1.5f; x += 0.05f) {
            float a = x * x + y * y - 1;
            fputc(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ',fp);
        }
        fputc('\n',fp);
    }
}

int main()
{
	//get user's name
	char UserName[MAX_NAME] = {0};
	unsigned long NameLen = sizeof(UserName);
	GetUserName(UserName, &NameLen);
	printf("Hello! %s!\n", UserName);
	
	//get path of Desktop
	char   path[255];  
    SHGetSpecialFolderPath(0,path,CSIDL_DESKTOPDIRECTORY,0); 
	//printf("%s",path);
	
	//trick
	int i=0;
	char name[20],invite[]="玩游戏吗",word[]="我中意你";
	FILE *fp = NULL;
	printf("------------------------\n");
	printf("| I'm a VERY BAD VIRUS |\n");
	printf("------------------------\n");
	printf("Processing..");
	for(i=0;i<5;i++)	
	{
		sprintf(name,"%s/%c%c.txt",path,invite[2*i],invite[2*i+1]);
		fp = fopen(name,"w+");
		fprintf(fp,"%c%c\nOnly For U,%s",word[2*i],word[2*i+1],UserName);
		draw(fp);
		fclose(fp);
		printf(".");
		sleep(1);
	}
	printf("\nCheck your Desktop!");
	sleep(0x5); 
	return 0;
}

