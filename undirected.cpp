#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <chrono>
#include <set>

//Testes com grafos aleatórios
void preencherAleatorio (std::vector<std::vector<int>> &matrizAdjacencia){
	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if( (i%2 == 0) || (j%2 == 0) ){
				matrizAdjacencia[i][j] = 1;
				matrizAdjacencia[j][i] = 1;
			}
		}
	}
}

void preencherMatriz(std::vector<std::vector<int>> &matrizAdjacencia){


	//TESTE COM 5 VÉRTICES
	matrizAdjacencia[0][1] = 1;
	matrizAdjacencia[1][0] = 1;

	matrizAdjacencia[2][1] = 1;
	matrizAdjacencia[1][2] = 1;

	matrizAdjacencia[3][2] = 1;
	matrizAdjacencia[2][3] = 1;


	matrizAdjacencia[3][0] = 1;
	matrizAdjacencia[0][3] = 1;


	// TESTE 2
	// matrizAdjacencia[0][1] = 1;
	// matrizAdjacencia[1][0] = 1;

	// matrizAdjacencia[2][1] = 1;
	// matrizAdjacencia[1][2] = 1;

	// matrizAdjacencia[3][2] = 1;
	// matrizAdjacencia[2][3] = 1;


	// matrizAdjacencia[3][4] = 1;
	// matrizAdjacencia[4][3] = 1;

	// matrizAdjacencia[1][4] = 1;
	// matrizAdjacencia[4][1] = 1;


	// TESTE COM 10 VÉRTICES
	// matrizAdjacencia[0][1] = 1;
	// matrizAdjacencia[1][0] = 1;

	// matrizAdjacencia[2][1] = 1;
	// matrizAdjacencia[1][2] = 1;

	// matrizAdjacencia[3][2] = 1;
	// matrizAdjacencia[2][3] = 1;

	// matrizAdjacencia[3][7] = 1;
	// matrizAdjacencia[7][3] = 1;

	// matrizAdjacencia[3][6] = 1;
	// matrizAdjacencia[6][3] = 1;


	// matrizAdjacencia[3][4] = 1;
	// matrizAdjacencia[4][3] = 1;

	// matrizAdjacencia[1][4] = 1;
	// matrizAdjacencia[4][1] = 1;


	// matrizAdjacencia[5][6] = 1;
	// matrizAdjacencia[6][5] = 1;


	// matrizAdjacencia[3][6] = 1;
	// matrizAdjacencia[6][3] = 1;


	// matrizAdjacencia[3][5] = 1;
	// matrizAdjacencia[3][3] = 1;

	// matrizAdjacencia[8][7] = 1;
	// matrizAdjacencia[7][8] = 1;

	// matrizAdjacencia[8][6] = 1;
	// matrizAdjacencia[6][8] = 1;


	// matrizAdjacencia[8][9] = 1;
	// matrizAdjacencia[9][8] = 1;

	// matrizAdjacencia[1][1] = 1;

	








}

void SomaGraus(std::vector<std::vector<int>> &matrizAdjacencia,std::vector<int> &somas){

	
	int soma = 0;

	somas.clear();


	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if(matrizAdjacencia[i][j] == 1) soma++;
		}
		
		somas.push_back(soma);
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
		
		}


		int achou = 0; 
		int j = 0;

			for (j; j < matrizAdjacencia[0].size(); ++j)
			{


				if((matrizAdjacencia[v][j] == 1) && (marcados[j] == 0)){
					achou = 1; 
					matrizAdjacencia[j][v] = -1;
					matrizAdjacencia[v][j] = -1;
					break;
				}else if (((matrizAdjacencia[v][j] == -1) && (marcados[j] == 1)) && (j==matrizAdjacencia.size()-1)){
					return true;
				 }
			
			} 

			if (achou == 1)
				v = j;
			else if (v!=matrizAdjacencia.size()-1)
				v++;
			else{

				pilha.pop();

				if(pilha.empty()){
					break;
				}

				v = pilha.top();
			}
	}


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

