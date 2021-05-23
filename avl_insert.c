#include<dictionary.h>

int max(int a,int b){
    return (a>b?a:b);
}

int height(Record* root){
    if(!root)
        return -1;
    else
        return root->height;
}

Record* singleRotateLeft(Record* x){
    Record* w=x->left;
    x->left=w->right;
    w->right=x;
    x->height=max(height(x->left),height(x->right))+1;
    w->height=max(height(w->left),x->height)+1;
    return w;
}


Record* singleRotateRight(Record* w){
    Record* x=w->right;
    w->right=x->left;
    x->left=w;
    w->height=max(height(w->right),height(w->left))+1;
    x->height=max(height(x->right),w->height)+1;
    return x;
}

Record* doubleRotateLeft(Record* z){
    z->left=singleRotateRight(z->left);
    return singleRotateLeft(z);
}

Record* doubleRotateRight(Record* z){
    z->right=singleRotateLeft(z->right);
    return singleRotateRight(z);
}

Record* add(Record* root,char data[])
{
    if(!root)
    {
        root=(Record*)malloc(sizeof(Record));
        if(!root)
        {
            printf("memory error\n");
            return NULL;
        }
        else
        {
            root->height=0;
            root->count=1;
            root->left=root->right=NULL;
            strcpy(root->keyword,data);
        }
    }
    else if(strcmp(data,root->keyword)<0)
    {
        root->left=add(root->left,data);
        if((height(root->left)-height(root->right))==2)
        {
            if(strcmp(data,root->left->keyword)<0)
                root=singleRotateLeft(root);
            else root=doubleRotateLeft(root);
        }
    }
    else if(strcmp(data,root->keyword)>0)
    {
        root->right=add(root->right,data);
        if((height(root->right)-height(root->left))==2)
        {
            if(strcmp(data,root->right->keyword)>0)
                root=singleRotateRight(root);
            else root=doubleRotateRight(root);
        }
    }
    else if(strcmp(data,root->keyword)==0){
        root->count++;
    }
    root->height=max(height(root->left),height(root->right))+1;
    return root;
}
