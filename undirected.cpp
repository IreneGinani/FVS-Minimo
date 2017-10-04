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
#include <algorithm>
#include <chrono>
#include <set>

void preencherAleatorio (std::vector<std::vector<int>> &matrizAdjacencia){
	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if(( i%2 == 0) || (j%2 == 0)){
				matrizAdjacencia[i][j] = 1;
				matrizAdjacencia[j][i] = 1;
			}
		}
	}
}

void preencherMatriz(std::vector<std::vector<int>> &matrizAdjacencia){

	matrizAdjacencia[0][1] = 1;
	matrizAdjacencia[1][0] = 1;

	matrizAdjacencia[2][1] = 1;
	matrizAdjacencia[1][2] = 1;

	matrizAdjacencia[3][2] = 1;
	matrizAdjacencia[2][3] = 1;

	// matrizAdjacencia[1][1] = 1;
	// matrizAdjacencia[1][1] = 1;


	matrizAdjacencia[3][4] = 1;
	matrizAdjacencia[4][3] = 1;

	matrizAdjacencia[1][4] = 1;
	matrizAdjacencia[4][1] = 1;


	matrizAdjacencia[5][6] = 1;
	matrizAdjacencia[6][5] = 1;

	matrizAdjacencia[5][4] = 1;
	matrizAdjacencia[4][5] = 1;

	matrizAdjacencia[1][3] = 1;
	matrizAdjacencia[3][1] = 1;

	matrizAdjacencia[3][6] = 1;
	matrizAdjacencia[6][3] = 1;

	matrizAdjacencia[4][6] = 1;
	matrizAdjacencia[6][4] = 1;

	matrizAdjacencia[3][5] = 1;
	matrizAdjacencia[3][3] = 1;

	// matrizAdjacencia[8][7] = 1;
	// matrizAdjacencia[7][8] = 1;

	// matrizAdjacencia[8][3] = 1;
	// matrizAdjacencia[3][8] = 1;


	// matrizAdjacencia[8][9] = 1;
	// matrizAdjacencia[9][8] = 1;

	// matrizAdjacencia[8][6] = 1;
	// matrizAdjacencia[6][8] = 1;





}

