#include <stdio.h>
#include "RAC.h"


void inicio() {
    int op = 0;
    int auxop = 0;
    int auxres;
    int auxi;
    vendedor auxvendedor;
    char auxchar;
    unsigned long auxdocumento;
    FILE *f1;
    arbol abb;
    rs ReSe;
    rac ReAbCua;
    initabb(&abb);
    initRAC(&ReAbCua);
    init(&ReSe);
    printf("        Bienvenido al sistema! Que estructura desea usar? \n\n\n");
    printf("<1>         Arbol binario de busqueda (ABB). \n\n");
    printf("<2>         Rebalse separado (RS).  \n\n");
    printf("<3>         Rebalse Abierto Cuadratico (RAC).  \n\n");
    printf("<4>         Salir.\n\n");
    do {
        printf("Ingrese una operacion: ");
        scanf("%d", &op);
    } while (0 >= op || op > 4);
    while (op != 4 && auxop != 7) {
        if (op != 4) {
            printf("       Que operacion desea realizar? \n\n\n");
            printf("<1>         Cargar vendedor. \n\n");
            printf("<2>         Eliminar vendedor.  \n\n");
            printf("<3>         Consultar un vendedor.  \n\n");
            printf("<4>         Mostrar toda la estructura.  \n\n");
            printf("<5>         Precarga.  \n\n");
            printf("<6>         Cambiar estructura. \n\n");
            printf("<7>         Salir. \n\n");
            do {
                printf("Ingrese una operacion: \n");
                scanf("%d", &auxop);
            } while (0 >= op || auxop > 7);
            switch (auxop){
                //ALTA
                case 1:
                    if (op == 1) {
                        cargaVendedor(&auxvendedor);
                        auxres = altaabb(&abb, auxvendedor);
                        if (auxres == 2) {
                            printf("La estructura esta llena, no pueden cargarse mas vendedores");
                        }
                        if (auxres == 1) {
                            printf("El vendedor se cargo correctamente.\n");
                        } else if (auxres == 0) {
                            printf("Ya existe un vendedor con ese documento.\n");
                        }
                    } else if (op == 2) {
                        cargaVendedor(&auxvendedor);
                        auxres = altars(&ReSe, auxvendedor);
                        if (auxres == 2) {
                            printf("la estructura esta llena. No pueden cargarse mas vendedores.\n");
                        }
                        if (auxres == 1) {
                            printf("El vendedor se cargo correctamente.\n");
                        } else if (auxres == 0) {
                            printf("Ya existe un vendedor con ese documento.\n");
                        }
                    }else {
                        if(ReAbCua.cant >= MAX){
                            printf("La estructura esta llena. No pueden cargarse mas vendedores.");
                        }else {
                            cargaVendedor(&auxvendedor);
                            auxres = altaRAC(&ReAbCua, auxvendedor);
                            if (auxres == 0) {
                                printf("Ya existe un vendedor con ese documento. \n");
                            }else{
                                printf("El vendedor se cargo correctamente. \n");
                            }
                        }
                    }
                    break;

                    //BAJA
                case 2:
                    if (op == 1) {
                        if (abb.raiz!=NULL) {
                            printf("Ingrese el documento del vendedor a eliminar \n");
                            scanf("%lu", &auxdocumento);
                            auxres = bajaabb(&abb, auxdocumento);
                            if (auxres == 1) {
                                printf("Baja realizada con exito.\n");
                            } else if (auxres == 0) {
                                printf("No existe un vendedor con ese documento.\n");
                            }
                            else{
                                printf("Baja cancelada\n");
                            }
                        } else {
                            printf("La estructura esta vacia, no puede eliminarse un elemento \n");
                        }

                    } else if(op == 2){
                        if (ReSe.contador != 0) {
                            printf("Ingrese el documento del vendedor a eliminar: \n");
                            scanf("%lu", &auxdocumento);
                            auxres = bajars(&ReSe, auxdocumento);
                            if (auxres == 1) {
                                printf("Baja realizada con exito.\n");
                            } else if (auxres == 0) {
                                printf("No existe un vendedor con ese documento.\n");
                            }
                        } else {
                            printf("La estructura esta vacia. No puede eliminarse un elemento. \n");
                        }
                    }else{
                        if(ReAbCua.cant != 0){
                            printf("Ingrese el documento del vendedor a eliminar. \n");
                            scanf("%lu", &auxdocumento);
                            auxres = bajaRAC(&ReAbCua, auxdocumento);
                            if(auxres == 1){
                                printf("Baja realizada con exito. \n");
                            }else if(auxres == 0){
                                printf("No existe un vendedor con ese documento. \n");
                            }
                        }else {
                            printf("La estructura esta vacia. No puede eliminarse un elemento. \n");
                        }
                    }
                    break;

                    //CONSULTAR
                case 3:
                    if (op == 1) {
                        if (abb.raiz !=NULL) {
                            printf("Ingrese el documento del vendedor a consultar: \n");
                            scanf("%lu", &auxdocumento);
                            getchar();
                            auxvendedor = evocacionabb(&abb, auxdocumento, &auxres);
                            if (auxres == 1) {
                                muestraPantalla(auxvendedor);
                            } else {
                                printf("No existe un vendedor con ese documento \n");
                            }

                        } else {
                            printf("La estructura esta vacia, no se puede consultar. \n");
                        }

                    } else if(op == 2) {
                        if (ReSe.contador != 0) {
                            printf("Ingrese el documento del vendedor a consultar: \n");
                            scanf("%lu", &auxdocumento);
                            getchar();
                            auxvendedor = evocacionrs(&ReSe, auxdocumento, &auxres);
                            if (auxres == 1) {
                                muestraPantalla(auxvendedor);
                            } else {
                                printf("No existe un vendedor con ese documento. \n");
                            }
                        } else {
                            printf("La estructura esta vacia. No se puede consultar. \n");
                        }
                    }else {
                        if(ReAbCua.cant != 0){
                            printf("Ingrese el documento del vendedor a consultar: \n");
                            scanf("%lu", &auxdocumento);
                            getchar();
                            auxvendedor = evocacionRAC(&ReAbCua, auxdocumento, &auxres);
                            if(auxres == 1){
                                muestraPantalla(auxvendedor);
                            }else{
                                printf("No existe un vendedor con ese documento. \n");
                            }
                        }else
                            printf("La estructura esta vacia. No se puede consultar.\n");
                    }
                    break;

                    //Mostrar toda la estructura
                case 4:
                    getchar();
                    if (op == 1) {
                        if (abb.raiz!=NULL ) {
                            auxi=1;
                            preordenabb(abb.raiz,&auxi);
                        } else {
                            printf("La estructura esta vacia\n");
                        }
                    } else if(op == 2){
                        if (ReSe.contador != 0) {
                            int i;
                            for (i = 0; i < MLV; i++) {
                                printf("\n Lista %d\n",i+1);
                                ReSe.cur=ReSe.arrlv[i].acc;
                                ReSe.aux=ReSe.arrlv[i].acc;
                                if(ReSe.cur==NULL){
                                    printf("\n La lista esta vacia.\n");
                                }
                                else{
                                    do{
                                        muestraPantalla(ReSe.cur->vipd);
                                        getchar();
                                        ReSe.aux=ReSe.cur;
                                        ReSe.cur=ReSe.cur->next;
                                    } while (ReSe.cur!=NULL);
                                }

                            }
                        } else {
                            printf("La estructura esta vacia. \n");
                        }
                    }else{
                        if(ReAbCua.cant != 0){
                            int i;
                            for(i = 0; i < MAX; i++){
                                printf("Celda: %d\n",i);
                                if(ReAbCua.vendedores[i].documento == 0){
                                    printf("\n\nCELDA VIRGEN. \n\n");
                                }else if(ReAbCua.vendedores[i].documento == 1){
                                    printf("\n\nCELDA VACIA. \n\n");
                                }else {
                                    muestraPantalla(ReAbCua.vendedores[i]);
                                }
                                getchar();
                            }
                        }else{
                            printf("La estructura esta vacia. \n");
                        }
                    }
                    break;

                    //Precarga
                case 5:
                    if ((f1 = fopen("vendedores.txt", "r")) == NULL) {
                         printf("El archivo no pudo ser abierto, por favor intentelo de nuevo mas tarde. \n");
                    } else {
                        auxres=0;
                        if (op == 1) {
                            while (feof(f1) == 0&& auxres!=2) {

                                //Documento
                                fscanf(f1, "%lu", &auxvendedor.documento);
                                fscanf(f1, "%c", &auxchar);

                                //Nombre
                                /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                                /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                                fgets(auxvendedor.nombre, 51, f1);
                                /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                                /*strtok limpia el caracter\n*/
                                strtok(auxvendedor.nombre, "\n");

                                //Telefono
                                /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                                /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                                fgets(auxvendedor.telefono, 17, f1);
                                /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                                /*strtok limpia el caracter\n*/
                                strtok(auxvendedor.telefono, "\n");



                                //Monto
                                fscanf(f1, "%f", &auxvendedor.monto);
                                fscanf(f1, "%c", &auxchar);

                                //Cantidad
                                fscanf(f1, "%d", &auxvendedor.cantidad);
                                fscanf(f1, "%c", &auxchar);

                                //Canal venta
                                fgets(auxvendedor.canal, 21, f1);
                                strtok(auxvendedor.canal, "\n");

                                //Alta
                                auxres=altaabb(&abb, auxvendedor);
                            }
                            printf("Precarga Terminada.\n");
                            if(auxres==2){
                                printf("La estructura se lleno.\n");
                            }

                        } else if(op ==2){
                            while (feof(f1) == 0&& auxres!=2) {

                                //Documento
                                fscanf(f1, "%lu", &auxvendedor.documento);
                                fscanf(f1, "%c", &auxchar);

                                //Nombre
                                /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                                /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                                fgets(auxvendedor.nombre, 51, f1);
                                /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                                /*strtok limpia el caracter \n*/
                                strtok(auxvendedor.nombre, "\n");

                                //Telefono
                                /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                                /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                                fgets(auxvendedor.telefono, 17, f1);
                                /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                                /*strtok limpia el caracter\n*/
                                strtok(auxvendedor.telefono, "\n");

                                //Monto
                                fscanf(f1, "%f", &auxvendedor.monto);
                                fscanf(f1, "%c", &auxchar);

                                //Cantidad
                                fscanf(f1, "%d", &auxvendedor.cantidad);
                                fscanf(f1, "%c", &auxchar);

                                //Canal venta
                                fgets(auxvendedor.canal, 22, f1);
                                strtok(auxvendedor.canal, "\n");
                                //Alta
                                auxres=altars(&ReSe, auxvendedor);
                            }
                            printf("Precarga Terminada.\n");
                            if(auxres==2){
                                printf("La estructura se lleno.\n");
                            }

                        }else{
                            while (feof(f1) == 0&&ReAbCua.cant<MAX) {
                                //Documento
                                fscanf(f1, "%lu", &auxvendedor.documento);
                                fscanf(f1, "%c", &auxchar);

                                //Nombre
                                /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                                /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                                fgets(auxvendedor.nombre, 51, f1);
                                /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                                /*strtok limpia el caracter \n*/
                                strtok(auxvendedor.nombre, "\n");

                                //Telefono
                                /*https://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf*/
                                /*usamos una funcion que permite espacios y tiene proteccion de buffer.*/
                                fgets(auxvendedor.telefono, 17, f1);
                                /*https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input*/
                                /*strtok limpia el caracter\n*/
                                strtok(auxvendedor.telefono, "\n");

                                //Monto
                                fscanf(f1, "%f", &auxvendedor.monto);
                                fscanf(f1, "%c", &auxchar);

                                //Cantidad
                                fscanf(f1, "%d", &auxvendedor.cantidad);
                                fscanf(f1, "%c", &auxchar);

                                //Canal venta
                                fgets(auxvendedor.canal, 22, f1);
                                strtok(auxvendedor.canal, "\n");

                                //Alta
                                auxres=altaRAC(&ReAbCua, auxvendedor);
                            }
                            printf("Precarga Terminada.\n");
                            if(ReAbCua.cant>=MAX){
                                printf("La estructura se lleno.\n");
                            }
                        }
                        fclose(f1);
                    }
                    break;

                    //Cambiar estructura
                case 6:
                    printf("      Sobre que estructura desea operar? \n\n");
                    printf("<1>         Arbol binario de busqueda. \n\n");
                    printf("<2>         Rebalse separado.  \n\n");
                    printf("<2>         Rebalse Abierto Cuadratico.  \n\n");

                    printf("<3>         Salir.\n\n\n");
                    do {
                        printf("Ingrese una operacion: ");
                        scanf("%d", &op);
                    } while (0 >= op || op > 3);
                    break;
            }
        }
    }
}


int main() {
    inicio();
    return 0;
}
