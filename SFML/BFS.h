#include<bits/stdc++.h>

//-----------------------------------------BFS---------------------------------------------------------
void BFS(std::queue<int> q){
	if(!q.empty()){

		std::pair<int,int> u = q.front();
		q.pop();

		int u_i = u.first;
		int u_j = u.second;
		
		std::cout<<u_i<<" "<<u_j<<"\n";
		visited[u_i][u_j] = true;

		if(u_i==ei && u_j==ej){
			std::cout<<"Found\n";
			break;
		}

		if(u_i!=si || u_j!=sj)
			grid[u_i][u_j] = 4;


		for(int i=0; i<4; i++)
		{
			int neighRow = u_i + differenceY[i];
			int neighCol = u_j + differenceX[i];
			if(std::min(neighRow, neighCol) >= 0 && neighRow < sq_num && neighCol < sq_num && visited[neighRow][neighCol]==false && grid[neighRow][neighCol]!=1){
				//process node
				q.push(std::make_pair(neighRow,neighCol));
			}
		}
	}
}
//-----------------------------------------------------------------------------------------------------------

