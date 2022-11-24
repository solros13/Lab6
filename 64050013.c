#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum, msum;
void *runner(void *param);

int main(int argc, char *argv[])
{

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);

    int ip;
    msum = 0;

    if (atoi(argv[1]) > 0)
    {
        for (ip = 1; ip <= atoi(argv[1]); i++)
            msum += ip;
    }
    // printf("msum = %d\n", msum);
    pthread_join(tid, NULL);

    printf("child => %d | parent => %d | result = %d\n", csum, msum, csum - msum);
    // แบบที่1 child เสร็จก่อน parent (ทำงานปกติ) => ได้ค่าออกมา
    // แบบที่2 parent เสร็จก่อน แต่ child นั้น 0 => -parent
    // แบบที่3 parent เสร็จก่อน child ยังไม่เสร็จ(ติด loop อยู่) => -parent 
    return 0;
}

void *runner(void *param)
{

    int i;
    csum = 0;

    if (atoi(param) > 0)
    {
        for (i = 1; i <= 2 * (atoi(param)); i++)
            csum += i;
    }
    pthread_exit(0);
}
