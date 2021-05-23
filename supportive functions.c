#include<dictionary.h>

int count;

void print_util(Record* root){
   if(root==NULL){
        return;
    }
    print_util(root->left);
    printf("%-7d%-20s\t%d\n",++count,root->keyword,root->count);
    print_util(root->right);
}

void print(Record* root){
    count=0;
    print_util(root);
}


void search(Record* root,char keyword[]){
    if(root==NULL){
        printf("key word not found\n");
        printf("----------------------------------------------------\n");
        return;
    }
    if(strcmp(keyword,root->keyword)==0){
        printf("\nword is present and is:- %s\tcount is %d\n",root->keyword,root->count);
        printf("----------------------------------------------------\n");
        return;
    }
    if(strcmp(keyword,root->keyword)<0){
        search(root->left,keyword);
    }
    else{
        search(root->right,keyword);
    }
}

void range_query_util(Record* root,char a,char b){
    if(root==NULL){
        return;
    }
    range_query_util(root->left,a,b);
    if(root->keyword[0]-a>=0&&root->keyword[0]-b<=0)
     printf("%-7d%-20s\t%d\n",++count,root->keyword,root->count);
    range_query_util(root->right,a,b);
}

void range_query(Record* root,char a,char b){
    count=0;
    range_query_util(root,a,b);
}


int precmp(char pre[],char cmp[]){
    int i=0;
    while(pre[i]!='\0'){
        if(pre[i]!=cmp[i])
            return 0;
        i++;
    }
    return 1;
}

void preprint_util(Record* root,char pre[]){
    if(root==NULL){
        return;
    }
    preprint_util(root->left,pre);
    if(precmp(pre,root->keyword))
     printf("%-7d%-20s\t%d\n",++count,root->keyword,root->count);
    preprint_util(root->right,pre);
}

void preprint(Record* root,char pre[]){
    count=0;
    preprint_util(root,pre);
}

void lenq_util(Record* root,int num){
    if(root==NULL){
        return;
    }
    lenq_util(root->left,num);
    if(strlen(root->keyword)>=num)
     printf("%-7d%-20s\t%d\n",++count,root->keyword,strlen(root->keyword));
    lenq_util(root->right,num);
}

void lenq(Record* root,int num){
    count=0;
    lenq_util(root,num);
}

