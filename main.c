#include<dictionary.h>

int main(){
   Record *root=load();
   int choice,num;
   char a,b;
   char word[50];
   while(1){
    printf("----------------------------------------------------\n");
    printf("1:search         2:display\n");
    printf("3:insert         4:range query\n");
    printf("5:length query   6:prefix search\n");
    printf("7:save and exit  8:normal exit\n");
    printf("----------------------------------------------------\n");
    printf("enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("enter the word :");
        scanf(" %s",word);
        search(root,word);
        break;
    case 2:
        printf("all words in dictionary are:\n");
        printf("Sl.num Word\t\t\tCount\n");
         printf("-----------------------------------------------\n");
        print(root);
        break;
    case 3:
        printf("enter the word\n");
        printf("------------------------------------------------\n");
        scanf(" %s",word);
        root=add(root,word);
        break;
    case 4:
        printf("enter the first characters of the range ex: e j\n");
        scanf(" %c %c",&a,&b);
        printf("Sl.num Word\t\t\tCount\n");
        printf("------------------------------------------------\n");
        range_query(root,a,b);
        break;
    case 5:
        printf("enter the length :");
        scanf(" %d",&num);
        printf("Sl.num Word\t\t\tlength\n");
        printf("------------------------------------------------\n");
        lenq(root,num);
        break;
    case 6:
        printf("enter the prefix: ");
        scanf(" %s",word);
        printf("------------------------------------------------\n");
        printf("Sl.num Word\t\t\tcount\n");
        printf("------------------------------------------------\n");
        preprint(root,word);
        break;
    case 7:
        store(root);
        exit(0);
    case 8:
        exit(0);
    default:
        printf("invalid choice\n");
    }
   }
}
