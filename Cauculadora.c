#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
void converter(int numero,int escolha){
    int binario[32];
    int cont=0;
    if(escolha==1){
        
        while(numero>0){
            binario[cont]= numero%2;
            int resultado=numero/2;
            
            printf("%d/2=%d,resto=%d\n",numero,resultado,binario[cont]);
            numero=resultado;
            cont++;
        }
    }
    else if(escolha==2){
        while(numero>0){
            int resultado=numero/8;
            int resto=numero%8;
            
            printf("%d/8=%d,resto=%d\n",numero,resultado,resto);
            binario[cont]=resto;
            
            
            numero=resultado;
            cont++;
        }
    }
    else if(escolha==3){
        while(numero>0){
            int resultado=numero/16;
            int resto=numero%16;
            if(numero%16==10){
                printf("%d/16=%d,resto=%d\n",numero,resultado,resto);
                binario[cont]=0xA;
            }
            else if(numero%16==11){
                printf("%d/16=%d,resto=B\n",numero,resultado,resto);
                binario[cont]=0xB;
            }
            else if(numero%16==12){
                printf("%d/16=%d,resto=C\n",numero,resultado,resto);
                binario[cont]=0xC;
            }
            else if(numero%16==13){
                printf("%d/16=%d,resto=D\n",numero,resultado,resto);
                binario[cont]=0xD;
            }
            else if(numero%16==14){
                printf("%d/16=%d,resto=E\n",numero,resultado,resto);
                binario[cont]=0xE;
            }
            else if(numero%16==11){
                printf("%d/16=%d,resto=F\n",numero,resultado,resto);
                binario[cont]=0xF;
            }
            else{
                printf("%d/16=%d,resto=%d\n",numero,resultado,resto);
                binario[cont]=resto;
            }
            numero=resultado;
            cont++;
        }
    }
    else if(escolha==4){
        while(numero>0){
            int resto=numero %10;
            int resultado=numero/10;
            printf("%d/10=%d,resto=%d\n",numero,resultado,resto);
            
            numero=resultado;
            binario[cont]=resto;
            cont++;
            

        }
        printf("Agora vamos transforma o resto das divisoes em numeros binarios com 4bits\n");
        
    }
   
    printf("o resultado da conversão foi:");
    for(int i=cont-1;i>=0;i--){
        if(escolha==3){
            printf("%X",binario[i]);
        }
         else if (escolha == 4){ 
             if(binario[i]==0){
                printf("0000 ");
            }
            else if(binario[i]==1){
                printf("0001 ");
            }
            else if(binario[i]==2){
                printf("0010 ");
            }
            else if(binario[i]==3){
                printf("0011 ");
            }
            else if(binario[i]==4){
                printf("0100 ");
            }
            else if(binario[i]==5){
                printf("0101 ");
            }
            else if(binario[i]==6){
                printf("0110 ");
            }
            else if(binario[i]==7){
                printf("0111 ");
            }
            else if(binario[i]==8){
                printf("1000 ");
            }
            else if(binario[i]==9){
                printf("1001 ");
            }
            
        }
        
        else{
            printf("%d",binario[i]);
        }
        
    }
    printf("\n");
    
    
}
void complemento2(int numero){
    int binario[16];
    int cont=0;
    int sinal=0;
    int16_t a2 = (int16_t)numero; 
    if(numero<0){
        sinal++;
        numero=abs(numero);
    }
    while(cont<16){
        int resto=numero%2;
        int resultado=numero/2;
        printf("%d/2=%d,resto=%d\n",numero,resultado,resto);
        numero=resultado;
        binario[cont]=resto;
        cont++;
    }
    
    for(int i=15;i>=0;i--){
        
        printf("%d",binario[i]);
        if (i % 4 == 0) printf(" "); 
    }
    printf("\n");
    printf("Agora vamos inverter depois do primeiro 1 da direita esse numero binario para deixar em complemento a2: ");
     for (int i = 15; i >= 0; i--) {
        printf("%d", (a2 >> i) & 1);
        if (i % 4 == 0) printf(" ");  // Adiciona espaço a cada 4 bits para leitura mais fácil
    }
    
    
    
}

int main(void){
    int numero;
    int escolha=0;
    while(escolha!=6){
        printf("digite:\n1-Caso queira converter decimal para base de 2.\n2-converter decimal para base de 8.\n3-de decimal para base de 16.\n4-decimal para BCD\n5-decimal para complemento a2.\n6-)para sair.");
        scanf("%d",&escolha);
        if(escolha==1){
            printf("digite o numero que deseja converter:");
            scanf("%d",&numero);
            converter(numero,escolha);
        }
        else if(escolha==2){
            printf("digite o numero que deseja converter:");
            scanf("%d",&numero);
            converter(numero,escolha);
        }
        else if(escolha==3){
            printf("digite o numero que deseja converter:");
            scanf("%d",&numero);
            converter(numero,escolha);
        }
        else if(escolha==4){
            printf("digite o numero que deseja converter:");
            scanf("%d",&numero);
            converter(numero,escolha);
        }
        else if(escolha==5){
            printf("digite o numero que deseja converter:");
            scanf("%d",&numero);
            complemento2(numero);
        }
        else if(escolha==6){
            break;
        }
    }
    

    
    return 0;
}
