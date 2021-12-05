#include<bits/stdc++.h>
using namespace std;

#define INF 1000000
#define size 20


int differenceX[] = {0,0,1,-1};
int differenceY[] = {-1,1,0,0};

class Node{

/**
 *
 *
 * Node state
 *	0 -> available
 *	1 -> obstacle
 *	2 -> current
 *	3 -> start
 *	4 -> goal
 *
 *
 * */
	public:
		int state;
		int i,j;
		int g;
		int rhs; 
		pair<int,int> key;
		vector<Node> Successors;
		vector<Node> Predecessors;

};


//pair<int,int>
void calculateKey(Node s, int h[][size]){
	//Calculates the key value
	int a = min(s.g,s.rhs) + h[s.i][s.j];
	int b = min(s.g,s.rhs);


	pair<int,int> key = make_pair(a,b);
	s.key = key;
	//return key;
}

struct CompareKeys {
    bool operator()(Node const& p1, Node const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return (p1.key.first < p2.key.first || (p1.key.first == p2.key.first && p1.key.first <= p2.key.first));
    }
};


void initialize(Node grid[][size], int h[][size], Node start, Node goal, priority_queue<Node,vector<Node>, CompareKeys> &q){
//Initializes the grid of Nodes
	
	grid[start.i][start.j].state = 3;
	grid[goal.i][goal.j].state = 4;


	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
				grid[i][j].i = i;
				grid[i][j].j = j;
				grid[i][j].g = INF;
				grid[i][j].rhs = INF;
			if((i == start.i && j == start.j)){
				grid[i][j].state = 3;
			}else if( i == goal.i && j == goal.j){
				grid[i][j].state = 4;
			}
			else{
				grid[i][j].state = 0;
			}

			//generated using manhatton distances
			h[i][j] = std::abs(goal.i-i)+ std::abs(goal.i-j);
		}
	}

	calculateKey(grid[start.i][start.j],h);
	q.push(grid[start.i][start.j]);

}

void neighbours(Node grid[][size]){
//Populate successors
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			
			int neighRow = i + differenceY[i];
			int neighCol = j + differenceX[i];
			if(neighRow < size && neighCol <size && neighRow >=0 && neighCol >= 0 && grid[neighRow][neighCol].state!=1){
				grid[i][j].Successors.push_back(grid[neighRow][neighCol]);

			}

		}
	}
}

void obs2(Node grid[][size]){
 //	10 x 10 obstacle
	grid[3][3].state=1;
	grid[4][3].state=1;
	grid[5][3].state=1;
	grid[6][3].state=1;
	grid[7][3].state=1;
	grid[3][4].state=1;
	grid[3][5].state=1;
}




int main(){
	Node grid[size][size];
	int h[size][size];
	
	Node start;
	start.i = 2;
	start.j = 2;


	Node goal;
	goal.i = 18;
	goal.j = 10;

	priority_queue< Node , vector<Node>, CompareKeys> q;

	initialize(grid,h,start,goal,q);

	obs2(grid);

	neighbours(grid);

	


	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<grid[i][j].state<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n\n =================== Heuristic graph ========================= \n\n\n";
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			int temp = h[i][j];

			if(temp < 10)
				cout<<" "<<temp<<" ";
			else
				cout<<temp<<" ";
		}
		cout<<"\n";
	}


	return 0;
}
