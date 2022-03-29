#include "mujoco.h"
#include "stdio.h"

char error[1000];
mjModel* m;
mjData* d;

int main(void)
{
    m = mj_loadXML("example.xml",NULL,error,1000);
    if(!m)
    {
        printf("%s",error);
        return 1;
    }

    d=mj_makeData(m);
    while(d->time < 100)
    {
        mj_step(m,d);
    }

    mj_deleteData(d);
    mj_deleteModel(m);

    return 0;
}