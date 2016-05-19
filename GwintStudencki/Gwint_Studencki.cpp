#include "Gwint_Studencki_Header.h"
#include "Game_Header.h"
Game core;
int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !core.init() )
	{
		printf( "Failed to initialize!\n" );
		system("PAUSE");
	}
	else
	{
		//Load media
		if( !core.loadMedia() )
		{
			printf( "Failed to load media!\n" );
			system("PAUSE");
		}
		else
		{	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}
				core.applythepng();
			}
		}
	}
	//Free resources and close SDL
	core.close();

	return 0;
}