#include <SFML/Graphics.hpp>  
#include <bits/stdc++.h>

#define INF 1000000

int win_size = 500;
#define sq_num 10
int grid[10][10];
int si,sj,ei,ej;

int differenceX[] = {0,0,1,-1};
int differenceY[] = {-1,1,0,0};

void obs1(){
 //	50 x 50 obstacle
	grid[11][11]=1;
	grid[11][12]=1;
	grid[11][13]=1;
	grid[11][14]=1;
	grid[11][15]=1;
	grid[11][10]=1;
	grid[11][9]=1;
	grid[11][8]=1;
}


void obs2(){
 //	10 x 10 obstacle
	grid[3][3]=1;
	grid[4][3]=1;
	grid[5][3]=1;
	grid[6][3]=1;
	grid[7][3]=1;
	grid[3][4]=1;
	grid[3][5]=1;
}


int main()
{

	bool visited[sq_num][sq_num];
	int sq_size = win_size/sq_num;
	bool flag = false;
 
	std::pair<int,int> start_node;
	std::pair<int,int> end_node;

	std::memset(visited,false,sizeof(visited));
	std::memset(grid,0,sizeof(grid));

	//render window with pixel size and title
	sf::RenderWindow window(sf::VideoMode(win_size, win_size), "Path Grid");
//grid options-----------------------
	//   2 - start node
	//   3 - end node
	start_node = std::make_pair(1,1);
	end_node = std::make_pair(4,4);

	//Checking grid----------------------

	//	grid[20][30] = 1;
//	obs1(); 
	obs2();
	// Robot ----------------------------
	
	//draw circle of 100px radius
	sf::CircleShape shape(5.f);
	//circle color green
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(15*sq_size,5*sq_size);


	// Environment ----------------------
	sf::Vector2f position(100, 100);
	sf::Vector2f size(sq_size, sq_size);	

	//rectangle object (Float) or else IntRect
	sf::RectangleShape r;
	r.setSize(size);
	r.setPosition(position);
	r.setFillColor(sf::Color::Red);
	r.setOutlineColor(sf::Color::Black);
	r.setOutlineThickness(1);

	//set framelimit to 0 and enable vsync
	//required for unneccasary single core load
	window.setFramerateLimit(120);
	window.setVerticalSyncEnabled(true);


//----------For pathfinding implementation

	si = start_node.first;
	sj = start_node.second;
	ei = end_node.first;
	ej = end_node.second;


	grid[si][sj] = 2;
	grid[ei][ej] = 3;

	//BFS queue non priority
	std::queue<std::pair<int,int>> q;
	q.push(start_node);

	std::priority_queue<int, vector<int>, greater<int> > q;
	q.push(start_node);

	int dis[sq_num][sq_num];
	std::memset(dis,INF,sizeof(dis));

	//Manhattan  distances for A* 
	int manDis[sq_num][sq_num];
	std::memset(manDis,INF,sizeof(manDis));
	
	for(int i=0;i<sq_num;i++){
		for(int j=0;j<sq_num;j++){
			manDis[i][j]=std::abs(ei-i)+ std::abs(ej-j);
			std::cout<<manDis[i][j]<<" ";
		}
		std::cout<<"\n";
	}

	dis[si][sj]= 0 + manDis[si][sj];

	//loop while window open
	while (window.isOpen()) { 
		sf::Event event; 
		int posx,posy;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i pos = sf::Mouse::getPosition();
				posx = int(pos.x/sq_size);
				posy = int(pos.y/sq_size);
				if(posx < sq_num && posy <sq_num)
					grid[int(pos.x/sq_size)][int(pos.y/sq_size)-3]=1;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				sf::Vector2i pos = sf::Mouse::getPosition();
				posx = int(pos.x/sq_size);
				posy = int(pos.y/sq_size);
				//check title bar selection
				if(posx < sq_num && (posy>3 && posy<sq_num-3))
					grid[int(pos.x/sq_size)][int(pos.y/sq_size)-3]=0;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && flag==false)
			{
				flag = true;
			}
		}

////----------------------------------------- Life Long A* with Manhattan heuristic---------------------------------------------------------
	if(!q.empty()){

		int u = q.top();
		q.pop();


		std::cout<<u<<"\n";
	}

//-----------------------------------------------------------------------------------------------------------
		window.clear();
		for(int i=0;i<sq_num;i++){
			for(int j=0;j<sq_num;j++){
				if(grid[i][j]==0){
					r.setFillColor(sf::Color::White);
				}
				else if(grid[i][j]==2){	
					r.setFillColor(sf::Color::Red);
				}
				else if(grid[i][j]==3){	
					r.setFillColor(sf::Color::Green);
				}
				else if(grid[i][j]==4){	
					r.setFillColor(sf::Color::Blue);
				}
				else{
					r.setFillColor(sf::Color::Black);
				}
				r.setPosition(sq_size*i,sq_size*j);
				window.draw(r);
			}
		}
	//	window.draw(shape);
		window.display();
	}
	return 0;
}
