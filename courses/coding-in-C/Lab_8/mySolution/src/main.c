#include "../include/playlist.h"

#include <stdio.h>

int main(void)
{
	Playlist first_playlist = init_playlist();
	int menu_code;

	while (1)
	{
		printf("\n\n\n");
		menu_code = menu();

		switch (menu_code)
		{
		case CONST_ADD:
			add_song(&first_playlist);
			break;

		case CONST_DELETE_FIRST:
			delete_first_Song(&first_playlist);
			break;

		case CONST_DELETE_PLAYLIST:
			delete_playlist(&first_playlist);
			break;

		case CONST_DELETE_TITLE:
			delete_song_by_title(&first_playlist, get_string("Titel"));
			break;

		case CONST_PRINT_PLAYLIST:
			printf("\n");
			print_playlist(&first_playlist);
			break;

		case CONST_COUNT_ELEMENT:
			printf("\nElemente in der Liste:	%d", count_playlist_elements(&first_playlist));
			break;

		case CONST_EXIT:
			delete_playlist(&first_playlist);
			return 0;
			break;


		default:
			printf("\nWrong input, try again");
		}


	}

	return 0;
}