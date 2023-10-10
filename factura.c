#include <stdio.h>
#include <string.h>
int ncedula(){
int cedula, ceduaux , aux , aux2 ,snum , par;
aux = 0;
par = 0;
    while (snum != aux ) {
        printf("\nIngrese la cedula/RUC: ");
        scanf("%d", &cedula);
        ceduaux = cedula;
        snum = cedula % 10;
        cedula = cedula / 10;
            while(cedula != 0)
        {
            if(par==0)
        {
            if(2*(cedula % 10)>10)
            {
                aux2 = 2*(cedula%10);
                aux+= aux2%10;
                aux2 = aux2 / 10;
                aux+= aux2%10;
            }
            else
            {
                aux+= 2 * (cedula % 10); 
            }
            cedula = cedula /10;
            par = 1;
        }
        else
        {
            aux+= cedula%10;
            par = 0;
            cedula= cedula/10;
        }
    }
            aux = (aux%10);
            aux = 10 - (aux % 10);
        if (snum != aux) {
            printf("\n Numero de cedula invalido");
        }
    }
    return (ceduaux);
}
int main(){
    int menu, ceduaux, aux, subtotal, cuent_a, cuent_b,cuent_c, cuent_d, cuent_e;
    cuent_e = 0;
    cuent_b = 0;
    cuent_a = 0;
    cuent_c = 0;
    cuent_d = 0;
    menu = 0;
    subtotal = 0;
    char nombre[20] = "Consumidor";
    char apellido[20] = "Final";
    char ubicacion[20] = " ";
    char telefono[20] = "000000000";
    char producto[10];
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
            ceduaux = ncedula();
            printf("\nIngrese la ubicacion: ");
            scanf("%s", ubicacion);
            printf("\nIngrese el telefono: ");
            scanf(telefono,20,stdin);
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
            aux = 1;
            while (aux != 0) {
                printf("\na. llantas($150)\nb. kit de pastillas de freno($55)\nc. kit de embrague($180)\nd. Faro($70)\ne. radiador($120)\ng. Salir");
                printf("\nIngrese el producto: ");
                scanf("%s",producto);
                if (strcmp(producto,"a")==0) {
                    printf("\n Ingrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent_a);
                    subtotal+= 150 * cuent_a;
                }
                else if (strcmp(producto,"b")==0)
                {
                    printf("\n Ingrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent_b);
                    subtotal+= 55 * cuent_b;
                    cuent_b++;
                }
                else if (strcmp(producto,"c")==0)
                {
                    printf("\n Ingrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent_c);
                    subtotal+= 180 * cuent_c;
                    cuent_c++;
                }
                else if (strcmp(producto,"d")==0)
                {
                    printf("\n Ingrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent_d);
                    subtotal+= 70 * cuent_d;
                    cuent_d++;
                }
                else if (strcmp(producto,"e")==0)
                {
                    printf("\n Ingrese la cantidad del producto comprado: ");
                    scanf("%d", &cuent_e);
                    subtotal+= 120 * cuent_e;
                    cuent_e++;
                }else if (strcmp(producto,"g")==0)
                {
                    aux = 0;
                }
                else {
                    printf("\n Ingrese un producto valido");
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
    printf("\n %s , %s , %d , %s, %s ", nombre, apellido, ceduaux, ubicacion, telefono);
    printf("\n\t Producto \t Valor unitario \t cantidad \t Valor combinado");
    if (cuent_a != 0)
    {
    printf("\n\tllantas \t  $150 \t  \t %d \t %d", cuent_a , (cuent_a*150));
    }
        if (cuent_b != 0)
    {
    printf("\n\tkit de pastillas de freno  $55  \t\t %d \t %d", cuent_b , (cuent_b*55));
    }
        if (cuent_c != 0)
    {
    printf("\n\tkit de embrague \t \t $180  \t %d \t %d", cuent_c , (cuent_c*180));
    }
        if (cuent_d != 0)
    {
    printf("\n\tfaro \t \t \t  $70  \t %d \t %d", cuent_d , (cuent_d*70));
    }
        if (cuent_e != 0)
    {
    printf("\n\tradiador \t  $120  \t \t %d \t %d", cuent_d , (cuent_d*120));
    }
    printf("subtotal: %d", subtotal);
    if (subtotal > 100 && subtotal <501)
    {
        subtotal = subtotal * 0,5;
    }
        if (subtotal > 500 && subtotal <1000)
    {
        subtotal = subtotal * 0,7;
    }
        if (subtotal >1000)
    {
        subtotal = subtotal * 0,10;
    }
    subtotal = subtotal * 1.12;
    printf("Iva 12 %d", subtotal * 0.12);
    printf("Total: %d", subtotal);
    

    return 0;
}