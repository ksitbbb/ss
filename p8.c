#include<stdio.h>
struct process
{
    int all[6],max[6],need[6],finished;
}p[10];
int avail[6],sseq[10],ss=0,check1=0,check2=0,n,work[6],nor,safeseq(void);
int main(){
    int ch,i=0,j=0,k,pid,ch1;
    do{
        printf("\n----------------------------------------------------------");
        printf("\n1. Input");
        printf("\n2. Safe state or not");
        printf("\n3. Print");
        printf("\n4. Exit");
        printf("\n----------------------------------------------------------");
        printf("\nEnter ur choice : ");scanf("%d",&ch);
        printf("----------------------------------------------------------");
        switch(ch){
            case 1:
                printf("\n\nEnter number of process : ");scanf("%d",&n);
                printf("\nEnter number of resources : ");scanf("%d",&nor);
                printf("\nEnter available resources : ");
                for(j=0;j<n;j++){
                    for(k=0;k<nor;k++){
                        if(j==0){
                            printf("\nFor resource type %d : ",k);
                            scanf("%d",&avail[k]);
                        }
                        p[j].max[k]=0;
                        p[j].all[k]=0;
                        p[j].need[k]=0;
                        p[j].finished=0;

                    }
                }
                for(i=0;i<n;i++){
                    printf("\nEnter max and allocated resource for P %d : ",i);
                    for(j=0;j<nor;j++){
                        printf("\nEnter the max of resource %d : ",j);
                        scanf("%d",&p[i].max[j]);
                        printf("\nAllocation of resources %d : ",j);
                        scanf("%d",&p[i].all[j]);
                        if(p[i].all[j]>p[i].max[j]){
                            printf("\nAllocation should be less < or == max");
                            j--;
                        }else{
                            p[i].need[j]=p[i].max[j]-p[i].all[j];
                            // avail[j]=avail[j]-p[i].all[j];
                        }
                    }
                }
                break;
            case 2:
                if(safeseq()==1)
                    printf("\nThe system is in safe state");
                else
                    printf("\nThe system is not in safe state");
                break;
            case 3:
                printf("\nNumber of processes : %d",n);
                printf("\nNumber of resource : %d",nor);
                printf("\nPid\tMax\tAllocated\tNeed");
                for(i=0;i<n;i++){
                    printf("\nP%d",i);
                    for(j=0;j<nor;j++)
                        printf("%d ",p[i].max[j]);
                    printf("\t");
                    for(j=0;j<nor;j++)
                        printf("%d ",p[i].all[j]);
                    printf("\t");
                    for(j=0;j<nor;j++)
                        printf("%d ",p[i].need[j]);
                }
                printf("\nAvailable : ");
                for(i=0;i<nor;i++)
                    printf("%d ",avail[i]);
                break;
            default:
                break;
        }
    }while(ch!=4);
}

int safeseq(){
    int tj,tk,i,j,k;ss=0;
    for(j=0;j<nor;j++)
        work[j]=avail[j];
    for(j=0;j<n;j++)
        p[j].finished=0;
    for(tk=0;tk<nor;tk++){
        for(j=0;j<n;j++){
            if(p[j].finished==0){
                check1=0;
                for(k=0;k<nor;k++){
                    if(p[j].need[k]<=work[k])
                        check1++;
                }
                if(check1==nor){
                    for(k=0;k<nor;k++){
                        work[k]=work[k]+p[j].all[k];
                        p[j].finished=1;
                    }
                    sseq[ss]=j;
                    ss++;
                }
            }
        }
    }
    check2=0;
    for(i=0;i<n;i++)
        if(p[i].finished==1)
            check2++;
    if(check2>=n){
        printf("\nThe system is in safe state : ");
        for(tj=0;tj<n;tj++)
            printf("P%d\t",sseq[tj]);
        return 1;
    }else{
        printf("\nThe system is not in safe state");
    }
    return 0;
}