    #ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#endif // ABB_H_INCLUDED

#include "Vendedor.h"

typedef struct node {
    vendedor vipd;
    struct node *hi;
    struct node *hd;
} nodoabb;

typedef struct {
    nodoabb *raiz;
    nodoabb *pos;
    nodoabb *padre;

} arbol;

void initabb(arbol *abb){
    abb->padre=NULL;
    abb->raiz=NULL;
    abb->pos=NULL;
}

void resetabb(arbol *abb){
    abb->padre=NULL;
    abb->pos=NULL;
}

int localizarabb(unsigned long doc, arbol *abb) {
    nodoabb *auxpos, *ant;
    auxpos = abb->raiz;
    ant = abb->raiz;

    while (auxpos != NULL && doc != auxpos->vipd.documento) {
        ant = auxpos;
        if (doc > auxpos->vipd.documento) {
            auxpos = auxpos->hd;
        } else {
            auxpos = auxpos->hi;
        }
    }
    abb->padre = ant;
    abb->pos = auxpos;
    if (auxpos == NULL) {
        return 0;
    } else {
        return 1;
    }
}

int altaabb(arbol *abb, vendedor x) {
    nodoabb *auxnptr;
    if (abb->raiz == NULL) {
        auxnptr = malloc(sizeof(nodoabb));
        if(auxnptr==NULL){
            return 2;
        }
        auxnptr->hi=NULL;
        auxnptr->hd=NULL;
        auxnptr->vipd = x;
        abb->raiz = auxnptr;
        return 1;
    } else if (localizarabb(x.documento, abb) == 0) {
        auxnptr = malloc(sizeof(nodoabb));
        if(auxnptr==NULL){
            return 2;
        }
        auxnptr->hi=NULL;
        auxnptr->hd=NULL;
        auxnptr->vipd = x;
        if (x.documento > abb->padre->vipd.documento) {
            abb->padre->hd = auxnptr;
        } else {
            abb->padre->hi = auxnptr;
        }
        return 1;
    } else {
        return 0;
    }
}

int bajaabb(arbol *abb, unsigned long doc) {
    int op;
    if (localizarabb(doc,abb)==0){
        return 0;
    }//confirmar
    else{
        muestraPantalla(abb->pos->vipd);
        printf("Desea eliminar este vendedor? 1=SI, 2=NO \n");
        scanf("%d", &op);
        if (op == 1) {
            if(abb->pos->hd!=NULL){
                if(abb->pos->hi!=NULL){
                             //Caso con dos hijos
                    nodoabb *auxpos= abb->pos->hd;
                    nodoabb *auxposp= abb->pos;

                    while(auxpos->hi!=NULL) {
                        auxposp = auxpos;
                        auxpos = auxpos->hi;
                    }
                    abb->pos->vipd=auxpos->vipd;
                    if(auxpos==auxposp){
                        abb->pos->hd=auxpos->hd;
                    }
                    else {
                        auxposp->hi=auxpos->hd;
                    }
                    free(auxpos);
                    return 1;
                }
                else{
                    //Caso con un hd != NULL, hi NULL
                    if(abb->pos==abb->raiz){
                        abb->raiz=abb->raiz->hd;
                    }
                    else if(abb->pos==abb->padre->hi){
                        abb->padre->hi=abb->pos->hd;

                    }
                    else{
                        abb->padre->hd=abb->pos->hd;

                    }
                    free(abb->pos);
                    return 1;
                }
                //caso con hi!=NULL hd NULL
            } else {
                if(abb->raiz==abb->pos){
                        abb->raiz=abb->raiz->hi;
                }
                else{
                    if(abb->pos==abb->padre->hi){
                        abb->padre->hi=abb->pos->hi;
                    }
                    else{
                        abb->padre->hd=abb->pos->hi;

                    }
                    free(abb->pos);
                }

                return 1;
            }

        }
        else {
            return 2;
        }
    }
}

vendedor evocacionabb(arbol *abb,unsigned long x, int *auxres){
    vendedor auxvendedor;
    auxvendedor.documento=100000000;
    *auxres= localizarabb(x,abb);
    if (*auxres==1){
        return abb->pos->vipd;
    }
    else return auxvendedor;
}

void preordenabb(nodoabb *nodo, int *i){
    if (nodo==NULL){
    }
    else{

        printf("Nodo: %d\n",*i);
        muestraPantalla(nodo->vipd);
        (*i)++;
        if(nodo->hi!=NULL){
            printf("\nDNI hijo izquierdo: %lu\n",nodo->hi->vipd.documento);
        } else{
            printf("\nEl nodo no tiene hijo izquierdo. \n");
        }
        if(nodo->hd!=NULL){
            printf("\nDNI hijo derecho: %lu\n",nodo->hd->vipd.documento);
        } else{
            printf("\nEl nodo no tiene hijo derecho.\n");
        }
        getchar();
        preordenabb(nodo->hi,i);
        preordenabb(nodo->hd,i);
    }

}