int calcularFVS(int &it, int lb, int ub, std::vector<std::vector<int>> matrizAdjacencia,std::vector<std::vector<int>> matrizAdjacenciaAux,std::vector<std::vector<int>> matrizAdjacenciaAux0, std::vector<int> &CI, std::set<int> &FVS, std::map<int, int> map,std::vector<int> somas){
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
	//std::cout<< "itt:"<<it<<std::endl;

	if (upperbound < ub){
		return 0; 
	}
	else if (upperbound > ub)
		ub = upperbound; 
	if (lowerbound > lb){
		return 0;
	}
	else if (lowerbound < lb)
		lb = lowerbound; 

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
	 		calcularFVS(it,lb, ub, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );	
	 	}else if (vizinhosGenericos(matrizAdjacenciaAux0,vizinhos2, r1) >= 4){
			CI.push_back(r);
			calcularFVS(it, lb, ub, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			for (int j = 0; j < matrizAdjacenciaAux0.size(); ++j)
			{
				matrizAdjacenciaAux0[i][r] = 0;
				matrizAdjacenciaAux0[r][i] = 0;
			}
			printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);
			calcularFVS(it, lb, ub,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
	  	}else if(vizinhosGenericos(matrizAdjacenciaAux0,vizinhos2,r1) == 2){
			CI.push_back(r);
			calcularFVS(it,lb, ub, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
			{
				if ((matrizAdjacencia[r][j] != 0) && (vizinhos.size()<2)) 
				{
					vizinhos.push_back(j);
				}
					
			}
			
			for (int k = 0; k < matrizAdjacenciaAux0.size(); ++k)
			{
				
				if(vizinhos.size()==2){

					matrizAdjacenciaAux0[i][vizinhos[1]] = 0;
			 		matrizAdjacenciaAux0[vizinhos[1]][i] = 0;

				}
	
			 	matrizAdjacenciaAux0[i][vizinhos[0]] = 0;
			 	matrizAdjacenciaAux0[vizinhos[0]][i] = 0;
			 	
			}

			CI.push_back(vizinhos[0]);
			CI.push_back(vizinhos[1]);
			if(verificaCiclo(matrizAdjacenciaAux0)){
				CI.pop_back();
				CI.pop_back();
			}

			vizinhos.clear();
			printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);
			calcularFVS(it,lb, ub, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
			
	 	}else if(vizinhosGenericos(matrizAdjacenciaAux0,vizinhos,r1) == 3)

			aux++;
	}

	if (aux == CV.size()){
		int r2 = rand() % CV.size();

		int random = CV[r2];

		CI.push_back(random);

		calcularFVS(it,lb,ub,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

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

		calcularFVS(it,lb,ub,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

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

	 	calcularFVS(it, lb, ub,matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );

	 }

	printFVS(FVS,matrizAdjacencia,CI,CIAux, 1);

}

int BranchBound(int i,int d,int lb, int up, std::set<int> &FVS, std::vector<std::vector<int>> matrizAdjacencia,std::vector<std::vector<int>> &matrizAdjacenciaAux,std::vector<std::set<int>> &FVS2){
	
	matrizAdjacenciaAux = matrizAdjacencia;
	std::set<int>::iterator it;
	std::map<int, int> map;
	std::vector<int> graus;
		if (FVS.size() > up){
			FVS.clear();
			return 0;
	    }else{


			FVS.insert(i);

			for (it=FVS.begin(); it!=FVS.end(); ++it){

				
				for (int k = 0; k < matrizAdjacencia.size(); ++k)
				{
					int auz = *it;
					

					matrizAdjacenciaAux[auz][k] = 0;
					matrizAdjacenciaAux[k][auz] = 0;

			 	
					
				}
		}
		}
		
	



		 if (!verificaCiclo(matrizAdjacenciaAux)){
		 	//FVS.erase(i);
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
					for (int s = 0; s < matrizAdjacencia.size(); ++s)
					{
						matrizAdjacencia[d][s] = 0;
						matrizAdjacencia[s][d] = 0;
					}

						BranchBound(i++,d,lb, up, FVS, matrizAdjacencia, matrizAdjacenciaAux,FVS2);
						
				}
				
		  	}
			
		  }
 

}

