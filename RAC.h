#ifndef RAC_H_INCLUDED
#define RAC_H_INCLUDED

#endif // RAC_H_INCLUDED

#include "RS.h"
#define MAX 149

typedef struct {
    vendedor vendedores [MAX];
    int cant;
}rac;

void initRAC(rac *array){
    int i;
    array->cant=0;
    for(i = 0; i < MAX; i++){
        array->vendedores[i].documento = 0;
    }
}

int localizarRAC(rac *array, unsigned long dni, int *pos){
    int i, k;
    k = 0;
    i = hashing(dni,MAX);
    int cont = 0;
    int n = 0;
    while(n<MAX && array->vendedores[(i+k)%MAX].documento != 0 && array->vendedores[(i+k)%MAX].documento != dni ){
        if(cont == 0 && array->vendedores[(i+k)%MAX].documento == 1){
            cont++;
            *pos = (i+k)%MAX;
        }
        n++;
        k += n;
    }
    if(n>=MAX){
            if(cont==0){
            return 2;
            }
            else{
            return 0;
            }

    }
    else if(array->vendedores[(i+k)%MAX].documento == dni) {
        *pos = (i + k) % MAX;
        return 1;
    }
    else  {
        if(cont == 0){
            *pos = (i+k)%MAX;
        } return 0;
    }
}

int altaRAC(rac *array, vendedor x) {
    int pos;
    int auxloc;
    if ((auxloc=localizarRAC(array, x.documento, &pos)) == 1) {
        return 0;
    }else if(auxloc==2){
      return 2;
    } else {
        array->cant++;
        array->vendedores[pos] = x;
        return 1;
    }
}

int bajaRAC(rac *array, unsigned long dni){
    int pos;
    int op;
        if (localizarRAC(array, dni, &pos) == 0) {
            return 0;
        } else {
            printf("Desea eliminar este vendedor? 1 <- SI 2 <- NO\n");
            muestraPantalla(array->vendedores[pos]);
            scanf("%d", &op);
            while (op < 1 || op > 2) {
                printf("Ingrese un valor valido. 1 <- SI 2 <- NO\n");
                scanf("%d", &op);
            }
            if (op == 1) {
                array->vendedores[pos].documento = 1;
                array->cant--;
                return 1;
            } else
                return 2;
        }
}


vendedor evocacionRAC(rac *array, unsigned long dni, int *res){
    int pos;
    vendedor auxvendedor;
    auxvendedor.documento = 0;
    *res = localizarRAC(array, dni, &pos);
    if(*res == 1){
        return array->vendedores[pos];
    }else
        return auxvendedor;
}