void SomaGraus(std::vector<std::vector<int>> &matrizAdjacencia,std::vector<int> &somas){

	
	int soma = 0;

	somas.clear();


	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if(matrizAdjacencia[i][j] == 1)
				soma++;
		}

		
		somas.push_back(soma);
		// std::cout<<somas[i]<<std::endl;
		// std::cout<<matrizAdjacencia[4][3];
		soma = 0;
	}

	// for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
	// {
	// 	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	// 	{
	// 		soma++;
	// 	}

	// 	somas[j] = somas[j] + soma;
	// 	soma = 0;
	// }


	


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
int MinGrau(std::vector<int> &soma, std::map<int, int> &map, std::vector<std::vector<int>> &matrizAdjacencia ){



	for (int i = 0; i < soma.size(); ++i)
	{
		map[i] = soma[i];
	}

	int max = 100000000;
	int chave = 0;

	for (int i = 0; i < soma.size(); ++i)
	{

		if ((map[i] < max) && (map[i] != 0)){

			max = map[i];
			chave = i;

		}

	}


	return chave;


}
int MaxGrau(std::vector<int> &soma, std::map<int, int> &map, std::vector<std::vector<int>> &matrizAdjacencia ){

	SomaGraus(matrizAdjacencia,soma);
	

	for (int i = 0; i < soma.size(); ++i)
	{
		map[i] = soma[i];
	}

	int max = 0;
	int chave = 0;


	for (int i = 0; i < soma.size(); ++i)
	{

		if ((map[i] >= max)){

			max = map[i];
			chave = i;
			
		}

	}


	return chave;


}
void ConjuntoIndependente(std::vector<int> &somas, std::vector<std::vector<int>> &matrizAdjacenciaAux,std::vector<std::vector<int>> &matrizAdjacencia, std::vector<int> &CI,std::map<int, int> map){

	int aux = 0;
	std::vector<int> vertices;

	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		vertices.push_back(0);
	}

	while (!eVazio(somas)){


		aux = MinGrau(somas, map, matrizAdjacenciaAux);

		//std::cout << aux;
		
		CI.push_back(aux);

		 somas[aux] = 0;

		 vertices[aux] = -1;

		 for (int i = 0; i < matrizAdjacenciaAux[aux].size(); ++i)
		 {

			if((matrizAdjacenciaAux[aux][i] == 1) || (matrizAdjacenciaAux[i][aux] == 1)){
			 	for (int j = 0; j < matrizAdjacenciaAux[i].size(); ++j)
			 	{
			 		matrizAdjacenciaAux[j][i] = 0;
			 		matrizAdjacenciaAux[i][j] = 0;

			 		vertices[i] = -1;

			 		
			 	}
			 	
			}

			matrizAdjacencia[aux][i] = 0;
			matrizAdjacencia[i][aux] = 0;

		 	
		}

		
		SomaGraus(matrizAdjacenciaAux, somas);
	}

	for (int i = 0; i < CI.size(); ++i)
	{
		vertices[CI[i]] = -1;
	}

	for (int i = 0; i < vertices.size(); ++i)
	{
		if((vertices[i] != -1) && (eVazio(somas))){
			CI.push_back(i);
		}

		//std::cout<<CI[i];
	}
	vertices.clear();
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
		// }else {

		// 	std::cout<<"v:"<<v;
		// 	return true; 
		}


		int achou = 0; 
		int j = 0;

		// for (int i = 0; i < matrizAdjacencia.size(); ++i)
		// {
			for (j; j < matrizAdjacencia[0].size(); ++j)
			{


				if((matrizAdjacencia[v][j] == 1) && (marcados[j] == 0)){
					achou = 1; 
					matrizAdjacencia[j][v] = -1;
					matrizAdjacencia[v][j] = -1;
					//std::cout<<"vn:"<<v<<"j"<<j;
					break;
				}else if (((matrizAdjacencia[v][j] == -1) && (marcados[j] == 1)) && (j==matrizAdjacencia.size()-1)){
					//std::cout<<"v:"<<v<<"j"<<j;
					return true;
				 }//else if (((matrizAdjacencia[v][j] == -1) && (marcados[j] == 1)))
				// 	j++;

			
			} 

			if (achou == 1)
				v = j;
			else if (v!=matrizAdjacencia.size()-1)
				v++;
			else{

				pilha.pop();

				if(pilha.empty()){
					//std::cout<<"dhh";
					break;
				}

				v = pilha.top();
			}
		//}
	}

	//std::cout<<"falso";

	return false;

}
int printFVS(std::set<int> &FVS,std::vector<std::vector<int>> matrizAdjacencia, std::vector<int> CI, std::vector<int> CIAux, int s){
	std::vector<int>::iterator it;
	std::vector<int>::iterator it1;
	std::set<int>::iterator it0;
	int count =0;
	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		it = find(CI.begin(), CI.end(), i);
		it1 = find(CIAux.begin(), CIAux.end(), i);

		if ((it == CI.end()) && (it1 == CIAux.end())){
			count++;
			if (s==1)
				FVS.insert(i);
		}

		// if (s==1)
		// 	for (it0=FVS.begin(); it0!=FVS.end(); ++it0)
		// 		std::cout << *it0 << std::endl;

	}
	return matrizAdjacencia.size() -  count;
}

int vizinhosGenericos(std::vector<std::vector<int>> matrizAdjacencia, std::vector<int> conjunto, int vertice){
	int gd = 0;
	std::vector<int>::iterator it;
	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		it = find(conjunto.begin(), conjunto.end(), i);
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if ((matrizAdjacencia[i][j] == 1) && (it!= conjunto.end()) && (i!=j)){
				matrizAdjacencia[vertice][j] = 1;
				matrizAdjacencia[i][j] = 0;
				gd++;
			}
		}
	}

	return gd;


}