int printMax(std::vector<std::set<int>> FVS2, int imp){
	int max = 0;
	std::set<int>::iterator it0;

	for (int i = 0; i < FVS2.size();i++){
		if (FVS2[i].size() >= max)
			max = i;
		
				
	 }
	 if (imp == 1){
		 for (it0=FVS2[max].begin(); it0!=FVS2[max].end(); ++it0)
			{
				std::cout << *it0 ;
			}

			std::cout<<std::endl;
	}
		return max;
}

int main(){

	
	std::set<int> FVS1;
	std::vector<std::set<int>> FVS2;
	std::vector<int> CI;
	std::vector<int> somas;
	std::map<int, int> map;
	int *cc;
	int ub, lb, it = 0;
	int upperbound, lowerbound;
	std::set<int>::iterator it0;
	std::set<int>::iterator it1;
	std::set<int>::iterator it2;

	std::set<int> FVS;

	// //TESTE COM 5 VÉRTICES
	std::vector<std::vector<int>> matrizAdjacenciaAux2 (5, std::vector<int>(5) );
	std::vector<std::vector<int>> matrizAdjacencia (5, std::vector<int>(5) );
	std::vector<std::vector<int>> matrizAdjacenciaAux (5, std::vector<int>(5) );
	std::vector<std::vector<int>> matrizAdjacenciaAux0 (5, std::vector<int>(5) );
	std::vector<std::vector<int>> matrizAdjacenciaAux1 (5, std::vector<int>(5) );
	
	// TESTE COM 10 VÉRTICES
	// std::vector<std::vector<int>> matrizAdjacenciaAux2 (10, std::vector<int>(10) );
	// std::vector<std::vector<int>> matrizAdjacencia (10, std::vector<int>(10) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux (10, std::vector<int> (10) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux0 (10, std::vector<int>(10) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux1 (10, std::vector<int>(10) );
	
	// //TESTE COM 20 VÉRTICES
	// std::vector<std::vector<int>> matrizAdjacenciaAux2 (20, std::vector<int>(20) );
	// std::vector<std::vector<int>> matrizAdjacencia (20, std::vector<int>(20) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux (20, std::vector<int>(20) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux0 (20, std::vector<int>(20) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux1 (20, std::vector<int>(20) );
	

	// //TESTE COM 40 VÉRTICES
	// std::vector<std::vector<int>> matrizAdjacenciaAux2 (40, std::vector<int>(40) );
	// std::vector<std::vector<int>> matrizAdjacencia (40, std::vector<int>(40) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux (40, std::vector<int>(40) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux0 (40, std::vector<int>(40) );
	// std::vector<std::vector<int>> matrizAdjacenciaAux1 (40, std::vector<int>(40) );
	


	std::chrono::time_point<std::chrono::system_clock> inicio, fim;
	unsigned long long int nanosegundos_decorridos;

	inicio = std::chrono::system_clock::now();
	preencherMatriz(matrizAdjacencia);

	// preencherAleatorio(matrizAdjacencia);
	
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



	  calcularFVS(it, lb, ub, matrizAdjacencia,matrizAdjacenciaAux,matrizAdjacenciaAux0, CI, FVS, map, somas );
      fim = std::chrono::system_clock::now();

    lowerbound = 1;
	upperbound = FVS.size();
	  for (it0=FVS.begin(); it0!=FVS.end(); ++it0){
				
				BranchBound(0,*it0,lowerbound,upperbound, FVS1, matrizAdjacenciaAux1,matrizAdjacenciaAux2,FVS2);
	}

	if (printMax(FVS2,0)>= FVS.size()){
		for (it0=FVS.begin(); it0!=FVS.end(); ++it0){
				std::cout << *it0 << std::endl;

		}
	}else
		printMax(FVS2,1);
	  
	 nanosegundos_decorridos = nanosegundos_decorridos + std::chrono::duration_cast<std::chrono::nanoseconds> (fim-inicio).count();

	 std::cout<<nanosegundos_decorridos<<" ms";
	


}
