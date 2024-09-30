#include <LiquidCrystal.h>  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 



 int porta;
 String botao;
 int estado = 1;
 int ponto = 0;
 boolean flag = false;
 int aux = 0; 
 bool pulado = false;
 

void setup()   {  
  lcd.begin(16, 2); 
}  



void loop()  { 

  switch (estado) {

    case 1: 
            ponto = 0;
            
            lcd.clear();
          lcd.home();
          lcd.print(" Bem vindos ao");
        lcd.setCursor(0, 1);
        lcd.print(" Formula E Quiz"); 
            
            delay (3000);

            lcd.clear();
            lcd.home();  
            lcd.print(" Use as Teclas"); 
            lcd.setCursor(0,1);  
            lcd.print("   UP e DOWN"); 

            delay (3000);
    
        lcd.clear();
            lcd.home();  
            lcd.print("Para escolher a"); 
            lcd.setCursor(0,1);  
            lcd.print("resposta correta"); 

            delay (3000);
    
        lcd.clear();
            lcd.home();  
            lcd.print("E a tecla LEFT"); 
            lcd.setCursor(0,1);  
            lcd.print("para retornar");
    
        delay (3000);
    
        lcd.clear();
            lcd.home();  
            lcd.print("Tecle SELECT p/"); 
            lcd.setCursor(0,1);  
            lcd.print("   confirmar"); 

            delay (3000);
    
        lcd.clear();
            lcd.home();  
            lcd.print("Iniciando o Quiz"); 
            lcd.setCursor(0,1);  
            lcd.print("   Boa Sorte!"); 

            delay (3000);

            estado = 2;   // joga para o caso 2

            break;
            
    case 2: 
            lcd.clear();
            lcd.home();  
            lcd.print("Precione Select "); 
            lcd.setCursor(0,1);  
            lcd.print("Para inciar JOGO"); 

            porta = analogRead (0);  // le as portas dos botoes
            lcd_Shield();

            if (botao == "Select"){
              estado = 110;  //vai para a pergunta 1
            }

            else if (botao != "vazio"){
              tecla_Error();
            }
    
        delay (200);

            break;
    
            
    case 110:   //Questão 1
    
            lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 1:"); 
            lcd.setCursor(0,1);  
            lcd.print("Ano da temporada inaugural da Formula E");  
            
        delay (3000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("2014()"); 
            lcd.setCursor(0,1);  
            lcd.print("2012()");
        
        delay (200);
        estado = 111; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 111:  //resposta
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("2014 (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("2012  ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("2014()"); 
              lcd.setCursor(0,1);  
              lcd.print("2012 (X)");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Correto!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens");
                  
                  ponto++;
                  estado = 120; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errou"); 
                  lcd.setCursor(0,1);  
                  lcd.print("");
                  
                  estado = 120; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{  //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Questao");
                
          
        estado = 120; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 110;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
   
                                        // Questão 2 
    
    
    case 120: 
            lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 2:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual a diferenca entre Formula E e F1 ?"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){    //20=4  ou seja 16+4=20
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
    
        lcd.clear();
            lcd.home();  
            lcd.print("Eletrico()"); 
            lcd.setCursor(0,1);  
            lcd.print("Pistas Ovais()");
    
    
              
              flag = true;
              aux++;
        
        delay (200);
        estado = 121;  //vai para a resposta
        aux =0; 
    
        break;
    
    case 121:           //resposta
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Eletrico(X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Pistas Ovais()");
              flag = true;
              aux++;
              
            
            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Eletrico()"); 
              lcd.setCursor(0,1);  
              lcd.print("Pistas Ovais(X)");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Correto!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("");
                  
                  ponto++;
                  estado = 130; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errou"); 
                  lcd.setCursor(0,1);  
                  lcd.print("");
                  
                  estado = 130; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 130; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 120;     //repete
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                            // Questão 3
    
    
    case 130:
    
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 3:"); 
            lcd.setCursor(0,1);  
            lcd.print("Quantas equipes competem na Formula E??"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("10 ()"); 
            lcd.setCursor(0,1);  
            lcd.print("11 ()");
        
        delay (200);
        estado = 131; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 131:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("10 ()"); 
              lcd.setCursor(0,1);  
              lcd.print("11 (X)");
              
              flag = true;
              aux++;

            }

            else if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("10(X)"); 
              lcd.setCursor(0,1);  
              lcd.print("11()");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Correto!"); 
                  lcd.setCursor(0,1);  
                  lcd.print(":)");
                  
                  ponto++;
                  estado = 140; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errado!"); 
                  lcd.setCursor(0,1);  
                  lcd.print(":(");
                  
                  estado = 140; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("");
                
        estado = 140; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 130;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                            // Questão 4
    
    case 140:
        
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 4:"); 
            lcd.setCursor(0,1);  
            lcd.print("Duracao aproximada de uma corrida?"); 
            
        delay (2000);
    
            for(int cont=0; cont <20; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("45 min()"); 
            lcd.setCursor(0,1);  
            lcd.print("90 min()");
        
        delay (200);
        estado = 141; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 141:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("45 min (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("90 min()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("45 min()"); 
              lcd.setCursor(0,1);  
              lcd.print("90 min(X)");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Corretooooo"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Ta sabendo ein");
                  
                  ponto++;
                  estado = 150; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errou!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Nao desista");
                  
                  estado = 150; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 150; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 140;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                            // Questão 5
    
    case 150:
    
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 5:"); 
            lcd.setCursor(0,1);  
            lcd.print("Onde foi a primeira corrida Formula E?"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("Pequim ()"); 
            lcd.setCursor(0,1);  
            lcd.print("New York ()");
        
        delay (200);
        estado = 151; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 151:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Pequim()"); 
              lcd.setCursor(0,1);  
              lcd.print("New York (X)");
              
              flag = false;
              aux++;

            }

            else if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Pequim (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("New Work ()");
              
              flag = true;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Correto!!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Sabe muito");
                  
                  ponto++;
                  estado = 160; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errou!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Nao desista");
                  
                  estado = 160; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 160; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 150;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                            // Questão 6
    
    case 160:
    
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 6:"); 
            lcd.setCursor(0,1);  
            lcd.print("Sistema que potencializa o carro?"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("Attack Mode ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Nitro ()");
        
        delay (200);
        estado = 161; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 161:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Attack Mode()"); 
              lcd.setCursor(0,1);  
              lcd.print("Nitro(X)");
              
              flag = false;
              aux++;

            }

            else if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Attack Mode (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Nitro ()");
              
              flag = true;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Correto!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("PARABENS");
                  
                  ponto++;
                  estado = 170; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errou!"); 
                  lcd.setCursor(0,1);  
                  lcd.print(":(");
                  
                  estado = 170; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 170; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 160;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                               // Questão 7
    
    case 170:
    
        
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 7:"); 
            lcd.setCursor(0,1);  
            lcd.print("Qual scuderia participa da Fórmula E?"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("Ferrari()"); 
            lcd.setCursor(0,1);  
            lcd.print("Audi()");
        
        delay (200);
        estado = 171; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 171:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Ferrari()"); 
              lcd.setCursor(0,1);  
              lcd.print("Audi(X)");
              
              flag = true;
              aux++;

            }

            else if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Ferrari (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Audi ()");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Correto!!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Muito Bem =)");
                  
                  ponto++;
                  estado = 180; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errado!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("=(");
                  
                  estado = 180; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 180; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 170;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                                   // Questão 8
    
    case 180:
    
    
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 8:"); 
            lcd.setCursor(0,1);  
            lcd.print("Continente com mais corridas realizadas?"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("Europa ()"); 
            lcd.setCursor(0,1);  
            lcd.print("Asia ()");
        
        delay (200);
        estado = 181; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 181:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Europa (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Asia ()");
              
              flag = true;
              aux++;

            }

            else if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Europa ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Asia (X)");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("CORRETO!!"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Continue assim!");
                  
                  ponto++;
                  estado = 190; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errado"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Nao desista");
                  
                  estado = 190; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 190; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 180;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                                   // Questão 9
    
    case 190:
    
    
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 9:"); 
            lcd.setCursor(0,1);  
            lcd.print("Cor da bandeira do fim da corrida?"); 
            
        delay (2000);
    
            for(int cont=0; cont <24; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("Xadrez()"); 
            lcd.setCursor(0,1);  
            lcd.print("Verde()");
        
        delay (200);
        estado = 191; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 191:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Xadrex ()"); 
              lcd.setCursor(0,1);  
              lcd.print("Verde (X)");
              
              flag = false;
              aux++;

            }

            else if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Xadrez (X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Verde()");
              
              flag = true;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("CORRETO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Muito bem ;)");
                  
                  ponto++;
                  estado = 200; //vai para a proxima questao
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Errou"); 
                  lcd.setCursor(0,1);  
                  lcd.print("=(");
                  
                  estado = 200; //vai para a proxima questao
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 200; //vai para a proxima questao
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 190;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
                                                       // Questão 10
    
    case 200:
    
    
        lcd.clear();
            lcd.home();  
            lcd.print("Pergunta 10:"); 
            lcd.setCursor(0,1);  
            lcd.print("Vantagem ambiental da Fórmula E?"); 
            
        delay (2000);
    
            for(int cont=0; cont <20; cont++){
          lcd.scrollDisplayLeft();
          delay (200); 
        }
        
        delay (2000);
                                        //mostra as altenativas
        lcd.clear();
            lcd.home();  
            lcd.print("Gasolina()"); 
            lcd.setCursor(0,1);  
            lcd.print("Emissao Zero()");
        
        delay (200);
        estado = 210; //vai para a resposta
        aux =0; 
    
        break;
    
    
    case 210:  //resposta
    
            porta = analogRead (0);
            lcd_Shield();

            if (botao == "Baixo"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Gasolina()"); 
              lcd.setCursor(0,1);  
              lcd.print("Emissao Zero(X)");
              
              flag = true;
              aux++;

            }

            else if (botao == "Cima"){
              
              lcd.clear();
              lcd.home();  
              lcd.print("Gasolina(X)"); 
              lcd.setCursor(0,1);  
              lcd.print("Emissao Zero()");
              
              flag = false;
              aux++;
              
            }
    
        else if (botao == "Select"){
              if (aux !=0){
                if(flag == true){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("CORRETO"); 
                  lcd.setCursor(0,1);  
                  lcd.print("Parabens");
                  
                  ponto++;
                  estado = 4; //vai para a pontuação
                  delay (3000);
                }
                
                if(flag == false){
                  lcd.clear();
                  lcd.home();  
                  lcd.print("Game over"); 
                  lcd.setCursor(0,1);  
                  lcd.print(":( :( :( ");
                  
                  estado = 4; //vai para a pontuação
                  delay (3000);
                }
              }
              
              else{     //se caso pular a questão
                lcd.clear();
                lcd.home();  
                lcd.print("Voce pulou essa!!"); 
                lcd.setCursor(0,1);  
                lcd.print("Tava facil em!!");
                
        estado = 4; //vai para a pontuação
                delay (3000);
              }
            }
    
        else if (botao == "Esquerda"){
              estado = 200;         //repete a pergunta
            }

            else if (botao != "vazio"){
              tecla_Error();
            }

            break;
    
    

    case 4:         //pontuação
            lcd.clear();
            lcd.home();  
            lcd.print("Total: "); 
            lcd.setCursor(7,0);  
            lcd.print(ponto); 
            lcd.setCursor(9,0);  
            lcd.print("Pto");
    

        if (ponto < 1){
              lcd.setCursor(0,1);  
              lcd.print("Deve Aprender");
            }
    
    
            if (ponto >= 1){
              lcd.setCursor(0,1);  
              lcd.print("Assista mais");
            }
    
    
        if (ponto >= 3){
              lcd.setCursor(0,1);  
              lcd.print("Vai chegar la");
            }
    
    
        if (ponto >= 5){
              lcd.setCursor(0,1);  
              lcd.print("Foi bem");
            }
    
    
        if (ponto >= 7){
              lcd.setCursor(0,1);  
              lcd.print("Quase chega la");
            }
    
    
      if (ponto = 9){
              lcd.setCursor(0,1);  
              lcd.print("Um jogador");
            }
    
    
        if (ponto = 10){
              lcd.setCursor(0,1);  
              lcd.print("INTELIGENTE ");
            }
            

            estado = 1;       //volta para o começo
            ponto = 0;

            delay (3000);

            break;
  }

}


void lcd_Shield () {

   botao = "vazio";

   if (porta < 100) {  
      botao = "Direita";  
   }  
   else if (porta < 200) {  
      botao = "Cima";  
   }  
   else if (porta < 400){  
      botao = "Baixo";  
   }  
   else if (porta < 600){  
      botao = "Esquerda";  
   }  
   else if (porta < 800){  
      botao = "Select";  
   } 
}

void tecla_Error(){
  lcd.clear();
  lcd.home();
  lcd.print (" Tecla Errada!! ");
  delay (1000); }