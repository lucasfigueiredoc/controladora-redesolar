# controladora-redesolar

##Controladora de rede eletrica domestica

  Este projeto tem como objetivo controlar o fornecimento de eletricidade equilibrando entre um banco de baterias abastecido por energia solar ou do fornecimento da companhia de energia.
  A controladora avalia parametros para decidir qual o melhor abastecimento, fornecendo economia de energia e proteção as baterias.
  
  As condições observadas para uso da rede de baterias são:
  
    - A partir das 08:00/ Antes das 16:00.                        x Ainda inexistente
    - Baterias operando a baixo de 23.5v por mais de 5 minutos.   x Operando
    - Intenção direta do usuário em trocar a rede em operação.    x Operando
    
    ![Imagem exemplo](https://user-images.githubusercontent.com/56358855/179367468-8364eaf5-0fdb-4ec8-b824-53ef5c6ebae0.png)

  Imagem exemplo de como ocorre as ligações.
  [Link para o thinkercad do projeto ](https://www.tinkercad.com/things/by0GOYtaDOF?sharecode=ksrxNvYdH24I_jZM7gQ_ctvKDwQwvTURNYJnERIHGsk).
  
  
  ## Lista de itens
  
 # Nome,Quantidade,Componente
- "U1",1," Arduino Uno R3"
- "U3",1," LCD 16 x 2"
- "R1",1,"330 Ω Resistor"
- "Rpot1, Rpot3",2,"250 kΩ Potenciômetro"
- "S1",1," Botão"
- "R2",1,"10 kΩ Resistor"
- "T1, T2",2," Transistor NPN (BJT)"
- "D1, D2",2,"Vermelho LED"
- "P2",1,"3 , 0.5  Fonte de energia"
- "R5",1,"100 kΩ Resistor"
- "R6",1,"1 MΩ Resistor"
- "JP2, JP1",2," Conector de oito pinos"
- "P1",1,"27.8 , 3  Fonte de energia"
- "R3, R4",2,"1 kΩ Resistor"
