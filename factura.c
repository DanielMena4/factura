#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int validacion(char cedula[11])
{
    for(int i = 0; i < strlen(cedula);i++)
    {
        if(!(isdigit(cedula[i])))
        {
        printf("\nNumero no valido");
        return 0;
        }
    }
    return 1;    
}

int cedulan(char cedula[11])
{
    int aux,aux2,aux3,snum, par;
    aux = atoi(cedula);
    aux3 = 0;
    par = 0;
    snum = aux % 10;
    aux = aux / 10;
            while(aux != 0)
        {
                if(par == 0)
            {
                if(2*(aux % 10)>10)
                {
                    aux2 = 2*(aux%10);
                    aux3+= aux2%10;
                    aux2 = aux2 / 10;
                    aux3+= aux2%10;
                    aux = aux /10;
                    par = 1;
                }
                    else
                {
                    aux3+= 2 * (aux % 10);
                    aux = aux /10;
                    par = 1;
                }
            }
            else
            {
                aux3+= aux%10;
                par = 0;
                aux= aux/10;
            }
        }
    aux3 = 10 - (aux3 % 10);
    if(snum == aux3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int ceduruc(char cedula[11])
{
int num;
    num = validacion(cedula);
    if(num == 0)
    {
        return 0;
    }
    num = cedulan(cedula);
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(){
    int menu, menu2, menu3, cuent[5], cedula;
    float subtotal;
    cuent[0] = 0;
    cuent[1] = 0;
    cuent[2] = 0;
    cuent[3] = 0;
    cuent[4] = 0;
    cedula = 0;
    menu = 0;
    subtotal = 0;
    char nombre[20] = "Consumidor";
    char apellido[20] = "Final";
    char ubicacion[20] = " ";
    char ceduaux[11] = "000000000";
    char telefono[11] = "000000000";
    char producto[2];
    while (menu != 2) {
        printf("1. Ingresar datos \n2. Consumidor final \n");
        scanf("%d", &menu);
        switch (menu)
        {
            case 1:
            printf("Ingrese el nombre: ");
            scanf("%s",nombre);
            printf("\nIngrese el apellido: ");
            scanf("%s",apellido);
            while(cedula == 0){
                printf("\nIngrese cedula/RUC: ");
                scanf("%s", ceduaux);
                cedula = ceduruc(ceduaux);    
            }
            printf("\nIngrese la ubicacion: ");
            scanf("%s", ubicacion);
            printf("\nIngrese el telefono: ");
            scanf("%s",telefono);
            menu = 2;
        break;
    case 2:
        printf("Consumidor final \n");
        break;
        default:
            printf("Ingrese un valor valido \n");
            break;
        }
    }
    menu = 0;
    while (menu!=2) {
        printf("\n1. Ingresar producto \n2. Salir\n");
        scanf("%d", &menu);
        switch (menu)
        {
            case 1:
            menu2 = 1;
            while (menu2 != 0) {
                printf("\na. llantas($150)\nb. kit de pastillas de freno($55)\nc. kit de embrague($180)\nd. Faro($70)\ne. radiador($120)\nf. Salir");
                printf("\nIngrese el producto: ");
                scanf("%s",producto);
                if (strcmp(producto,"a")==0) 
                {
                    printf("\nIngrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent[0]);
                    subtotal+= 150 * cuent[0];
                }
                else if (strcmp(producto,"b")==0)
                {
                    printf("\nIngrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent[1]);
                    subtotal+= 55 * cuent[1];
                }
                else if (strcmp(producto,"c")==0)
                {
                    printf("\nIngrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent[2]);
                    subtotal+= 180 * cuent[2];
                }
                else if (strcmp(producto,"d")==0)
                {
                    printf("\nIngrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent[3]);
                    subtotal+= 70 * cuent[3];
                }
                else if (strcmp(producto,"e")==0)
                {
                    printf("\nIngrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent[4]);
                    subtotal+= 120 * cuent[4];

                }else if (strcmp(producto,"f")==0)
                {
                    menu2 = 0;
                }
                else {
                    printf("\nIngrese un producto valido");
                }
            }
            break;
            case 2:
            break;
        default:
            printf("\nIngrese una opcion valida");
            break;
        }
    }
    printf("\nNombre: %s\nApellido: %s\nCedula/RUC: %s\nUbicacion: %s\nTelefono: %s ", nombre, apellido, ceduaux, ubicacion, telefono);
    if (cuent[0] != 0)
    {
    printf("\n\tProducto: llantas\tValor unitario: $150\tCantidad: %d\tValor combinado: $%d", cuent[0] , (cuent[0]*150));
    }
        if (cuent[1] != 0)
    {
    printf("\n\tProducto: kit de pastillas de freno\tValor unitario: $55\tCantidad: %d\tValor combinado: $%d", cuent[1] , (cuent[1]*55));
    }
        if (cuent[2] != 0)
    {
    printf("\n\tProducto: kit de embrague\tValor unitario: $180\tCantidad: %d\tValor combinado: $%d", cuent[2] , (cuent[2]*180));
    }
        if (cuent[3] != 0)
    {
    printf("\n\tProducto: faro\tValor unitario: $70\tCantidad: %d\tValor combinado: $%d", cuent[3] , (cuent[3]*70));
    }
        if (cuent[4] != 0)
    {
    printf("\n\tProducto: radiador\tValor unitario: $120\tCantidad: %d\tValor combinado: $%d", cuent[4] , (cuent[4]*120));
    }
    printf("\nSubtotal: $%.2f", subtotal);
    if (subtotal > 100 && subtotal <501)
    {
        printf("\nDescuento 5: $%.2f ", subtotal*0.05);
        subtotal-= (subtotal * 0.05);
    }
        if (subtotal > 500 && subtotal <1000)
    {
        printf("\nDescuento 7: $%.2f ", subtotal*0.07);
        subtotal-=(subtotal * 0.07);
    }
        if (subtotal >1000)
    {
        printf("\nDescuento 10: $%.2f ", subtotal * 0.1);
        subtotal-=(subtotal * 0.1);
    }

    printf("\nIva 12: $%.2f", subtotal*0.12);
    subtotal = subtotal * 1.12;
    printf("\nTotal: $%.2f", subtotal);
    

    return 0;
}
