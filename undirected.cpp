//achar o máximo conjunto independente
//achar a árvore que ele ta presente de forma máxima
//se tem mais de uma componente fazer o de cima para os dois 

//casos

// se o conjunto independente e igual ao grafo p FVS é vazio -- ok
//escolha um vértice ativo em F, se não tiver nenhum escolha um aleatório e chame de ativo
//se V\F sobram só os vizinhos de t construa um grafo H e faça seu conjunto independente, daí a árvore será f+i e o que sobra o FVS
//Se existe um vertice em vizinhos de t que ele tem grau menor ou igual a um de vizinhos gerais add a F
//Se existe a mesma coisa mas com grau maior ou igual a 4 chame o alg de novo adicionando esse vertice a F ou retirando de G
//Se existe a mesma coisa com vizinho igual a dois chame o alg de novo com G e F com u, ou G \ u e f + W + w que são seus dois vizinhos. Se isso gerar um ciclo ignore
//Se existe a mesma coisa com 3 vizinhos, v que está em vizinhos de u tem 3 generalizados vizinhos q w e. pelo menos um deles não esta em viznhos de t por 5, então chame de novo o algoritmo em F + u, G\v F+q, G\v,q f + w e , se u ultimo gerar um ciclo retire. 

#include <iostream>
#include <vector>
#include <map>
#include <stack>

void preencherMatriz(std::vector<std::vector<int>> matrizAdjacencia){


}

void SomaGraus(std::vector<std::vector<int>> &matrizAdjacencia,std::vector<int> &somas){

	
	int soma = 0;

	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			soma++;
		}

		somas.push_back(soma);
		soma = 0;
	}

	for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
	{
		for (int i = 0; i < matrizAdjacencia.size(); ++i)
		{
			soma++;
		}

		somas[j] = somas[j] + soma;
		soma = 0;
	}


	


}

bool eVazio(std::vector<int> somas){

	int count = 0;

	for (int i = 0; i < somas.size(); ++i)
	{
		if (somas[i] == 0){

			count ++;
		}
	}

	if(count == somas.size())
		return true;
	else return	
		false;



}
int MaxGrau(std::vector<int> &soma, std::map<int, int> &map, std::vector<std::vector<int>> &matrizAdjacencia ){



	for (int i = 0; i < soma.size(); ++i)
	{
		map[i] = soma[i];
	}

	int max = 0;
	int chave = 0;

	for (int i = 0; i < soma.size(); ++i)
	{

		if (map[i] > max){

			max = map[i];
			chave = i;

		}

	}


	return chave;


}

void ConjuntoIndependente(std::vector<int> &somas, std::vector<std::vector<int>> &matrizAdjacenciaAux, std::vector<int> &CI,std::map<int, int> map){

	int aux = 0;

	while (!eVazio(somas)){

		SomaGraus(matrizAdjacenciaAux, somas);

		aux = MaxGrau(somas, map, matrizAdjacenciaAux );

		CI.push_back(aux);

		somas[aux] = 0;

		for (int i = 0; i < matrizAdjacenciaAux[aux].size(); ++i)
		{
			matrizAdjacenciaAux[aux][i] = 0;
			matrizAdjacenciaAux[i][aux] = 0;
		}





	}
}

void dfsComponente(std::vector<std::vector<int>> matrizAdjacencia, int *cc, int v, int id){


	cc[v] = id;

	for (int i = 0; i < matrizAdjacencia[v].size(); ++i){
      if (cc[i] == -1) 
         dfsComponente( matrizAdjacencia, cc, i, id); 
	}




}

