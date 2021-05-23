#include<dictionary.h>

Record* load(){
    FILE *fp;
    char word[50];
    Record *root=NULL;
    int i=1;
    fp=fopen("sample-2mb-text-file.txt","r");   //mention the text file to be analyzed
    if(fp==NULL){
        printf("unable to open file");
        exit(0);
    }
    while(fscanf(fp,"%s",word)!=EOF){
         if(!isalpha(word[0])){
            for(i=0;i<=strlen(word);i++){
                word[i]=word[i+1];
            }
        }
        i=strlen(word)-1;
        while(!isalpha(word[i])){
            i--;
        }
        word[i+1]='\0';
         root=add(root,word);
    }
    printf("height of the tree is %d\n",height(root));
    fclose(fp);
    return root;
}

void store_util(Record* root,FILE* fp){
    if(root==NULL){
        return;
    }
    store_util(root->left,fp);
    fprintf(fp,"%-20s\t%d\n",root->keyword,root->count);
    store_util(root->right,fp);
}

void store(Record* root){
    FILE *fp;
    fp=fopen("words.txt","w");   //enter the  file in which words are to be stored
    store_util(root,fp);
    fclose(fp);
}
