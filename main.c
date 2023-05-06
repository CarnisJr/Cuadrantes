#include<stdio.h>

int main(void){

    int acum1, acum2, acum3, acum4, contador, cantidadPuntos, acumEjeX, acumEjeY;
    int x, y; /*Cuando declaro estas variables como float, el programa no sirve. No entiendo muy bien el porqué
                de este problema*/

    contador = 1;
    acum1 = 0;
    acum2 = 0;
    acum3 = 0;
    acum4 = 0;
    acumEjeX = 0;
    acumEjeY = 0;

    printf("¿Cuántos puntos desea ingresar?: ");
    scanf("%d", &cantidadPuntos);

    while(cantidadPuntos > 0){

        printf("Ingrese la cordenada x del punto número %d: ", contador);
        scanf("%d", &x);
        printf("Ingrese la cordenada y del punto número %d: ", contador++);
        scanf("%d", &y);

        while(x == 0 && y == 0){
        
            puts("\tSu punto está en el origen. Ingrese otro punto");
            printf("Ingrese la cordenada x del punto número %d: ", --contador);
            scanf("%d", &x);
            printf("Ingrese la cordenada y del punto número %d: ", contador++);
            scanf("%d", &y);
        }

/*Tengo la sensación que el problema está aquí. Porque cuando las variables "x" y "y" son de tipo float pareciera que no entra en los if's
  y los acumuladores no funcionan*/
  
        if(x >= 0 && y > 0){
            if(x == 0)
                ++acumEjeY; //coordenada en Oy
            else
                ++acum1; //coordenada en el primer cuadrante
        }
        if(x < 0 && y >= 0){
            if(y == 0)
                ++acumEjeX; //coordenada en Ox
            else
                ++acum2; //coordenada en segundo cuadrante
        }
        if(x <= 0 && y < 0){
            if(x == 0)
                ++acumEjeY; //coordenada en Oy
            else
                ++acum3; //coordenada en el tercer cuadrante
        }
        if(x > 0 && y <= 0){
            if(y == 0)
                ++acumEjeX; //coordenada en Ox
            else
                ++acum4; //coordenada en el cuarto cuadrante
        }
   
        --cantidadPuntos;
    }

    printf("Hay %d puntos en el primer cuadrante\n", acum1);
    printf("Hay %d puntos en el segundo cuadrante\n", acum2);   
    printf("Hay %d puntos en el tercer cuadrante\n", acum3);
    printf("Hay %d puntos en el cuarto cuadrante\n", acum4);
    printf("Hay %d puntos en Ox\n", acumEjeX);
    printf("Hay %d puntos en Oy\n", acumEjeY);

    return 0;
}


/*Otra forma (creo que más compleja)

#include<stdio.h>
int main(void){

    int acum1, acum2, acum3, acum4, contador, acumEjeX, acumEjeY;
    int x, y;
    char valorCentinela;

    valorCentinela = 'n';
    contador = 1;
    acum1 = 0;
    acum2 = 0;
    acum3 = 0;
    acum4 = 0;
    acumEjeX = 0;
    acumEjeY = 0;

    do{
        printf("Ingrese la cordenada x del punto número %d: ", contador);
        scanf("%d", &x);
        printf("Ingrese la cordenada y del punto número %d: ", contador++);
        scanf("%d", &y);

        //Comprobar que la coordenada ingresada no esté en el origen
        while (x == 0 && y == 0){
            puts("Su punto está en el origen. Ingrese otro punto");
            printf("Ingrese la cordenada x del punto número %d: ", --contador);
            scanf("%d", &x);
            printf("Ingrese la cordenada y del punto número %d: ", contador++);
            scanf("%d", &y);           
        }

        if(x >= 0 && y > 0){
            if(x == 0)
                ++acumEjeY; //coordenada en Oy
            else
                ++acum1; //coordenada en el primer cuadrante
        }
        if(x < 0 && y >= 0){
            if(y == 0)
                ++acumEjeX; //coordenada en Ox
            else
                ++acum2; //coordenada en segundo cuadrante
        }
        if(x <= 0 && y < 0){
            if(x == 0)
                ++acumEjeY; //coordenada en Oy
            else
                ++acum3; //coordenada en el tercer cuadrante
        }
        if(x > 0 && y <= 0){
            if(y == 0)
                ++acumEjeX; //coordenada en Ox
            else
                ++acum4; //coordenada en el cuarto cuadrante
        }
        
        //Verficar si se quiere continuar ingresar más puntos
        fflush(stdin);
        printf("Para continuar ingresando punto presione \'y\' y \'n\' para terminar el programa\n");
        scanf("%c", &valorCentinela);

    }while (valorCentinela != 'n');

    printf("Hay %d puntos en el primer cuadrante\n", acum1);
    printf("Hay %d puntos en el segundo cuadrante\n", acum2);   
    printf("Hay %d puntos en el tercer cuadrante\n", acum3);
    printf("Hay %d puntos en el cuarto cuadrante\n", acum4);
    printf("Hay %d puntos en Ox\n", acumEjeX);
    printf("Hay %d puntos en Oy\n", acumEjeY);

    return 0;
}
*/