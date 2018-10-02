#include<stdio.h>
void gencard(int ,int, int *, int );
int main()
{
    int card[6];
    int i;int val;
    int u1,l1,u2,l2;   // u1 and li for the limits of hypotender  u2 and l2 for hypertender
    int cheker =50;
    int h;      // to select who plays first. the opposite player gets to select the range
    printf("read whoo plays first \n 0 for hypotender 1 for hyper tender ");
    scanf("%d",&h);
    switch(h)
    {
    case 0:
        printf("hypertender please select upper limit og your range 80 to 100 , in a window of 5");
        scanf("%d",&u2);
        l2=u2-5;
        l1=100-u2;
        u1=l1+5;
        break;
    case 1:
        printf("hypotender please select lower limit of your range 0 to 20 , in a window of 5");
        scanf("%d",&l1);
        u1=l1+5;
        u2=100-l1;
        l2=u2-5;
        break;
    default:
        printf("wrong input");

    }
    printf(" so the wiining windows are\n");
    printf("hypotender     %d    -     %d  \n",l1,u1);
    printf("\nhypertender     %d    -     %d  \n",l2,u2);
    if(h==0)
        printf("*************************************\nhypotender plays first\n****************************************\n");
    else
        printf("\n***********************************\nhypertender playes first\n***************************************\n");
    gencard(l1,l2,card,h);
    int ave1=0,ave2=0;
    for(i=0;i<6;i++)
    {
        if(h==0&&i<3 || h==1&&i>2)
        {
            ave1=ave1+card[i];

            printf("card hypertender");
            cheker=cheker+card[i];
        }
        else if(h==1&&i<3 || h==0&&i>2)
        {
            ave2=ave2+card[i];
            printf("card hypotender");
            cheker=cheker-card[i];
        }



        printf("%d",card[i]);
        printf("                  %d\n",cheker);


    }
    printf("HYPERtender card= %d\n",(ave2*3)/5);
    printf("HYPO tender card= %d\n",(ave1*3)/5);
    // multiplication card generation
    int j,k=0,l=0;
    int mul[20];
    mul[0]=u2/(u1+1);

    for(j=u1+2;j<=45;j++)
    {
        val=u2%j;
        printf("val==  %d\n ",val);

        if(val<5)
        {
            val=u2/j;
            printf("val inside less than 5==  %d\n ",val);

            if(val!=mul[k])
            {   k++;
                mul[k]=val;
            }
        }

    }
    int div[20];
    int l11=l1;
    int rangelower;
    int rangeupper;
    if(l1==0){ // avoiding division by zero
        l11=1;
    }
    int divu=50/l11;
    int divl=50/u1;
    int intdiv;
    for(intdiv=2;intdiv<=14;intdiv++)
    {
        if(intdiv==divl)
        {
            intdiv=divu;

        }
        else{
            rangelower=intdiv*l11;
            rangeupper=intdiv*(u1+1)-1;

        }



    }

    /*div[0]=59/u1;
    for(j=60;j<=l2-1;j++)
    {
        val=j/l1;
        if(val!=div[l])
            {   l++;
                div[l]=val;
            }
    }*/
        printf("*************************************\n");

    for(j=0;j<=k;j++)   // multiplication
        printf("%d\n",mul[j]);
    printf("*************************************\n");

    /* for division set upper and lower division limits
    excluding those values from integer 2 calcualte li * integer and u1+1  * integer,
    this will be range of winning division card holder ,
     among different ranges select a good range good luck */
    /*

    for(j=0;j<=l;j++)   // division
        printf("%d\n",div[j]);  */


    printf("\n%d      not cards just diplaying value       %d\n",ave1,ave2);
}
void gencard(int l1,int l2,int *card,int h)
{
    int u1=l1+5;
    int u2=l2+5;
    card[0]=((l2-u1)/2); //+ randomize(2);
    card[3]=(card[0]*3)/4;// +randomize(1)
    card[1]=(l2+ 2)- (50 - card[3]);
    card[4]=(60-u1); // + randomize
    card[5]=50 - card[4] + card[1] -(l1+3);
    card[2]=(card[0]*4)/3;
}









