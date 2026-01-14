/*

Grafo Desconexo: é como se tivessemos duas ilhas/grafos conectdos isolados, que não se conecta com outra ilha.
em um grafo desse, não é possivel ir de uma ilha a outra.

Grafo Conexo: mesmo com multiplos e longo caminhos entre vertices, sendo esses conectados em uma única ilha.

Grafos Isomorfos: vem de formas iguais. Dois grafos são isomorfos quando, mesmo quando são graficamente diferentes, estruturalmente são iguais
suas conexões são iguais. Para isso, eles precisam do mesmo número de vertices e arestas. o que importa são as conexões. 

Grafo Ponderado: é aquele grafo onde as arestas possuem diferentes pesos, e esses pesos definem a importância de cada vertice. Esse peso é um valor numérico associado.
Nem todas as conexões são iguais.
Por exemplo, sendo um grafo uma ligação entre duas cidades A, B e C. Visto que estamos em A, queremos ir de A par B ou C. Sendo assim, os pesos podem ser a distãncia de cada cidade, 
ou seja, se o peso maior será daquele de maior distãncia. Esses parâmetros e escolhas das importância dos pesos dependem da lógica do gráfo.

Grafo Hamiltoniano: o foco sendo os vértices, é aquele grafo em se consegue traçar um caminho que visita todos os vertices exatamente uma vez.
EX: Um carteiro precisa entregar cada carta em cada casa sem passar duas vezes pela mesma casa

Grafo Euleriano: O foco são as arestas, é aquele grafo que não repete caminhos, não importa se passar pelo mesmo vertice.
EX: um caminhão de lixo não pode passar duas vezes pela mesma rua.


um computador entende um grafo de duas maneiras:
- matriz de adjacencia (tabela)
- lista de adjecencia (ponteiro)

Matriz de Adjacência:
Em uma tabala, as linhas são os vertices de origem e as colunas são os vertices de destino.
Se há 5 pessoas:
cria-se uma matriz 5 x 5. (VERTICES SÃO DE 0 A 4)
se a pessoa 0 for amigo da pessoa 2, vamos na linha 0, na coluna 2, e adicionamos 1 nesse ponto da matriz. 1 -> verdadeiro, 0 -> falso.

Lista de adjacência:
Visualmente, a matriz é facil. Mas quando temos muitos dados as relações ficam diferente. 
Assim, criamos uma array onde cada posição é um ponteiro que aponta para uma corrente (lista encadeada) contendo apenas os vizinhos que existem. 
Ao invés de termos uma tabela com zeros e uns, teremos o indice v0 apontando para uma lista.
a vantagem dela é que ela cria memoria com o que realmmente há conexão.
*/