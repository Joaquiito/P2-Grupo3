#ifndef VENDEDOR_H_INCLUDED
#define VENDEDOR_H_INCLUDED

#endif // VENDEDOR_H_INCLUDED

#include <malloc.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    unsigned long documento;
    char nombre [52];
    char telefono [17];
    float monto;
    unsigned int cantidad;
    char canal[22];
}vendedor;

void muestraPantalla(vendedor x){
    printf("\nNombre: %s\n", x.nombre);
    printf("DNI: %lu\n", x.documento);
    printf("Telefono: %s\n", x.telefono);
    printf("Monto: %f\n", x.monto);
    printf("Cantidad vendida: %u\n", x.cantidad);
    printf("Canal de venta: %s\n", x.canal);
}

void cargaVendedor(vendedor *auxvendedor){
    int i;
    printf("Ingrese el documento: \n");
    scanf("%lu",&auxvendedor->documento);
    getchar();
    printf("Ingrese el nombre:\n");
    fgets(auxvendedor->nombre,52,stdin);
    strtok(auxvendedor->nombre,"\n");
    for(i=0;i<strlen(auxvendedor->nombre);i++){
        auxvendedor->nombre[i]=toupper(auxvendedor->nombre[i]);
    }
    printf("Ingrese el numero de telefono: \n");
    fgets(auxvendedor->telefono,17,stdin);
    strtok(auxvendedor->telefono,"\n");
    printf("Ingrese el monto: \n");
    scanf("%f",&auxvendedor->monto);
    printf("Ingrese la cantidad de ventas: \n");
    scanf("%u", &auxvendedor->cantidad);
    getchar();
    printf("Ingrese el canal de ventas: \n");
    fgets(auxvendedor->canal,21,stdin);
    strtok(auxvendedor->nombre,"\n");
    for(i=0;i<strlen(auxvendedor->nombre);i++){
        auxvendedor->nombre[i]=toupper(auxvendedor->nombre[i]);
    }

}