int calcularFVS(int &it, int lb, int ub,std::vector<std::vector<int>> &grafo, std::vector<std::vector<int>> matrizAdjacencia,std::vector<std::vector<int>> matrizAdjacenciaAux,std::vector<std::vector<int>> matrizAdjacenciaAux0, std::vector<int> &CI, std::set<int> &FVS, std::map<int, int> map,std::vector<int> somas){
	std::vector<int> CIAux;
	std::vector<int> CV ;
	std::vector<int> vizinhos ;
	std::vector<int> vizinhos2;
	int aux;
	int lowerbound = CI.size();
	int upperbound = matrizAdjacencia.size();
	std::vector<int>::iterator it0;
	std::vector<int>::iterator it1;

	std::vector<int>::iterator it2;

	it++;
	std::cout<< "itt:"<<it<<std::endl;

	if (upperbound < ub){
		//std::cout<< "dede"<<std::endl;
		return 0; 
	}
	else if (upperbound > ub)
		ub = upperbound; 
	if (lowerbound > lb){
		//std::cout<< lb <<std::endl;
		return 0;
	}
	else if (lowerbound < lb)
		lb = lowerbound; 
	// if(lowerbound == matrizAdjacencia.size())
	// 	return 0;

	///grafo[it].push_back(matrizAdjacencia.size() - CI.size());
		//std::cout<<matrizAdjacencia.size() - CI.size()<<std::endl;	
    
	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		CV.push_back(0);
		
	}


	for (int i = 0; i < CI.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia.size(); ++j)
		{
			it0 = std::find (CI.begin(), CI.end(), j);
			it1 = std::find (CI.begin(), CI.end(), i);
			if ((matrizAdjacenciaAux0[CI[i]][j] != 0) && (matrizAdjacenciaAux0[j][CI[i]] != 0) && (it0 == CI.end()) && (it1 == CI.end())){

				CV[CI[i]]++;

			}
		}
	}


	for (int i = 0; i < CV.size(); ++i)
	{

		matrizAdjacenciaAux0 = matrizAdjacencia;

		int r = rand() % matrizAdjacenciaAux0.size();

		for (int j = 0; j < matrizAdjacenciaAux0[i].size(); ++j)
		{

			if (matrizAdjacenciaAux0[CI[i]][r] == 1)
				break;
			else
				int r = rand() % matrizAdjacenciaAux0.size();
		}

		for (int j = 0; j < matrizAdjacenciaAux0[i].size(); ++j)
		{

			it2 = find(CI.begin(), CI.end(), j);
			if ((matrizAdjacenciaAux0[r][j] == 1) && (j!=CI[i]) && (it2 != CI.end()))
				vizinhos2.push_back(j);
		}

		int r1 = rand() % matrizAdjacenciaAux0.size();

		

		if (CV[CI[i]] == matrizAdjacenciaAux0[CI[i]].size()-1){

			//std::cout<< matrizAdjacenciaAux0[CI[i]].size()<<std::endl;
			for (int j = 0; j < matrizAdjacenciaAux0.size(); ++j)
			{
				for (int k = 0; k < matrizAdjacenciaAux0[CI[i]].size(); ++k)
				{
					if ((matrizAdjacenciaAux0[j][k] != 0) && (k != i) && (j != i) && (matrizAdjacenciaAux0[j][k+1] != 0) && (k<matrizAdjacenciaAux0.size()-1)){
							matrizAdjacenciaAux0[k][k+1] = 1;
					}
				}
			}



			
		    SomaGraus(matrizAdjacenciaAux0,somas);
		    


		    ConjuntoIndependente(somas, matrizAdjacenciaAux0,matrizAdjacencia, CIAux, map);

		    printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);

			std::cout << "FVS é: ";
			for (int i = 0; i < CV.size(); ++i)
			{
				if((matrizAdjacenciaAux0[CI[i]][i] == 1) || (matrizAdjacenciaAux0[i][CI[i]] == 1)){
				 	for (int j = 0; j < matrizAdjacencia[i].size(); ++j)
				 	{
				 		matrizAdjacencia[j][i] = 0;
				 		matrizAdjacencia[i][j] = 0;

				 	}
				 }

				 
			}

			for (int i = 0; i < CV.size(); ++i)
			{
				if((matrizAdjacenciaAux0[CI[i]][i] == 1) || (matrizAdjacenciaAux0[i][CI[i]] == 1)){
				 	for (int j = 0; j < matrizAdjacenciaAux[i].size(); ++j)
				 	{
						matrizAdjacencia[i][j] = 0;
						matrizAdjacencia[j][i] = 0;


						std::cout<<CIAux[i];
					}
				}
				
			}

			printFVS(FVS,matrizAdjacencia, CI, CIAux,1);
			return 0;

	  	}else if(vizinhosGenericos(matrizAdjacenciaAux0, vizinhos2, r1) <= 1){
	 		CI.push_back(r);

	 		if (printFVS(FVS,matrizAdjacencia,CI,CIAux,0) < ub){
	 		  	ub = printFVS(FVS,matrizAdjacencia,CI, CIAux,0);
	 		  	lb = CI.size();
	 			
			    
	 		}
	 		printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);
	 		calcularFVS(it,lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );	
	 	}else if (vizinhosGenericos(matrizAdjacenciaAux0,vizinhos2, r1) >= 4){
			CI.push_back(r);
			//std::cout<<r <<CI.back();
			calcularFVS(it, lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			for (int j = 0; j < matrizAdjacenciaAux0.size(); ++j)
			{
				matrizAdjacenciaAux0[i][r] = 0;
				matrizAdjacenciaAux0[r][i] = 0;
			}
			printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);
			calcularFVS(it, lb, ub, grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
	  	}else if(vizinhosGenericos(matrizAdjacenciaAux0,vizinhos2,r1) == 2){
			CI.push_back(r);
			calcularFVS(it,lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
			{
				if ((matrizAdjacencia[r][j] != 0) && (vizinhos.size()<2)) 
				{
					vizinhos.push_back(j);
				}
					
			}
			
			for (int k = 0; k < matrizAdjacenciaAux0.size(); ++k)
			{
				//std::cout<<vizinhos[1]<<":";

				if(vizinhos.size()==2){

					matrizAdjacenciaAux0[i][vizinhos[1]] = 0;
			 		matrizAdjacenciaAux0[vizinhos[1]][i] = 0;

				}
	
			 	matrizAdjacenciaAux0[i][vizinhos[0]] = 0;
			 	matrizAdjacenciaAux0[vizinhos[0]][i] = 0;
			 	
			}

			CI.push_back(vizinhos[0]);
			if(vizinhos.size()==2)
				CI.push_back(vizinhos[1]);
			if(verificaCiclo(matrizAdjacenciaAux0)){
				CI.pop_back();
				CI.pop_back();
			}

			vizinhos.clear();
			printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);
			calcularFVS(it,lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			
	 	}else if(vizinhosGenericos(matrizAdjacenciaAux0,vizinhos,r1) == 3)

			aux++;
	}

	if (aux == CV.size()){
		int r2 = rand() % CV.size();

		int random = CV[r2];

		CI.push_back(random);

		calcularFVS(it,lb,ub,grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

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

		calcularFVS(it,lb,ub,grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

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

	 	calcularFVS(it, lb, ub, grafo,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

	 }

	printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);

	 // for (int i = 0; i < grafo.size(); ++i)
	 // {
		

	 // 	std::cout<<std::endl;
	 // }



// for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
// 		{
// 	 		std::cout<<CI[j];
// 		}
}

int BranchBound(int i,int d,int lb, int up, std::set<int> &FVS, std::vector<std::vector<int>> matrizAdjacencia,std::vector<std::vector<int>> &matrizAdjacenciaAux,std::vector<std::set<int>> &FVS2){
	
	matrizAdjacenciaAux = matrizAdjacencia;
	std::set<int>::iterator it;
	std::map<int, int> map;
	std::vector<int> graus;
		if (FVS.size() > up){
			//FVS.clear();
			return 0;
	    }else{


			FVS.insert(i);
			

			for (it=FVS.begin(); it!=FVS.end(); ++it){

				//std::cout<<*it;
				
				for (int k = 0; k < matrizAdjacencia.size(); ++k)
				{
					int auz = *it;
					// if((matrizAdjacenciaAux[auz][k] == 1) || (matrizAdjacenciaAux[k][auz] == 1)){
					// for (int j = 0; j < matrizAdjacenciaAux[0].size(); ++j)
					// {
						 
					// 	matrizAdjacenciaAux[j][k] = 0;
			 	// 		matrizAdjacenciaAux[k][j] = 0;
					// 	//std::cout<<matrizAdjacencia[k][j]<<std::endl;
				 	
					// }

					matrizAdjacenciaAux[auz][k] = 0;
					matrizAdjacenciaAux[k][auz] = 0;

			 	
					//}	

				}
		}
		}
		
		//std::cout<<std::endl;

	// 	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	// {
	// 	for (int j = 0; j < matrizAdjacencia.size(); ++j)
	// 	{
	// 		std::cout<<matrizAdjacenciaAux[i][j];
	// 	}

	// 	std::cout<<std::endl;
		
	// }


		 if (!verificaCiclo(matrizAdjacenciaAux)){
		 	FVS.erase(i);
		 	FVS2.push_back(FVS);
		 	return 0;


		 }else{
			for (int j = 0; j < matrizAdjacencia.size(); ++j)
			{
				SomaGraus(matrizAdjacencia,graus);

				if (graus[j] == 1)
					continue;	
				else{
					int d = MaxGrau(graus,map,matrizAdjacencia);
					//std::cout<< d <<"d"<<std::endl;
					for (int s = 0; s < matrizAdjacencia.size(); ++s)
					{
						matrizAdjacencia[d][s] = 0;
						matrizAdjacencia[s][d] = 0;
					}

						BranchBound(i++,d,lb, up, FVS, matrizAdjacencia, matrizAdjacenciaAux,FVS2);
						//int b = BranchBound(j++,lb, up, FVS, matrizAdjacencia, matrizAdjacenciaAux);
						// if (a==0){
						// 	//std::cout<<"njn";
						// 	return 0;
						// }
				}
				
		  	}
			
		  }
 //std::cout<<std::endl;


}

void printMax(std::vector<std::set<int>> FVS2){
	int max = 0;
	std::set<int>::iterator it0;

	for (int i = 0; i < FVS2.size();i++){
		if (FVS2[i].size() >= max)
			max = i;
		
				
	 }

	 for (it0=FVS2[max].begin(); it0!=FVS2[max].end(); ++it0)
		{
			std::cout << *it0 ;
		}

		std::cout<<std::endl;

}

int main(){

	
	std::set<int> FVS1;
	std::vector<std::set<int>> FVS2;
	std::vector<int> CI;
	std::vector<std::vector<int>> matrizAdjacenciaAux2 (200, std::vector<int>(200) );
	std::vector<std::vector<int>> matrizAdjacencia (200, std::vector<int>(200) );
	std::vector<std::vector<int>> matrizAdjacenciaAux (200, std::vector<int>(200) );
	std::vector<std::vector<int>> matrizAdjacenciaAux0 (200, std::vector<int>(200) );
	std::vector<std::vector<int>> matrizAdjacenciaAux1 (200, std::vector<int>(200) );
	std::vector<std::vector<int>> grafo (100, std::vector<int>(100) );
	std::vector<int> somas;
	std::map<int, int> map;
	int *cc;
	int ub, lb, it = 0;
	int upperbound, lowerbound;
	std::set<int>::iterator it0;
	std::set<int>::iterator it1;
	std::set<int>::iterator it2;

	std::set<int> FVS;

	std::chrono::time_point<std::chrono::system_clock> inicio, fim;
	unsigned long long int nanosegundos_decorridos;

	inicio = std::chrono::system_clock::now();
	preencherAleatorio(matrizAdjacencia);

	//ComponentesConexas(matrizAdjacencia, cc);

	 matrizAdjacenciaAux = matrizAdjacencia;
	 matrizAdjacenciaAux0 = matrizAdjacencia;

	matrizAdjacenciaAux1 = matrizAdjacencia;

  	matrizAdjacenciaAux2 = matrizAdjacencia;
	

	SomaGraus(matrizAdjacencia, somas);
	
	ConjuntoIndependente(somas,matrizAdjacenciaAux,matrizAdjacencia, CI, map);

	 
	 
    lb = CI.size();

	ub = matrizAdjacencia.size();

    if (CI.size() == matrizAdjacencia.size()){
		std::cout << "O FVS é vazio:";
		return 0;
	}else if (map[MaxGrau(somas, map, matrizAdjacenciaAux0)] <= 1){
		std::cout << "O FVS é vazio!";
		return 0;
	}



	  calcularFVS(it, lb, ub, grafo, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
      fim = std::chrono::system_clock::now();

    lowerbound = 1;
	upperbound = FVS.size();
	  for (it0=FVS.begin(); it0!=FVS.end(); ++it0){
				std::cout << *it0 << std::endl;

				BranchBound(0,*it0,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2,FVS2);
	}

	printMax(FVS2);
	  
	 nanosegundos_decorridos = nanosegundos_decorridos + std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();

	 std::cout<<nanosegundos_decorridos<<" ms";
	


	

	// BranchBound(0,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(1,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(2,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(3,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(4,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(5,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(6,lowerbou5,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(7,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(8,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	// BranchBound(9,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2);
	
	// for (int i = 0; i < FVS2.size();i++){
	// 	for (it0=FVS2[i].begin(); it0!=FVS2[i].end(); ++it0)
	// 	{
	// 		std::cout << *it0 ;
	// 	100
	// 	std::cout<<std::endl;
				
	//  }
	
	 // for (int i = 0; i < grafo.size(); ++i)
	 // {
		// for (int j = 0; j < grafo[0].size(); ++j)
		// {
	 // 		std::cout<<matrizAdjacenciaAux1[i][j];
		// }

	 // 	std::cout<<std::endl;
	 // }

 //    std::cout<<grafo[0][0];

	//acho que não precisa chamar pra cada componente, porque o conjunto independente é calculado encima dos vértices.




}