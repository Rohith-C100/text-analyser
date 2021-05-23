#include<dictionary.h>

void test(){
    char s[20];
    FILE* fp=fopen("sample-2mb-text-file.txt","r");
    for(int i=1;i<=100;i++){
        fscanf(fp," %s",s);
        if(!isalpha(s[strlen(s)-1]))
            s[strlen(s)-1]='\0';
        printf(" %s\n",s);
    }
    fclose(fp);
}
