#include <stdio.h>
#include <stdlib.h>

int FIFO(char s[], char F[], int f, int l){
    int i,j,k,flag=0,cnt=0;
    printf("\n\tPAGE\t\tFRAMES\t\tFAULTS");
    for(i=0;i<l;i++){
        for(k=0;k<f;k++){
            if(F[k]==s[i])
                flag=1;
        }
        if(flag==0){
            printf("\n\t%c\t",s[i]);
            F[j]=s[i];
            j++;
            for(k=0;k<f;k++)
                printf("\t%c",F[k]);
            printf("\tPage_faulted %d",cnt);
            cnt++;
        }else{
            flag=0;
            printf("\n\t%c\t",s[i]);
            for(k=0;k<f;k++)
                printf("\t%c",F[k]);
            printf("\tNo Page_faulted");
        }
        if(j==f) j=0;
    }
}
int findLRU(int time[],int n){
    int i,minimum=time[0],pos=0;
    for(i=1;i<n;i++){
        if(time[i]<minimum){
            minimum=time[i];
            pos=i;
        }
    }return pos;
}

int lru(char s[], char F[],int f,int l){
    int counter=0,time[10],flag1,flag2,i,j,pos,faults=0,page;
    for(i=0;i<f;++i)
        F[i]=-1;
    for(i=0;i<l;++i){
        flag1=flag2=0;
        page=s[i]-'0';
        for(j=0;j<f;++j){
            if(F[j]==page){
                counter++;
                time[j]=counter;
                flag1=flag2=1;
                break;
            }
        }
        if(flag1==0){
            for(j=0;j<f;++j){
                if(F[j]==-1){
                    counter++;
                    faults++;
                    F[j]=page;
                    time[j]=counter;
                    flag2=1;
                    break;
                }
            }
        }
        if(flag2==0){
            pos=findLRU(time,f);
            counter++;
            faults++;
            F[pos]=page;
            time[pos]=counter;
        }
        printf("\n");
        for(j=0;j<f;j++)
            printf("%d\t",F[j]);
    }
    printf("\n\nTotal page faults = %d",faults);
    return 0;
}

int main(){
    int ch,YN=1,i,l,f;
    char s[25], F[10];
    do{
        printf("\nOptions : \n---------------------------------------");
        printf("\n1.FIFO\n2.LRU\n3.EXIT\n-------------------------------------");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        printf("----------------------------");
        if(ch==1 || ch==2){
            printf("\nEnter the number of frames : ");
            scanf("%d",&f);
            printf("\nEnter the number of pages : ");
            scanf("%d",&l);
            printf("\nEnter string : ");
            scanf("%s",s);
        }
        switch(ch){
            case 1: for(i=0;i<f;i++){F[i]=-1;}FIFO(s,F,f,l);break;
            case 2: for(i=0;i<f;i++){F[i]=-1;}lru(s,F,f,l);break;
            default:printf("\n");exit(0);
        }
        printf("\n\nPress 1 to continue ....0 to exit : ");
        scanf("%d",&YN);
    }while(YN==1);
    return 0;
}