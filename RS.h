#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED

#endif // RS_H_INCLUDED

#define MLV 60
#include "LV.h"

typedef struct {
    lista arrlv[MLV];
    nodolv *cur;
    nodolv *aux;
    int contador;
}rs;

int hashing (unsigned long dni, int m) {
    char x[8];
    int longitud, i;
    int contador = 0;
    sprintf(x,"%lu", dni);
    longitud = strlen(x);

    for (i = 0; i < longitud; i++)
        contador += ((int) x[i]) * (i + 1);
    return (contador % m);
}

void init(rs *rs){
    int i;
    for (i=0; i<MLV;i++){
        initlv(&rs->arrlv[i]);
    }
    rs->contador=0;
}

int localizarrs(rs *rs, unsigned long doc, int *j) {
    *j = hashing(doc, MLV);
    if(rs->arrlv[*j].acc==NULL){
        return 0;
    }
    rs->cur = rs->arrlv[*j].acc;
    rs->aux = rs->arrlv[*j].acc;
    while (rs->cur->next != NULL && rs->cur->vipd.documento != doc) {
        rs->aux = rs->cur;
        rs->cur = rs->cur->next;
    }
    if (rs->cur->vipd.documento == doc) {
        return 1;
    } else {
        return 0;
    }
}

int altars(rs *rs, vendedor x) {
    int j;
    if (localizarrs(rs,x.documento,&j)==0){
        nodolv *l = (nodolv *) malloc(sizeof(nodolv));
            if (l == NULL) {
                return 2;
            }
            rs->contador++;
            l->vipd = x;
            if(rs->arrlv[j].acc==NULL){
                l->next = NULL;
                rs->arrlv[j].acc=l;
                return 1;
            }
            else{
                l->next=rs->arrlv[j].acc;
                rs->arrlv[j].acc=l;
                return 1;
            }
        }
    else return 0;
}


int bajars(rs *rs, unsigned long doc) {
    int op;
    int j;
    if (localizarrs(rs, doc,&j) == 0) {
            return 0;
    } else {
        muestraPantalla(rs->cur->vipd);
        printf("Desea eliminar este vendedor? 1=SI, 2=NO \n");
        scanf("%d", &op);
        if (op == 1) {
            rs->contador--;
            if (rs->cur == rs->arrlv[j].acc) {
                rs->arrlv[j].acc = rs->arrlv[j].acc->next;
                rs->aux = rs->arrlv[j].acc;
                free(rs->cur);
                rs->cur = rs->arrlv[j].acc;
                } else {
                rs->aux->next = rs->cur->next;
                free(rs->cur);
                rs->cur = rs->aux->next;
                }
            return 1;
            } else {
                return 2;
            }
        }
}


vendedor evocacionrs(rs *rs, unsigned long doc, int *res) {
    vendedor auxvendedor;
    auxvendedor.documento = 100000000;
    int j;
    *res = localizarrs(rs, doc, &j);
    if (*res == 1) {
        return rs->cur->vipd;
    } else return auxvendedor;
}
