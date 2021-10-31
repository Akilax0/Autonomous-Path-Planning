#include <SFML/Graphics.hpp>  
#include <bits/stdc++.h>

int main()
{
	int win_size = 500;
	int sq_num = 50;
	int grid[sq_num][sq_num];
	int sq_size = win_size/sq_num;
	
	std::memset(grid,0,sizeof(grid));
		
	//render window with pixel size and title
    sf::RenderWindow window(sf::VideoMode(win_size, win_size), "Path Grid");

//Checking grid----------------------

//	grid[20][30] = 1;

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
	window.setFramerateLimit(0);
	window.setVerticalSyncEnabled(true);

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
        }

        window.clear();
		for(int i=0;i<sq_num;i++){
			for(int j=0;j<sq_num;j++){
				if(grid[i][j]==0){
					r.setFillColor(sf::Color::White);
				}
				else{
					r.setFillColor(sf::Color::Black);
				}
				r.setPosition(sq_size*i,sq_size*j);
				window.draw(r);
			}
		}
        window.draw(shape);
        window.display();
    }
    return 0;
}
