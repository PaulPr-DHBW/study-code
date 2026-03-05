#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Song
{
	char* song_title;
	char* artist_name;

	struct Song* next_Song_ptr;

} Song;

typedef struct Playlist
{

	Song* head_song;

} Playlist;

Playlist init_playlist(void);
void add_song(Playlist* origin_playlist);
void delete_first_Song(Playlist* origin_playlist);
void delete_playlist(Playlist* origin_playlist);
void delete_song_by_title(Playlist* origin_playlist, const char* title);

char* get_string(const char* Input_Name);
void print_playlist(Playlist* origin_playlist);
int count_playlist_elements(Playlist* origin_playlist);


int main(void)
{
	Playlist first_playlist = init_playlist();

	add_song(&first_playlist);
	add_song(&first_playlist);
	add_song(&first_playlist);

	print_playlist(&first_playlist);

	delete_first_Song(&first_playlist);

	print_playlist(&first_playlist);


	delete_song_by_title(&first_playlist , get_string("zu loeschenden Titel"));

	print_playlist(&first_playlist);

	return 0;
}


Playlist init_playlist(void)
{
	Playlist new_playlist;
	new_playlist.head_song = NULL;
	return new_playlist;
}

void add_song(Playlist* origin_playlist)
{
	//Initialise a new Array
	Song* new_Song = (Song*)malloc(sizeof(Song));
	if (new_Song == NULL)
	{
		printf("Fehler beim Hinzufügen eines neuen Songs\n");
		return;
	}

	new_Song->next_Song_ptr = NULL;
	char artist_name[] = "Artistname";
	char song_name[] = "Song Name";
	new_Song->artist_name = get_string(artist_name);
	new_Song->song_title = get_string(song_name);

	if (origin_playlist->head_song == NULL)
	{
		origin_playlist->head_song = new_Song;
		return;
	}

	Song* iterator = origin_playlist->head_song;

	while (iterator->next_Song_ptr != NULL)
	{
		iterator = iterator->next_Song_ptr;
	}

	iterator->next_Song_ptr = new_Song;

}

char* get_string(const char* Input_Name)
{
	char buffer[100];
	do
	{
		printf("Gib %s ein:", Input_Name);
	} while (fgets(buffer, sizeof(buffer), stdin) == NULL);

	buffer[strcspn(buffer, "\n")] = '\0';

	size_t input_len = strlen(buffer) + 1;

	char* return_string = (char*)malloc(input_len * sizeof(char));
	if (return_string == NULL)
	{
		printf("Get String fehlgeschlagen");
		return NULL;
	}

	strcpy(return_string, buffer);

	return return_string;


}

void delete_first_Song(Playlist* origin_playlist)
{
	Song* help_ptr = origin_playlist->head_song->next_Song_ptr;
	free(origin_playlist->head_song->artist_name);
	free(origin_playlist->head_song->song_title);
	free(origin_playlist->head_song);
	origin_playlist->head_song = help_ptr;
}

void delete_playlist(Playlist* origin_playlist)
{
	Song* iterator = origin_playlist->head_song;
	Song* help_pointer = NULL;

	while (iterator != NULL)
	{
		help_pointer = iterator->next_Song_ptr;
		free(iterator->artist_name);
		free(iterator->song_title);
		free(iterator);
		iterator = help_pointer;
	}
	origin_playlist->head_song = NULL;
}

void print_playlist(Playlist* origin_playlist)
{
	Song* iterator = origin_playlist->head_song;

	while (iterator != NULL)
	{
		printf("\nTitle: %s Artist: %s", iterator->song_title, iterator->artist_name);
		iterator = iterator->next_Song_ptr;
	}
	printf("\n\n");
}

void delete_song_by_title(Playlist* origin_playlist, const char *title)
{
	if (origin_playlist == NULL || title == NULL)
	{
		printf("Pointer in delete song bei tile sind auf NULL");
		return;
	}

	Song* iteration = origin_playlist->head_song;
	Song* help = NULL;
	if (iteration == NULL)
	{
		printf("keine Elemente in dieser Playlist");
		return;
	}

	while (iteration != NULL)
	{
		if (strcmp(title, iteration->song_title) == 0)
		{
			help = iteration;
			break;
		}

		iteration = iteration->next_Song_ptr;
	}

	if (help == NULL)
	{
		printf("Song mit Titel \"%s\" nicht gefunden\n", title);
		return;
	}

	//iterator auf element vorher und help auf danach
	//zunächst schauen ob es head ist
	if (help == origin_playlist->head_song)
	{
		origin_playlist->head_song = origin_playlist->head_song->next_Song_ptr;
		free(help->artist_name);
		free(help->song_title);
		free(help);
		return;
	}
	//Check if Last
	else if (help->next_Song_ptr == NULL)
	{
		iteration = origin_playlist->head_song;

		while (iteration->next_Song_ptr != help)
		{
			iteration = iteration->next_Song_ptr;
		}

		free(help->artist_name);
		free(help->song_title);
		free(help);
		iteration->next_Song_ptr = NULL;
		return;
	}
	//nun in der Mitte
	iteration = origin_playlist->head_song;
	while (iteration->next_Song_ptr != help)
	{
		iteration = iteration->next_Song_ptr;
	}
	iteration->next_Song_ptr = help->next_Song_ptr;
	free(help->artist_name);
	free(help->song_title);
	free(help);

}

int count_playlist_elements(Playlist* origin_playlist)
{
	Song* iteration = origin_playlist->head_song;
	int count = 0;

	if (iteration == NULL)
	{
		return count;
	}

	while (iteration != NULL)
	{
		count++;
		iteration = iteration->next_Song_ptr;
	}

	return count;
}