int ComponentesConexas(std::vector<std::vector<int>> matrizAdjacencia, int *cc){

	
   int id = 0;
   for (int v = 0; v < matrizAdjacencia.size(); ++v) 
      cc[v] = -1;
   for (int v = 0; v < matrizAdjacencia.size(); ++v){
      if (cc[v] == -1) 
         dfsComponente( matrizAdjacencia, cc, v, id++);
   }
   

   return id;


}
bool verificaCiclo(std::vector<std::vector<int>> matrizAdjacencia){


	std::stack<int> pilha;
	std::vector<int> marcados (matrizAdjacencia.size());

	int v = 0;
	while(true){

		if (marcados [v] == 0){

			marcados[v] = 1; 
			pilha.push(v);
		}else {
			return true; 
		}


		int achou = 0; 
		int j = 0;

		for (int i = 0; i < matrizAdjacencia.size(); ++i)
		{
			for (j; j < matrizAdjacencia[0].size(); ++j)
			{

				if(marcados[i] == 0){
					achou = 1; 
					break;
				}
			
			} 

			if (achou == 1)
				v = j;
			else {

				pilha.pop();

				if(pilha.empty()){
					break;
				}

				v = pilha.top();
			}
		}
	}

	return false;

}
void printFVS(std::vector<std::vector<int>> matrizAdjacencia){
	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if(matrizAdjacencia[i][j] != 0){
				std::cout << i << std::endl;
			}

		}
	}
}

