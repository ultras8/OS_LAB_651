#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int csum;
int msum;
void *runner(void *param);

int main(int argc, char *argv[]){

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    int upper = atoi(argv[1]);
    int i;
    if(upper > 0){
        for(i = 1; i <= upper; i++){
            msum += i;
        }
    }else{ msum = 0; }
    //pthread_join(tid,NULL);
    printf("CSUM = %d\n",csum);
    printf("MSUM = %d\n",msum);
    printf("Diff = %d\n",csum-msum);

    return 0;
}
void *runner(void *param){
    int upper = atoi(param)*2;
    int i;
    csum = 0;
    if(upper > 0){
        for(i = 1; i <= upper; i++){
            csum += i;
        }
    }else{ csum = 0; }
    pthread_exit(0);
}
