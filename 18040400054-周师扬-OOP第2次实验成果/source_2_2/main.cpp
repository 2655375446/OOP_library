//
//  main.cpp
//  周师扬 18040400054
//  编写日期：2020年3月20日
//  oop第二次上机实验第二题
//

#include <iostream>
#include <string>

using namespace std;

typedef struct Tnode//定义一个Tnode类型
{
    string word;
    int count;
    Tnode *left;
    Tnode *right;
}BSTNode, *BSTree;
 
bool Search(BSTree bst, string key, BSTree f, BSTree *p);
 
void InOderTraverse(BSTree bst)//中序递归遍历二叉树
{
    if(bst!=NULL)
    {
        InOderTraverse(bst->left);
        cout<<bst->word<<" "<<bst->count<<endl;
        InOderTraverse(bst->right);
    }
}
 
static BSTNode* BuyNode(string data)//生成一个节点并进行初始化
{
    BSTNode *pTmp=new BSTNode;
    if(pTmp==NULL)
    {
        exit(0);
    }
    pTmp->word=data;
    pTmp->count=1;
    pTmp->left=NULL;
    pTmp->right=NULL;
    return pTmp;
}
 
bool Insert(BSTree *bst, string key)
{
    if (*bst==NULL)
    {
        *bst=BuyNode(key);
        return true;
    }
    BSTNode *p;
    if(!Search(*bst,key,NULL,&p))
    {
        BSTNode *pNew=BuyNode(key);
        if(key<p->word)
        {
            p->left=pNew;
        }
        else if(key>p->word)
        {
            p->right=pNew;
        }
        return true;
    }
    else
    {
        p->count+=1;
    }
    return false;
}

bool Search(BSTree bst, string key, BSTree f, BSTree *p)
{
    if(!bst)
    {
        *p=f;
        return false;
    }
    if(bst->word==key)
    {
        *p=bst;
        return true;
    }
    else if(bst->word<key)
    {
        return Search(bst->right,key,bst,p);
    }
    return Search(bst->left,key,bst,p);
}

void destroy(BSTree T)//销毁二叉树
{
    if(T==NULL)
        return;
    if(T->left!=NULL)
    {
        destroy(T->left);
        T->left=NULL;
    }
    if(T->right!=NULL)
    {
       destroy(T->right);
        T->right=NULL;
    }
    if(T!=NULL)
    {
        delete T;
        T=NULL;
    }
}

int main(void)
{
    BSTNode *root=NULL;
    string word;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>word;
        Insert(&root,word);
    }
    InOderTraverse(root);
    destroy(root);
    return 0;
}
