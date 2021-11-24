#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

#define INF 1000000



//void obs2(){
 ////	10 x 10 obstacle
	//grid[3][3]=1;
	//grid[4][3]=1;
	//grid[5][3]=1;
	//grid[6][3]=1;
	//grid[7][3]=1;
	//grid[3][4]=1;
	//grid[3][5]=1;
//}


class Node{

	public:
		int i,j,val;
};

int main()
{
	Node n;

	n.i=5;
	n.j=5;
	n.val=1;

	int win_size  = 500;
	int sq_num = 10;
	int grid[10][10];

	int sq_size = win_size/sq_num;

	std::memset(grid,0,sizeof(grid));

	grid[n.i][n.j]=n.val;
	//render window with pixel size and title
	sf::RenderWindow window(sf::VideoMode(win_size, win_size), "Path Grid");
	//obs2();
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


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

		for(int i=0;i<sq_num;i++){
			for(int j=0;j<sq_num;j++){
				if(grid[i][j]==0){
					r.setFillColor(sf::Color::White);
				}
				else if(grid[i][j]==1){	
					r.setFillColor(sf::Color::Blue);
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
