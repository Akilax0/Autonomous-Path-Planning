#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#define INF 1000000

#define win_size 500
#define sq_num  10

class Node{

	public:
		int i,j,val;
		int rhs = 0;
};

struct CompareDis {
    bool operator()(Node const & n1, Node const & n2) {
        // return "true" if "n1" is ordered before "n2", for example:
        return n1.rhs < n2.rhs;
    }
};

int grid[sq_num][sq_num];

bool visited[sq_num][sq_num];
int differenceX[] = {0,0,1,-1};
int differenceY[] = {-1,1,0,0};

void LPA(std::priority_queue<Node,std::vector<Node>,CompareDis> *q, Node end){

	if(!q->empty()){

		Node u = q->top();
		q->pop();
		visited[u.i][u.j] = true;

		grid[u.i][u.j]=u.val;

		if(u.i==end.i && u.j==end.j){
			std::cout<<"Found\n";
			while(true){}
		}

		for(int i=0; i<4; i++)
		{
			int neighRow = u.i + differenceY[i];
			int neighCol = u.j + differenceX[i];
			if(std::min(neighRow, neighCol) >= 0 && neighRow < sq_num && neighCol < sq_num && visited[neighRow][neighCol]==false && grid[neighRow][neighCol]!=1){
				//process node
				Node v;
				v.i=neighRow;
				v.j=neighCol;
				v.val=4;
				q->push(v);
			}

		}
	}
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

	int sq_size = (int) win_size/sq_num;

	bool flag = false;
	std::memset(grid,0,sizeof(grid));
	std::memset(visited,false,sizeof(visited));

	//render window with pixel size and title
	sf::RenderWindow window(sf::VideoMode(win_size, win_size), "Path Grid");

	obs2();


    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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

//======================== Prep for BFS ===============================



	Node start;
	Node end;


	start.i=2;
	start.j=2;
	start.val=2;

	end.i=8;
	end.j=9;
	end.val=3;
	
	std::priority_queue<Node,std::vector<Node>,CompareDis> q;
	q.push(start);


    while (window.isOpen())
    {
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

		grid[start.i][start.j]=start.val;
		grid[end.i][end.j]=end.val;

		LPA(&q,end);

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
        //window.draw(shape);
        window.display();
    }

    return 0;
}