int calcularFVS(int it, int lb, int ub,std::vector<std::vector<int>> grafo, std::vector<std::vector<int>> matrizAdjacencia,std::vector<std::vector<int>> matrizAdjacenciaAux,std::vector<std::vector<int>> matrizAdjacenciaAux0, std::vector<int> CI, std::vector<int> FVS, std::map<int, int> map,std::vector<int> somas){

	std::vector<int> CIAux;
	std::vector<int> CV ;
	std::vector<int> vizinhos ;
	int aux;
	int lowerbound = CI.size();
	int upperbound = matrizAdjacencia.size();

	if (upperbound > lb)
		return 0; 
	else if (upperbound < lb)
		lb = upperbound; 
	if (lowerbound < lb)
		return 0;
	else if (lowerbound > lb)
		lb = lowerbound; 

	grafo[it].push_back(matrizAdjacencia.size() - CI.size());

	for (int i = 0; i < CI.size(); ++i)
	{
		CV.push_back(0);
	}

	if (CI.size() == matrizAdjacencia.size()){
		std::cout << "O FVS é vazio";
		return 0;
	}else if (MaxGrau(somas, map, matrizAdjacencia) == 1){
		std::cout << "O FVS é vazio";
		return 0;
	}

	for (int i = 0; i < CI.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia.size(); ++j)
		{
			if ((matrizAdjacencia[CI[i]][j] != 0) &&  (matrizAdjacencia[j][CI[i]] != 0)){

				CV[CI[i]]++;

			}
		}
	}

	

	for (int i = 0; i < CV.size(); ++i)
	{
		matrizAdjacenciaAux0 = matrizAdjacencia;

		if (CV[CI[i]] = matrizAdjacenciaAux0[CI[i]].size()){

			for (int j = 0; j < matrizAdjacenciaAux0.size(); ++i)
			{
				for (int k = 0; k < matrizAdjacenciaAux0[CI[i]].size(); ++k)
				{
					if ((matrizAdjacenciaAux0[j][k] != 0) && (k != i) && (j != i) && (matrizAdjacenciaAux0[j][k+1] != 0)){
							matrizAdjacenciaAux0[k][k+1] = 1;
					}
				}
			}

			ConjuntoIndependente(somas, matrizAdjacenciaAux0,CIAux, map);

			std::cout << "FVS é: ";
			for (int i = 0; i < CI.size(); ++i)
			{
				matrizAdjacencia[i][CI[i]] = 0;
				matrizAdjacencia[CI[i]][i] = 0;
			}
			for (int i = 0; i < CIAux.size(); ++i)
			{
				matrizAdjacencia[i][CIAux[i]] = 0;
				matrizAdjacencia[CIAux[i]][i] = 0;
			}
			printFVS(matrizAdjacencia);
			return 0;
		}else if(somas[CV[CI[i]]] == 1){
			CI.push_back(CV[CI[i]]);
			calcularFVS(it++,lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
		}else if (somas[CV[CI[i]]] >= 4){
			CI.push_back(CV[CI[i]]);
			calcularFVS(it++, lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			for (int j = 0; j < matrizAdjacenciaAux0.size(); ++j)
			{
				matrizAdjacenciaAux0[i][CV[CI[i]]] = 0;
				matrizAdjacenciaAux0[CV[CI[i]]][i] = 0;
			}

			calcularFVS(it++, lb, ub, grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

		}else if(somas[CV[CI[i]]] == 2){
			CI.push_back(CV[CI[i]]);
			calcularFVS(it++,lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			for (int j = 0; j < matrizAdjacencia[CV[CI[i]]].size(); ++j)
			{
				if (matrizAdjacencia[CV[CI[i]]][j] != 0)
				{
					vizinhos.push_back(j);
				}
			}
			
			for (int j = 0; j < matrizAdjacenciaAux0.size(); ++j)
			{
				matrizAdjacenciaAux0[i][vizinhos[0]] = 0;
				matrizAdjacenciaAux0[vizinhos[0]][i] = 0;
				matrizAdjacenciaAux0[i][vizinhos[1]] = 0;
				matrizAdjacenciaAux0[vizinhos[1]][i] = 0;
			}

			CI.push_back(vizinhos[0]);
			CI.push_back(vizinhos[1]);
			if(verificaCiclo(matrizAdjacenciaAux0)){
				CI.pop_back();
				CI.pop_back();
			}

			vizinhos.clear();

			calcularFVS(it++,lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			
		}else if(somas[CV[CI[i]]] == 3)

			aux++;
	}

	if (aux == CV.size()){
		int random = rand() % CV.size();

		CI.push_back(random);

		calcularFVS(it++,lb,ub,grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

		for (int i = 0; i < matrizAdjacencia[random].size(); ++i)
		{
			if (matrizAdjacenciaAux0[random][i] != 0){
				vizinhos.push_back(i);
			}
		}

		for (int i = 0; i < matrizAdjacencia[random].size(); ++i)
		{
			matrizAdjacenciaAux0[random][i] = 0;
			matrizAdjacenciaAux0[i][random] = 0;
		}

		CI.push_back(vizinhos[0]);

		calcularFVS(it++,lb,ub,grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

		for (int i = 0; i < matrizAdjacencia[random].size(); ++i)
		{
			matrizAdjacenciaAux0[random][i] = 0;
			matrizAdjacenciaAux0[i][random] = 0;

			matrizAdjacenciaAux0[vizinhos[0]][i] = 0;
			matrizAdjacenciaAux0[i][vizinhos[0]] = 0;
		}

		CI.push_back(vizinhos[1]);
		CI.push_back(vizinhos[2]);

		if(verificaCiclo(matrizAdjacenciaAux0)){
			CI.pop_back();
			CI.pop_back();
		}

		calcularFVS(it++, lb, ub, grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

	}



}

int main(){

	std::vector<int> FVS;
	std::vector<int> CI;
	std::vector<std::vector<int>> matrizAdjacencia (5, std::vector<int>(5) );
	std::vector<std::vector<int>> matrizAdjacenciaAux (5, std::vector<int>(5) );
	std::vector<std::vector<int>> matrizAdjacenciaAux0 (5, std::vector<int>(5) );
	std::vector<std::vector<int>> grafo (5, std::vector<int>(5) );
	std::vector<int> somas;
	std::map<int, int> map;
	int *cc;
	int ub, lb, it = 0;



	preencherMatriz(matrizAdjacencia);

	ComponentesConexas(matrizAdjacencia, cc);

	matrizAdjacenciaAux = matrizAdjacencia;
	matrizAdjacenciaAux0 = matrizAdjacencia;

	SomaGraus(matrizAdjacencia, somas);
	
	ConjuntoIndependente(somas,matrizAdjacenciaAux, CI, map);

	lb = CI.size();

	ub = matrizAdjacencia.size();

	calcularFVS(it, lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

	
	



	//acho que não precisa chamar pra cada componente, porque o conjunto independente é calculado encima dos vértices.




}