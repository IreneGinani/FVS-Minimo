
#include <vector>
#include <iostream>
#include <algorithm>

void preencherMatriz(std::vector<std::vector<int>> matrizAdjacencia){


}

void mergeSuc(std::vector<std::vector<int>> &matrizAdjacencia, int verticep, int vertices){

	int count;

	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		if (matrizAdjacencia[i][verticep] == 1){
			matrizAdjacencia[i][vertices] ++;
			matrizAdjacencia[i][verticep] = 0;
		}else 
			count++;
	}
	for (int i = 0; i < matrizAdjacencia[verticep].size(); ++i)
	{
                 
        if (matrizAdjacencia[verticep][i] == 1){
			matrizAdjacencia[vertices][i] ++;
			matrizAdjacencia[verticep][i] = 0;
		} else
		   count++;      
		
	}




}
void mergePred(std::vector<std::vector<int>> &matrizAdjacencia, int verticep, int vertices){

	int count;

	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		if (matrizAdjacencia[i][vertices] == 1){
			matrizAdjacencia[i][verticep] ++;
			matrizAdjacencia[i][vertices] = 0;
		}else
		   count++;
	}
	for (int i = 0; i < matrizAdjacencia[vertices].size(); ++i)
	{
                 
        if (matrizAdjacencia[vertices][i] == 1){
			matrizAdjacencia[verticep][i] ++;
			matrizAdjacencia[vertices][i] = 0;
		}else
			count++;    
		
	}



}

void autoLoop(std::vector<std::vector<int>> &matrizAdjacencia, std::vector<int> &FVS){

	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			if((i==j) and (matrizAdjacencia[i][j] >= 1)){

				FVS.push_back(i);
				matrizAdjacencia[i][j] = 0;

			}
		}
	}


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



int main(){


	std::vector<int> FVS;
	std::vector<int> OC;
	std::vector<std::vector<int>> matrizAdjacencia (5, std::vector<int>(5) );
	std::vector<int> somas;
	preencherMatriz(matrizAdjacencia);
	SomaGraus(matrizAdjacencia, somas);




	for (int i = 0; i < matrizAdjacencia.size(); ++i)
	{
		for (int j = 0; j < matrizAdjacencia[0].size(); ++j)
		{
			mergeSuc(matrizAdjacencia,i,j);
 		    mergePred(matrizAdjacencia,i,j);
 		    autoLoop(matrizAdjacencia, FVS);
 		    SomaGraus(matrizAdjacencia,somas);


 		    if (eVazio(somas))
 		    	break;
		}


	}

	if(!eVazio(somas)){

		sort(somas.begin(), somas.end());


	}
 	




}