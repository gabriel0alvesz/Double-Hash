 <h1 align = "center" >Tabela Hash - Hash Duplo</h1>
 
 <h2> O que é uma Tabela Hash?</h2>

 <p align = "justify">
      A Tabela Hash ou Tabela de Dispersão é uma estrutura de dados especial que associa chaves de mapeamento a valores, para indexação de dados. É por meio de uma função matemática, conhecida como <i>Função Hash</i> ou <i>Função de Espelhamento</i>, que faz a associação de uma chave à uma posição. Entretanto, neste caso, foi utilizado duas funções hash para fazer a assosciação de chaves em caso colisões. O objetivo de uma Tabela Hash é, por meio de uma simples chave fazer uma busca de forma rápida e assim, conseguir o valor desejado.<br>
      </p>

<h2>Colisões</h2>

<p align = "justify">
      Em uma Tabela Hash, quando uma posição já está ocupada, uma outra chave é associada a mesma posição, dizemos que há uma colisão. Para corrigir as colisões, neste repositório, foi implementado o método de <i>Endereçamento Aberto</i>, que não utiliza <a href = "https://github.com/Nerd100oculoS/Simple-Hash"> Listas Encadeadas</a>. Dessa forma, espaço gasto com encadeamento é economizado e a colisão é tratada com uma nova busca na própria tabela para inserção. A figura 2 abaixo, demonstra como acontece as colisões no <i>Endereçamento Aberto</i>.
      </p>

<p align = "center">
 <img width="291" alt="Captura de Tela 2022-07-05 às 19 15 23" src="https://user-images.githubusercontent.com/103065659/177430181-1218f849-9451-489e-9544-2d159593c699.png"><br>
Figura 1 - Exemplo de Colisão em Endereçamento Aberto
</p>

<br>

<h2> O que é Hash Duplo? </h2>

<p align = "justify">
     O Hash Duplo é a implementação de duas funções de espelhamento que trabalham em conjunto quando há colisão. No Desenvolvimento deste algoritmo foi utilizado as seguintes funções para tratar as colisões. Sendo "tam" o tamanho da tabela.
      </p>

* h1(chave, tam) = (chave*1/3) mod tam
* h2(chave,tam) = [(chave + 1) mod 7] + 1
* H(h1,h2,K) = [h2*k + h1 + k] mod tam ; K = quantidade de colisões ao tentar inserir.

![video](https://user-images.githubusercontent.com/103065659/177434872-e16016d6-29b3-4723-a0f5-6435cdb19163.gif)<br>
Execução do algoritmo


<h2>Qual o custo de uma Tabela Hash com Endereçamento Aberto?</h2>
<p align = "justify">
        </p>

<h2>Referências</h2>
<p align = "justify">
        <ul>
        <li><a = href = "https://www2.unifap.br/furtado/files/2016/11/Aula7.pdf">Tabelas de Dispersão</a> - Nelson Cruz Sampaio Neto;2016</li>
        </ul>
        </p>

<h2>Compilação e Execução</h2>

````
gcc -g *.c -o main && ./main
````

