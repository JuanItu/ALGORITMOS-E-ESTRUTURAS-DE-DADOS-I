TAREFA AVALIATIVA 1	
Esta tarefa foi feita na aula e s investigar entregue por Juan Ignacio Iturralde Pereira.	
Este codigo funciona como um caixa de um local onde vende limonadas, podendo receber notas de 5, 10 e 20. 	
Falando do que o exercicio nos trazia, ele nos dava um array de inteiros das notas e com isso deveriamos resolver o problema.	
Para a resolução do problema eu imaginei uma mão com a contagem de notas de 10 e notas de 5 e praticar os testes para conseguir fazer todas as leituras.	
Comecei inicializando duas variaveis chamadas "five" e "ten" para fazer a contagens de notas.	
Criei o loop para fazer a leitura utilizando o tamanho das notas que nos foi disponibilizado no exercicio.	
Apos criar o loop, começei a criar os if de leitura. 	
Começando pela nota de 5, onde se ela for lida adiciona 1 na variavel "five".	
Depois de criar o 5, criei o if de leitura da nota 10. Onde no if coloquei que se "five" for maior que 0, ele faz five-- e ten++. E no else o codigo retorna "False".	
Logo isso criei o teste para receber a nota de 20, onde tive minhas dificuldades em aula. Já que meu teste não estava correta.	
Eu estava tentando dar o troco primeiro pelo 15 "uma nota de 5 e uma de 10" porem eu estava tentando testar se o valor de "five" era maior que 3.	
Na hora da aula eu não entendi ao certo pelo que essa mudança fez meu codigo funcionar melhor, mas chegando em casa pesquiseie achei sobre a "greedy algorithm".	
E lendo isso consegui entender que no meu codigo a nota de 5 é mais importante que a de 10 então devo priorizar utilizar a de 5.	
